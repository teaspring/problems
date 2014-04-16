/*
* BeanMan game: moving in a M*N matrix and try to eat the most beans with his path
* Problem I : one man starts from [0,0] to [M-1][N-1], only downward and rightward movement is allowed
* Problem II: two men start from [0,0] to [M-1][N-1], only downward and rightward movement is allowed
* -- Date: Jan, 2013
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
#include <stack>

using namespace std;

const int Rows = 6;
const int Columns = 6;
//it should be enum 
const int EMove = 1;
const int WMove = 2;
const int NMove = 3;
const int SMove = 4;

int beanMan(int pool[Rows][Columns], int prev[Rows][Columns], int beginX, int beginY, int destRow, int destCol){
    cout << "The bean pool is:  " <<endl;        
    for(int i=0;i<Rows; i++){
        for(int j=0; j<Columns; j++){
            cout << pool[i][j] << "    ";
        }
        cout << endl;
    }

    int score[Rows][Columns];
    memset(score, 0, sizeof(score));

    for(int i=beginX; i < destRow+1; i++){
        for(int j = beginY; j < destCol+1; j++){
            int preVal = 0;
            if(i == beginX && j == beginY){
                preVal = 0;
            }else if(i == beginX){
                preVal = score[i][j-1];
                prev[i][j] = WMove;
            }else if(j == beginY){
                preVal = score[i-1][j];
                prev[i][j] = NMove;
            }else{
                if(score[i-1][j] > score[i][j-1]){
                    preVal = score[i-1][j];
                    prev[i][j] = NMove;
                }else if(score[i-1][j] < score[i][j-1]){
                    preVal = score[i][j-1];
                    prev[i][j] = WMove;
                }else{
                    int tmpi = i-1;
                    int tmpj = j-1;
                    while(tmpi-1 >= beginX && tmpj-1 >= beginY ){
                        if(score[tmpi-1][j] < score[i][tmpj-1]){
                            preVal = score[i][j-1];
                            prev[i][j] = WMove;
                            break;
                        }else if(score[tmpi-1][j] > score[i][tmpj-1]){
                            preVal = score[i-1][j];
                            prev[i][j] = NMove;
                            break;
                        }else{
                            tmpi--;
                            tmpj--;
                            continue;
                        }
                    }

                    if(tmpi -1 < beginX && tmpj - 1 >= beginY){
                        preVal = score[i][j-1];
                        prev[i][j] = WMove;
                    }else if(tmpi -1 >= beginX && tmpj -1 < beginY){    
                        preVal = score[i-1][j];
                        prev[i][j] = NMove;
                    }

                    if(prev[i][j] != NMove){
                        prev[i][j] = WMove;
                        preVal = score[i][j-1];
                    }
                }
            }
            score[i][j] = preVal + pool[i][j];
        }
    }

    cout << "The score array is:  " <<endl;        
    for(int i=beginX;i<=destRow; i++){
        for(int j=beginY; j<=destCol; j++){
            cout << score[i][j] << "    ";
        }
        cout << endl;
    }
    return score[destRow][destCol];
}

//recurse
void trace(int prev[Rows][Columns], int beginX, int beginY, int dR,  int dC){
    int r = dR;
    int c = dC;
    if(r == beginX && c == beginY){
        cout << "(" << r << ", " << c << ")";
        return;
    }else{
        switch (prev[r][c]){
        case NMove:
            r--;
            break;
        case WMove:
            c--;
            break;
        default:
            r--;
            c--;
            break;            
        }
        trace(prev, beginX, beginY, r, c);
    }
    cout << " --> " << "(" << dR << ", " << dC << ")" ;
}

/*
 * for double bean man problem.
 */

/* 
 * trace the best path from begin point to destination point backwards
 * */
void backTrace(int prev[Rows][Columns], int boundary[Rows], int sR, int sC, int dR,  int dC, bool bResetUpper){
    if(bResetUpper){
        for(int i=0; i<Rows; i++){
            boundary[i] = Columns;
        }
    }else{
        for(int i=0; i<Rows; i++){
            boundary[i] = -1;
        }        
    }
    
    int r = dR;
    int c = dC;
    while(r >= sR && c >= sC){
        cout << "(" << r << ", " << c << ") <<" ;        
        if(bResetUpper){
            if(c < boundary[r])        boundary[r] = c;
        }else{
            if(c > boundary[r])        boundary[r] = c;
        }

        switch (prev[r][c]){
        case NMove:
            r--;
            break;
        case WMove:
            c--;
            break;
        default:
            r--;
            c--;
            break;            
        }
        continue;            
    }
    cout << endl << "-----------------------------------" << endl;
}

