/*
 * given an int array, given a range [i,j], find the maximum in the range.
 * requirement: this find operation will be executed frequently
 * */
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * @param begin and end are index both, making up a range of [begin, end]
     * prepare space O(n), time O(n)
     * operation time O(l) where l is length of range
     * */
    int maxInRange_1(int *A, int n, int begin, int end){
        vector<int> peaks = getPeaks(A, n); // elements in peaks is index of A[]

        int beginPeak = biSearchExclu(peaks, begin); // return index of peaks[]
        int endPeak = biSearchExclu(peaks, end);

        int res = A[begin];
        for(int i = beginPeak; i < endPeak; i++){
            res = max(res, A[peaks[i]]);
        }
        return max(res, A[end]);
    }

    /*
     * split range length l to 2^x + ... + 4 + 2 + 1
     * prepare: space O(nlgn), time O(n^2)
     * operation: time O(lgn)
     * */
    int maxInRange_2(int *A, int n, int begin, int end){
        vector<int> bricks;
        for(int l = 1; l <= n; l *= 2){
            bricks.push_back(l);
        }

        vector<vector<int> > rulersMax = getBrickRangesMax(A, n, bricks);

        int l = end - begin + 1, b = begin;
        int res = 0;
        while(l > 0){
            int brickIdx = biSearchInclu(bricks, l);
            int ruler = bricks[brickIdx];
            res = max(res, rulersMax[b][ruler]);
            l -= ruler;
            b += ruler;
        }

        return res;
    }

private:
    /*
     * used by maxInRange_1(), return all peaks in int[]
     * */
    vector<int> getPeaks(int *A, int n){
        vector<int> peaks;
        for(int i = 1; i < n-1; i++){
            if(A[i-1] < A[i] && A[i] > A[i+1]){
                peaks.push_back(i);
            }
        }
        return peaks;
    }

    /*
     * used by maxInRange_2(), find the next exclusive peak index of idx
     * @return index in peaks
     * */
    int biSearchExclu(const vector<int>& peaks, int idx){
        if(peaks.empty())    return 0;

        int l = 0, r = peaks.size();
        while(l < r){
            int m = (l + r) >> 1;
            if(peaks[m] == idx)    return (m+1);
            if(peaks[m] < idx){
                l = m+1;
            }else{
                r = m;
            }
        }
        // now l == r, can it be l == peaks.size()?
        return peaks[l] > idx ? l : l+1;
    }

    /*
     * @return index in bricks
     * */
    int biSearchInclu(const vector<int>& bricks, int length){
        int l = 0, r = bricks.size();
        while(l < r){
            int m = (l + r) >> 1;
            if(bricks[m] == length)    return m;
            if(bricks[m] < length){
                l = m+1;
            }else{
                r = m;
            }
        }
        // now l == r, can it be l == bricks.size()?
        return bricks[l] < length ? l : l-1;
    }

    /*
     * for beginning at i, return max of range with length 1,2,4,8,16...
     * sub problem is: in array of length n, for range of fixed length l, maximum inside such sliding range
     * */
    vector<vector<int> > getBrickRangesMax(A, n, bricks){
        vector<vector<int> > res;

        return res;
    }
};
