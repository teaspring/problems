/*
 * quesiton on Aug06
 * given an integer array arr[], find the greatest arr[j]-arr[i], while j>i
 * */
#include "../header/preliminary.h"
using namespace std;

/*
 * time O(n), space(1).
 * if to find all optiional pairs of greatest arr[j]-arr[i], space O(n)
 * */
int findMostMinus(int* arr, int N, int& b, int& e){
	if(N<2)	return 0;
	b = 0;
	int res = arr[1]-arr[0];
	e = 1;
	int least = arr[0];
	for(int i=2;i<N;i++){
		if(least > arr[i-1]){		//update the least element beneath [i]
		  least = arr[i-1];
		  b = i-1;
		}
		int tmp = arr[i] - least;
		if(tmp>=res){
		  res = tmp;
		  e = i;
		}
	}
	return res;
}

int main(int argc, char* argv[]){
	string str;
	int* arr = new int[100]();
	while(getline(cin, str)){
		if(str.size() == 0)	break;
		int leng = splitStr2IntArray(str, arr);
		int i=0,j=0;
		int res = findMostMinus(arr, leng, i, j);
		printf("the most minus is %d, from [%d] to [%d]\n", res, i, j);
	}
	return 0;
}


