/*
 * given a sorted array and a target value, return index if it is found. if not, return the index where it would be inserted in order
 * assume array is in ascending order without duplicates.
 * */
#include "../header/preliminary.h"

int searchInsert(int A[], int n, int x){
    int v=0, u=n, m;
    while(v<u){
        m = (v+u)>>1;
        if(A[m]==x){
            return m;
        }else if(A[m] > x){
            if(m==0 || A[m-1] < x){
                return m;
            }else{
                u=m;
            }
        }else{
            if(m == n-1 || A[m+1] >= x){
                return m+1;
            }else{
                v=m+1;
            }
        }
    }
    return v;
}

void test_01(){
    string str;
    while(1){
        printf("please input sorted integer array:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);

        printf("please input target value to seach:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int target = atoi(str.c_str());
        printf("position to insert: %d\n", searchInsert(arr, n, target));
        delete[] arr;
    }
}

int main(int, char**){
    test_01();
    return 0;
}

