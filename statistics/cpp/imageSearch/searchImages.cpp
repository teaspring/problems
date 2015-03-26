/**
 * @file searchImages.cpp
 * @brief C++ implementation of one search image engine based on statistical test with histogram 
 * @author bruce.yu
 *
 * one optional HSV bin set is {8, 12, 3}, from pyimagesearch
 * another is {50, 60}, without V, from opencv-userguide/sample/imgproc/histogram
 * finally, I find {50, 60, 2} is relatively better than above two options
 *
 * how to compile it:
 * precedence: opencv installed already
 * $ cmake .
 * $ make
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fts.h>
#include <fnmatch.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include "MaxHeap.h"

using namespace std;
using namespace cv;

const int SEG_COUNT = 5;

class SearchEngine{

public:
    SearchEngine(int h, int s, int v): h_bins(h), s_bins(s), v_bins(v){}
    virtual ~SearchEngine(){}

    void searchHist(const char* base, const char* test1, const char* test2);

    int searchImages(char* srcImgName, char** paths, char** pImgNames /* out */, int topN);

    const static int MAX_COUNT = 200;

private:
    int getMaskedHists(const char* srcName /* in */, Mat* hists /* out */);

    void generateSegMasks(int height, int width, Mat* masks);

    void calcMaskedHists(const Mat* hsvSrc, int nimages, Mat* hists, int n, Mat* masks, const int* channels,
                const int dims, const int* histSize, const float** ranges);

    int compareHistWeighted(const Mat* histsBase, int n, const Mat* histsTest, int methodIdx, float alpha);

    inline bool isImage(char* name){
        return (fnmatch("*.jpg", name, FNM_CASEFOLD) == 0
                || fnmatch("*.png", name, FNM_CASEFOLD) == 0);
    }

