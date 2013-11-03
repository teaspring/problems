/*
 * question on Sep 02
 * an int array has positive and negative integers. put negative at head and postive at tail.internal sequence order between positive and negative remains.
 * 
 * my solution: convert array by plus multiplies(index) of m, once quick sort to move negative ahead, then sort positive in quick sort
 * space O(1), time O(nlgn); sort positive part in time of O(nlgn)
 * 
 * author answer: 
 *
 * test data:
 * input: 1,-2,2,-3,3,-1,4,-4,5,-6,-7
 * output:-1,-2,-3,-4,-6,1,2,3,5
 * */
#include "../header/preliminary.h"

void convertArray(int *arr, int n, int m, int tick){    //tick==1 for plus multiple m, 0 for mode m 
    if(tick){
    for(int i=0;i<n;++i){
        if(arr[i]>0)    arr[i] += i*m;
        else        arr[i] -= i*m;
    }
    }else{
    for(int i=0;i<n;++i)
        arr[i] %= m;
    }
}

template<typename T>
void mySwap(T *pa, T *pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp = 0;
}

inline int cmpResidual(int x, int y, int m){
    if(m==0)    return 0;                //invalid input
    return x/m > y/m ? 1 : 0;
}
void myQuickSort(int *arr, int n, int m){    //sort in O(nlgn), compare by value mode m
    if(n<2)    return;
    int *p = arr-1, *q = arr;
    int t = *(arr + n-1);
    while(q < arr+n-1){
    if(cmpResidual(t,*q,m)){        //t/m > (*q)/m
        ++p;
        mySwap<int>(p, q);
    }
    ++q;
    }
    ++p;
    mySwap<int>(p,q);
    
    myQuickSort(arr, p-arr, m);
    myQuickSort(p+1, arr+n-1-p, m);
}

void convertDivert(int *arr, int n){
    int mode =0, negN = 0;
    for(int i=0;i<n;++i){
        if(arr[i] < 0){
            negN += 1;
            if(mode < 0-arr[i])
            mode = 0-arr[i];
    }else{
        if(mode < arr[i])
        mode = arr[i];
    }          
    }
    mode += 1;                    //mode must be more than the greatest absolute value
    int posN = n - negN;
    convertArray(arr, n, mode, 1);        //convert by plus multiple mode
    int *p=arr-1, *q=arr;
    while(q<arr+n){
        if(*q<0){                //swap negetive to head
        ++p;
        mySwap<int>(p, q);
    }
    ++q;
    }
    p = 0;
    q = 0;
    myQuickSort(arr+negN, posN, mode);        //sort in time O(nlgn)
    convertArray(arr, n, mode, 0);

    for(int i=0;i<n;++i){            //out
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//simplest solution, time O(n), space O(n)
void simpleDivert(int *arr, int n){
    int *dst = new int[n]();
    int ind = 0;
    for(int i=0;i<n;++i){
    if(arr[i]<0){
        dst[ind] = arr[i];
        ++ind;
    }
    }
    for(int i=0;i<n;++i){
        if(arr[i]>0){
        dst[ind] = arr[i];
        ++ind;
    }
    }

    for(int i=0;i<n;++i){                //out
    printf("%d ", dst[i]);
    }
    printf("\n");
    delete[] dst;
    dst = 0;
} 

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())
        break;
    int *arr = new int[str.size()]();
    int n = splitStr2IntArray(str, arr);
    convertDivert(arr, n);
    //simpleDivert(arr, n);
    delete[] arr;
    arr = 0;
    str.clear();
    }
    return 0;
}
