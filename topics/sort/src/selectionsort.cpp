/*
 * bubble sort, inefficient sort algorithm
 * selection sort, a bit better 
 * */
#include "../header/preliminary.h"

void myswap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * bubble method, time O(n^2), with excessive use of swap in each internal iteration
 */
int bubblesort(int* A, int n){
    int op = 0;
    for(int i=0; i<n-1; i++){        
        for(int j=n-1; j>i; j--){
            if(A[j-1] > A[j]){
                myswap(A[j-1], A[j]);
                op += 2;
            }
            op++;
        }
        op++;
    }
    return op;
}

/*
 * improvement is to reduce swap() to once in each internal iteration. 
 * its average efficiency is a little worse than insertionsort
 * */
int selectionsort(int* A, int n){
    int op = 0;
    for (int i=0; i<n-1; i++){
        int sel = i;
        for(int j=n-1; j>i; j--){
            if(A[j] < A[sel]){        
                sel=j;
                op++;
            }
            op++;
        } 
        if(sel != i){
            myswap(A[i], A[sel]);
            op += 2;
        }
        op++;
    }
    return op;
}

/*
 * basic insertion sort. in internal iteration, stops till finding its correct postion. 
 * */
int insertionsort(int* A, int n){
    int op = 0;
    for(int i=1;i<n;i++){
        int temp = A[i];
        int j=i-1;
        for(;j>=0 && A[j]>temp;j--){
            A[j+1] = A[j];
            op++;
        }
        A[j+1] = temp;
        op++;
    }
    return op;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int* A = new int[n]();

        copyarray(A, arr, n);
        int op = bubblesort(A, n);
        printf("bubblesort: %d\n", op);
        showarray(A, n);
        
        copyarray(A, arr, n);
        op = selectionsort(A, n);
        printf("selectionsort: %d\n", op);
        showarray(A, n);

        copyarray(A, arr, n);
        op = insertionsort(A, n);
        printf("insertionsort: %d\n", op);
        showarray(A, n);

        delete[] A;
        A=0;
        delete[] arr;
        arr=0;
    }
    return 0;
}
