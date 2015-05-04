/*
 * implement next permutation, which rearranges numbers into lexicographically next greater permutation of numbers.
 * if such arrangement is not possible, it must be in accending order. the replacement is in-place
 * e.g 
 * 1,2,3 -> 1,3,2
 * 3,2,1 -> 1,2,3
 * 1,1,5 -> 1,5,1
 * 
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     *
     * */
    void nextPermutation(vector<int> &num){
        const int n = num.size();

        int i = n-2;
        for(; i >= 0 && num[i] >= num[i+1]; --i);

        if(i < 0){ // in case num is like "321"
            reverse(num);
            return;
        }

        int j = n-1, x = num[i];
        for(; j >= i+1 && num[j] <= x; --j);  // j == i+1 at least

        swap(num[i], num[j]);
        quicksort(num, i+1, n-1);
    }

    /*
     * another similar question which solution is based nextPermutation().
     * note: in case k >> n!
     * but it is TIME LIMIT ERROR on oj.leetcode
     * */
    string getPermutation(int n, int k){    // k is 1-based
        vector<int> nums;

        for(int i = 1; i <= n; ++i){
            nums.push_back(i);
        }

        for(int i = 2; i <= k; ++i){
            nextPermutation(nums);
        }

        char cstr[n+1];
        memset(cstr, 0, sizeof(cstr));
        cstr[n] = '\0';

        for(int i = 0; i < n; ++i){
            cstr[i] = '0' + nums[i];
        }

        return string(cstr);
    }

private:
    void swap(int& a, int & b){
        int tmp = b;
        b = a;
        a = tmp;
    }

    void reverse(vector<int>& num){
        const int n = num.size();
        for(int i = 0;i < (n>>1); ++i){
            swap(num[i], num[n-1-i]);
        }
    }

    void quicksort(vector<int>& vec, int b, int e){  //sort sub list [b,e]
        if(b >= e)    return;

        int p = b-1, q = b;

        while(q < e){
            if(vec[q] < vec[e]){
                ++p;
                swap(vec[p], vec[q]);
            }
            ++q;
        }

        ++p;
        swap(vec[p], vec[e]);

        quicksort(vec, b, p-1);
        quicksort(vec, p+1, e);
    }
};

/* unit test is in ../cpp_unittest/nextPermutation_unittest */
