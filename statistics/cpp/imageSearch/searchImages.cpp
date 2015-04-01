/**
 * @file searchImages.cpp
 * @brief C++ implementation of one search image engine based on statistical test with histogram 
 * @author bruce.yu
 *
 * about HSV bins setup, there are many options:
 * from pyimageseaerch, it is {8, 12, 3}
 * from image compare example in opencv manual, it is {50, 60}
 * you can test varied HSV bins to test which is better for your use.
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

static const int SEG_COUNT = 5;

class SearchEngine{

public:
    SearchEngine(int h, int s, int v): h_bins(h), s_bins(s), v_bins(v){}

    virtual ~SearchEngine(){}

    void searchHist(const char *base, const char *test1, const char *test2);

    int searchImages(const char *srcImgName, char **paths, char **pImgNames /* out */, int topN);

    static const int MAX_COUNT = 200;

private:
    int getMaskedHists(const char *srcName, Mat *hists /* out */);

    static void generateSegMasks(int height, int width, Mat *masks);

    static void calcMaskedHists(const Mat *hsvSrc, int nimages, Mat *hists /* out */, int n, Mat *masks, const int *channels,
                const int dims, const int *histSize, const float **ppRanges);

    static int compareHistWeighted(const Mat *histsBase, int n, const Mat *histsTest, int methodIdx, float alpha);

    inline bool isImage(const char* name){
        return (fnmatch("*.jpg", name, FNM_CASEFOLD) == 0
                || fnmatch("*.png", name, FNM_CASEFOLD) == 0);
    }

