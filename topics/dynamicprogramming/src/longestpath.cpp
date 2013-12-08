/*
 *<IntroductionToAlgorithm> chapter15 dynamic programming, exercise 15-1 longest simple path from s to t in a directed acyclic graph
 * key words: directed, and acyclic
 *
 * good DP exercise, alternative to min path we have known already
 * prove: 
 * if the longest path from A to F includes D, assume A->(C)->D->(E)->F, then the subpath D->F must be the longest path from D to F.
 * why? if there is another longer path from D to F includes C, it means path occurs from D to C, then cycle occurs between C and D!
 * this is base of our algorithm
 *
 * test data: here apply 0 to the edge (i,j) if this edge does not exist.
 * 0 4 3 0 0 0
 * 0 0 1 0 2 0
 * 0 0 0 1 2 0
 * 0 0 0 0 0 2
 * 0 0 0 0 0 3
 * 0 0 0 0 0 0
 * -------------------
 * 0 3 0 2 0
 * 0 0 2 0 0
 * 0 0 0 0 2
 * 0 2 2 0 3
 * 0 0 0 0 0
 * */
#include "../header/preliminary.h"
#include <queue>

/*
 * 1. iterate vertices in topologic order, use queue to save all new entry vertex
 * 2. for each entry vertice, scan all included vertices if it needs to update its path to t
 * @params:
 *        n : vertices count
 * */
int longestpath(int** adjMtx, int n, int s, int t){
    int* paths = new int[n]();              //paths[i] means path from i to t
    int* entries = new int[n]();            //mark whether vertex has been pushed to queue
    int* pnext = new int[n]();              //pnext[i] means for longest path (i,t), next vertex
    queue<int> vqueue;
    vqueue.push(t);
    entries[t]=1;
    while(!vqueue.empty()){
        int v = vqueue.front();
        vqueue.pop();
        if(v != t){            //update paths[v], while paths[t] = 0
            int* edgesv = adjMtx[v];
            for(int i=0;i<n;++i){           //edgesv[i] means edge (v,i)
                if(i != v && edgesv[i] != 0){
                    if(paths[v] < edgesv[i] + paths[i]){ //update path(v,t) if it < edge(v,i) + path(i,t) 
                        paths[v] = edgesv[i] + paths[i];
                        pnext[v] = i;
                    }
                }
            }
            for(int i=0;i<n;++i){           //update paths[i] if paths[i] < edge(i,v) + paths[v]
                if(i != v && paths[i] > 0 && adjMtx[i][v] != 0 && adjMtx[i][v] + paths[v] > paths[i]){
                    paths[i] = adjMtx[i][v] + paths[v];
                    pnext[i] = v;
                }                  
            }
        }
        for(int i=0;i<n;++i){               //push i if edge (i,v) occurs
            if(i != v && adjMtx[i][v] != 0 && entries[i]==0){
                vqueue.push(i);
                entries[i]=1;
            }
        }    
    }
    int vn = s;
    printf("the longest path from %d to %d is: %d", s, t, vn);
    while(pnext[vn] != 0){
        vn = pnext[vn];
        printf(" -> %d", vn);
    }
    printf("\n");
    int sum = paths[s];
    
    delete[] paths;
    paths = 0;
    delete[] entries;
    entries = 0;
    delete[] pnext;
    pnext = 0;

    return sum;
}

int main(int, char**){
    string str;    
    if(getline(cin, str)==0 || str.empty())
      return 0;
    int n = atoi(str.c_str());
    int** mtx = new int*[n];
    for(int i=0;i<n;++i){
        if(getline(cin, str)==0 || str.empty())
          continue;
        mtx[i] = new int[n]();
        splitStr2IntArray(str, mtx[i]);
    }        
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int s = atoi(str.c_str());
        if(getline(cin, str)==0 || str.empty())
          break;
        int t = atoi(str.c_str());
        int res = longestpath(mtx, n, s, t);
        printf("the longest path is %d\n", res);
    }

    for(int i=0;i<n;++i){
        delete[] mtx[i];
        mtx[i]=0;
    }
    delete[] mtx;
    mtx=0;
    return 0;
}
