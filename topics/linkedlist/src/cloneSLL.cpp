/*
 * problem on leetcode. 
 * one SLL which node has another pointer of 'random' which points to one other node in the SLL randomly. Q: copy the SLL
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include "stdlib.h"

using namespace std;

const int CSIZE = 11;

struct ranSLLNode{
    char* cValue;
    ranSLLNode* pNext;
    ranSLLNode* pRandom;

    ranSLLNode(): pNext(0), pRandom(0){
        cValue = new char[CSIZE];
        memset(cValue, 0, CSIZE);
    }
    ~ranSLLNode(){
        delete cValue;
        cValue=0;
        pNext=0;
        pRandom=0;
    }
};

/*
 * no extra space, but through 3 iterations. pay time for space
 * */
ranSLLNode* cloneRandomSLL(ranSLLNode* srcHeader){
    ranSLLNode* curr = srcHeader;
    while(curr != 0){                            //create new node one after each source node 
        ranSLLNode* nNode = new ranSLLNode();
        strcpy(nNode->cValue, curr->cValue);
        nNode->cValue[strlen(curr->cValue)]='\0';
        nNode->pRandom = curr->pRandom;
        nNode->pNext = curr->pNext;
        curr->pNext = nNode;
        curr = nNode->pNext;
        nNode = 0;
    }

    curr=srcHeader;
    while(curr != 0){                            //set pRandom of new node be new node
        curr->pNext->pRandom = curr->pRandom->pNext;
        curr = curr->pNext->pNext;
    }
    
    curr = srcHeader;
    ranSLLNode* next = curr->pNext;
    ranSLLNode* nHeader = next;
    while(next != 0){                            //unplug new node and source node
        curr->pNext = next->pNext;
        curr = next;
        next = curr->pNext;
    }

    curr=0;
    next = 0;
    return nHeader;
}

/*
 * with a map of [initial, copy], but just once iteration. pay space for time
 * */
ranSLLNode* clone_02(ranSLLNode* phead){
    map<ranSLLNode*, ranSLLNode*> mnodes;
    ranSLLNode *curr = phead;
    while(1){
        if(mnodes.find(curr) == mnodes.end()){
            ranSLLNode *p = new ranSLLNode;
            p->cValue = curr->cValue;
            mnodes[curr] = p;
        }

        if(mnodes.find(curr->pRandom) == mnodes.end()){
            ranSLLNode *p = new ranSLLNode;
            p->cValue = curr->pRandom->cValue;
            mnodes[curr->pRandom] = p;
            mnodes[curr]->pRandom = p;
        }else{
            mnodes[curr]->pRandom = mnodes[curr->pRandom];
         }
        
        if(curr->pNext != 0){
            if(mnodes.find(curr->pNext) == mnodes.end()){
                ranSLLNode *p = new ranSLLNode();
                p->cValue = curr->pNext->cValue;
                mnodes[curr->pNext] = p;
                mnodes[curr]->pNext = p;
            }else{
                mnodes[curr]->pNext = mnodes[curr->pNext];
            }
        }else{        //reach tail, exit
            mnodes[curr]->pNext = 0;
            break;
        }        
    }
    return mnodes[phead];
}

void showRandomSLL(ranSLLNode* header){
    ranSLLNode* curr = header;
    printf("iterate the SLL:\n");
    while(curr != 0){
        printf("value: %s, random: %s\n", 
                curr->cValue, curr->pRandom==0 ? "null" : curr->pRandom->cValue);
        curr = curr->pNext;
    }
    curr = 0;
}

void delRandomSLL(ranSLLNode* header){
    ranSLLNode* curr = header;
    while(curr != 0){            //reset the random pointer
        curr->pRandom = 0;
        curr = curr->pNext;
    }
    curr = header;
    while(curr != 0){
        ranSLLNode* next = curr->pNext;
        delete curr;
        curr = next;
        next = 0;
    }
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        printf("input size of linked list:\n");
        if(getline(cin, str)==0 || str.empty())
          break;
        int count = atoi(str.c_str());
        ranSLLNode *header=0, *curr=0;
        for(int i=0;i<count;i++){
            printf("the %dth node is:\n", i);
            getline(cin, str);
            ranSLLNode* tmp = new ranSLLNode();
            strcpy(tmp->cValue, str.c_str());
            tmp->cValue[str.size()]='\0';
            if(header == 0){
                header=tmp;
            }else{
                curr->pNext=tmp;
            }
            curr=tmp;
            tmp=0;
        }
        curr=header;
        while(curr != 0){                    //set random pointer to be next of next
            ranSLLNode* next = curr;
            for(int i=0;i<2;i++){
                next = next->pNext;
                if(next == 0)    
                  next = header;
            }
            curr->pRandom = next;
            curr = curr->pNext;
            next=0;
        }
        curr=0;
        showRandomSLL(header);

        ranSLLNode* nHeader = cloneRandomSLL(header);
        showRandomSLL(nHeader);
        
        delRandomSLL(header);
        delRandomSLL(nHeader);
        header=0;
        nHeader=0;
    }
    return 0;
}
