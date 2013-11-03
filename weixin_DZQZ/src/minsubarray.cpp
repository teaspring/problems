/*
 * question on Sep04
 * give an integer array a[n], one integer S. output the minimum length of subarray which sum greater than S
 * 2nd and 3rd solution are author's answer.
 * test data:
   5 1 3 2 1 4 7 3, s=10,6,4
   2 1 1 1, s=1
   1 1 1 2, s=1
   5 1 3 2, s=10
 * */
#include "../header/preliminary.h"

/*
 * no matter positive/negative
 * time O(n^2), space O(n)
 * */
int minsubarray1(int* arr, int n, int s, int& start){
    int minleng = 0;
    int* arrsum = new int[n]();
    for(int l=1;l<=n;++l){        //l is length of subarray
        for(int i=0;i<=n-l;++i){
            arrsum[i] += arr[l+i-1];       
            if(arrsum[i] > s){
        start = i;
        minleng = l;
        break;
        }          
    }
    if(minleng>0)    break;
    }
    delete[] arrsum;
    arrsum = 0;
    return minleng;
}

/*
 * in case all positive integers
 * time O(nlgn), space O(n)
 * */
int minsubarray2(int *arr, int n, int s, int& start){
    if(arr[0] > s){
        start = 0;
    return 1;
    }
    int minleng = n;
    int *arrsum = new int[n]();
    arrsum[0] = arr[0];
    for(int i=1;i<n;++i)
    arrsum[i] = arrsum[i-1] + arr[i];
    for(int i=0;i<n;++i){
    if(arrsum[i] <= s)
        continue;
    int v=0, u=i;
    while(u<=i && v<u){               //bi-search, O(lgn);edge case v==u-1
        int m = (u+v)/2;
        if(arrsum[i]-arrsum[m] > s){  //for edge case v==u-1, v==m, so v must be m+1 for next iterate
        if(minleng > i-m){
            minleng = i-m;
            start = m+1;
        }       
        v = m+1;                  //this bi-search looks tricky
        }else
        u = m;                    //u never equals to m(u>v), so u set m can be next iterate
    }
    }
    delete[] arrsum;
    arrsum = 0;
    return minleng;
}

/*
* in case all positive integers
* time O(n), space O(1)
*/
int minsubarray3(int *arr, int n, int s, int& start){
    start = 0;
    int minleng = n;
    int i=-1, si=0, j=0, sj=arr[0];    //initialize i,si,j,sj are skilled
    do{
        while(j<n-1 && sj-si <= s){
            ++j;
        sj += arr[j];
        }
        while(i<j && sj-si > s){
        if(minleng > j-i){
            minleng = j-i;
        start = i+1;
        }
        ++i;
        si += arr[i];   
        }
        if(j==n-1)    break;
    }while(j<n);
    return minleng;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
    if(getline(cin, str) == 0 || str.empty())
        break;
    int *arr = new int[str.size()]();
    int n = splitStr2IntArray(str, arr);
    getline(cin, str);
    int s = atoi(str.c_str());
    int b = 0, subleng = 0;
    subleng = minsubarray1(arr, n, s, b);
    printf("minsubarray1(): the min subarray with sum greater than %d begins at [%d] with length of %d\n",
        s, b, subleng);
        
    b = 0;
    subleng = 0;
    subleng = minsubarray2(arr, n, s, b);
    printf("minsubarray2(): the min subarray with sum greater than %d begins at [%d] with length of %d\n",
        s, b, subleng);
        
    b = 0;
    subleng = 0;
    subleng = minsubarray3(arr, n, s, b);
    printf("minsubarray3(): the min subarray with sum greater than %d begins at [%d] with length of %d\n",
        s, b, subleng);

    delete[] arr;
    arr = 0;
    }
    return 0;
}
