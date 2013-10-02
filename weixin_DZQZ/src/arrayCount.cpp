/*
* question on Aug28
* int[n], optional values are 1-n, some appears multiple times and some never. calculate every value appearance count
* time O(n), space O(1) which means in-place search 
* author answer1: use residual after divided by n
* author answer2: use multiples of n
* my own answer: use negative
* 
* test data:
* 1 2 4 2 2 2 3 4 3 1
* 1 1 1 1 1 2
* 1 1 1 1 1 1 
*/
#include "../header/preliminary.h"

/*
 * my own solution: use negative to be occurance count
 * time O(n), space O(1)
 * a little hard to read
 * */
void negativeCount(int* arr, const int& n){		
    for(int i=0;i<n;++i){
        if(arr[i] <= 0)    continue;			//set arr[i] negative to be occurance count
        int j = arr[i];
        while(j <= n && arr[j-1] > 0){                           
            if(arr[j-1] != j){                           
                arr[i] = arr[j-1];
                arr[j-1] = -1;        //skill:timing to update arr[j-1]
                j = arr[i];               
            }else{
                arr[j-1] = -1;
            }
        }
        if(j > n)    continue;        //invalid value
        if(arr[j-1] <= 0){
            arr[i] = 0;
            arr[j-1] -= 1;
        }       
    }
    
    for(int i=0;i<n;++i){			  //output
        printf("negativeCount(): integer {%d} appears %d times\n", 
                i+1,				//be careful
                0-arr[i]);
    }
}

/*
 * designed to use residual to mode n+1 as occurance count. 
 * note:optional answers are 0-n, but mode n is 0 - (n-1). so the mode must be n+1 at least 
 * */
void residualCount(int *arr, const int& n){
    for(int i=0;i<n;++i)
        arr[i] *= (n+1);
    for(int i=0;i<n;++i){
        arr[arr[i]/(n+1) - 1] += 1;
    }
    for(int i=0;i<n;++i){			  //output
        printf("residualCount(): integer {%d} appears %d times\n", 
		i+1,			
		arr[i] % (n+1));
    }
}

/*
 * designed to use quatient by n to be occurance count
 * simplest, and the best
 * */
void multipleCount(int *arr, const int& n){
    for(int i=0;i<n;i++){
    	arr[arr[i]%(n+1) - 1] += (n+1);
    }
    for(int i=0;i<n;++i){			  //output
        printf("multipleCount(): integer {%d} appears %d times\n", 
                i+1,
		arr[i]/(n+1));
    }
}

int main(int argc, char* argv[]){
    string str;
    while(1){
    	if(getline(cin, str) == 0 || str.empty())
    	    break;
	int* arr = new int[str.size()](); 
	int n = splitStr2IntArray(str, arr);
	int *arr1 = new int[n]();
	int *arr2 = new int[n]();
	for(int i=0;i<n;++i){
	    arr1[i] = arr[i];
	    arr2[i] = arr[i];
	}
	
	negativeCount(arr, n);
	residualCount(arr1, n);
	multipleCount(arr2, n);
	
	delete[] arr;
	arr = 0;
	delete[] arr1;
	arr1 = 0;
	delete[] arr2;
	arr2 = 0;
	str.clear();
    }
    return 0;
}
