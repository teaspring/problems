/* 
 *question on Aug18: 
 *we want to cut one long wood into N parts,length of which L1,L2...Ln. the payment of one cut is the total length. 
 *ask the least payment when the total wood is cut to L1,L2...Ln 
 *test data:
 *N=8, if we cut 8 into 5 + 3, the payment is 8
 * */
#include "../header/preliminary.h"

template<typename T>
void myswap(T *pa, T *pb){		//type of swapped object is T. swap(T*, T*), wrap once
	T tmp = *pb;
	*pb = *pa;
	*pa = tmp;
	tmp = 0;
}

void quickSort(int* arr, int N){	//sort in descending
	if(N<2)	return;
	int *p = arr-1, *q = arr;
	for(;q<arr+N-1;q++){
		if(*q > arr[N-1]){
			++p;
			myswap<int>(p, q);
		}
	}
	++p;
	myswap<int>(p, q);
	quickSort(arr, N-(q-p+1));
	quickSort(p+1, q-p);	
}

/*
 * solution:
 * 12 9 6 5 3 2 1,     //cut 1, combine 1 and 2
 * 12 9 6 5 3 3,	   //cut 3, combine 3 and 3
 * 12 9 6 6 5,		   //cut 5, combine 5 and 6
 * 12 11 9 6,		   //cut 6, combine 6 and 9
 * 15 12 11,		   //cut 11, combine 12 and 11
 * 33 15,			   //cut 15 
 * 
 * time O(n^2), space O(1)
 * change to use priority queue can reduce to time O(nlogn)+ space O(n)
 * */
int getLeastCutPay(int* arr, int N, int *resArr){
	quickSort(arr, N);			//sorted to be decending
	int* src = new int[N]();
	for(int i=0;i<N;i++)		//initialize own array
	  src[i] = arr[i];
	int sum=0;
	int *p=src+N-1, *q = src+N-1; 
	for(int i=N-1;i>1;i--){
		int tmp = src[i] + src[i-1];	//updated [i-1]
		src[i]=0;
		p = src+i-2;			
		while(p>=src && tmp > *p)
		  --p;
		++p;				//position where src[i-1] to insert
		q = src+i-1;
		while(q != p){
		  *(q) = *(q-1);	//assign backward
		  --q;
		}
		*q = tmp;
		sum += tmp;
		*(resArr+i-1) = tmp;
	}
	sum += (src[0] + src[1]);
	*resArr = src[0] + src[1];
	p=0;
	q=0;
	delete[] src;
	src = 0;
	return sum;
}

int main(int argc, char* argv[]){
	string str;
	while(getline(cin, str)!=0){
		if(str.size()==0)	break;
		int *arr = new int[str.size()]();
		int leng = splitStr2IntArray(str, arr);
		int *pay = new int[leng-1]();
		int res = getLeastCutPay(arr, leng, pay);
		printf("the least wood cut payment is %d, which is ", res);
		for(int i=0;i<leng-1;i++)			//output
		  printf("%d ", pay[i]);
		printf("\n");
		delete[] arr;
		arr=0;
	}
		
	return 0;
}
