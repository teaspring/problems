/*
 * problem: input are array1 as source, and array2 as target; you have a intermedia stack;
 * transform operation is: push is to push first element of array1 to stack; pop is to pop element of stack to tail of array2
 * if unable to do such transform, output "None"
 *
 * example 1:
 * input: src: [1,2,3,4], dst: [1,2,3,4]
 * output: push1|pop1|push2|pop2|push3|pop3|push4|pop4
 *
 * exmaple 2:
 * input: src: [1,2,3,4], dst: [4,3,2,1]
 * output: push1|push2|push3|push4|pop4|pop3|pop2|pop1
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

class arrStkOperation{
public:
    arrStkOperation(int *arr1, int m): M(m), idx1(0), idx2(0){
        origi = new int[M]();
        path  = new int[2*M](); 
        for(int i=0;i<M;i++){
            origi[i] = arr1[i];
        }
    }
    virtual ~arrStkOperation(){
        delete[] origi;
        origi = NULL;
        delete[] path;
        path  = NULL;
    }
    void route(int *result);
private:
    void push();
    void pop();
    bool check(int*);
    void outputPath(int*);
  
    int M;         // size of origi[]
    int *origi;    // origi[M]
    stack<int> myStk;
    int idx1, idx2;
    int *path;        //path[2*M], 1 for push, -1 for pop
};

void arrStkOperation::push(){
    if(idx1>M-1)    return;
    myStk.push(origi[idx1]);
    path[idx1+idx2] = 1;    //1 for push
    idx1++;
    return;
}

void arrStkOperation::pop(){
    if(idx2>M-1) return;
    myStk.pop();
    path[idx1+idx2] = -1;    //-1 for pop
    idx2++;
    return;
}

bool arrStkOperation::check(int *result){
    return myStk.empty() ? false : myStk.top() == result[idx2];
}

void arrStkOperation::route(int *result){
    push();
    while(idx2 < M){
        if(check(result)){
            pop();
        }else if(idx1<M){
            push();
        }else{
            break;
        }
    }
    if(idx1==M){
        if(idx2 < M){
            printf("None\n");
        }else{
            outputPath(result);
        }
    }
}

void arrStkOperation::outputPath(int *result){
    int j=0,k=0;
    for(int i=0; i < 2*M-1; ++i){
        switch(path[i]){
        case 1:
            printf("push%d|",origi[j]);
            ++j;
            break;
        case -1:
        default:
            printf("pop%d|", result[k]);
            ++k;
            break;
        }
    }
    if(path[2*M-1] == 1){
        printf("push%d\n", origi[M-1]);
    }else{
        printf("pop%d\n", result[M-1]);
    }
    return;
}

void test_01(){
    int arr1[] = {1,2,3,4};
    int arr2[] = {4,3,2,1};
    arrStkOperation* pStkOper = new arrStkOperation(arr1, 4);
    pStkOper->route(arr2);
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
