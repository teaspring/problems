/*
 * question on Sep07
 * all elements in an integer array appears in 3 times except one number appear just once.find the single number
 *
 * for this kind of question, the idea is bitset operation mostly
 *
 * test data:
 * 1 2 1 1 2 3 3 2 5 3
 * */
#include "../header/preliminary.h"

int findSingleNum01(int* arr, int n){		// use an integer array of size 32
	int x=0;
	for(int i=0;i<32;++i){					//time O(32n) = O(n)
		int count = 0;
		int offset = 1<<i;
		for(int j=0;j<n;++j){
			count += (arr[j] & offset) >>i;
		}
		if(count % 3 == 1)
		  x |= 1<<i;
	}
	return x;
}

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str) == 0 || str.empty())
		  break;
		int *arr = new int[str.size()]();
		int leng = splitStr2IntArray(str, arr);
		int x = findSingleNum01(arr, leng);
		printf("the single number is %d\n", x);
		delete[] arr;
		arr = 0;
	}
	return 0;
}
