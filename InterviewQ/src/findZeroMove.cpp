/*
 * problem: we have matrix[5][5], values are unsorted 0-24. special is 0, it can swap with its upper,lower,left,right num which is named as U/D/L/R 
 * input: source mat[5][5] and result mat[5][5]. output: the movement sequence in correct order; if not, output "None"
 * 
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MaxN = 5;

void sort(char *arr, int n){
    for(int k=0;k<n-1;k++){
        for(int s=k+1;s<n;s++){        //bug ever!!!
            if(arr[k] > arr[s]){
                char tmp = arr[k];
                arr[k] = arr[s];
                arr[s] = tmp;
            }
        }
    }
    return;
}

void findZeroMove(int src[5][5], int dst[5][5], char* seq, const int length){
    int i=0,j=0;    //in src
    int p=0,q=0;    //in dst
    char orders[MaxN*4];        //use the constant int
    memset(orders, 0, sizeof(char)*MaxN * 4);
   
    for(;i<5 && j<5;){            //find 0 in src[i][j]
        if(src[i][j] == 0)    break;
        j++;
        if(j==5){
            j=0;
            i++;
        }           
    }
    for(;p<5 && q<5;){            //find 0 in dst[p][q]
        if(dst[p][q] == 0)    break;
        q++;
        if(q==5){
            q=0;
            p++;
        }           
    }

    int step = 0;
    while(dst[i][j] != 0){
        if(i<4 && dst[i][j] == src[i+1][j]){
            orders[step++] = 'D';
            i++;
        }else if(i>0 && dst[i][j] == src[i-1][j]){        //bug ever!!!
            orders[step++] = 'U';
            i--;
        }else if(j<4 && dst[i][j] == src[i][j+1]){
            orders[step++] = 'R';
            j++;
        }else if(j>0 && dst[i][j] == src[i][j-1]){
            orders[step++] = 'L';
            j--;
        }
        else break;
    }

    if(dst[i][j] != 0){
        printf("Unable to move to the dst[][]\n");
        return;
    }
    sort(seq, length);            //sort it

    char sortedOrder[MaxN*4];        //copy orders[] to sortedOrder[] in length
    for(int k=0;k<length;k++)
        sortedOrder[k] = orders[k];
    sort(sortedOrder, length);        //sort it

    bool seqAvail = true;
    int k=0;
    for(;k<length && seq[k]==sortedOrder[k];k++);    //compare the two sorted
    if(k<length)    seqAvail = false;
   
    if(!seqAvail){
        printf("input sequence is incorrect\n");
        return;
    }
    for(k=0;k<length;k++)
        printf("%c", orders[k]);
    printf("\n");
}

/**************test*************/
void test_01(){ 
    int a[5][5]={
        {2,5,6,17,20},
        {3,1,7,23,13},
        {10,0,11,4,8},
        {21,9,19,12,22},
        {18,14,16,15,24}
    };
    int b[5][5]={
        {2,5,6,17,20},
        {3,7,23,4,13},
        {10,1,11,12,8},
        {21,9,0,19,22},
        {18,14,16,15,24}
    };
    char sequence[7] = {'R', 'D', 'R', 'D', 'L', 'U', '\0'};    //correct is "URRDDL"    //bug ever!!
    findZeroMove(a, b, sequence, 6);
    return;
}

int main(int, char**){
    test_01();
}
