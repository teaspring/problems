/*
 * question on Aug30
 * int a[n], abs(a[i]-a[i-1]) == 1. give x, ask for postion of x in array. time should be better than O(n) 
 * 
 * my solution: extended bi-search in O(lgn)
 * 4,5,6,5,6,7,8,9,10,9
 * m=a[j]-a[i], n=j-i, (n-m) is count of (-1)
 *
 * author's answer: cursor pointer(int* curr) , move forwards in steps of abs(x-*curr). less and more simple code 
 * better than bisearch, its time is O(f(x)), f(x) is the occurance of int x
 *
 * test case:
 * 1 2 3 4 3 2, x=1,2,3
 * 3 2 3 2 3 2 1 2 3 4 3 2, x=3,2
 * */
#include "../header/preliminary.h"

/*
 * my own solution, time O(lgn)
 * u must be in arrage
 * array is up and down, so x is possible to appear in pre half and post half both. a while() can not be used, recursive function is fine
 * hard to maintain
 * */
void bisearchUpDown(int* arr, int v, int u, int x){
    if(v>u || v<0)    return;            //forgetful edge case: v<0; note: v>u is relatgive edge, but v<0 is absolute edge. 
    if(v==u){ 
        if(arr[v] == x){
        printf("appearance at arr[%d]\n", v);
    }
    return;
    }
    int mid = (u+v)/2;
    if(arr[mid] == x){
        printf("appearance at arr[%d]\n", mid);        
    }

    int phalfMinus = ((mid-v) - (arr[mid]-arr[v]))/2;
    int bhalfMinus = ((u-mid) - (arr[u]-arr[mid]))/2;    
    if(x>arr[v] + u-v-(phalfMinus + bhalfMinus) 
       || x < arr[v] - (phalfMinus + bhalfMinus)){            //exclusive adjustment must be done prior to half split
        printf("Sorry, %d not appear in the array\n", x);
        return;
    }
    if(!(phalfMinus == 0 && arr[mid]==x)        //exclude one case which spawn another unnecessary recurse
       && x >= arr[v]-phalfMinus 
       && x <= arr[v]+mid-v-phalfMinus){
        bisearchUpDown(arr, v, mid-1, x);                //as we reduce either v or u to half the range, v<0 is an edge necessary to handle
    }

    if(x >= arr[mid]-bhalfMinus && x <= arr[mid]+u-mid-bhalfMinus){
        bisearchUpDown(arr, mid+1, u, x);
    }
}

inline int myAbs(int x){
    return x>=0 ? x : 0-x;
}

/*
 * best solution. time is O(f(x)), f(x) is occurance of x in array
 * */
void stepsearchUpDown(int* arr, int n, int x){
    int *curr = arr;
    int find = 0;
    while(curr > arr-1 && curr < arr+n){
        if(*curr == x){
            ++find;
            printf("appearance at arr[%d]\n", curr-arr);
            curr += 1;
        }else{
            curr += myAbs(x - *curr);            
        }        
    }
    if(find == 0)
        printf("Sorry, %d not appear in the array\n", x);
    curr = 0;
}

int main(int agrc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)!=0 && str.size() == 0)
            break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        getline(cin,str);
        int x = atoi(str.c_str());
        
        cout<<"bisearch result:"<<endl;
        bisearchUpDown(arr, 0, n-1, x);
        cout<<"stepsearch result:"<<endl;
        stepsearchUpDown(arr, n, x);
        
        delete[] arr;
        arr = 0;
    }
    return 0;
}
