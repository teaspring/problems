/*
 * "IntroductionToAlgorithm" chapter8    
 * countsort: not in place, 
 * assumption: input elements land in a range [0,k)
 * time O(n), space O(n)
 *
 * point: since it is stable sort in O(n), it can be used by radix sort
 * test data:
 * 0,2,3,2,1,5,3,4
 */
#include "../header/preliminary.h"

int* countsort(int* A, int n){    
    int k = 1;                        //Arr[] is [0,k)
    for(int i=0;i<n;i++){
        if(A[i] > k)
          k = A[i];
    }
    k++;      
    int* C = new int[k]();
    for(int i=0;i<n;i++)
      C[A[i]] += 1;
    for(int i=1;i<k;i++)
      C[i] += C[i-1];
    int* B = new int[n]();
    for(int i=n-1;i>-1;i--){    //key of descending iteration: stable!
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    delete[] C;
    C = 0;
    return B;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int N = splitStr2IntArray(str, arr);
        int* res = countsort(arr, N);
        for(int i=0;i<N;i++)
          printf("%d ", res[i]);
        printf("\n");
        delete[] res;
        res = 0;
    }
    return 0;
}
