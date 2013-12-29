/*
 * from leetcode, lowest common ancestor of two given nodes in a binary tree part II. each node contains another pointer pointing to its parent.
 * note that given two NODES, not the value encapsulated in node.
 * one more parent pointer? it hints 
 * 1. traverse upward from two given nodes to root, store travesed node to hash_set(unordered_set)       ----- solution 1 
 * 2. calculate the distance from the node to root, move two nodes forwards starting from the same depth ----- solution 2
 *
 * compile constraint:
 * as <unordered_set> replaces <ext/hash_set>, add std=c++0x in compile option
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>    //told by backward_warning.h, it is replacement of <ext/hash_set> in c++0x

using namespace std;

struct node{
    int val;
    node* parent;
    node* left;
    node* right;
    node(int v, node* p):val(v),parent(p),left(0),right(0){}
    virtual ~node(){}
};

/*
 * solution 1
 * */
node* LCA_01(node *root, node *p, node *q){
    unordered_set<node*> visited;            //instead of hash_set
    while(p || q){
        if(p){
            if(!visited.insert(p).second)    //pair<iterator, bool> unordered_set::insert(T _value) 
              return p; //insert p failed(p exists in the table)
            p = p->parent;
        }
        if(q){
            if(!visited.insert(q).second)
              return q; //insert q failed(q exists in the table)
            q = q->parent;
        }
    }
    return 0;
}

/*
 * solution 2
 * */
int getHeight(node *p){        //height of root is 1
    int height=0;
    while(p){
        height++;
        p = p->parent;
    }
    return height;
}

template<typename T>
void myswap(T* pa, T* pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp = 0;
}

node *LCA(node *p, node *q){
    int h1 = getHeight(p);
    int h2 = getHeight(q);
    if(h1 > h2){
        myswap<int>(&h1, &h2);
        myswap<node*>(&p, &q);
    }

    int dh = h2 - h1;    //invariant: h1 <= h2, p is higher than q
    for(int h=0;h<dh;h++)
      q = q->parent;        //boost lower q to depth of p
    while(p && q){
        if(p == q)    return p;
        p = p->parent;
        q = q->parent;
    }
    return 0;    //p and q are not in one tree
} 

int main(int, char**){
    return 0;
}
