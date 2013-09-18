/* 
 * question on Jul 21
 * input is an array of int{1,2,3} where each integer appears varied times. sort the array in time O(n)
 * 
 * test data:
 * 1 1 1 3
 * 2 1 2 1 3 1
 * 3 3 2 2 1 1
 * 3 3 3 3
 * 2 2 2 2
 * 1 1 1 1
 * 3 1 1 1 2
 * */
#include "../header/preliminary.h"

template<typename T>
void myswap(T* left, T* right){
	T tmp = *right;		//copy pointer
	*right = *left;
	*left = tmp;
	tmp = 0;
}

void sortTriArray(int* arr, int N){
	int *p1=arr, *p2=0, *p3=arr+N-1;
	while(p3 > p2){
		while(p1<arr+N && (*p1)==1)
		  p1++;
		while(p3>=arr && (*p3)==3)
		  p3--;
		p2 = p1;
		while(p2<arr+N && (*p2)==2)
		  p2++;
		if(p3<p2)	break;
		if((*p2)==3)
		  myswap<int>(p2, p3);
		else
		  myswap<int>(p2, p1);
	}
}

void sortOutputPrimeTriArray(int* arr, int N){
	//mapping 1->2, 2->3, 3->5
	long multi = 1;
	for(int i=0;i<N;i++){
		if(arr[i] == 1)
		  multi *= 2;
		else if(arr[i] == 2)
		  multi *= 3;
		else if(arr[i] == 3)
		  multi *= 5;
	}
	
	while(multi%2 == 0){
	  cout<<1<<" ";
	  multi /= 2;
	}
	while(multi%3 == 0){
	  cout<<2<<" ";
	  multi /= 3;
	}
	while(multi%5 == 0){
	  cout<<3<<" ";
	  multi /= 5;
	}
	cout<<endl;
}

/*
 * once round of quick sort
 * move all elements equal to pivot to beginning of array
 * return length of pivot
 * */
int myQuickSort(int* arr, int N, int pivot){	//arr has element of ==pivot and >pivot
	if(N<1) return 0;
	int *left=arr-1, *cur=arr;
	while(cur<arr+N){
		if(*cur>pivot){
			cur++;
			continue;
		}
		left++;
		myswap(left, cur);
		cur++;									//potential bug!
	}
	return left-arr+1;
}

/*
 * idea of quick sort, apply multi rounds of quick sort
 * */
void sortQuartArray(int* arr, int N){	//array of {1,2,3,4}
	int *src = arr;
	for(int i=1;i<4;i++){				//elements of {1,2,3,4}, sort by 1,2,3 seperately
		int leng = myQuickSort(src, N, i);
		src = src+leng;
		N = N-leng;
	}
}

void outputArray(int* arr, int N){
	for(int i=0;i<N;i++)
	  cout<<arr[i]<<" ";
	cout<<endl;
}

int main(int argc, char* argv[]){
	string str;
	while(getline(cin, str)){
		if(str.size()==0)	break;
		int INF = 0x00ff;
		int* array = new int[INF]();
		int length = splitStr2IntArray(str,array);
		outputArray(array, length);
		sortQuartArray(array, length);
		outputArray(array, length);
	}
}

