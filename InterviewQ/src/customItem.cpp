/********************customItem.cpp**************************/
/*
* Custom Item problem. find what else item bought mostly by the customers who buys item1
* input: {customA, item1, customA, item2, customB, item1, customA, item3...}, item1; output: item2
* 
* pesudo input: {A,1,A,2,B,1,A,2,B,2,A,3,C,1,D,2...}
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

const int MaxC = 10;    //custom count
const int MaxI = 10;    //item count
const int MaxOrder = 30;

template<typename T>
int addArray(T arr[MaxOrder], T c){    //add and find
    int i=0;
    for(; arr[i]!=0 && arr[i]!=c && i<MaxOrder;i++);
    if(i==MaxOrder)        return 0;
    if (arr[i] == 0){
        arr[i] = c;
    }
    return i;            // now arr[i]==c
}

void mergeArray(int* src, int* plus, int n){        //n is item count
    for(int i=0; i<n; i++){
        src[i] += plus[i];
    }
    return;
}

int findAnotherMostItem(char orders[MaxOrder], int itemNo){        //orders size is MaxOrder
    char *custs = new char[MaxC];
    memset(custs, 0, sizeof(char)*MaxC);
    int *items = new int[MaxI]();   
    int **adjMtx= new int*[MaxC];            //|Custom|*|Item|
    for(int i=0;i<MaxI;i++){
        adjMtx[i] = new int[MaxI]();
    }
    int *mergeItem = new int[MaxI]();

    int cIdx = 0;
    int iIdx = 0;
    for(int i=0; i<(MaxOrder/2);i++){        //scan order list and initialize cust[], item[] and adjMtx[][]
        if(orders[2*i] == 0)    break;
        cIdx = addArray<char>(custs, orders[2*i]);    //[2i] is char, [2i+1] is int
        iIdx = addArray<int>(items, atoi(&orders[2*i+1]));
        adjMtx[cIdx][iIdx]++;
    }
    cIdx = 0;
    iIdx = addArray<int>(items, itemNo);    //item to find
    for(int i=0; i<MaxC; i++){
        if(adjMtx[i][iIdx] > 0){
            mergeArray(mergeItem, adjMtx[i]);
        }
    }
    mergeItem[iIdx] =0;        //skip itemNo
    int maxI = 0;
    for(int i=0; i<MaxI; i++){                //this scan can be merged to above iteration of merging item arrays of customers
        if(mergeItem[maxI] < mergeItem[i]){
            maxI = i;
        }
    }
    int res = items[maxI];
    
    delete[] custs;
    custs=0;
    delete[] items;
    items=0;
    for(int i=0;i<MaxC;i++){
        delete[] adjMtx[i];
        adjMtx[i] = 0;
    }
    delete[] adjMtx;
    adjMtx=0;
    delete[] mergeItem;
    mergeItem=0;

    return res;   
}

int main(int argc, char* argv[]){
    char arr[MaxOrder]={
        'A','1','A','2','B','1','B','3','A','3',
        'C','1','C','2','B','4','C','4','D','1',
        'D','4','D','5','E','2','E','4','E','5'};
    int res = findAnotherMostItem(arr, 1);
    printf("%d",res);
    return 0;
}
