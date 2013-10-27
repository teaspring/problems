/*
 * "introduction to algorithm" chapter6, heap sort
 * 
 * note: 
 *
 * 1. index of heap in process must begin with 1, otherwise [0] cannot support valid Left or Right
 * 2. heap sort: time O(nlgn), can be in place sort
 * */
#include "../header/preliminary.h"

const int MINUSLIMIT = -0xff;

template<typename T>
void myswap(T* pa, T* pb){
	if(pa == pb)	return;
	T tmp = *pb;
	*pb = *pa;
	*pa = tmp;
	tmp = 0;
}

inline int Left(int i){
	return 2*i;
}

inline int Right(int i){
	return 2*i + 1;
}

inline int Parent(int i){
	return i/2;
}

// time O(lgn)
void max_heapify(int* A, int n, int i){				//enable i is max of the subtree which root is i
	if(n==1)	return;
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	if(l <= n && A[l] > A[i]){
		largest = l;
	}
	if(r <= n && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		myswap(A+largest, A+i);
		max_heapify(A, n, largest);
	}
}

//time O(n)
void build_max_heap(int* A, int n){				//ensure A[1...n] are elements in scope
	for(int i=n/2;i>0;i--){
		max_heapify(A, n, i);
	}
}

//time O(nlgn)
void heap_sort_desc(int* A, int n){		//output in descending order, or return ascending array in place 
	build_max_heap(A, n);
	int hsize = n;
	for(int i=n;i>0;i--){
		myswap<int>(A+i, A+1);
		//printf("%d ", A[i]);
		hsize--;
		max_heapify(A, hsize, 1);
	}
	//printf("\n");
}

/*
 * priority_queue implemented in max-heap
 * */
int heap_extract_max(int* A, int n){		//following max heap, A[1...n]
	if(n<1)	return -1;
	int max = A[1];
	A[1] = A[n];
	A[n] = MINUSLIMIT;								//my added statement
	max_heapify(A, n-1, 1);
	return max;
}

void heap_increase_key(int* A, int n, int i, int key){		//increase A[i] to k
	if(i > n)	return;
	if(key < A[i])	return;
	A[i] = key;
	while(i > 1 && A[Parent(i)] < A[i]){					//A[1] is root without parent
		myswap<int>(A+Parent(i), A+i);
		i = Parent(i);
	}
}

void max_heap_insert(int* A, int n, int key){				//build a priority queue(max heap) via insert
	A[n+1] = MINUSLIMIT;
	heap_increase_key(A, n+1, n+1, key);
}

/*
 * Young tableau!!!
 * */

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str) == 0 || str.empty())
		  break;
		int* arr = new int[str.size()]();
		int N = splitStr2IntArray(str, arr);
		
		int* brr = new int[N+1]();				//enable A[1...n]
		for(int i=1;i<N+1;i++){
			brr[i] = arr[i-1];
		}
		delete[] arr;
		arr = 0;

		heap_sort_desc(brr, N);		
		for(int i=1;i<=N;i++)
		  printf("%d ", brr[i]);
		printf("\n");
		delete[] brr;
		arr = 0;		
	}
	return 0;
}
