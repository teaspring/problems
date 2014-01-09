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

struct RandomListNode{
    int label;
    RandomListNode* next;
    RandomListNode* random;

    RandomListNode(int x): label(x), next(0), random(0){
    }
    ~RandomListNode(){
        next=0;
        random=0;
    }
};

/*
 * no extra space, but through 3 iterations. pay time for space
 * */
RandomListNode* cloneRandomSLL(RandomListNode *head){
    if(!head)    return NULL;            //NULL input must be considered
    RandomListNode* curr = head;
    while(curr != 0){                            //create new node one after each source node 
        RandomListNode* nNode = new RandomListNode(curr->label);
        nNode->random = curr->random;
        nNode->next = curr->next;
        curr->next = nNode;
        curr = nNode->next;
        nNode = 0;
    }

    curr=head;
    while(curr != 0){                            //set random of new node be new node
        if(curr->random != NULL){    //NULL random pointer must be considered!!!
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    curr = head;
    RandomListNode* next = curr->next;
    RandomListNode* nHeader = next;
    while(next != 0){                            //unplug new node and source node
        curr->next = next->next;
        curr = next;
        next = curr->next;
    }

    curr=0;
    next = 0;
    return nHeader;
}

/*
 * with a map of [initial, copy], but just once iteration. pay space for time.
 * from oj.leetcode judge, this solution is not recommended as it cost more structure
 * */
RandomListNode* clone_02(RandomListNode* phead){
    if(phead==NULL)        return NULL;
    map<RandomListNode*, RandomListNode*> mnodes;
    RandomListNode *curr = phead;
    while(1){
        if(mnodes.find(curr) == mnodes.end()){
            RandomListNode *p = new RandomListNode(curr->label);
            mnodes[curr] = p;
        }
        
        if(curr->random!=NULL){
            if(mnodes.find(curr->random) == mnodes.end()){
                RandomListNode *p = new RandomListNode(curr->random->label);
                mnodes[curr->random] = p;
                mnodes[curr]->random = p;
            }else{
                mnodes[curr]->random = mnodes[curr->random];
            }
        }
        
        if(curr->next != 0){
            if(mnodes.find(curr->next) == mnodes.end()){
                RandomListNode *p = new RandomListNode(curr->next->label);
                mnodes[curr->next] = p;
                mnodes[curr]->next = p;
            }else{
                mnodes[curr]->next = mnodes[curr->next];
            }
        }else{        //reach tail, exit
            mnodes[curr]->next = 0;
            break;
        }        
    }
    return mnodes[phead];
}

void showRandomSLL(RandomListNode* head){
    RandomListNode* curr = head;
    printf("iterate the SLL:\n");
    while(curr != 0){
        printf("value: %d, random: %d\n", 
                curr->label, curr->random==0 ? -1 : curr->random->label);
        curr = curr->next;
    }
    curr = 0;
}

void delRandomSLL(RandomListNode* head){
    RandomListNode* curr = head;
    while(curr != 0){            //reset the random pointer
        curr->random = 0;
        curr = curr->next;
    }
    curr = head;
    while(curr != 0){
        RandomListNode* next = curr->next;
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
        RandomListNode *head=0, *curr=0;
        for(int i=0;i<count;i++){
            printf("the %dth node is:\n", i);
            getline(cin, str);
            RandomListNode* tmp = new RandomListNode(atoi(str.c_str()));
            if(head == 0){
                head=tmp;
            }else{
                curr->next=tmp;
            }
            curr=tmp;
            tmp=0;
        }
        curr=head;
        while(curr != 0){                    //set random pointer to be next of next
            RandomListNode* next = curr;
            for(int i=0;i<2;i++){
                next = next->next;
                if(next == 0)    
                  next = head;
            }
            curr->random = next;
            curr = curr->next;
            next=0;
        }
        curr=0;
        showRandomSLL(head);

        RandomListNode* nHeader = cloneRandomSLL(head);
        showRandomSLL(nHeader);
        
        delRandomSLL(head);
        delRandomSLL(nHeader);
        head=0;
        nHeader=0;
    }
    return 0;
}