/* 
 * based on an existing boundary and up/down direction, update the pool matrix 
 * */
void updatePool(int pool[Rows][Columns], int boundary[Rows], bool bResetUpper){
    cout << "The boundary array is: " << endl;
    for(int i = 0; i < Rows; ++i){    
        int j = boundary[i];
        cout << "[" << i << ", " << boundary[i] << "] --> ";
        if(bResetUpper){
            if(j >= Columns)    continue;
            while(j < Columns){
                pool[i][j] = 0;
                j++;
            }
        }else{
            if(j < 0)    continue;            
            while(j >= 0){
                pool[i][j] = 0;
                j--;
            }            
        }    
    }
    cout<<endl;
}

void cpArray(int src[Rows][Columns], int dest[Rows][Columns]){
    memset(dest, 0, sizeof(dest));
    for(int i=0; i<Rows; i++){
        for(int j=0; j<Columns; j++){
            dest[i][j] = src[i][j];
        }
    }
}

/*
 * plan A, independent best path from [0,1] to [N-2, N-1], and dependent best path from [1,0] to [N-1, N-2]
 * plan B, independetn best path from [1,0] to [N-1, N-2], and dependent best path from [0,1] to [N-2, N-1]
 * */
void beanMan2(int pool[Rows][Columns], int prev[Rows][Columns], int sR, int sC, int dR, int dC){
    memset(prev, 0, sizeof(prev));
        
    int tmpPool[Rows][Columns];
    cpArray(pool, tmpPool);

    int boundary[Rows];
    for(int i=0; i<Rows; i++){
        boundary[i] = Columns-1;
    }

    //independent best path from [0,1] to [N-2, N-1]
    int beginX = sR;
    int beginY = sC + 1;
    int endX = dR - 1;
    int endY = dC;
    
    int UpScoreA = beanMan(pool, prev, beginX, beginY, endX, endY);
    cout << "Plan A, independent best path scores: " << UpScoreA << endl;
    backTrace(prev, boundary, beginX, beginY, endX, endY, true);

    //dependent best path from [1,0] to [N-1,N-2]
    updatePool(tmpPool, boundary, true);
    memset(prev, 0, sizeof(prev));
    beginX = sR + 1;
    beginY = sC;
    endX = dR;
    endY = dC -1;
    int DownScoreA = beanMan(tmpPool, prev, beginX, beginY, endX, endY);
    cout << "Plan A, dependent best path scores: " << DownScoreA << endl;
    backTrace(prev, boundary, beginX, beginY, endX, endY, false);
    int scoreA = pool[sR][sC] + UpScoreA + DownScoreA + pool[dR][dC];
    cout << "In total, Plan A scores: " << scoreA <<endl;
    cout << "===========================================================" << endl;    
    

    //plan B:
    memset(prev, 0, sizeof(prev));
    cpArray(pool, tmpPool);

    //independent best path from [1,0] to [N-1, N-2]
    beginX = sR + 1;
    beginY = sC;
    endX = dR;
    endY = dC - 1;
    int DownScoreB = beanMan(pool, prev, beginX, beginY, endX, endY);
    cout << "Plan B, independent best path scores: " << DownScoreB << endl;
    backTrace(prev, boundary, beginX, beginY, endX, endY, false);

    //dependent best path from [0,1] to [N-2,N-1]
    updatePool(tmpPool, boundary, false);
    memset(prev, 0, sizeof(prev));
    beginX = sR;
    beginY = sC + 1;
    endX = dR - 1;
    endY = dC;
    int UpScoreB = beanMan(tmpPool, prev, beginX, beginY, endX, endY);
    cout << "Plan B, dependent best path scores: " << UpScoreB << endl;
    backTrace(prev, boundary, beginX, beginY, endX, endY, true);
    int scoreB = pool[sR][sC] + UpScoreB + DownScoreB + pool[dR][dC];
    cout << "In total, Plan B scores: " << scoreB <<endl;
    cout << "Among Plan A and B, the better is " << (scoreB > scoreA ? 'B':'A') << endl;
    cout << "******************************************************************************" << endl;
}

int main(int, char**){
    return 0;
}

