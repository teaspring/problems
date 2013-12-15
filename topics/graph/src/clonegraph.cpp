/*
 * from leetcode.
 * clone a graph. input is a Node pointer, return the Node pointer of the cloned graph.
 * struct Node{
 *     int val;   //added by me to present content
 *     vector neighbors;
 * }
 * 
 * the main problem to solve is when clone A' of A, the neighbor nodes of A' are not constructed yet. similar to clone SLL with random pointer  
 * two methods to iterate graph: BFS and DFS. here I choose BFS
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct Node{
    int val;
    vector<Node*> neighbors;
};

/*
 * 1.this graph is directed certainly, because for the edge A->B, B must appear in neighbors of A
 * 2.don't forget the case there is cycle between A and B, A<->B. don't imply infinitely loop in iteration
 *
 * without map, but with twice iterations. pay time for space
 * */
Node* clonegraph_01(Node* pnode){
    set<Node*> snodes;
    queue<Node*> qnodes;
    qnodes.push(pnode);
    snodes.insert(pnode);
    while(!qnodes.empty()){    //1st iteration to append cloned A' to neighbors of A
        Node* curr = qnodes.front();
        qnodes.pop();
        vector<Node*>::const_iterator iter = curr->neighbors.begin();
        for(;iter != curr->neighbors.end();++iter){
            if(snodes.find(*iter) == snodes.end()){    //Node* not pushed yet
                qnodes.push(*iter);
                snodes.insert(*iter);
            }
        }
        Node* clone = new Node;
        clone->val = curr->val;
        curr->neighbors.push_back(clone);    //append clone at tail
    }
    snodes.clear();

    qnodes.push(pnode);
    snodes.insert(pnode);
    Node* npnode = pnode->neighbors.back(); //pointer to return
    while(!qnodes.empty()){
        Node* curr = qnodes.front();
        qnodes.pop();
        Node* clone = curr->neighbors.back();
        vector<Node*>::iterator iter = curr->neighbors.begin();
        for(;iter != curr->neighbors.end()-1;++iter){
            if(snodes.find(*iter) == snodes.end()){
                qnodes.push(*iter);
            }
            clone->neighbors.push_back((*iter)->neighbors.back());  //push clone to neighbors of clone
        }
        curr->neighbors.erase(iter);    //now iter points to A' of A 
    }
    return npnode;
}

/*
 * using map with only once iteration. pay space for time
 * */
Node* clonegraph_02(Node *graph){
    if(!graph)
      return NULL;
    map<Node*, Node*> gmap;        //[initial, copy]
    queue<Node*> q;
    q.push(graph);

    Node *graphCopy = new Node;
    graphCopy->val = graph->val;
    gmap[graph] = graphCopy;
    
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for(int i=0;i<n;++i){
            Node *neighbor = node->neighbors[i];
            if(gmap.find(neighbor) == gmap.end()){    //no copy exist in map
                Node *p = new Node;
                p->val = neighbor->val;
                gmap[node]->neighbors.push_back(p);
                gmap[neighbor] = p;
            }else{
                gmap[node]->neighbors.push_back(gmap[neighbor]);
            }
        }
    }
    return graphCopy;
}

int main(int, char**){
    return 0;
}

