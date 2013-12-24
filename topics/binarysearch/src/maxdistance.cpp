/*
* from leetcode. given an integer array A, find maximum j-i subjected to the constraint of A[i] < A[j]
* the solution is a good exercise of binary search!
* 
* test data:
* 1 4 3 5 2 7 5 4
* 7 6 5 4 3 2 1
* 1 2 3 4 5 6
*/

#include "../header/preliminary.h"

bool distanceExist(int *A, int n, int k, int& begin){   //k=j-i
    for(int i=0;i+k<n;++i){
        if(A[i] < A[i+k]){
            begin = i;
            return true;
        }
    }
    return false;
}

int maxDistance(int *A, int n, int& begin){
    int u=n, v=0, m=0;
    while(v<u){
        m = (u+v)/2;
        if(distanceExist(A, n, m, begin)){
            v = m+1;    //enlarge m
        }else{
            u = m;
        }
    }
    return m;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input integer array:\n");
        if(getline(cin, str)==0 || str.empty())
            break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int b=0;
        int res = maxDistance(arr, n, b);
        printf("the max distanace is %d:", res);
        for(int i=b; i<=b+res;++i){
            printf("%d ", arr[i]);
        }
        printf("\n");

        delete[] arr;
        arr = 0;
    }
    return 0;
}
