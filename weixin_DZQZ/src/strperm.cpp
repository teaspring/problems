/*
 * problem on Sep29
 * given string A, and string B, ask if the permutation of B's char is substring of A
 * 
 * test data:
 * A: abefg, B: ba, output: true
 * */
#include "../header/preliminary.h"

template<typename T>
void myswap(T* pa, T* pb){
	T tmp = *pb;
	*pb = *pa;
	*pa = tmp;
	tmp = 0;
}

template<typename T>
void quicksort(T* arr, int n){		//sort in ascending
	if(n<1)	return;
	T *p=arr-1, *q=arr;
	T s = *(arr+n-1);
	while(q<arr+n-1){
		if(*q < s){
			++p;
			myswap<T>(p, q);
		}
		++q;
	}
	++p;
	myswap<T>(p, q);
	quicksort<T>(arr, p-arr);
	quicksort<T>(p+1, n-1-(p-arr));
}

template<typename T>
void output(T* arr, int count){
	for(int i=0;i<count;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

/*
 * permutation, e.g. 1 2 3 4
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * 1 3 4 2
 * 1 4 2 3
 * 1 4 3 2 
 * 2 1 3 4 ...
 * */
template<typename T>
void perm(T* src, int count){
	quicksort<T>(src, count);				//ensure src is asending
	output<T>(src, count);
	while(1){
		int j = count-1;
		for(;j>0 && src[j]<=src[j-1];j--);
		if(j==0)	break;
		int t = count-1;
		while(t > j){
			if(src[t] > src[j-1])
			  break;
			t--;
		}
		myswap<T>(src+t, src+j-1);
		quicksort<T>(src+j, count-j);		//here needs sort the src[j:count] instead of just iteration
		output<T>(src, count);
	}
}

/*
 * get permutation of cstrB, search if it exists in cstrA
 * */
bool substrmatch(char* cstrA, char* cstrB){
	int count = strlen(cstrB);
	quicksort<char>(cstrB, count);
	if(strstr(cstrA, cstrB) != NULL)
	  return true;
	while(1){								//get permutation of cstrB, check if it exists in cstrA
		int j = count-1;
		for(;j>0 && cstrB[j]<=cstrB[j-1];j--);
		if(j==0)	break;
		int t = count-1;
		while(t > j){
			if(cstrB[t] > cstrB[j-1])
			  break;
			t--;
		}
		myswap<char>(cstrB+t, cstrB+j-1);
		quicksort<char>(cstrB+j, count-j);		//here needs sort the src[j:count] instead of just iteration
		if(strstr(cstrA, cstrB) != NULL)
		  return true;
	}
	return false;
}

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str)==0 || str.empty())
		  break;		
		char* arrA = new char[str.size()];
		strcpy(arrA, str.c_str());
		
		if(getline(cin, str)==0 || str.empty())
		  break;
		char* arrB = new char[str.size()];
		strcpy(arrB, str.c_str());
		
		bool res = substrmatch(arrA, arrB);
		printf("result is %s\n", res ? "true" : "false");
		delete[] arrA;
		arrA = 0;
		delete[] arrB;
		arrB = 0;
	}
	return 0;
}

