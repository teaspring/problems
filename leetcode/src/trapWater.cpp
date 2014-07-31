/*
 * given a non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * */
#include "../header/preliminary.h"

/*
 * one-pass solution: scan leftward and rightward at the same time, start from lower of the two.  
 * */
int trap(int A[], int n){
    if(n <= 2)    return 0;
    int l=0, r=n-1, sum=0;
    while(l < r){
        bool leftMove = A[l] < A[r];
        int w = 0;
        if(leftMove){
            int h = A[l++];
            while(h > A[l]){
                w += h - A[l];
                ++l;
            }
        }else{
            int h = A[r--];
            while(h > A[r]){
                w += h - A[r];
                --r;
            }
        }
        sum += w;
    }
    return sum;
}

int main(){
    string str;
    while(1){
        cout << "please input non-negative integer array as wall:" << endl;
        if(getline(cin, str)==0 || str.empty())    break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        printf("trapped water is %d\n", trap(arr, n));
        delete[] arr;
    }
    return 0;
}

