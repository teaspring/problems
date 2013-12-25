/*
 * from leetcode, but popular problem. given a binary tree, find the lowest common ancestor of a binary tree 
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v), left(0), right(0){}
    virtual ~node(){}
};

/*
 * solution 1
 * it is said to be "top-down". I think it brings in more complexity with repeated search in left half in some case.
 * */
int countMatchesPQ(node *root, node *p, node *q){
    if(!root)
      return 0;
    int matches = countMatchesPQ(root->left, p, q) + countMatchesPQ(root->right, p, q);
    if(root==p || root ==q)
      return 1+matches;
    else
      return matches;
}

node *LCA(node *root, node *p, node *q){
    if(!root || !p || !q)    
      return 0;
    if(root==p || root==q)
      return root;
    int totalMatches = countMatchesPQ(root->left, p, q);
    if(totalMatches == 1){
        return root;        //the other matched must exist in right half, so return root as LCA
    }else if(totalMatches == 2){
        return LCA(root->left, p, q);  //both of p and q in left half, now dig in it. this brings repeated search! 
    }else{
        return LCA(root->right, p, q); //neither of p and q in left half, dig in right half which is never searched
    }
}

/*
 * solution 2
 * it is said to be "bottom-up". I think it is excellent at utilizing own function recursively. 
 * really refined code, without repeated search. worst in time O(n)
 * */
node* LCA_02(node *root, node *p, node *q){
    if(!root)
      return 0;
    if(root == p || root == q)
      return root;            //bottom return, return the node of exact p or q
    node *L = LCA(root->left, p, q);
    node *R = LCA(root->right, p, q);
    if(L && R)
      return root;            //finally return, the required LCA of p and q
    return L ? L : R;         //intermediate return, by parent of found p/q 
}

int main(int, char**){
    return 0;
}

