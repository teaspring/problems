/*
 * one-to-all shortest path
 * label-setting and label-correcting methods.
 * Dijkstra algorithm: label-setting, for non-negative weight.
 * Idea:
 * check vertex in order of ascending distance. for each checked vertex u, review its adjacent v and update distance[v].
 *
 * why update dist[v] without dist[u]?:
 * as u is checked already before v, dist[u] will not change.
 *
 * Prerequisite:
 * labels(weight) is non-negative, which is called 'label-setting'
 *
 * Ford algorithm: label-correcting, work for negative weight
 * */

/*
 * all-to-all shortest path
 * Warshall Floyd Ingerman algorithm
 */

#include "../header/algorithmHeader.h"

bool NotNullArray(int *a, int length){
    int i=0;
    for(; i<length && a[i] == NullVert; i++);
    return i != length;
}

/*
* Para: *weightAdjaMat is [][]
*/
void shortestPath::DijkstraShortest( genGraph* pGraph, int start){    
    const int N = pGraph->vNum;
    int *currDist = new int[N]();
    int *predecessor = new int[N]();
    for(int i=0; i<N; i++){     //initialize
        currDist[i] = MAX;
        predecessor[i] = -1;
    }
    currDist[start]=0;      // every vertex shortest distance to start

    int *toBeChecked = new int[N]();    //toBeChecked is set of all vertices
    for(int i=0;i<N; i++)
        toBeChecked[i] = i;

    while(NotNullArray(toBeChecked, N)){    // toBeChecked not null
        int v=-1 ;
        for(int i=0; i<N; i++){     // pick up v of minimum currDist(v) in toBeChecked[]
            if(toBeChecked[i] == NullVert)      continue;
            if(v == -1){        // set v initial value
                v = i;
                continue;
            }
            if(currDist[i] < currDist[v])    v = i;
        }
        int* vAdjs = pGraph->adjaMtx[v];
        for(int u=0; u<N; u++){
            if(vAdjs[u] == MAX      // u not adjacent to v
            || v==u
            || toBeChecked[u] == NullVert)  // which is checked already not need update. different with label-correcting
                continue;
            if(currDist[u] > currDist[v] + vAdjs[u]){
                currDist[u] = currDist[v] + vAdjs[u];    
                predecessor[u] = v;
            }
        }
        toBeChecked[v] = NullVert;  // remove v from toBeChecked
    }   
    //output
    cout << "Dijkstra algorithm, currDist[] is: \n";
    for(int i=0; i<N; i++)
        cout << currDist[i] << " ";
    cout << endl;
    cout << "predecessor[] is: \n";
    for(int i=0; i<N; i++)
        cout << predecessor[i] << " ";
    cout << endl;

    delete[] currDist;
    currDist=0;
    delete[] predecessor;
    predecessor=0;
    delete[] toBeChecked;
    toBeChecked=0;
}

int firstNotNull(int* a, int length){
    int i=0;
    for(; i<length && a[i] == NullVert; i++);
    return i;
}

