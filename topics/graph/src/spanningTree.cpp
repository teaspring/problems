/*********************spanning tree construction algorithm**************************/
/* 
 * Boruvka algorithm, nice to parallel programming; Jun 20, 2013
 * Kruskal algorithm, sort edges by weight ascending,add it if not leading to cycle;
 * JanikPrim algorithm, sort edges by weight ascending, add it if it incident to vertex already in spanning tree and not leading to cycle;
 * Dijkstra: iterate edges without sorted, add one by one. if cycle appears, delete the weightest edge
 * 
 * Q to all 4 methods: how to exit if the undigraph is not connected?
*/
#include "algorithmHeader.h"

int findNextDiff(int arr[BoundMax], int size, int currIdx){
    int i = (currIdx+1)%size;
    for(;i != currIdx && arr[i] == arr[currIdx];i++, i=i%size);
    return i == currIdx ? -1 : arr[i];
}

/*
 * it doesnot need edge collection
 * */
void spanningTree::Boruvka(genGraph* pGraph, int sTree[BoundMax][BoundMax]){
    const int vN = pGraph->vNum;   
    int *treeOfVert = new int[vN]();            //[vertex] is tree No
    for(int i=0;i<vN;treeOfVert[i]=i, i++);       
   
    int treeCount = vN;
    int iTree=0;        //tree i
    while(treeCount > 1){
        int minWeight = MAX;
        int adjIdx = 0;
        int iniIdx = 0;
        bool treeNull = true;
        for(int j=0;j<vN;j++){    //vertex j of iTree; find shortest edge(vu) for u adjacent to v while v in iTree and u not; combine u's tree to v's tree
            if(treeOfVert[j] != iTree) continue;                           
            treeNull = false;
            int* vertRow = pGraph->adjaMtx[j];
            for(int k=0; k<vN;k++){       
                if(vertRow[k] == MAX        //unadjacent k to j
                    || treeOfVert[j] == treeOfVert[k])    continue;    //vertices in one tree
                if(minWeight > vertRow[k]){
                    minWeight = vertRow[k];
                    adjIdx = k;
                    iniIdx = j;
                }
            }
        }
           
        if(!treeNull){   
            sTree[iniIdx][adjIdx] = sTree[adjIdx][iniIdx] = pGraph->adjaMtx[iniIdx][adjIdx];            //insert edge(vu) to result tree
            printf("%d - %d : %d\n",
                iniIdx<adjIdx? iniIdx : adjIdx,
                iniIdx<adjIdx? adjIdx : iniIdx,
                pGraph->adjaMtx[iniIdx][adjIdx]);

            int currTree = treeOfVert[adjIdx];
            for(int q=0;q<vN;q++){
                if(treeOfVert[q] != currTree) continue;
                treeOfVert[q] = iTree;
            }
            treeCount--;           
        }
           
        iTree = findNextDiff(treeOfVert, vN, iniIdx);
        if(iTree == -1) break;
    }
    delete[] treeOfVert;
    treeOfVert=0;
    return;
}

/*
 * Point: how to detect cycle.instead of formal method, a less weighted method is one edge incident with two vertices which are in one spanning tree already
 * */
void spanningTree::Kruskal(genGraph* pGraph, int sTree[BoundMax][BoundMax]){
    const int eN = pGraph->eNum;
    const int vN = pGraph->vNum;
    int *treeOfVert = new int[vN]();
    for(int i=0;i<vN;treeOfVert[i]=i, i++);

    int mergedVert = 1;
    pGraph->sortEdges();
    for(int i=0;i<eN && mergedVert<vN;i++){        //as here every added one stay there, the mergedVert is accountable
        int v1 = pGraph->edgeArray[i]->v1;
        int v2 = pGraph->edgeArray[i]->v2;
        if(treeOfVert[v1] == treeOfVert[v2]) continue;    //skip if already in a spanning tree(including case of cycle)    
        int treeOfV2 = treeOfVert[v2];
        for(int k=0;k<vN;k++){
            if(treeOfVert[k] != treeOfV2) continue;
            treeOfVert[k] = treeOfVert[v1];
        }
        mergedVert++;                            //vertice merged into spanning tree
        
        sTree[v1][v2] = sTree[v2][v1] = pGraph->edgeArray[i]->weight;
        printf("%d - %d : %d\n",v1,v2,pGraph->edgeArray[i]->weight);
    }
    delete[] treeOfVert;
    treeOfVert=0;
    return;
}

