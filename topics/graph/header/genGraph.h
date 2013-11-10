//*************************genGraph.h*******************************
//
#include <stdio.h>
#include "string.h"
#include "graphConst.h"

struct genEdge{
    int weight;
    int v1;
    int v2;
    genEdge()
        :weight(0)
        ,v1(0)
        ,v2(0){}
    genEdge(int w, int d1, int d2)
        :weight(w)
        ,v1(d1<d2 ? d1:d2)
        ,v2(d1<d2 ? d2:d1){}
    ~genEdge(){}
    bool compare(genEdge* rh){
        return this->weight > rh->weight;
    }
};

/*
 * undigraph
 * */
struct genGraph{
    const int vNum;
    const int eNum;
    int adjaMtx[BoundMax][BoundMax];                //adjacent matrix, a V*V matrix
    genEdge** edgeArray;    
    
    genGraph(int, int, int[BoundMax][BoundMax]);
    ~genGraph();
    void sortEdges();        //sort edges by weight
    void quickSort(genEdge* arr[BoundMax], int start, int length);
    void outputEdges();
    int findEdge(int, int);
};

