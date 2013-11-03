/*
 * merge sort, "IntroductionToAlgorithm chapter2"
 * divide-and-conquer
 * 
 * */

#include "../header/preliminary.h"
const int MAXIM = 0xffff;

void merge(int* A, int p, int q, int r){    //use one sentinel at tail to avoid checking which new subarray is empty. simplify!
    int n1 = q-p+1;
    int n2 = r-q;
    
    int* AL = new int[n1+1]();
    for(int i=p;i<=q;i++){
        AL[i-p] = A[i];
    }
    AL[q-p+1] = MAXIM;

    int* AR = new int[n2+1]();
    for(int i=q+1;i<=r;i++){
        AR[i-q-1] = A[i];
    }
    AR[r-q] = MAXIM;

    int i=0, j=0;
    for(int k=p;k<=r;k++){
        if(AL[i]<=AR[j]){
            A[k] = AL[i];
            i++;
        }else{
            A[k] = AR[j];
            j++;
        }
    }
    delete[] AL;
    AL=0;
    delete[] AR;
    AR=0;
}

void mergesort(int* A, int p, int r){                // p,r are inclusive
    if(p < r){
        int q = (p+r)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        mergesort(arr, 0, n-1);
        showarray(arr, n);
        delete[] arr;
        arr = 0;
    }
    return 0;
}