/*
 * to add edge to spanning tree: besides not leading to cycle, it must be incident with current spanning tree
 * it require added vertex incident to working spanning tree, which not bring side effect to result but change the order in which vertex is added. its performance is worse than Kruskal 
 * */
void spanningTree::JanikPrim(genGraph* pGraph, int sTree[BoundMax][BoundMax]){
    const int eN = pGraph->eNum;
    const int vN = pGraph->vNum;
    int *treeOfVert = new int[vN]();
    for(int i=0;i<vN;treeOfVert[i]=i, i++);

    int mergedVert = 1;
    pGraph->sortEdges();
    int currTree = -1;
    while(mergedVert<vN){
      for(int i=0;i<eN;i++){        //same to Kruskal, every added edge stays,so the mergedVert is accountable 
        int v1 = pGraph->edgeArray[i]->v1;
        int v2 = pGraph->edgeArray[i]->v2;
        if(treeOfVert[v1] == treeOfVert[v2]) continue;    //skip if v1&v2 already in a same spanning tree(leading to cycle or have been in already)        
        if(currTree == -1)
          currTree = treeOfVert[v1];
        else
          if(treeOfVert[v1] != currTree && treeOfVert[v2] != currTree) continue; //not incident to current sTree

        treeOfVert[v1] = currTree;
        treeOfVert[v2] = currTree;
        mergedVert++;
        //output
        sTree[v1][v2] = sTree[v2][v1] = pGraph->edgeArray[i]->weight;
        printf("%d - %d : %d\n",v1,v2,pGraph->edgeArray[i]->weight);
        break;                    //if one edge is added, next iteration must start from head of sorted edges
      }
    }
    delete[] treeOfVert;
    treeOfVert=0;
    return;
}

/*
 * iterate edges without sort and add one by one.if cycle appears, delete the weightest edge. 
 * */
void spanningTree::Dijkstra(genGraph* pGraph, int sTree[BoundMax][BoundMax]){
    const int vN = pGraph->vNum;
    const int eN = pGraph->eNum;
    int *treeOfVert = new int[vN]();
    for(int i=0;i<vN;treeOfVert[i]=i, i++);
    for(int i=0;i<eN;i++){    //because Dijsktra accept remove of weightest if added one leading to cycle, it must iterate all the edges
        int v1 = pGraph->edgeArray[i]->v1;
        int v2 = pGraph->edgeArray[i]->v2;
        int w = pGraph->edgeArray[i]->weight;
       
        sTree[v1][v2] = sTree[v2][v1] = w;    //add to spanning tree       
        printf("add %d - %d: %d\n", v1, v2, w);
        if(treeOfVert[v1] == treeOfVert[v2]){    //this cycle detection is error            
            int topW = 0;
            int d1 = 0;
            int d2 = 0;
            for(int i=0;i<vN;i++)                //delete the weightest from spanning tree
                for(int j=0;j<vN;j++){
                    if(topW < sTree[i][j]){
                        topW = sTree[i][j];
                        d1 = i;
                        d2 = j;
                    }
                }
            printf("delete %d - %d: %d\n", d1, d2, topW);
            sTree[d1][d2] = sTree[d2][d1] = 0;
        }
        int treeOfV2 = treeOfVert[v2];
        for(int k=0;k<vN;k++){
            if(treeOfVert[k] != treeOfV2) continue;
            treeOfVert[k] = treeOfVert[v1];
        }
    }
    delete[] treeOfVert;
    treeOfVert=0;
    return;
}
