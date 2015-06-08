/*
 * test cases
 * */
#include "algorithmHeader.h"

int main(int argc, char* argv[]){    
    if(1){
        shortestPath* pShortest = new shortestPath();    
        if(0){
            int mtx1[BoundMax][BoundMax] = {    //case1 for Dijkstra algorithm(one2all), with undigraph without negative weight
                {0, 1, 4, 3, 2, MAX, MAX},
                {1, 0, 2, MAX, MAX, 4, MAX},
                {4, 2, 0, 1, MAX, 3, MAX},
                {3, MAX, 1, 0, 2, MAX, 1},
                {2, MAX, MAX, 2, 0, MAX, 3},
                {MAX, 4, 3, MAX, MAX, 0, 2},
                {MAX, MAX, MAX, 1, 3, 2, 0}
            };
            int start = 2;
            genGraph* pGraph1 = new genGraph(7, 12, mtx1);    
            pShortest->DijkstraShortest(pGraph1, start);
            printf("\n");
            delete pGraph1;
            pGraph1 = 0;
        }

        if(0){
            int mtx2[BoundMax][BoundMax]={        //case2 for Ford algorithm(one2all), with negative weight digraph
                {0,1,1,1,MAX,MAX,MAX,MAX,MAX},
                {MAX,0,-1,MAX,MAX,MAX,MAX,MAX,MAX},
                {MAX,MAX,0,-1,MAX,MAX,MAX,MAX,MAX},
                {MAX,MAX,MAX,0,2,MAX,4,MAX,1},
                {MAX,MAX,MAX,MAX,0,1,MAX,MAX,MAX},
                {MAX,MAX,MAX,MAX,MAX,0,-5,MAX,MAX},
                {MAX,MAX,MAX,MAX,MAX,MAX,0,4,MAX},
                {MAX,MAX,MAX,MAX,MAX,MAX,MAX,0,MAX},
                {MAX,MAX,MAX,MAX,MAX,MAX,MAX,1,0}
            };
            genGraph* pGraph2 = new genGraph(9, 12, mtx2);
            int start = 0;
            pShortest->FordShortest(pGraph2, start);
            printf("\n");
            delete pGraph2;
            pGraph2=0;
        }

        if(0){
            int mtx3[BoundMax][BoundMax] = {    //case3 for WFI algorithm(all2all), negative weight digraph
                {0,2,MAX,-4,MAX},
                {MAX,0,-2,1,3},
                {MAX,MAX,0,MAX,1},
                {MAX,MAX,MAX,0,4},
                {MAX,MAX,MAX,MAX,0}
            };
            genGraph* pGraph3 = new genGraph(5, 7, mtx3);
            pShortest->WFIShortest(pGraph3);
            printf("\n");
            delete pGraph3;
            pGraph3=0;
        }

        if(0){
            int mtx4[BoundMax][BoundMax] = {    //diagraph
                {0,2,MIN,1,MIN},
                {MIN,0,4,1,3},
                {MIN,MIN,0,MIN,1},
                {MIN,MIN,MIN,0,3},
                {MIN,MIN,MIN,MIN,0}
            };
            genGraph* pGraph4 = new genGraph(5, 7, mtx4);
            pShortest->WFIUngraphLongest(pGraph4);
            printf("\n");
            delete pGraph4;
            pGraph4=0;
        }

        int mtx5[BoundMax][BoundMax] = {    //diagraph
            {0,2,MIN,1,MIN},
            {2,0,4,1,3},
            {MIN,4,0,MIN,1},
            {1,1,MIN,0,3},
            {MIN,3,1,3,0}
        };
        genGraph* pGraph5 = new genGraph(5, 7, mtx5);
        pShortest->WFIGraphLongest(pGraph5);
        printf("\n");
        delete pGraph5;
        pGraph5=0;

        delete pShortest;
        pShortest=0;
    }

    if(0){
        cycleDetection* pCycle = new cycleDetection();
        int mtx4[BoundMax][BoundMax] = {    //digraph for cycle detection
            {0,2,MAX,MAX,MAX},
            {MAX,0,-2,1,MAX},
            {MAX,MAX,0,MAX,1},
            {-4,MAX,MAX,0,4},
            {MAX,MAX,MAX,MAX,0}
        };
        genGraph* pGraph4 = new genGraph(5, 6, mtx4);
        printf("digraphCycleDetectionDFS:\n");
        pCycle->digraphCycleDetectionDFS(pGraph4, 1);
        printf("\n");
        delete pGraph4;
        pGraph4=0;
        
        printf("undigraphCycleDetectionDFS:\n");
        int mtx5[BoundMax][BoundMax] = {    //digraph for cycle detection
            {0,2,MAX,4,MAX},
            {2,0,2,1,MAX},
            {MAX,2,0,MAX,1},
            {4,1,MAX,0,4},
            {MAX,MAX,1,4,0}
        };
        genGraph* pGraph5 = new genGraph(5, 6, mtx5);
        pCycle->undigraphCycleDetectionDFS(pGraph5, 1);
        printf("\n");
        delete pGraph5;
        pGraph5=0;
        
        delete pCycle;
        pCycle=0;
    }

    if(0){                                    // spanning tree
        int arr[BoundMax][BoundMax] = {
            {0,6,5,MAX,MAX,MAX,MAX},
            {6,0,9,MAX,13,MAX,MAX},
            {5,9,0,16,MAX,12,MAX},
            {MAX,MAX,16,0,15,7,MAX},
            {MAX,13,MAX,15,0,MAX,8},
            {MAX,MAX,12,7,MAX,0,3},
            {MAX,MAX,MAX,MAX,8,3,0}
        };
        genGraph* pGraph = new genGraph(7, 10, arr);
        int resTree[BoundMax][BoundMax];
        memset(resTree, 0, sizeof(int)*BoundMax * BoundMax);
        spanningTree* pSTree = new spanningTree();
        printf("\nDijkstra case1 of random sequential edges:\n");
        memset(resTree, 0, sizeof(int)*BoundMax * BoundMax);
        pSTree->Dijkstra(pGraph, resTree);
        printf("\nBoruvka:\n");
        pSTree->Boruvka(pGraph, resTree);
        printf("\nKruskal:\n");
        memset(resTree, 0, sizeof(int)*BoundMax * BoundMax);
        pSTree->Kruskal(pGraph, resTree);
        printf("\nJanikPrim:\n");
        memset(resTree, 0, sizeof(int)*BoundMax * BoundMax);
        pSTree->JanikPrim(pGraph, resTree);
        printf("\nDijkstra case 2 of sorted edges:\n");
        memset(resTree, 0, sizeof(int)*BoundMax * BoundMax);
        pSTree->Dijkstra(pGraph, resTree);
        
        delete pGraph;
        pGraph=0;
    }
    return 0;
}
