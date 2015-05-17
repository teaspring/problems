//*************************genGraph.h*******************************

#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "graphConst.h"

using namespace std;

/*
 * struct for general undirected edge
 * */
struct genEdge{
    int weight;
    int v1;  // index in vertex array
    int v2;  // index in ~

    genEdge()
        :weight(0)
        ,v1(0)
        ,v2(0){}

    genEdge(int w, int d1, int d2)
        :weight(w)
        ,v1(d1 < d2 ? d1:d2)
        ,v2(d1 < d2 ? d2:d1){}

    virtual ~genEdge(){}

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

    int adjaMtx[BoundMax][BoundMax];  // adjacent matrix, a V*V matrix

    genEdge** edgeArray;

    genGraph(int, int, int[BoundMax][BoundMax]);

    virtual ~genGraph();

    void sortEdges();  // sort edges by weight

    void outputEdges();

    int findEdge(int, int);
};

enum CoveredEnum {
    NoProbed = 0,
    Probed,
    Covered
};

struct Point{
    Point(int val):
        value(val),
        Left(NULL),
        Mid(NULL),
        Right(NULL),
        Cov(NoProbed){}

    int value;
    Point *Left;
    Point *Mid;
    Point *Right;
    CoveredEnum Cov;
};
