/*
 * radix sort: in place, time O(n), space O(n)
 * assumption: elements are integer, which digit not differ too much
 * 
 * MSD: maximum significant digit
 * LSD: least significant digit
 *
 * test data:
 * 329, 457, 657, 839, 436, 720, 355, 41
 * */
#include "../header/preliminary.h"

/*
 * radix sort start from LSD to MSD
 * it uses count sort for once sort on digit because 
 * 1.time O(n) 
 * 2.stable sort
 */
void radixonce(int* A, int n, int* key){        //sort on one digit can use linear sort like count
    int* C = new int[10]();
    for(int i=0;i<n;i++)
      C[key[i]] += 1;
    for(int i=1;i<10;i++)
      C[i] += C[i-1];
    int* B = new int[n]();
    for(int i=n-1;i>-1;i--){                    //key of the descending iteration: stable
        B[C[key[i]]-1] = A[i];
        C[key[i]]--;
    }
    for(int i=0;i<n;i++)
      A[i] = B[i];
    delete[] C;
    C = 0;
    delete[] B;
    B = 0;
    return;
}

void radixsort(int* A, int n){
    int digits = 1;
    int* key = new int[n]();        
    while(1){
        int r = 0;
        for(int i=0;i<n;i++){
            key[i] = (A[i]/digits)%10;
            if(key[i] > r)
              r = key[i];
        }
        if(r==0)    break;        //all A[i] can not divided by digits
        radixonce(A, n, key);
        digits *= 10;
        memset(key, 0, sizeof(int)*n);
    }
    delete[] key;
    key = 0;
    return;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int N = splitStr2IntArray(str, arr);
        radixsort(arr, N);
        for(int i=0;i<N;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        delete[] arr;
        arr = 0;
    }
    return 0;
}
