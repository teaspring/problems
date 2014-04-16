/*
* 0-1 knapsack problem
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int TotalCount = 6;

int W[TotalCount] = {1, 3, 2, 4, 5, 7};
int V[TotalCount] = {2, 5, 3, 6, 7, 9};
int C[TotalCount] = {};

//N objects in total, M weight in total
const int N=5;   
int weigh[N+1] = {0,1,2,4,5,6};
int value[N+1] = {0,2,3,5,7,9};  
const int M=11;

int Max(int& lv, int& rv){
    return lv > rv ? lv : rv;
}

int ZeroOneKnapsack(int weighx){
    int V[M+1];
    memset(V, 0, sizeof(int)*(M+1));
    for(int i=1;i<=N;i++){  
        for(int j=M; j>=weigh[i]; --j){    
            int tmp = V[j-weigh[i]] + value[i];        //0-1 Knapsack
            if(tmp > V[j])        V[j] = tmp;
         }  
     }
    if(weighx>M ||weighx<1)         return 0;
    return V[weighx];      
}

//non-01 means one weight object can be packed for 1+ times
int NonZeroOneKnapsack(int weighx){
    int V[M+1];
    memset(V, 0, sizeof(int)*(M+1));
    for(int i=1;i<=N;i++){ 
        for(int j=weigh[i]; j<=M; ++j){    
            int tmp = V[j-weigh[i]] + value[i];        //reverse order enable it non 01 knapsack
            if(tmp > V[j])        V[j] = tmp;
        }  
    }     

    if(weighx>M ||weighx<1 )    return 0;
    return V[weighx];
}

void ZeroOneKnapsack01()  {       
    // V[i][j] means with no more than i objects, the total weight no more than j, the biggest value
    int V[N+1][M+1];  
    for(int i=0;i<=M;i++){
        V[0][i]=0;  
    }
    for(int i=0;i<=N;i++){
        V[i][0]=0;
    }

    for(int i=1;i<=N;++i){  
        for(int v=1; v<=M; ++v){  
            V[i][v] = V[i-1][v];  
            if(weigh[i] <= v){  
                int tmp = V[i-1][v-weigh[i]] + value[i];
                V[i][v] = Max((V[i][v]), tmp); 
            }  
        }  
    }      
   
    for(int v=1;v<=M;v++){  
        cout<<v<<" : ";  
        for(int i=1;i<=N;i++){  
             cout<<V[i][v]<<"   ";  
        }  
        cout<<endl;  
    }  
   
    int ii=N,jj=M;  
    while(ii > 0){  
        if(V[ii][jj] > V[ii-1][jj]){  
            cout<<ii<<" ";  
            jj -= weigh[ii];  
            --ii;
        }else if(V[ii][jj] == V[ii-1][jj]){
            ii--;
        }else{  
            cout<<"error"<<endl;  
        }  
     }         
 }

int main(int, char**){
	return 0;
}