private:
    int h_bins; // channel bins
    int s_bins;
    int v_bins;

    static const float alpha = 0.28f; // weights are [alpha, beta, beta ...] where beta = (1 - alpha) / (n-1)
    static const int method_idx = HISTCMP_CHISQR;  // CHI-SQUARE compare, enum value equals to 1
};

    /*
     * compare two test images with one base image
     * */
    void SearchEngine::searchHist(const char *base, const char *test1, const char *test2){
        Mat baseHists[SEG_COUNT];
        getMaskedHists(base, baseHists);

        Mat test1Hists[SEG_COUNT];
        getMaskedHists(test1, test1Hists);

        Mat test2Hists[SEG_COUNT];
        getMaskedHists(test2, test2Hists);

        /// compare histogram in weighted
        float base_base  = compareHistWeighted(baseHists, SEG_COUNT, baseHists, method_idx, alpha);
        float base_test1 = compareHistWeighted(baseHists, SEG_COUNT, test1Hists, method_idx, alpha);
        float base_test2 = compareHistWeighted(baseHists, SEG_COUNT, test2Hists, method_idx, alpha);
        printf("weighted compare hitogram perfect, Base-Test(1), Base-Test(2): %f, %f, %f \n",
                    base_base, base_test1, base_test2);
        return;
    }

    /*
     * search top images in <dstPath> similar with srcImg
     * */
    int SearchEngine::searchImages(const char *base, char **dstPath, char **pImgNames /* out */, int topN){
        if(!isImage(base)){
            printf("Invalid base image file!\n");
            return 1;
        }

        Mat baseHists[SEG_COUNT];
        if(getMaskedHists(base, baseHists)){
            printf("source image fail to calculate masked histograms!\n");
            return 0;
        }

        int sqrValues[MAX_COUNT]; // image compare integer result
        int soldCount = 0;

        float t = (float)getTickCount();

        // iterate <dstPath> to process image file
        FTS *tree = fts_open(dstPath, FTS_NOCHDIR, 0);
        if(!tree){
            perror("fts_open");
            return 0;
        }

        MaxHeap mheap(sqrValues, pImgNames, topN);  // max heap to keep N minimum elements

        bool isKMinimum = true;
        FTSENT *node;

        while(node = fts_read(tree)){ // use <fts.h> to iterate image files
            if(MAX_COUNT == soldCount)    break;

            if(node->fts_level > 0 && node->fts_name[0] == '.'){ // skip directory and "." and ".."
                fts_set(tree, node, FTS_SKIP);
                continue;
            }

            if((node->fts_info & FTS_F) && isImage(node->fts_name)){ // fts_name is short file name
                char *lname = node->fts_accpath; // fts_accpath is access path (long file name)

                if(strcmp(base, lname) == 0)    continue; // base image compare with itself results 0 definitely

                Mat testHists[SEG_COUNT];

                if(getMaskedHists(lname, testHists)){ // fail to get masked histograms, skip this image
                    fts_set(tree, node, FTS_SKIP);
                    continue;
                }

                sqrValues[soldCount] = compareHistWeighted(baseHists, SEG_COUNT, testHists, method_idx, alpha);

                for(int i = 0; i < SEG_COUNT; i++){  // release unused Mat[] of test image
                    testHists[i].release();
                }

                char *nameCopy = new char[strlen(lname) + 1]; // copy image file name
                nameCopy[strlen(lname)] = '\0';
                strcpy(nameCopy, lname);
                pImgNames[soldCount] = nameCopy;

                soldCount++;

                if(isKMinimum){
                    if(soldCount > topN){
                        mheap.heap_insert(sqrValues[soldCount - 1], pImgNames[soldCount - 1]);
                    }
                }
            }
        }

        for(int i = 0; i < SEG_COUNT; i++){  // release unused Mat[] of base image
            baseHists[i].release();
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
     * non-static method to calculate segment histograms dependent on segment masks.
     * @return 0 for success, > 0 for error
     * */
    int SearchEngine::getMaskedHists(const char *nameSrc /* in */, Mat *hists /* out */){
        Mat matSrc, hsvSrc;
        matSrc = imread(nameSrc, 1); // CV_LOAD_IMAGE_COLOR

        cvtColor(matSrc, hsvSrc, COLOR_BGR2HSV);  // BGR -> HSV, here V = R

        /// we have 5 segment histograms for each image
        Mat srcMasks[SEG_COUNT];
        generateSegMasks(hsvSrc.rows, hsvSrc.cols, srcMasks);
        
        // image process parameters
        static const float h_ranges[] = { 0, 180 };
        static const float s_ranges[] = { 0, 256 };
        static const float v_ranges[] = { 0, 256 };
        static const float* ranges[] = { h_ranges, s_ranges, v_ranges };

        static const int channels[] = {0, 1, 2}; // H, S and V
        static const int dims = sizeof(channels) / sizeof(int);

        const int histSize[] = { this->h_bins, this->s_bins, this->v_bins };

        calcMaskedHists(&hsvSrc, 1, hists, 5, srcMasks, channels, dims, histSize, ranges);

        for(int i = 0; i < SEG_COUNT; i++){  // release unused Mat[] of masks
            srcMasks[i].release();
        }

        return 0;
    }

    /*
     * static method to generate segment masks:
     * mid ellipse, left-up corner(rectangle), right-up corner, left-down corner, right-down corner
     * */
    void SearchEngine::generateSegMasks(int height, int width, Mat *masks){
        int h = height, w = width;
        int cx = w/2, cy = h/2;
        Size axes(w * 3/8, h * 3/8); // half of size of ellipse's main axes
    
        Mat ellipMask = Mat::zeros(h, w, CV_8UC1);  // mask type must be CV_8UC1(0)
        ellipse(ellipMask, Point(cx, cy), axes, 0, 0, 360, Scalar(255), -1);
        masks[0] = ellipMask;

        /// draw 4 corner masks which subtracts ellipse mask 
        int XYs[] = { 0,  0, cx, cy,
                     cx,  0,  w, cy,
                      0, cy, cx,  h,
                     cx, cy,  w,  h};
        for(int i = 0; i < 4; i++){
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
     * static method to calculate masked histograms
     * @param hists and masks have same size of n
     * @param channels, histSize and ranges have same size of dims
     * */
    void SearchEngine::calcMaskedHists(const Mat* hsvSrc, int nimages, Mat* hists, int n, Mat* masks, const int* channels,
                const int dims, const int* histSize, const float** ppRanges){
        for(int i = 0; i < n; i++){
            Mat hist;
            calcHist(hsvSrc, nimages, channels, masks[i], hist, dims, histSize, ppRanges);
            normalize(hist, hist); // normalize the histogram Mat

            hists[i] = hist;
        }
        return;
    }

    /*
     * static method to compare images with masked histograms in weight
     * @param alpha: weight of 1st element
     * @param methodIdx: one of CV_COMP_XXX
     * */
    int SearchEngine::compareHistWeighted(const Mat* histsBase, int n, const Mat* histsTest, int methodIdx, float alpha){
        float beta = (1 - alpha) / (n-1);
        float res = compareHist(histsBase[0], histsTest[0], methodIdx) * alpha;
        for(int i = 1; i < n; i++){
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

    SearchEngine se(50, 60, 3);
    char* outImages[SearchEngine::MAX_COUNT];
    se.searchImages(argv[1], argv + 2, outImages, atoi(argv[3]));
    // se.searchHist(argv[1], argv[2], argv[3]);
    return 0;
}
