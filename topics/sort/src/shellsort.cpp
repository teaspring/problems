/*
 * insertion sort. <IntroductionToAlgorithm chapter2>, in-place, stable
 * shell sort, one progression sort based on insertion sort.in-place, not stable
 * generally it is thought to be better than direct insert sort, around time O(n(lgn)^2)
 *
 * different implementation differs in choose of group step only
 * */
#include "../header/preliminary.h"

void myswap(int& a, int& b){
	int tmp = a;
	a = b;
	b= tmp;
}

/*basic insertion sort. avoid swap*/
int insertionsort(int* A, int n){
	int op = 0;
	for(int i=1;i<n;i++){
		int temp = A[i];
		int j=i-1;
		for(;j>=0 && A[j]>temp;j--){
			A[j+1] = A[j];
			op++;
		}
		A[j+1] = temp;
		op++;
	}
	return op;
}

//D.Shell initial version
int shellsort_Sh(int *p, int n){
	int op = 0;
	for(int h=n/2;h>0;h /= 2){			//different group step
		for(int i=h;i<n;i++){
			int temp = p[i];
			int j = 0;
		 	for(j=i-h;j>=0 && p[j]>temp;j-=h){ //insert temp(p[i], search in reverse order
				p[j+h] = p[j];
				op++;
			}
			p[j+h] = temp;
			op++;
		}
	}
	return op;
}

//Lazarus-Frank, 1960'
int shellsort_LF(int *p, int n){
	int op = 0;
	for(int h=n/2;h>0;h /= 2){			//different group step
		if(h%2 == 0)	h--;
		for(int i=h;i<n;i++){
			int temp = p[i];
			int j = 0;
			for(j=i-h;j>=0 && p[j]>temp;j-=h){
				p[j+h] = p[j];
				op++;
			}
			p[j+h] = temp;
			op++;
		}
	}
	return op;
}

//Hibband, 1963
int shellsort_Hb(int *p, int n){
	int op = 0;
	int h;
	for(h=1;h<=n/4;h=h*2+1);
	for(;h>0;h=(h-1)/2){
		/* 1,3,7,15,31,...2^i-1*/
		for(int i=h;i<n;i++){
			int temp = p[i];
			int j = 0;
			for(j=i-h;j>=0 && p[j]>temp;j-=h){
				p[j+h] = p[j];
				op++;
			}
			p[j+h] = temp;
			op++;
		}
	}
	return op;
}

/*Papernov-Stasevich, 1965. this is nearly reach the performance of Knuth's*/
int shellsort_PS(int *p, int n){
	int op = 0;
	int h;
	for(h=2;h<=n/4;h=h*2-1);
	for(;h>1;){			//different group step
		h = (h==3) ? 1 : (h+1)/2;
		/* h=1,3,5,9,17,33...2^i+1 */
		for(int i=h;i<n;i++){
			int temp = p[i];
			int j = 0;
			for(j=i-h;j>=0 && p[j]>temp;j-=h){
				p[j+h] = p[j];
				op++;
			}
			p[j+h] = temp;
			op++;
		}
	}
	return op;
}

/* Knuth, suggest in case n<1000. till now, this is nearly the best */
int shellsort_Kn(int *p, int n){
	int op = 0;
	int h;
	for(h=1;h<=n/9;h=h*3+1);
	for(;h>0;h=h/3){			//different group step
		/* h = 1,4,13,40,121,364...3^h+1*/
		for(int i=h;i<n;i++){
			int temp = p[i];
			int j = 0;
			for(j=i-h;j>=0 && p[j]>temp;j-=h){
				p[j+h] = p[j];
				op++;
			}
			p[j+h] = temp;
			op++;
		}
	}
	return op;
}

/* Gonnet, 1991*/
int shellsort_Go(int *p, int n){
	int op = 0;
	int h;
	for(h=n;h>1;){			//different group step
		h=(h<5)? 1 : (h*5-1)/11;
		for(int i=h;i<n;i++){
			int temp = p[i];
			int j = 0;
			for(j=i-h;j>=0 && p[j]>temp;j-=h){
				p[j+h] = p[j];
				op++;
			}
			p[j+h] = temp;
			op++;
		}
	}
	return op;
}

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str)==0 || str.empty())
		  break;
		int* arr = new int[str.size()]();
		int n = splitStr2IntArray(str, arr);		
		int* A = new int[n]();

		copyarray(A, arr, n);
		int op = shellsort_Sh(A, n);
		printf("Shell: %d\n", op);
		showarray(A, n);

		copyarray(A, arr, n);
		op = shellsort_Hb(A, n);
		printf("Hibbard: %d\n", op);
		showarray(A, n);

		copyarray(A, arr, n);
		op = shellsort_LF(A, n);
		printf("LF: %d\n", op);
		showarray(A, n);

		copyarray(A, arr, n);
		op = shellsort_PS(A, n);
		printf("PS: %d\n", op);
		showarray(A, n);

		copyarray(A, arr, n);
		op = shellsort_Kn(A, n);
		printf("Knuth: %d\n", op);
		showarray(A, n);

		copyarray(A, arr, n);
		op = shellsort_Go(A, n);
		printf("Gonnet: %d\n", op);
		showarray(A, n);
		
		copyarray(A, arr, n);
		op = insertionsort(A, n);
		printf("insertion sort: %d\n", op);
		showarray(A, n);
		
		copyarray(A, arr, n);
		op = selectionsort(A, n);
		printf("selection sort: %d\n", op);
		showarray(A, n);
		
		delete[] A;
		A = 0;
		delete[] arr;
		arr = 0;
	}
	return 0;
}