private:
    int h_bins, s_bins, v_bins;
};

    /*
     * compare two test images with one base image
     * */
    void SearchEngine::searchHist(const char* base, const char* test1, const char* test2){
        Mat baseHists[SEG_COUNT];
        getMaskedHists(base, baseHists);

        Mat test1Hists[SEG_COUNT];
        getMaskedHists(test1, test1Hists);

        Mat test2Hists[SEG_COUNT];
        getMaskedHists(test2, test2Hists);

        /// compare histogram in weighted
        float alpha = 0.28;     // our 5 weights are [alpha, (1 - alpha)/(n-1),...]
        int compare_method = 1;  // 1 for CV_COMP_CHISQR
        float base_base  = compareHistWeighted(baseHists, SEG_COUNT, baseHists, compare_method, alpha);
        float base_test1 = compareHistWeighted(baseHists, SEG_COUNT, test1Hists, compare_method, alpha);
        float base_test2 = compareHistWeighted(baseHists, SEG_COUNT, test2Hists, compare_method, alpha);
        printf("weighted compare hitogram perfect, Base-Test(1), Base-Test(2): %f, %f, %f \n",
                    base_base, base_test1, base_test2);
        return;
    }

    /*
     * search top images in <dstPath> similar with srcImg
     * */
    int SearchEngine::searchImages(char* base, char** dstPath, char** pImgNames /* out */, int topN){
        Mat baseHists[SEG_COUNT];
        if(getMaskedHists(base, baseHists)){
            printf("source image fail to calculate masked histograms!\n");
            return 0;
        }

        const int method_idx = 1;
        const float alpha = 0.28;

        int sqrValues[MAX_COUNT];
        int soldCount = 0;

        float t = (float)getTickCount();

        /// iterate <dstPath> for image
        FTS *tree = fts_open(dstPath, FTS_NOCHDIR, 0);
        if(!tree){
            perror("fts_open");
            return 0;
        }

        MaxHeap mheap(sqrValues, pImgNames, topN);
        bool isKMinimum = true;
        FTSENT *node;
        while(node = fts_read(tree)){
            if(MAX_COUNT == soldCount)    break;
            if(node->fts_level > 0 && node->fts_name[0] == '.'){
                fts_set(tree, node, FTS_SKIP);
                continue;
            }
            else if((node->fts_info & FTS_F) && isImage(node->fts_name)){ // fts_name is short file name
                Mat testHists[SEG_COUNT];
                char* lname = node->fts_accpath; // fts_accpath, access path is long file name
                if(getMaskedHists(lname, testHists)){
                    fts_set(tree, node, FTS_SKIP);
                    continue;
                }
                sqrValues[soldCount] = compareHistWeighted(baseHists, SEG_COUNT, testHists, method_idx, alpha);

                char* nameCopy = new char[strlen(lname) + 1];
                nameCopy[strlen(lname)] = '\0';
                strcpy(nameCopy, lname);
                pImgNames[soldCount] = nameCopy;

                soldCount++;

                if(isKMinimum){
                    if(soldCount == topN){
                        mheap.heap_build();
                    }else if(soldCount > topN){
                        mheap.heap_insert(sqrValues[soldCount - 1], pImgNames[soldCount - 1]);
                    }
                }
            }
        }

        if(!isKMinimum){
            Utility util;
            util.quick_sort(sqrValues, soldCount, pImgNames);
        }else{
            mheap.heap_sort();
        }

        float seconds = ((float)getTickCount() - t) / getTickFrequency();

        printf("base file: %s\n", base);
        printf("==========================================================\n");
        for(int i = 0 ; i < min(topN, soldCount); i++){
            printf("image %s, chi-square value: %d\n", pImgNames[i], sqrValues[i]);
        }
        printf("==========================================================\n");
        printf("engine channel bins:  H-%d, S-%d, V-%d\n", h_bins, s_bins, v_bins);
        printf("search + sort time: %f seconds\n", seconds);

        return min(topN, soldCount);
    }

    /*
     * calculate five histograms dependent on five segment masks.
     * @return 0 for success, >0 for error
     * */
    int SearchEngine::getMaskedHists(const char* nameSrc /* in */, Mat* hists /* out */){
        Mat matSrc, hsvSrc;
        matSrc = imread(nameSrc, 1);
        cvtColor(matSrc, hsvSrc, COLOR_BGR2HSV);  // BGR -> HSV, here V = R

        /// we have 5 segment histograms for each image
        Mat srcMasks[5];
        generateSegMasks(hsvSrc.rows, hsvSrc.cols, srcMasks);
        
        /// histogram size consisting of multiple channel bins
        int histSize[] = { this->h_bins, this->s_bins, this->v_bins };

        float h_ranges[] = { 0, 180 };
        float s_ranges[] = { 0, 256 };
        float v_ranges[] = { 0, 256 };
        const float* ranges[] = { h_ranges, s_ranges, v_ranges};

        int channels[] = {0, 1, 2};  // H, S and V
        const int dims = sizeof(channels) / sizeof(int);

        calcMaskedHists(&hsvSrc, 1, hists, 5, srcMasks, channels, dims, histSize, ranges);
        return 0;
    }

    /*
    * generate 5 masks dependent on size: mid, left-up corner(rectangle), right-up corner, left-down corner, right-down corner
    * */
    void SearchEngine::generateSegMasks(int height, int width, Mat* masks){
        int h = height, w = width;
        int cx = w/2, cy = h/2;
        Size axes((int)w/8*3, (int)h/8*3); // half of size of ellipse's main axes
    
        Mat ellipMask = Mat::zeros(h, w, CV_8UC1);  // mask type must be CV_8UC1(0)
        ellipse(ellipMask, Point(cx, cy), axes, 0, 0, 360, Scalar(255), -1);
        masks[0] = ellipMask;

        /// draw 4 corner masks which subtracts ellipse mask 
        int XYs[] = { 0,  0, cx, cy,
                     cx,  0,  w, cy,
                      0, cy, cx,  h,
                     cx, cy,  w,  h};
        for(int i=0; i<4; i++){
            Mat cornerMask = Mat::zeros(h, w, CV_8UC1);
            rectangle(cornerMask, 
                      Point(XYs[i*4], XYs[i*4 + 1]), 
                      Point(XYs[i*4 + 2], XYs[i*4 + 3]), 
                      Scalar(255), -1);  // get a corner mask whihc field is 1/4 of initial rectangle
            subtract(cornerMask, ellipMask, cornerMask);  // subtract ellipMask from cornerMask
            masks[i+1] = cornerMask;
        }
        return;
    }

    /*
    * @param hists and masks have same size of n
    * @param channels, histSize and ranges have same size of dims
    * */
    void SearchEngine::calcMaskedHists(const Mat* hsvSrc, int nimages, Mat* hists, int n, Mat* masks, const int* channels,
                const int dims, const int* histSize, const float** ranges){
        for(int i=0; i < n; i++){
            Mat hist;
            calcHist(hsvSrc, nimages, channels, masks[i], hist, dims, histSize, ranges);
            normalize(hist, hist);
            hists[i] = hist;
        }
        return;
    }

    /*
    * our weighted result of compareHist()
    * @param alpha: weight of 1st element
    * @param methodIdx: one of CV_COMP_XXX
    * */
    int SearchEngine::compareHistWeighted(const Mat* histsBase, int n, const Mat* histsTest, int methodIdx, float alpha){
        float beta = (1 - alpha) / (n-1);
        float res = compareHist(histsBase[0], histsTest[0], methodIdx) * alpha;
        for(int i=1; i < n; i++){
            res += compareHist(histsBase[i], histsTest[i], methodIdx) * beta;
        }
        return res;
    }

/****************************  @function main **************************/
int main( int argc, char** argv ){
    if(argc < 4){
        printf("** Error. Usage: ./searchImages <image_base> <search_repository> <top_N_results>\n");
        return -1;
    }
    SearchEngine se(50, 60, 2);
    char* outImages[SearchEngine::MAX_COUNT];
    int n = se.searchImages(argv[1], argv + 2, outImages, atoi(argv[3]));
    // se.searchHist(argv[1], argv[2], argv[3]);
    return 0;
}
