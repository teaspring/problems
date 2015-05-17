/****************<DataStructureInC++> chapter8 Graphs***************/
/***********************algorithmHeader.h*******************************/
#include "genGraph.h"

class shortestPath{
public:
    shortestPath(){}
    ~shortestPath(){}

    //one to all shortest
    void DijkstraShortest(genGraph*, int start);
    void FordShortest(genGraph*, int start);

    //all to all shortest
    void WFIShortest(genGraph*);

    //cycle detection in use of DFS
    void digraphCycleDetectionDFS(genGraph*, int v);

    void WFIUngraphLongest(genGraph*);

    void WFIGraphLongest(genGraph*);
};

class cycleDetection{
public:
    cycleDetection()
                :num(new int[BoundMax]())
                ,edgeIterated(new int[BoundMax]())
                ,cnt(0){}

    ~cycleDetection(){
        delete[] num;
        delete[] edgeIterated;
    }

    void digraphCycleDetectionDFS(genGraph*, int);

    void undigraphCycleDetectionDFS(genGraph*, int);

    int* num;  // array to mark vertex being iterated

    int* edgeIterated;  // array to mark edge being iterated

    int cnt;  // external variable of digraphCycleDetectionDFS(),mark the iterated vertex
};

class spanningTree{
public:
    spanningTree(){}
    ~spanningTree(){}
    void Boruvka(genGraph*, int[BoundMax][BoundMax]);
    void Kruskal(genGraph*, int[BoundMax][BoundMax]);
    void JanikPrim(genGraph*, int[BoundMax][BoundMax]);
    void Dijkstra(genGraph*, int[BoundMax][BoundMax]);
};

