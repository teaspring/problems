/*
 * given an array of n, integers 0,1,2 for color red, white, and blue. sort it in order 0/1/2 in one-pass with space O(1)
 * 
 * */
#include "../include/preliminary.h"

void swap(int *pa, int *pb){
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
    return;
}

void sortColors_01(int A[], int n){
    if(n<=1)    return;
    int *p = A-1, *q = A, *t = A+n;
    while(q != t){
        if(*q == 2){        // check 2 firstly
            t--;
            swap(q, t);
            continue;        // NOTE: value swapped from [t] is at right of q which has not been checked yet
        }else if(*q == 0){
            p++;
            if(q > p)    swap(q, p);
        }
        q++;
    }
    return;
}

void sortColors_02(int A[], int n){
    if(n<=1)    return;
    int *p = A-1, *q = A, *t = A+n;
    while(q != t){
        if(*q == 0){        // check 0 firstly
            p++;
            if(q > p)    swap(q, p);
        }else if(*q == 2){
            t--;
            swap(q, t);
            continue;      //NOTE: recheck of the swapped value from *t is necessary
        }
        q++;
    }
    return;
}

void test(){
    string str;
    while(1){
        cout << "please input initial integer array of 0,1,2" << endl;
        if(getline(cin, str)==0 || str.empty())    break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        sortColors_02(arr, n);
        for(int i=0; i<n; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        delete arr;
        arr = 0;
    }
    return;
}

int main(){
    test();
    return 0;
}
