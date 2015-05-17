/*****************genGraph.cpp*********************/
#include "genGraph.h"

template<typename pT>
void swapLocal(pT& lhd, pT&rhd){
    pT tmp = rhd;
    rhd = lhd;
    lhd = tmp;
    tmp = 0;
}

genGraph::genGraph(int vN, int eN, int mtx[BoundMax][BoundMax])
        :vNum(vN)
        ,eNum(eN)
        ,edgeArray(new genEdge*[BoundMax]()){
    int k = 0;
    for(int k = 0, int i = 0; i < vNum; i++)
        for(int j = 0;j < vNum; j++){
          adjaMtx[i][j] = mtx[i][j];

          if(k < eNum && mtx[i][j] != MAX && mtx[i][j] != MIN){    // j > i limit it to undigraph
            if(findEdge(i,j) == -1){
                edgeArray[k++] = new genEdge(mtx[i][j], i, j);
            }
          }
        }
}

genGraph::~genGraph(){
    delete[] edgeArray;
}

int genGraph::findEdge(int u, int v){
    if(u > v)    swapLocal<int>(u, v);

    for(int i = 0; NULL != edgeArray[i]; i++){
      if(edgeArray[i]->v1 == u && edgeArray[i]->v2 == v)    return i;
    }

    return -1;
}

void genGraph::sortEdges(){   // bumble sort
    for(int i = 0; i < eNum-1; i++)
      for(int j = i+1; j < eNum; j++){
        if(edgeArray[i]->compare(edgeArray[j])){    // greater than return true
            swapLocal<genEdge*>(edgeArray[i], edgeArray[j]);
        }
      }
}
