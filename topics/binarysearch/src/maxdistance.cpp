/*
* from leetcode. given an integer array A, find maximum j-i subjected to the constraint of A[i] < A[j]
* solution 1: binary search with linear scan
* solution 2: twice linear scan, key is the Rmax[]
* 
* test data:
* 1 4 3 5 2 7 5 4
* 6 5 4 3 2 1
* 1 2 3 4 5 6
*/

#include "../header/preliminary.h"

/*
 * in time O(nlgn)
 * */
bool distanceExist(int *A, int n, int k, int& begin){   //k=j-i
    for(int i=0;i+k<n;++i){
        if(A[i] < A[i+k]){
            begin = i;
            return true;
        }
    }
    return false;
}

int maxDistance_01(int *A, int n, int& begin){
    int u=n, v=0, m=0;
    while(v<u){
        m = (u+v)/2;
        if(distanceExist(A, n, m, begin)){
            v = m+1;  //enlarge m
        }else{  //reduce m to try smaller m
            u = m;
        }
    }
    return m;
}

/*
 * achieve linear search, in time O(n) and space O(n)
 * */
int maxDistance_02(int *A, int n, int& left){
    if(n<2)    return 0;
    int *Rmax = new int[n]();
    Rmax[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--){
        Rmax[i] = max(A[i], Rmax[i+1]);
    } 
 
    int l=0, r=0, maxDiff=-1;
    while(l<n && r<n){ 
        if(A[l] < Rmax[r]){
            if(r-l > maxDiff){
                maxDiff = r-l;
                left = l;
            }
            ++r;
        }else{
            ++l;
            ++r;    //resume to scan from the potential distance remaining r-l
        }
    }
    delete[] Rmax;
    return maxDiff;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input integer array:\n");
        if(getline(cin, str)==0 || str.empty())
            break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int begin = 0;
        int res = maxDistance_02(arr, n, begin);
        if(res<1){
            printf("no result\n");
        }else{
            printf("the max distanace is %d from A[%d]=%d to A[%d]=%d\n", 
                    res, begin, arr[begin], begin+res, arr[begin+res]);
        }
        delete[] arr;
        arr = 0;
    }
    return 0;
}
