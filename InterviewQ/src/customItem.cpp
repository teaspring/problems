/********************customItem.cpp**************************/
/*
* Custom Item problem, digraph
* input: {customA, item1, customA, item2, customB, item1, customA, item3...}, item1; output: item2
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
    if (arr[i] == 0)   
        arr[i] = c;
    return i;            // now arr[i]==c
}

void mergeArray(int src[MaxI], int plus[MaxI]){
    for(int i=0; i<MaxI; i++)
        src[i] += plus[i];
    return;
}

int findAnotherMostItem(char orders[MaxOrder], int itemNo ){
    char custs[MaxC];
    int items[MaxI];   
    int adjMtx[MaxC][MaxI];            //|Custom|*|Item|
    memset(custs, 0, sizeof(char)*MaxC);
    memset(items, 0, sizeof(int)*MaxI);
    memset(adjMtx, 0, sizeof(int) * MaxC * MaxI);

    int cIdx = 0;
    int iIdx = 0;
    for(int i=0; i<(MaxOrder/2);i++){        //scan order list and initialize cust[], item[] and adjMtx[][]
        if(orders[2*i] == 0) break;
        cIdx = addArray<char>(custs, orders[2*i]);    //[2i] is char, [2i+1] is int
        iIdx = addArray<int>(items, atoi(&orders[2*i+1]));
        adjMtx[cIdx][iIdx]++;
    }
    cIdx = 0;
    iIdx = addArray<int>(items, itemNo);    //item to find
    int mergeItem[MaxI];
    memset(mergeItem, 0, sizeof(int) * MaxI);
    for(int i=0; i<MaxC; i++){
        if(adjMtx[i][iIdx] > 0)
            mergeArray(mergeItem, adjMtx[i]);
    }
    mergeItem[iIdx] =0;        //skip itemNo
    int maxI = 0;
    for(int i=0; i<MaxI; i++){
        if(mergeItem[maxI] < mergeItem[i])
            maxI = i;
    }
    return items[maxI];   
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
