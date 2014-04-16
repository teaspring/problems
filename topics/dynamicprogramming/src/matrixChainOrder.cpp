/*
* classic problem of DP, matrix chain order
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int count = 6;
const int maxval = 1000 * 1000;

int cost[count][count]; // cost to multiple matrix, only use upper half, m[i][j], j>i
int pos[count][count]; // split position for a matrix chain, only upper half, m[i][j], j>i

void MatrixChainOrder(int ini[count+1], int m[count][count], int s[count][count]){
    for(int i=0; i<count;i++){
        m[i][i] = 0;
    }

    for(int len=1; len<count; len++){
        for(int i=0; i < count - len; i++){    
            int j = i + len ;
            m[i][j] = maxval; //better initialize here
            for(int k=i; k<j; k++){
                int q = m[i][k] + m[k+1][j] + ini[i] * ini[k+1] * ini[j+1];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void SearchPath(int s[count][count], int i, int j){
    if(i == j){
        cout << "A"<<i; 
    }else{
        cout << '(';
        SearchPath(s, i, s[i][j]);
        SearchPath(s, s[i][j] + 1, j);
        cout << ')';
    }    
}

void RunMatrixChainOrder(){
    // N matrix, N+1 dimension value
    int matrixArr[count + 1] = {
        30, 35, 15, 5, 10, 20, 25
    };

    memset(cost, 0, sizeof(cost));
    MatrixChainOrder(matrixArr, cost, pos);
    cout << "matrix multiple counts:" << endl;
    for(int i=0; i<count; i++){
        for(int j=0; j<count; j++){
            cout << cost[i][j] << "   ";
        }
        cout << endl;
    }

    cout << "best split position:" <<endl;
    for(int i=0; i<count;i++){
        for(int j=0; j<count; j++){
            cout << pos[i][j]<<"   ";
        }
        cout << endl;
    }

    cout <<"********************"<<endl;
    int src = 0;
    int dest = count-1;
    SearchPath(pos, src, dest);
}

int main(int, char**){
    return 0;
}
