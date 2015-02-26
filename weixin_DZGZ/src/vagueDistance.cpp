/*
 * question on Aug15.
 * input is serials of {1,0}, e.g.1111, 1000, 101, 1101. every two serial compare, the vague distance is the left serial lengths sum excluding common sequences of two serial.
 * 
 * test data:
 * 1111, 101, 0001, 10101
 * */
#include "../header/preliminary.h"
#include <stack>
using namespace std;

class bitNode{
public:
    char val;
    bitNode* parent;
    bitNode* left;            // '1'
    bitNode* right;            // '0'
    int lDepth;
    int rDepth;
    bitNode(char c, bitNode* pPar)
        :val(c)
        ,parent(pPar)
        ,left(0)
        ,right(0)
        ,lDepth(0)
        ,rDepth(0){}
    ~bitNode();
};

bitNode::~bitNode(){        //not delete other node* except its own
    left = 0;
    right = 0;
    parent = 0;
}

class bitTrie{
public:
    bitTrie():root(new bitNode('2', 0)), maxDist(0){}
    ~bitTrie();
    void insertStr(const string& str);
    int getGreatestVague();
    void iterPostOrder();
private:
    void delTree();
    bitNode* insertNode(char c, bitNode *parent);
    void updateAncestorDepth(bitNode*);
    void visit(bitNode*);
        
    bitNode* root;
    int maxDist;
};

bitTrie::~bitTrie(){
    //delTree();            
    root=0;
}

int bitTrie::getGreatestVague(){
    return maxDist;    
}

//BFS
void bitTrie::delTree(){    
}

void bitTrie::visit(bitNode* p){
    printf("%c ", p->val);
}

/*
 * not needed by this question. just for fun
 * */
void bitTrie::iterPostOrder(){    
    stack<bitNode*> stk;
    bitNode *p=root, *q=root;
    while(p != 0){
        while(p->left != 0){
            stk.push(p);
            p = p->left;
        }
        while(p->right == 0 || p->right == q){
            visit(p);
            if(stk.empty())    return;
            q = p;
            p = stk.top();
            stk.pop();
        }
        stk.push(p);            //V which is poped right now, is pushed once again ahead of right child
        p = p->right;
    }
}

void bitTrie::insertStr(const string& str){
    bitNode *curr=root;
    size_t pos = 0;
    for(;pos<str.size();pos++){
        if(str[pos] != '1' && str[pos] != '0')
          continue;
        curr = insertNode(str[pos], curr);
    }
    return;
}

/*
 * key method1
 * */
bitNode* bitTrie::insertNode(char c, bitNode *parent){
    bitNode* curr = 0;
    if(c == '1'){                            //
        if(parent->left == 0){
            parent->left = new bitNode(c, parent);
            parent->lDepth += 1;
            updateAncestorDepth(parent);
        }
        curr = parent->left;
    }else if(c == '0'){
        if(parent->right == 0){
            parent->right = new bitNode(c, parent);
            parent->rDepth += 1;
            updateAncestorDepth(parent);
        }
        curr = parent->right;
    }else
      return 0;    
    return curr;
}

/*
 * key method2
 * be careful about it,just update those node's rdepth or ldepth if it has to 
 * */
void bitTrie::updateAncestorDepth(bitNode *pNode){
    if(pNode == 0)    return;
    bitNode* curr = pNode;
    bitNode* par = pNode->parent;
    int tmp = pNode->lDepth + pNode->rDepth;
    if(tmp > maxDist)
      maxDist = tmp;
    while(par != 0){                                    //potential bug!!!
        int greater = curr->lDepth > curr->rDepth ? curr->lDepth : curr->rDepth;
        if(curr == par->left){
            if(par->lDepth < greater+1)
              par->lDepth = greater+1;
        }else{
            if(par->rDepth < greater+1)
              par->rDepth = greater+1;
        }
        int tmp = par->lDepth + par->rDepth;
        if(tmp > maxDist)            //as we have lDepth and rDepth at each node,we can save the traverse 
          maxDist = tmp;
        curr = par;
        par = par->parent;
    }
    par=0;
    curr=0;
    return;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        bitTrie* pTrie = new bitTrie();
        cin>>str;
        int n = atoi(str.c_str());
        if(n<1)    break;
        for(int i=0;i<n;++i){
            str.clear();
            cin>>str;
            pTrie->insertStr(str);
        }
        printf("the longest vague distance is %d\n", pTrie->getGreatestVague());
        delete pTrie;
        pTrie = 0;
    }
    return 0;
}
