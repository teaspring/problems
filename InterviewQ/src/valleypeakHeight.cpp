/*
 * question:
 * in an integer array, find the max of neighbor vallye-peak pair distance
 * 
 * test data:
 * 1 2 3 4 5
 * 5 4 3 2 1
 * 1 0 -1 2 3 4
 * 2 -1 3 4 2 0 -1 5
 * 1 2
 * */

#include "../header/preliminary.h"

inline int absolute(int x){
    return x<0 ? 0-x : x;
}

//time O(n)
int maxValleyPeakHeight(int *arr, int n){
    if(n<2)    return 0;
    int res = 0;
    int *p1 = arr, *p2 = arr+1;
    while(p2 < arr+n){
		int step = *(p1+1) - *p1;
		while(p2 < arr+n && (*p2-*(p2-1)) * step > 0){		//both positive or both negative
			++p2;
		}
		int tmp = absolute(*(p2-1) - *p1);
		if(tmp > res)	res = tmp;
		p1 = p2-1;
    }
    p1 = 0;
    p2 = 0;   
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
		if(getline(cin, str) == 0 || str.empty())
			break;
		int *arr = new int[str.size()]();
		int leng = splitStr2IntArray(str, arr);
		int h = maxValleyPeakHeight(arr, leng);
		printf("the max valley-peak height is %d\n", h);
		delete[] arr;
		arr = 0;
		str.clear();
    }
    return 0;
}
