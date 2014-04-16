/*
* Dijkstra, fixed source node, varied destination, no loop, no minus length
* one copy of implementation from web
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <stack>
#include <queue>

using namespace std;
 
const int maxnum = 5;
const int maxint = 999999;
 
//index begin with 1, indicating Nth node 
int dist[maxnum];        
int Prev[maxnum];        
int c[maxnum][maxnum];  
int n, line;           
 
// n -- n nodes
// v -- the source node
// dist[] -- the shortest distance from the ith node to the source node
// Prev[] -- the Previous node of the ith node
// c[][] -- every two nodes' distance
// greedy algorithm
void Dijkstra01(int n, int v, int *dist, int *Prev, int c[maxnum][maxnum]){
    bool s[maxnum];        // s[N]==1 means currently dist[N] is the calculated shortest path
    for(int i=1; i<=n; ++i){
        dist[i] = c[v][i];
        s[i] = 0;     
        if(dist[i] == maxint){  // the node whhich can not reach from fixed source node directly
            Prev[i] = 0;
        }else{
            Prev[i] = v;
        }
    }
    dist[v] = 0;
    s[v] = 1;
 
    for(int i=2; i<=n; ++i){
        int tmp = maxint;
        int u = v;
        for(int j=1; j<=n; ++j){
            if((!s[j]) && dist[j]<tmp){
                u = j;
                tmp = dist[j];
            }
        }
        s[u] = 1;
 
        for(int j=1; j<=n; ++j){    // update distance with other not covered nodes
            if((!s[j]) && c[u][j]<maxint){    //select the edge u-j starting from u
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j]){
                    dist[j] = newdist;
                    Prev[j] = u;
                }
            }
        }
    }
}
 
// because previous of each node is saved, it has to output the path in reverse order
//1.ensure no loop in the diagram
//2.path from v to u
void searchPath(int *Prev,int v, int u){
    int que[maxnum];
    memset(que, 0, sizeof(que));
    int tot = 0;
    que[tot++] = u;    
    int tmp = Prev[u];
    while(tmp != v){
        que[tot] = tmp;
        tot++;
        tmp = Prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=0; --i){
        if(i != 0){
            cout << que[i] << " -> ";
        }else{
            cout << que[i] << endl;
        }
    }
}
 
void test_01(){
    int c[][5] = {
        {0, 10, maxint, 5, maxint},
        {maxint, 0, 1, 2, maxint},
        {maxint, maxint, 0, maxint, 4},
        {maxint, 3, 9, 0, 2},
        {7, maxint, 6, maxint, 0}
    };
    Dijkstra01(4, 0, dist, Prev, c);

    for(int i=1; i<maxnum; i++){
        cout << "length from source to node[" << i << "] is " << dist[i] << endl; 
    }

    cout << "**********************" << endl;
    for(int i=1; i<maxnum;i++){
        searchPath(Prev, 0, i);
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
