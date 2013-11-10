/**********************cycle detection in digraph using DFS ****************************/
/*
 */
#include "algorithmHeader.h"
const int MAXCNT = 100;

/*
 * before it is called firstly, num[] must be reset
 * */
void cycleDetection::digraphCycleDetectionDFS(genGraph* pGraph, int v){
    const int N = pGraph->vNum;
    if(v > (N-1)) return;
    num[v] = ++cnt;

    int* vAdjs = pGraph->adjaMtx[v];
    for(int u=0; u<N; u++){
        if(vAdjs[u] == MAX || vAdjs[u] == 0)    continue;
        if(num[u] == 0)        
          digraphCycleDetectionDFS(pGraph, u);
        else if (num[u] != MAXCNT)
          printf("cycle detected between vertex %d - %d\n", v, u);
    }
    num[v] = MAXCNT;
}

/*
 * before it is called firstly, num[] and edgeIterated[] must be reset
 * */
void cycleDetection::undigraphCycleDetectionDFS(genGraph* pGraph, int v){
    const int vN = pGraph->vNum;
    if(v > (vN-1)) return;
    num[v] = ++cnt;
    int* vAdjs = pGraph->adjaMtx[v];
    for(int u=0;u<vN;u++){
        if(vAdjs[u] == MAX || vAdjs[u] == 0)    continue;
        int eIdx = pGraph->findEdge(v<u?v:u, v<u?u:v);
        if(eIdx == -1){                            //edge not remain in edges
            printf("edge not found between vertex %d - %d!\n", v, u);
            return;
        }
        if(num[u] == 0){
            this->edgeIterated[eIdx] = 1;        //attach edge(uv) to edges          
            undigraphCycleDetectionDFS(pGraph, u);
        }
        else if (this->edgeIterated[eIdx] == 0){
            this->edgeIterated[eIdx] = 1;
            printf("cycle detcetd!! between vertex %d - %d\n", v, u);
        }
    }
}
