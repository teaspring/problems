/*
* Floyd-Warshall algorithm, minimum distance between multiple nodes
* one copy of implementation from web
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <queue>

using namespace std;
 
const int maxnum = 5;
const int maxint = 999999;
const int NIL = -1;

//index begin with 1, indicating Nth node 
int dist[maxnum][maxnum];
int Prev[maxnum][maxnum];

void FloydWarshall(int c[maxnum][maxnum], int prev[maxnum][maxnum], int dist[maxnum][maxnum]){
    for(int i=0; i<maxnum; i++){
        for(int j=0; j<maxnum; j++){
            dist[i][j] =  c[i][j];
            prev[i][j] = NIL;
        }
    }

    for(int k =0;k<maxnum;k++){
        for(int i=0; i<maxnum;i++){
            for(int j=0; j<maxnum; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    prev[i][j] = k;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void SearchPath(int src, int dest, int prev[maxnum][maxnum]){
    if(src >= maxnum || dest >= maxnum)        return;

    int path[maxnum];
    memset(path, 0, sizeof(path));
    int tot = 0;
    path[tot] = dest; 
    int pred = prev[src][dest];    
    while(pred != NIL){
        path[++tot] = pred;
        pred = prev[src][pred];
    }
    tot++;
    path[tot] = src;

    for(int i = tot; i>0; i--){
        cout << path[i] << " -> ";
    }
    cout << path[0] << endl;
}

void test_01(){
    int ini[maxnum][maxnum] = {
        {0, 3, 8, maxint, -4},
        {maxint, 0, maxint, 1, 7},
        {maxint, 4, 0, maxint, maxint},
        {2, maxint, -5, 0, maxint},
        {maxint, maxint, maxint, 6, 0}
    };

    FloydWarshall(ini, Prev, dist);
    for(int i=0; i<maxnum; i++){
        for(int j=0; j<maxnum; j++){
            cout << dist[i][j] << "   ";
        }
        cout << endl;
    }

    cout <<"********************"<<endl;
    int src = 3;
    int dest = 4;
    SearchPath(src, dest, Prev);
}

int main(int, char**){
    test_01();
    return 0;
}
