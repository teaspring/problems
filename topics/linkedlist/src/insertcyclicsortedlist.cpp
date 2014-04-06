/*
 * from leetcode
 * given a node from a cyclic linked list which has been sorted. write a function to insert a value into the list which remains
 * as cyclic sorted list. the given node can be any single node in the list
 *
 * >>it needs careful process of edge cases where value to insert
 * test case: ascending list and decending list, and position to insert can be normal within the list or between tail and head.
 * */
#include "../header/preliminary.h"

struct node{
    int val;
    node *next;
    node(int v): val(v), next(NULL){}
};

void insertNode(node* prev, node* next, int v){
    node* curr = new node(v);
    prev->next = curr;
    curr->next = next;
    return;
}

/*
 * for 3 elements 
 * if in ascending order, 3 cases in total: [1,2,4], [2,4,1], [4,1,2]
 * if in decending order, 3 cases in total: [4,2,1], [2,1,4], [1,4,2]
 * */
bool isAscending(node *pnode){
    node *prev = pnode, *curr = prev->next, *post = curr->next;
    if(post == prev){
        return true;        //only two nodes, either ascending or descending is right
    }
    if(prev->val < curr->val){
        return (curr->val < post->val || prev->val > post->val);
    }
    if(prev->val > curr->val){
        return !(curr->val > post->val || prev->val < post->val);
    }
    return true;    // it should not reach this line
}

void insert_01(node *pnode, int v){  // assume ascending order
    if(pnode == NULL)        return;
    if(pnode->next == pnode){    // only one node in list
        insertNode(pnode, pnode, v);
        return;
    }
    bool ascending = isAscending(pnode);
    node *curr = pnode, *post = pnode->next;
    do{
        if(ascending){
            if((curr->val < v && v < post->val)
            || (curr->val > post->val && (curr->val < v || v < post->val))){
                insertNode(curr, post, v);
                return;
            }
        }else{
            if((curr->val > v && v > post->val)
            || (curr->val < post->val && (curr->val > v || v > post->val))){
                insertNode(curr, post, v);
                return;
            }
        }
        curr = post;
        post = post->next;
    }while(curr != pnode);
    
    insertNode(curr, post, v);
    return;
}

void showCycleSLL(node *pnode){
    if(pnode == NULL)    return;
    node *curr = pnode;
    printf("cyclic sorted list is: ");
    do{
        printf("%d ", curr->val);
        curr = curr->next;
    }while(curr != pnode);
    printf("\n");
    return;
}

void delCycleSLL(node *head){
    if(head == NULL)    return;
    node *curr = head->next;
    while(curr != head){
        node *h = curr->next;
        delete curr;
        curr = h;
    }
    delete curr;
    curr = 0;
    return;
}

void test_01(){
    string str;
    while(1){
        printf("please input integers value in order:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        if(n<1)        break;
        node *head = new node(arr[0]);
        node *h = head;
        for(int i=1; i<n; ++i){
            h->next = new node(arr[i]);
            h = h->next;
        }
        h->next = head;
        delete[] arr;

        printf("please input integer of node to insert:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int a = atoi(str.c_str());

        printf("please input input node of cyclc SLL:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int k = atoi(str.c_str());
        for(int i=0; i<k; ++i){   // now h is previous of real head 
            h = h->next;
        }
        insert_01(h, a);
        showCycleSLL(h);
        delCycleSLL(h);
        h = NULL;
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}

