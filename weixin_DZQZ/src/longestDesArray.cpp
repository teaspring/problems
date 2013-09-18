/*
* my own question inspired by "longest arithmetic array"
* find longest ascending/descending subarray in array
* 
* test case:
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
			if(((asc && arr[i] >= arr[j]) || (!asc && arr[i] <= arr[j]))
				&& plength[i] < plength[j]+1){
				plength[i] = plength[j]+1;
				if(plength[i] > res){			//have found current longest ascending/descending array 
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

int main(int argc, char* argv[]){
    string str;
    while(1){
    if(getline(cin, str) == 0 || str.empty())
        break;
    int *arr = new int[str.size()]();
    int n = splitStr2IntArray(str, arr);
    int e = 0;
    int leng = longestDesArray(arr, n, 1, e);
    printf("the longest ascending sub array is %d, ends at [%d]\n", leng, e);
    leng = longestDesArray(arr, n, 0, e);
    printf("the longest descending sub array is %d, ends at [%d]\n", leng, e);
    delete[] arr;
    arr = 0;   
    }
    return 0;
}

