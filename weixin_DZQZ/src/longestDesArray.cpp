/*
* my own question inspired by "longest arithmetic progression"
* find length of longest ascending/descending subarray
* 
* test data:
* 1 2 -1 3 0 4 1 5
* 1 2 1 2 0 2 2 2 -1 -2
*/
#include "../header/preliminary.h"

/*
* time O(n^2), space O(n)
*/
int longestDesArray(int *arr, int n, int asc, int& end){
    if(n<2)    return n;
    int res=1;
    int *plength = new int[n]();
    for(int i=0;i<n;++i)
      plength[i] = 1;
    for(int i=1;i<n;++i){
        int j = i-1;
        while(j>=0){
            if(((asc && arr[i] >= arr[j]) || (!asc && arr[i] <= arr[j]))    // equation belongs to ascending/descending
                && plength[i] < plength[j]+1){ // just compare plength[i-1] and plength[i]
                plength[i] = plength[j]+1;  // bring in excessive update of plength[i]
                if(plength[i] > res){
                    res = plength[i];
                    end = i;
                    break;
                }
            }
            --j;
        }
    }
    delete[] plength;
    plength = 0;
    return res;
}

int longestAscArray(int *arr, int n){
    int f[n]; // f[i] is length of longest ascending array in arr[0...i]
    int end[n]; // end[i] is end index of longest ascending array in arr[0...i]
    f[0] = 1;
    end[0] = 0;
    for(int i=1; i<n; i++){
        f[i] = f[i-1];
        end[i] = end[i-1];
        if(arr[end[i-1]] < arr[i]){
            f[i]++;
            end[i] = i;
            continue;
        }
        for(int j=i-1; j>=0; --j){
            if(j+1 < f[i])    break; // further preceding array has no means
            if(f[j] < f[i] || arr[end[j]] >= arr[i])    continue;
            f[i] = f[j] + 1;
            end[i] = i;
        }
    }
    return f[n-1];
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())  break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        int e = 0, leng = 0;
        leng = longestDesArray(arr, n, 1, e);
        printf("version1: the longest ascending array is %d, ends at [%d]\n", leng, e);
        leng = longestAscArray(arr, n);
        printf("version2: the longest ascending sub array is %d\n", leng);
        /*
        leng = longestDesArray(arr, n, 0, e);
        printf("the longest descending sub array is %d, ends at [%d]\n", leng, e);
        */
        delete[] arr;
        arr = 0;   
    }
    return 0;
}