/*
* one to all shortest, Label-correcting, Ford Algorithm, support negative weight
* toBeChecked can be list, queue, deque, and two queues or deque is better 
*/
void shortestPath::FordShortest(genGraph* pGraph, int first){
    const int N = pGraph->vNum;
    int *currDist = new int[N]();
    int *predecessor = new int[N]();
    for(int i=0; i<N;i++){        //initialize
        currDist[i] = MAX;
        predecessor[i] = NullVert;
    }
    currDist[first] = 0;
    
    int *toBeChecked = new int[N]();
    for(int i=0; i<N; toBeChecked[i]=NullVert, i++);
    toBeChecked[first] = first;

    /*
    std::queue<int> toBeChecked;
    toBeChecked.push(first);
    */
    int iterCount=0;
    while(1){
        int v = firstNotNull(toBeChecked, N);
        if (v == N) break;
        toBeChecked[v] = NullVert;    //remove  v from toBeChecked[]
        /*
        if(toBeChecked.empty())    break;
        int v = toBeChecked.top();
        toBeChecked.pop();
        */
        int* vAdjs = pGraph->adjaMtx[v];
        for(int u=0; u<N; u++){                    //edge v->u
            iterCount++;               
            if(vAdjs[u] == MAX) continue;        //u adjacent to v
            if(currDist[u] > currDist[v] + vAdjs[u]){
                currDist[u] = currDist[v] + vAdjs[u];
                predecessor[u] = v;
                toBeChecked[u] = u;             //add u to toBeChecked if it not in
                //toBeChecked.push(u);
            }
        }
    }

    //output
    printf("Ford algorithm:\ntoBeChecked as list, iterations of %d\n", iterCount);
    printf("currDist[] is: \n");
    for(int i=0; i<N; i++){
        printf("%d ", currDist[i]);
    }
    printf("\n");
   
    printf("predecessor[] is: \n");
    for(int i=0; i<N; i++){
        printf("%d ", predecessor[i]);
    }
    printf("\n");   
    
    delete[] currDist;
    currDist=0;
    delete[] predecessor;
    predecessor=0;
    delete[] toBeChecked;
    toBeChecked=0;
}

/*
 * WFI algorithm also can detect cycle. if the diagonal is initialized to MAXIMUM instead of 0, and if any diagonal is changed, a cycle remains.
 * if any initial MAXIMUM weight[i][j] is not changed to a finite value, there is no path from i to j 
 * */
void shortestPath::WFIShortest(genGraph* pGraph){
    const int N = pGraph->vNum;
    for(int i=0; i<N; i++)
      for(int j=0;j<N;j++)
        for(int k=0;k<N;k++){
          if(pGraph->adjaMtx[j][i] == MAX || pGraph->adjaMtx[i][k] == MAX)    //skip the unexisting edge
            continue;
          int tmp = pGraph->adjaMtx[j][i] + pGraph->adjaMtx[i][k];
          if(pGraph->adjaMtx[j][k] > tmp)
            pGraph->adjaMtx[j][k] = tmp;
        }
    //output
    printf("WFIalgorithm, weights become:\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        printf("%d, ", pGraph->adjaMtx[i][j]);        
      }
      printf("\n");
    }    
}

void shortestPath::WFIUngraphLongest(genGraph* pGraph){
    const int N = pGraph->vNum;
    for(int i=0; i<N; i++)
      for(int j=0;j<N;j++)
        for(int k=0;k<N;k++){
          if(pGraph->adjaMtx[j][i] == MIN || pGraph->adjaMtx[i][k] == MIN)    //skip the unexisting edge
            continue;
          int tmp = pGraph->adjaMtx[j][i] + pGraph->adjaMtx[i][k];
          if(pGraph->adjaMtx[j][k] < tmp)
            pGraph->adjaMtx[j][k] = tmp;
        }
    //output
    printf("WFIalgorithm, weights become:\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        printf("%d, ", pGraph->adjaMtx[i][j]);        
      }
      printf("\n");
    }        
}

/* bug remains
 * */
void shortestPath::WFIGraphLongest(genGraph* pGraph){
    const int N = pGraph->vNum;
    for(int i=0; i<N; i++)
      for(int j=0;j<N;j++)
        for(int k=0;k<N;k++){
          if (j==k)    continue;
          if(pGraph->adjaMtx[j][i] == MIN || pGraph->adjaMtx[i][k] == MIN)    //skip the unexisting edge
            continue;
          int tmp = pGraph->adjaMtx[j][i] + pGraph->adjaMtx[i][k];
          if(pGraph->adjaMtx[j][k] < tmp)
            pGraph->adjaMtx[j][k] = pGraph->adjaMtx[k][j] =tmp;
        }
    //output
    printf("WFIalgorithm, weights become:\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        printf("%d, ", pGraph->adjaMtx[i][j]);        
      }
      printf("\n");
    }        
}
