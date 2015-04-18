/*
 * search in a sorted(ascending) array which is rotated somewhere, assume it is ascending order initially
 *
 * key of binary search:
 * rotated sorted array is splited to two sorted arrangs by initial head item. now we have [l], [r], [m],
 * so wherever [m] is, inside left half and right half, one of them must be exactly sorted
 *
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     * problem I: search key in a rotated sorted array which has no duplicate
     * */
    int search(int A[], int n, int key){
        int l = 0, r = n-1; // r is inclusive right boundary
        while(l <= r){
            int m = l + (r - l)/2;

            if(key == A[m])    return m;

            if(A[l] < A[m]){  // left half is sorted
                if(A[l] <= key && key < A[m]){  // key in [l, m)
                    r = m-1;
                }else{  // key in (m, r]
                    l = m+1;
                }
            }else if(A[l] > A[m]){  // right half is sorted
                if(A[m] < key && key <= A[r]){   // key in (m, r]
                    l = m+1;
                }else{  // key in [l, m)
                    r = m-1;
                }
            }else{ // A[l] == A[m]! since dupicate is not allowed, l == m is only possible reason
                l = m+1; // ?
            }
        }
        return -1;
    }

    /*
     * problem II: search key in a rotated sorted array in which duplicate is allowed
     * */
    int searchII(int A[], int n, int key){
        int l = 0, r = n-1; // r is inclusive right boundary
        while(l <= r){
            int m = l + (r-l)/2;

            if(A[m] == key)    return m;

            if(A[l] < A[m]){ // left half is sorted
                if(A[l] <= key && key < A[m]){  // key in [l, m)
                    r = m-1;
                }else{ // key in (m, r]
                    l = m+1;
                }
            }else if(A[l] > A[m]){  // right half is sorted
                if(A[m] < key && key <= A[r]){  // key in (m, r]
                    l = m+1;
                }else{ // key in [l, m)
                    r = m-1;
                }
            }else{  // e.g.{1,1,5,1,1,1} with key=5, no idea where it is. so the time is O(n) in the worst
                l++;
            }
        }
        return -1;
    }

    /*
     * problem I: find minimum in a rotated sorted array which has no duplicate
     * */
    int findMin(vector<int>& nums){
        if(nums.empty())    return 0;

        const int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r){
            int m = l + (r-l)/2;
            if((m == 0 || nums[m-1] > nums[m])
            &&(m == n-1 || nums[m] < nums[m+1])){
                return nums[m];  // exit criteria
            }

            if(nums[l] < nums[m]){ // left half is sorted
                if(nums[l] > nums[r]){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }else if(nums[l] > nums[m]){  // right half is sorted while left half is not
                r = m-1;
            }else{  // l == m
                l = m+1;
            }
        }
        return 0;
    }

    /*
     * problem II: find minimum in a rotated sorted array in which duplicate is allowed
     * */
    int findMinII(vector<int>& nums){  // duplicate exists in array
        if(nums.empty())    return 0;

        const int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r){
            int m = l + (r-l)/2;

            if(m != 0 && m != n-1
            && nums[m-1] == nums[m]
            && nums[m] == nums[m+1]){  // [m-1] == [m] == [m+1]
                if(nums[l] > nums[r]){
                    l++;
                }else{
                    r--;
                }
                continue;
            }

            if((m == 0 || nums[m-1] > nums[m])
                &&(m == n-1 || nums[m+1] >= nums[m])){
                return nums[m];  // exit case, note the '>=' for right side
            }

            if(nums[l] < nums[m]){  // left half is sorted
                if(nums[l] >= nums[r]){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }else if(nums[l] > nums[m]){  // right half is sorted while left is not
                r = m-1;
            }else{  // nums[l] == nums[m]
                if(l < m){
                    l++;
                }else{
                    return min(nums[l], nums[r]);
                }
            }
        }
        return 0;
    }
};

/* unit test is in ../cpp_unittest/rotatedSortedArray_unittest */
