/*
* integer array A[n], B[n] are sorted in ascending both, find the median of all integers in time O(lgn)
* 
* note: 
* 1.case of m==n is in <IntroductionToAlgorithm> chapter9 median and order statistics, exercise 9.3-8
* 2.case of m!= n is an interview problem
* 
* test data:
* for m==n
* {1,3,5,8,9,10}, {2,4,6,9,10,11}
* {1,2,3,4,5,6}, {8,9,10,11,12,13}
* {8,9,10,11,12,13}, {1,2,3,4,5,6}
* 
* for m != n
* {1,3,5,8,9}, {2,4,6,7,10,11,12}
* {1,1,1,1}, {2,4,5,5,5,5}
* {7,8,9,10}, {1,2,3,4,5}
*/

#include "../header/preliminary.h"

inline int max(int a, int b){
    return a>b ? a : b;
}

bool findmediansingle(int* A,int m, int* B,int n,int& res,int tag){  // find total median in array A
    int u=m, v=0, k=0;
    int mid = (m+n)/2;
    while(v<u){               //[v,u)
        k = (v+u)/2;
        int j=(mid-1-k);      //index in B[]
        if(j<-1){
            u=k;              //reduce k to enlarge j
        }else if(j==-1){      //edge case for m-n==1 !!!
            break;
        }else if(j>n-1){        //enlarge k to reduce j
            v=k+1;            
        }else if(B[j] <= A[k]){              //depends on B[j+1] ?
            if(j==n-1 || B[j+1] >= A[k]){    //edge: either j==n-1 or A[k] between {B[j], B[j+1]}
                break;
            }else{            //B[j+1] < A[k], reduce k to enlarge j
                u=k;
            }
        }else{                //enlarge k to reduce j
            v = k+1;
        }
    }
    if(v<u){
        if(!tag){
            int prev = B[n-1-k];
            if(k>0 && A[k-1] > prev){
                prev = A[k-1];
            }
            res = (A[k] + prev)/2;
        }else{
          res = A[k];
        }
        return true;
    }else{
        return false;
    }
}

int findmedian(int* A, int m, int* B, int n){
    int res = 0;
    int tag=0;
    if((m+n)%2 == 1)
      tag=1;            //A'[mid] is median
    if(!findmediansingle(A,m,B,n,res,tag)){
        findmediansingle(B,n,A,m,res,tag);
    }
    return res;
}

/*
 * for two arrays with same size
 * */
bool findmediansingle(int* A, int* B, int n, int& res){  // find total median in array A
    int u=n, v=0, k=0;
    while(v<u){        //[v,u)
        k = (v+u)/2;
        int j=(n-1-k);
        if(j<0){
            u=k;
        }else if(B[j] <= A[k]){              //not sufficient !
            if(j==n-1 || B[j+1] >= A[k]){    //edge: either j==n-1 or A[m] between {B[j], B[j+1]}
                break;
            }else{                                //B[j+1] < A[k], reduce k to enlarge j
                u=k;
            }
        }else{                                //enlarge k to reduce j
            v = k+1;
        }
    }
    if(v<u){
        int prev = B[n-1-k];
        if(k>0 && A[k-1] > prev){
            prev = A[k-1];
        }
        res = (A[k] + prev)/2;
        return true;
    }else{
        return false;
    }
}

/*
 * for two arrays with same size
 * */
int findmedian(int* A, int* B, int n){
    int res = 0;
    if(!findmediansingle(A, B, n, res)){
        findmediansingle(B, A, n, res);
    }
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty()){
            break;
        }
        int* arr1 = new int[str.size()]();
        int m = splitStr2IntArray(str, arr1);
    
        str.clear();
        if(getline(cin, str)==0 || str.empty()){
            break;
        }
        int* arr2 = new int[str.size()]();
        int n = splitStr2IntArray(str, arr2);
        if(m==n){
            int r = findmedian(arr1, arr2, n);
            printf("the median of all the integers is %d\n", r);
        }else{
            int r = findmedian(arr1,m,arr2,n);
            printf("the median of all the integers is %d\n", r);        
        }
        delete[] arr1;
        arr1 = 0;
        delete[] arr2;
        arr2 = 0;    
    }
    return 0;
}
