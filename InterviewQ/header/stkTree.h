/**********stkTree.h**************/
#include "stdio.h"
#include "string.h"

/*
 * abandoned
 * 1.understanding incorrectly
 * 2.exam requires a function instead of class
 * */
const int N = 4;
struct stkArray{
    int stkSize;
	int headIdx;
    int stk[N];
    stkArray(int a[], int size=0):stkSize(size), headIdx(0){
        for(int i=0; i<N; i++)
            stk[i] = a[i];
    }
	int top(){
		return stk[headIdx];
	}
	void pop(){
		headIdx++;
		stkSize--;
	}
	void push(int idx){
		if(headIdx==0) return;
		headIdx--;
		stkSize++;
		if(idx != headIdx){
			int tmp = stk[headIdx];
			stk[headIdx] = stk[idx];
			stk[idx] = tmp;
		}
	}
	bool equalTo(stkArray* rhd){
		if(this->stkSize != rhd->stkSize)
		  return false;
		int i=0;
		for(;i<stkSize && this->stk[i+headIdx]==rhd->stk[i+headIdx];i++);
		return i == stkSize;
	}
};

/*
 * bandoned. exam requires a function instead of class
*problem: input are array1 as source, and array2 as target; you have a intermedia stack;
*transform operation is: push is to push first element of array1 to stack; pop is to pop element of stack to tail of array2
example 1:
input: 1,2,3,4
       1,2,3,4
output: push1|pop1|push2|pop2|push3|pop3|push4|pop4
exmaple 2:
input: 1,2,3,4
       4,3,2,1
output: push1|push2|push3|push4|pop4|pop3|pop2|pop1
if unable to do such transform, output "None"
*/
const int M=4;
class arrStkOperation{
    int origi[M];
    stack<int> myStk;
    int idx1, idx2;
    int path[2*M];        //1 for push, -1 for pop
public:
    arrStkOperation(int arr1[M]){
        memset(path, 0, sizeof(int)*2*M);
        for(int i=0;i<M;i++){
            origi[i] = arr1[i];
        }
        idx1 = idx2 = 0;
    }
    ~arrStkOperation();
    void route(int result[M]);
private:
    void push();
    void pop();
    bool check(int[M]);
    void outputPath(int[M]);
};

