/*
 * problem: given an int matrix as source and another as destination,  
 *
*/

#include "matrixFind.h"

void findZeroMove(int src[5][5], int dst[5][5], char* seq, const int length){
    int i=0,j=0;    //in src
    int p=0,q=0;    //in dst
    char* orders = new char[MaxN*4];        //use the constant int
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
    while(dst[i][j] != 0){            //start from begining in src[][]
        if(i<4 && dst[i][j] == src[i+1][j]){
            orders[step++] = 'D';
            i++;
        }else if(i>0 && dst[i][j] == src[i-1][j]){
            orders[step++] = 'U';
            i--;
        }else if(j<4 && dst[i][j] == src[i][j+1]){
            orders[step++] = 'R';
            j++;
        }else if(j>0 && dst[i][j] == src[i][j-1]){
            orders[step++] = 'L';
            j--;
        }
        else 
          break;
    }

    if(dst[i][j] != 0){
        printf("Unable to move to the dst[][]\n");
        delete[] orders;
        orders=0;
        return;
    }
    sort(seq, length);            //sort it

    char* sortedOrder = new char[MaxN*4];        //copy orders[] to sortedOrder[] in length
    for(int k=0;k<length;k++)
        sortedOrder[k] = orders[k];
    sort(sortedOrder, length);        //sort it

    bool seqAvail = true;
    int k=0;
    for(;k<length && seq[k]==sortedOrder[k];k++);    //compare the two sorted
    if(k<length){
        printf("input sequence is incorrect\n");
        delete[] orders;
        orders=0;
        return;
    }
    for(k=0;k<length;k++)
        printf("%c", orders[k]);
    printf("\n");
    delete[] orders;
    orders=0;
    return;
}

void sort(char arr[], int length){    //can sort two array in main function directly
    for(int k=0;k<length-1;k++)
        for(int s=k+1;s<length;s++){        //bug ever!!!
            if(arr[k] > arr[s]){
                char tmp = arr[k];
                arr[k] = arr[s];
                arr[s] = tmp;
            }
        }   
}
