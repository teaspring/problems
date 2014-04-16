/*
 * <Beauty Of Programming>
 * 2.16, given an array unsorted, negative/0/non-negative. caculate the longest ascending array sum
 *
 * test case:
 * 1 -1 2 -3 4 -5 6 -7
 * 1 2 -4 -3 -2 -1 0
 * */
#include "../header/preliminary.h"
#include <algorithm>

/*
 * time O(n^2), space O(n)
 * */
int LIS01(int* arr, int n){
    int res = 1;
    int* LIS = new int[n]();
    for(int i=0;i<n;++i)
      LIS[i] = 1;
    for(int i=1;i<n;++i){
        for(int j=i-1;j>=0;--j){
            if(arr[i] > arr[j]){
                LIS[i] = max(LIS[i], LIS[j] + 1);
                res = max(res, LIS[i]);
            }
        }
    }
    delete[] LIS;
    LIS = 0;
    return res;
}

/*
 * it uses MaxV[] instead of LIS[] is a good idea
 * time O(n^2), space O(n). but the time complexity is potential to be reduced to O(nlgn)
 * */
int LIS02(int* arr, int n){
    int res = 1;
    int *MaxV = new int[n]();            //MaxV[i] is for all the increasing sequence of length i, the least max value
    MaxV[1] = arr[0];
    /*int *LIS = new int[n]();            //LIS[i] means for array ends at arr[i], the longest increasing sequence length
    for(int i=0;i<n;++i)
      LIS[i] = 1;
      */
    for(int i=0;i<n;++i){
        int j= res;
        for(;j>0;--j){            //inner loop is to find the first MaxV[j] which less than arr[i]; but, MaxV[n] is increasing, bisearch can be used here to reduce the time from O(n^2) to O(nlgn)
            if(arr[i] > MaxV[j]){
                //LIS[i] = j+1;
                res = max(res, j+1);
                break;
            }
        }
        if(MaxV[j+1] == 0 || MaxV[j+1] > arr[i])
          MaxV[j+1] = arr[i];
    }
    delete[] MaxV;
    MaxV = 0;
    //delete[] LIS;
    //LIS = 0;
    return res;
}

void test_01(){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())        break;
        int* arr = new int[str.size()]();
        int leng = splitStr2IntArray(str, arr);
        int res = 1;
        res = LIS02(arr, leng);
        printf("LIS02(): the LIS is %d\n", res);
        res = LIS01(arr, leng);
        printf("LIS01(): the LIS is %d\n", res);
        delete[] arr;
        arr = 0;
        str.clear();
    }
    return;
}

int main(int argc, char *argv[]){
    test_01();
    return 0;
}
