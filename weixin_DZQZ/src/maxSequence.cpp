/******************maxSequence.cpp**********************/
/*problem1: 
 * one array of all 0 and 1, calculate the longest sequence which has the same count of 0 and 1
 * test data:
 * 1 1 1 1 0 0 0 0    returns 8
 * 1 1 1 1 0 0 0 1    returns 6
 * 1 1 0 1 0 0 0 0 1
 * */
#include "../header/preliminary.h"
using namespace std;

/*
 * target sequence begin from arr[0]
 * return: length of longest balance sequence
 * */
int longestBalanceSequence(int arr[], int N){
	int sum=0;
	for(int i=0;i<N;i++)
		sum += (arr[i]==0)? (-1) : 1;
	if(sum==0)	return N;
	for(int i=N-1;i>0;i--){
		sum -= (arr[i]==0)? (-1) : 1;
		if(sum == 0)
		  return i;				//return length
	}
	return 0;
}

/*
 * target sequence may begin inside the array
 * qestion: does it achieve O(n)?
 * */
int longestBalanceSequenceExt(int* arr, int N){
	int* subSum = new int[N]();	
	subSum[0] = (arr[0]==0) ? -1 : 1; 
	for(int i=1;i<N;i++){
		subSum[i] = subSum[i-1] + (arr[i]==0? -1 : 1);
	}
	int longest = 0;
	for(int cur=-1;cur<N && (N-cur)>longest;cur++){	//if arr[i]==0, it is balanced serial from head
		int tmp = (cur==-1)? 0 : subSum[cur];
		int j=N-1;
		for(;j>cur && subSum[j] != tmp;j--);
		if(j==cur)	continue;
		if((j-cur) > longest)	longest=(j-cur);		
	}
	return longest;
}

int main(int argc, char* argv[]){
	const int INF = 20;
	string str;
	while(getline(cin, str)){
		if(str.size()==0) break;
		int* arr = new int[INF]();
		int len = splitStr2IntArray(str, arr);
		int res = longestBalanceSequenceExt(arr, len);
		printf("the longest balance sequence length is %d\n", res);		
	}
	return 0;
}
