/*
 * given two sorted integer arrays A and B, merge B into A as one sorted array
 * assume A has enough space with size of m+n at least
 *
 * test case:
 * 3,4,5 | 1, 2
 * 1,2,2,5 | 0,2,3
 * */
#include "../include/preliminary.h"

void swap(int *pa, int *pb){
    int tmp = *pb;
    *pb = *pa;
    *pa = tmp;
}

void sortHead(int A[], int n){
    if(n < 2)    return;
    for(int *p = A+1; p < A+n; ++p){
        if(*(p-1) > *p){
            swap(p-1, p);
        }
    }
    return;
}

/*
 * point of solution is to sort the swapped *q to make it in order with following values 
 * */
void merge(int A[], int m, int B[], int n){
    if(n==0)   return;
    for(int i=0; i<n; ++i){
        A[m+i] = B[i];
    }
    if(m==0)    return;
    int *p = A, *q = A + m;
    while(p < q && q < A+m+n){
        if(*p > *q){
            swap(p, q);
            sortHead(q, A+m+n - q);
            continue;
        }
        ++p;
    }
    return;
}

void test(){
    string str;
    while(1){
        cout << "please input sorted array B[]:" << endl;
        if(getline(cin, str)==0 || str.empty())    break;
        int *B = new int[str.size()]();
        int n = splitStr2IntArray(str, B);
        
        cout << "please input sorted array A[]:" << endl;
        if(getline(cin, str)==0 || str.empty())    break;
        int *A = new int[str.size() + n]();
        int m = splitStr2IntArray(str, A);
        
        merge(A, m, B, n);
        for(int i=0; i<m+n; ++i){
            cout << A[i] << ", ";
        }
        cout << endl;

        delete A;
        A = 0;
        delete B;
        B = 0;
    }
}

int main(){
    test();
    return 0;
}
