/*
 * question on Aug11 
 * given n length, among the 3 which can construct a triangle, find the longest triangle perimeter
 * how to judge a triangle, three edges a>b, a>c, then b+c>a
 * */

#include "../header/preliminary.h"

void myswap(int& a, int& b){
    if(a == b)    return;
    int tmp = b;
    b = a;
    a = tmp;
}

void quickSort(int* arr, int N){    //sort in descending
    if(N<2)    return;
    int *p = arr-1, *q = arr;
    int s = arr[N-1];
    for(;q<arr+N-1;q++){
        if(*q > s){
            ++p;
            myswap(*p, *q);
        }
    }
    ++p;
    myswap(*p, *q);
    quickSort(arr, N-(q-p)-1);
    quickSort(p+1, q-p);    
}

// time O(nlgn), space O(1)
int longestTriPerimeter(int* arr, int N, int& a, int& b, int& c){
    if(N<3)    return 0;
    quickSort(arr, N);
    for(int i=0;i<N;i++)
      printf("%d ", arr[i]);
    printf("\n");
    for(int i=0;i<N-2;i++){
        if(arr[i] < (arr[i+1] + arr[i+2])){
            a = arr[i];
            b = arr[i+1];
            c = arr[i+2];
            return a+b+c;
        }
    }
    return 0;
}

int main(int argc, char* argv[]){
    string str;
    while(1){        
        if(getline(cin, str) == 0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int leng = splitStr2IntArray(str, arr);    
        int a=0,b=0,c=0;
        int res = longestTriPerimeter(arr, leng, a,b,c);
        printf("longest perimeter is %d, edges are %d,%d,%d\n", res, a,b,c);
        
        delete[] arr;
        arr = 0;
    }
    return 0;
}
