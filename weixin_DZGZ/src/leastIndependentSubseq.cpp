/*
 * problem on Oct 18, least independent subsequence(LIS)
 * for LIS in BST, if one node in, parent or child of it is not in
 * 
 * typical dynamic programming
 * dp[0][x] = sum{max{dp[0][y], dp[1][y]}}, y is every child of x   # x not in
 * dp[1][x] = sum{dp[0][y]} + x,            y is every child of x   # x in
 * dp[0][leaf] = 0
 * dp[1][leaf] = 1
 * finally, result is max{dp[0][root], dp[1][root]}
 * above indicates a bottom-up solution, so, post order iterate??
 *
 * in BST, leaf nodes around n/2. so tnat for LIS, all leaf nodes are always in
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>

using namespace std;

struct bstNode{                        //input data
    int val;
    bstNode *left;
    bstNode *right;
    bstNode(int v, bstNode* pl, bstNode* pr):val(v), left(pl), right(pr){
    }
    virtual ~bstNode(){
        delete left;
        left = 0;
        delete right;
        right = 0;
    }
};

struct nodeLIS{
    set<int> inLIS;
    set<int> outLIS;
};

map<int, nodeLIS*> LISMap;

void mergeset(set<int>& dst, set<int>& src){
    set<int>::const_iterator iter = src.begin();
    for(;iter != src.end();iter++){
        if(dst.count(*iter)==0){            // set<int>.find() returns iterator
            dst.insert(*iter);
        }
    }
    return;
}

void importOutLIS(set<int>& outLIS, nodeLIS* pChild){
    if(pChild->inLIS.size() > pChild->outLIS.size()){
        mergeset(outLIS, pChild->inLIS);
    }else{
        mergeset(outLIS, pChild->outLIS);
    }
    return;
}

void postIter(bstNode* root){   // post-order iterate make it bottom-up
    if(root == 0)    return;
    postIter(root->left);
    postIter(root->right);
    nodeLIS *pcurr = new nodeLIS();
    if(root->left != 0){
        importOutLIS(pcurr->outLIS, LISMap[root->left->val]);
        mergeset(pcurr->inLIS, LISMap[root->left->val]->outLIS);
    }
    if(root->right != 0){
        importOutLIS(pcurr->outLIS, LISMap[root->right->val]);
        mergeset(pcurr->inLIS, LISMap[root->right->val]->outLIS);
    }
    pcurr->inLIS.insert(root->val);
    
    LISMap[root->val] = pcurr;
    pcurr=0;
    if(root->left != 0){                    //release unused child LIS object
        LISMap.erase(root->left->val);
    }
    if(root->right != 0){
        LISMap.erase(root->right->val);
    }
    return;
}

void displayset(set<int>& iset){
    printf("LIS of %d in total: ", iset.size());
    set<int>::const_iterator iter = iset.begin();
    for(;iter != iset.end();iter++){
        printf("%d ", *iter);
    }
    return;
}

void findLeastIndependentSubsequence(bstNode* root){
    postIter(root);
    nodeLIS* pcurr = LISMap[root->val];
    if(pcurr->inLIS.size() > pcurr->outLIS.size()){
        displayset(pcurr->inLIS);
    }else{
        displayset(pcurr->outLIS);
    }
    return;
}

int main(int argc, char* argv[]){                //assume node of BST has distinct value
    bstNode* node3 = new bstNode(3,0,0);
    bstNode* node6 = new bstNode(6, node3, 0);
    bstNode* node5 = new bstNode(5,0,0);
    bstNode* node8 = new bstNode(8, node6, node5);
    bstNode* node2 = new bstNode(2,0,0);
    bstNode* node11 = new bstNode(11,node2,0);
    bstNode* node7 = new bstNode(7,0,0);
    bstNode* node9 = new bstNode(9, node11, node7);
    bstNode* root = new bstNode(10, node8, node9); 

    findLeastIndependentSubsequence(root);

    LISMap.erase(root->val);
    delete root;                //all children node object will be release in the serial process
    root = 0;
    return 0;
}

