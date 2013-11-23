/*
 * <IntroductionToAlgorithm> chapter15, exercise 15-6 Planning a company party
 * company has a hierarchical structure like tree, each employee has a conviviality(passion) rating.
 * rule: an employee and its immediate supervisor are not wanted to attend both(independent subsequence)
 * 
 * concept: in a tree, IS means for each node in the result set, parent or child of it is not in there
 * 
 * typical dynamic programming
 * dp[0][x] = sum{max{dp[0,1][y is child of x]}}
 * dp[1][x] = sum{dp[0][y is child of x]} + x
 * dp[0][leaf] = 0
 * dp[1][leaf] = 1
 * finally, result is max{dp[0][r], dp[1][r]}
 * 
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>

using namespace std;

struct bstNode{                        //input data
    int passion;
    bstNode *left;
    bstNode *right;
    bstNode(int v, bstNode* pl, bstNode* pr):passion(v), left(pl), right(pr){
    }
    virtual ~bstNode(){
        delete left;
        left = 0;
        delete right;
        right = 0;
    }
};

struct nodeIS{
    set<int> inIS;
    set<int> outIS;
};

map<int, nodeIS*> ISMap;

int sumset(const set<int>& iset){
    int res=0;
    set<int>::const_iterator iter = iset.begin();
    for(;iter != iset.end();iter++){
        res += *iter;
    }
    return res;
}

bool compareSet(const set<int>& lset, const set<int>& rset){
    int lsum = sumset(lset);
    int rsum = sumset(rset);
    return lsum > rsum;
}

void mergeset(set<int>& dst, const set<int>& src){
    set<int>::const_iterator iter = src.begin();
    for(;iter != src.end();iter++){
        if(dst.count(*iter)==0){            // set<int>.find() returns iterator
            dst.insert(*iter);
        }
    }
    return;
}

void importOutIS(set<int>& outIS, const nodeIS* pChild){
    if(compareSet(pChild->inIS, pChild->outIS)){                //compare sum of passion
        mergeset(outIS, pChild->inIS);
    }else{
        mergeset(outIS, pChild->outIS);
    }
    return;
}

void postIter(bstNode* root){
    if(root == 0)
      return;
    postIter(root->left);
    postIter(root->right);
    nodeIS *pcurr = new nodeIS();
    if(root->left != 0){
        importOutIS(pcurr->outIS, ISMap[root->left->passion]);
        mergeset(pcurr->inIS, ISMap[root->left->passion]->outIS);
    }
    if(root->right != 0){
        importOutIS(pcurr->outIS, ISMap[root->right->passion]);
        mergeset(pcurr->inIS, ISMap[root->right->passion]->outIS);
    }
    pcurr->inIS.insert(root->passion);
    
    ISMap[root->passion] = pcurr;
    pcurr=0;
    if(root->left != 0){                    //release unused child IS object
        ISMap.erase(root->left->passion);
    }
    if(root->right != 0){
        ISMap.erase(root->right->passion);
    }
    return;
}

void displayset(set<int>& iset){
    printf("independent sub sequence with maximum passion are: ");
    set<int>::const_iterator iter = iset.begin();
    for(;iter != iset.end();iter++){
        printf("%d ", *iter);
    }
    return;
}

void findLeastIndependentSubsequence(bstNode* root){
    postIter(root);
    nodeIS* pcurr = ISMap[root->passion];
    if(compareSet(pcurr->inIS, pcurr->outIS)){
        displayset(pcurr->inIS);
    }else{
        displayset(pcurr->outIS);
    }
    return;
}

int main(int argc, char* argv[]){                //assume node of BST has distinct passionue
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

    ISMap.erase(root->passion);
    delete root;                //all children node object will be release in the serial process
    root = 0;
    return 0;
}

