/*
 * search in a sorted(asending) array which is rotated somewhere, assume it is ascending order initially
 *
 * test case:
 * 5,1,3, x=4, return -1
 * 5,6,1,2,3,  x=5, return 0
 * */
#include "../include/preliminary.h"

class Solution{
public:

int search(int A[], int n, int key){  // problem I: no duplicate
    int l=0, r=n-1;
    while(l <= r){
        int m = l + (r-l)/2;
        if(key == A[m])    return m;
        if(A[l] < A[m]){  // left half is sorted
            if(A[l] <= key && key < A[m]){
                r = m-1;
            }else{
                l = m+1;
            }
        }else if(A[l] > A[m]){  // right half is sorted
            if(A[m] < key && key <= A[r]){
                l = m+1;
            }else{
                r = m-1;
            }
        }else{  // l == m
            l = m+1;
        }
    }
    return -1;
}

int searchII(int A[], int n, int key){  // probelm II: with duplicates
    int l = 0, r = n-1;
    while(l <= r){
        int m = l + (r-l)/2;
        if(A[m] == key)    return m;
        if(A[l] < A[m]){    // left half is sorted
            if(A[l] <= key && key < A[m]){
                r = m-1;
            }else{
                l = m+1;
            }
        }else if(A[l] > A[m]){  // right half is sorted
            if(A[m] < key && key <= A[r]){
                l = m+1;
            }else{
                r = m-1;
            }
        }else{    // e.g. {1,1,5,1,1,1} with key=5, no sense it is in which side. so the worst case is O(n)
            l++;
        }
    }
    return -1;
}

int findMin(vector<int>& nums){  // find minimum of a rotated sorted array
    int n = nums.size();
    if(n == 0)    return 0;
    if(n == 1)    return nums[0];
    int l = 0, r = n-1;
    while(l < r){
        if(r == l+1)    break;    // include case of m==0
        if(nums[l] < nums[r])    break;  // no rotate at all
        int m = l + (r-l)/2;
        if(nums[m-1] > nums[m])    return nums[m];
        if(nums[l] < nums[m]){ 
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return min(nums[l], nums[r]);
}

int findMinII(vector<int>& nums){  // duplicate exists in array
    int n = nums.size();
    if(n == 0)    return 0;
    if(n == 1)    return nums[0];
    int l = 1, res = nums[0], r = n-1;
    while(l < r){
        if(r == l+1)    break;
        int m = l + (r-l)/2;
        if(nums[m-1] > nums[m])    return min(res, nums[m]);
        if(nums[l] == nums[m]){
            res = min(min(nums[m], nums[r]), res);
            l++;
        }else if(nums[r] == nums[m]){
            res = min(min(nums[l], nums[m]), res);
            r--;
        }else if(nums[l] == nums[r]){
            res = min(nums[m], res);
            l++;
            r--;
        }else if(nums[l] < nums[m]){
            res = min(res, nums[l]);
            l = m+1;
        }else{
            res = min(res, nums[m]);
            r = m;
        }
    }
    return min(res, min(nums[l], nums[r]));
}

};

void test_01(){
    string str;
    printf("please input sorted ascending array which is rotated in some where\n");
    if(getline(cin, str)==0 || str.empty())    return;
    int *arr = new int[str.size()]();
    int n = splitStr2IntArray(str, arr);
    Solution s;
    while(1){    
        printf("please input target to search:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int target = atoi(str.c_str());
        printf("index of target is %d\n", s.search(arr, n, target));
    }
    delete[] arr;
    return;
}

void test_02(){
    Solution s;
    while(1){
        string str;
        printf("please input rotated integer array\n");
        if(getline(cin, str) == 0 || str.empty())    break;
        int arr[str.size()];
        int n = splitStr2IntArray(str, arr);
        vector<int> vec;
        for(int i=0; i<n; i++)    vec.push_back(arr[i]);
        printf("%d\n", s.findMinII(vec));
    }
    return;
}

int main(int, char**){
    test_02();
    return 0;
}
