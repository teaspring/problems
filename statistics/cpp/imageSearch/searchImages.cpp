/**
 * @file searchImages.cpp
 * @brief C++ implementation of one search image engine based on statistical test with histogram 
 * @author bruce.yu
 * 
 * one recommend HSV bins are {8, 12, 3}
 *
 * how to compile it:
 * precedence: opencv installed already
 * $ cmake .
 * $ make
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

class SearchEngine{

public:
    SearchEngine(int h, int s, int v): h_bins(h), s_bins(s), v_bins(v){}
    virtual ~SearchEngine(){}

    void searchHist(const char* base, const char* test1, const char* test2){
        Mat src_base,  hsv_base;
        Mat src_test1, hsv_test1;
        Mat src_test2, hsv_test2;

        src_base  = imread(base,  1); // int flag > 0, return a 3-channels color image
        src_test1 = imread(test1, 1);
        src_test2 = imread(test2, 1);
    
        /// BGR2HSV, the srcMat must have 3 or 4 channels 
        cvtColor(src_base,  hsv_base,  COLOR_BGR2HSV); // now V = R
        cvtColor(src_test1, hsv_test1, COLOR_BGR2HSV);
        cvtColor(src_test2, hsv_test2, COLOR_BGR2HSV);

        /// histogram size consisting of multiple channel bins
        int histSize[] = { h_bins, s_bins, v_bins };

        // hue varies from 0 to 179, saturation from 0 to 255
        float h_ranges[] = { 0, 180 };
        float s_ranges[] = { 0, 256 };
        float v_ranges[] = { 0, 256 };
        const float* ranges[] = { h_ranges, s_ranges, v_ranges };

        // Use the 0-th and 1-st channels
        int channels[] = { 0, 1, 2 };  // H, S and V

        /// Histograms, here we have 5 histograms for each image
        Mat srcMasks[5];
        generateFiveMasks(hsv_base.size(), srcMasks);
        Mat baseHists[5];
        calcMaskedHists(&hsv_base,  1, baseHists,  5, srcMasks, channels, 3, histSize, ranges);
    
        Mat test1Masks[5];
        generateFiveMasks(hsv_test1.size(), test1Masks);
        Mat test1Hists[5];
        calcMaskedHists(&hsv_test1, 1, test1Hists, 5, test1Masks, channels, 3, histSize, ranges);

        Mat test2Masks[5];
        generateFiveMasks(hsv_test2.size(), test2Masks);
        Mat test2Hists[5];
        calcMaskedHists(&hsv_test2, 1, test2Hists, 5, test2Masks, channels, 3, histSize, ranges);
    
        /// compare histogram in weighted
        double alpha = 0.28; // our 5 weights are [0.28, 0.18, 0.18, 0.18, 0.18]
        int compare_method = 1;  // 1 for CV_COMP_CHISQR
        double base_test1 = compareHistWeighted(baseHists, 5, test1Hists, compare_method, alpha);
        double base_test2 = compareHistWeighted(baseHists, 5, test2Hists, compare_method, alpha);    
        printf(" weighted compare histogram Base-Test(1), Base-Test(2) : %.4f, %.4f \n", base_test1, base_test2);
        return;
    }

private:
    /*
    * generate 5 masks dependent on size: mid, left-up corner(rectangle), right-up corner, left-down corner, right-down corner
    * */
    void generateFiveMasks(const Size& size, Mat* masks){
        int h = size.height, w = size.width;
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
                      Scalar(255), -1);
            subtract(cornerMask, ellipMask, cornerMask);  // subtract ellipMask from cornerMask
            masks[i+1] = cornerMask;
        }
        return;
    }

    /*
    * @param hists and masks have same size of n
    * @param channels, histSize and ranges have same size of dims
    * */
    void calcMaskedHists(const Mat* hsvSrc, int nimages, Mat* hists, int n, Mat* masks, const int* channels, 
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
    double compareHistWeighted(const Mat* histsBase, int n, const Mat* histsTest, int methodIdx, double alpha){
        double beta = (1 - alpha) / (n-1);
        double res = compareHist(histsBase[0], histsTest[0], methodIdx) * alpha;
        for(int i=1; i < n; i++){
            res += compareHist(histsBase[i], histsTest[i], methodIdx) * beta;
        }
        return res;
    }

private:
    int h_bins, s_bins, v_bins;
};

/**
 * @function main
 */
int main( int argc, char** argv ){
    /// Load three images with different environment settings
    if(argc < 4){
        printf("** Error. Usage: ./searchHist_Demo <image0_base> <images_dir_toSearch> <number_results>\n");
        return -1;
    }
    SearchEngine se(8, 12, 3);
    se.searchHist(argv[1], argv[2], argv[3]);
    return 0;
}
