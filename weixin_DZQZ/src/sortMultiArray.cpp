/* 
 * question on Jul 21
 * input is an array of int{1,2,3} where each integer appears varied times. sort the array in time O(n)
 * 
 * test data:
 * 1 2 3,
 * 1 3 2,
 * 3 2 1,
 * 3 1 2,
 * 2 1 3,
 * 2 3 1
 * */
#include "../header/preliminary.h"

template<typename T>
void myswap(T* left, T* right){
    T tmp = *right;        //copy pointer
    *right = *left;
    *left = tmp;
    tmp = 0;
}

void sortTriArray(int *arr, int N){
    int *p1=arr, *p2=0, *p3=arr+N-1;
    while(p3 > p1){
        while(p3 >= arr && (*p3)==3)
            --p3;
        if(p3 < arr)    break;
        while(p1<arr+N && (*p1)==1)
            ++p1;
        if(p1 == arr+N)    break;
        p2 = p1;        //p2 must begin with p1 because if(*p1==3) it needs to swap with p3
        while(p2 < arr+N && (*p2)==2)
            ++p2;
        if(p2 > p3)    break;   // if p2==p3, that must a '1'
        if((*p2)==3){
            myswap<int>(p2, p3);
        }else{            // *p2 is a '1'
            myswap<int>(p2, p1);
        }
    }
    return;
}

/*
 * mapping 1->2, 2->3, 3->5, all three are prime
 * */
void sortOutputPrimeTriArray(int* arr, int N){
    long multi = 1;
    for(int i=0;i<N;i++){
        if(arr[i] == 1)
            multi *= 2;
        else if(arr[i] == 2)
            multi *= 3;
        else if(arr[i] == 3)
            multi *= 5;
    }
    
    while(multi%2 == 0){
        cout<<1<<" ";
        multi /= 2;
    }
    while(multi%3 == 0){
        cout<<2<<" ";
        multi /= 3;
    }
    while(multi%5 == 0){
        cout<<3<<" ";
        multi /= 5;
    }
    cout<<endl;
}

/*
 * once round of quick sort
 * move all elements equal to pivot to head of array
 * */
int myQuickSort(int* arr, int N, int pivot){    //arr has element of ==pivot and >pivot
    if(N<1)    return 0;
    int *left=arr-1, *cur=arr;
    while(cur<arr+N){
        if(*cur>pivot){
            cur++;
            continue;
        }
        left++;
        myswap(left, cur);
        cur++;
    }
    return left-arr+1;
}

/*
 * idea of quick sort, apply multi rounds of quick sort
 * */
void sortQuartArray(int* arr, int N){    //array of element of {1,2,3,4}
    int *src = arr;
    for(int i=1;i<4;i++){        //elements of {1,2,3,4}, sort by 1,2,3 seperately
        int leng = myQuickSort(src, N, i);
        src = src+leng;
        N = N-leng;
    }
}

void outputArray(int* arr, int N){
    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void test_01(){
    string str;
    while(1){
        printf("please input integer array made up of 1, 2 and 3\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str,arr);
        //outputArray(arr, n);
        //sortQuartArray(arr, n);
        sortTriArray(arr, n);
        outputArray(arr, n);
        
        delete[] arr;
        arr = 0;
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
