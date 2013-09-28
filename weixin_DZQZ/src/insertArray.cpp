/*
 * question on Aug03
* input  [a1,a2,a3...an,b1,b2,b3...bn]
* output [a1,b1,a2,b2,...an,bn]
*
* test data:
* 1,2,3,4,5,6,7,8		(n/2 is even)
* 1,2,3,4,5,6,7,8,9,10  (n/2 is odd)
**/
#include "../header/preliminary.h"

template<typename T>
void myswap(T* left, T* right){
  T tmp = *right;
  *right = *left;
  *left = tmp;
  tmp = 0;
}

void swaparray(int* pA, int* pB, int N){
  for(int i=0;i<N;i++)
    myswap<int>(pA+i, pB+i);
}

/*
 * inspired by binary-swap,  time O(n*lgn), recurse
 * */
void insertarray(int* src, int length){
  if(length<4 || length%2 == 1){
	  return;
  }
  int half = length/2;
  int quart = half/2;
  if(half%2 == 1){
	  swaparray(src+quart, src+half, quart+1);
	  insertarray(src,half-1);
	  insertarray(src+half+1, half-1);
	  myswap(src+half-1, src+half);
  }
  else{
	  swaparray(src+quart, src+half, quart);
	  insertarray(src, half);
	  insertarray(src+half, half);
  }
}

void outputarray(int* src, int N){
  for(int i=0;i<N;i++)
    cout<<*(src+i)<<" ";
  cout<<endl;
}

int main(int i, char* argv[]){
  string str;
  while(1){
	  if(getline(cin, str) == 0 || str.empty())
		break;
	  int* arr = new int[str.size()]();
	  int leng = splitStr2IntArray(str, arr);
	  if(leng<4 || leng%2 == 1){
		  printf("invalid input array\n");
	  }else{
		  insertarray(arr, leng);
		  outputarray(arr, leng);
	  }
	  
	  delete[] arr;
	  arr = 0;
  }
  return 0;
}
