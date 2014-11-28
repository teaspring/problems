/*
 * design a stack that supports push, pop, and retrieving the minimum element in time O(1)
 * void push(x)
 * void pop()
 * int top()
 * int getMin()
 * */
#include "../include/preliminary.h"

/*
 * solution 1: in use of vector<> which leads to Memory Limit Error
 * */
struct element{
    int val;
    int minBelow;
    element(int v, int b): val(v), minBelow(b){}
};

class MinStackI{
public:
    void push(int x){
        int n = mVec.size();
        if(mVec.empty()){
            mVec.push_back(element(x, x));
        }else{
            mVec.push_back(element(x, min(x, mVec[n-1].minBelow)));
        }
        return;
    }

    void pop(){
        if(!mVec.empty())        mVec.pop_back();
        return;
    }

    int top(){
        return mVec.empty() ? 0 : mVec[mVec.size()-1].val;
    }

    int getMin(){
        return mVec.empty() ? 0 : mVec[mVec.size()-1].minBelow;
    }
private:
    vector<element> mVec;
};

/*
 * solution 2: in use of double linked list(DLL)
 * */
struct node{
    int val;
    int minFront;
    node* pre;
    node* next;
    node(int v, int f, node* p): val(v), minFront(f), pre(p), next(NULL){}
};

class MinStackII{
public:
    void push(int x){
        if(!mTail){
            mHead = new node(x, x, NULL);
            mTail = mHead;
        }else{
            mTail->next = new node(x, min(x, mTail->minFront), mTail);
            mTail = mTail->next;
        }
    }

    void pop(){
        if(!mTail)    return;
        node* tmp = mTail;
        mTail = mTail->pre;
        if(mTail)    mTail->next = NULL;
        tmp->pre = NULL;
        delete tmp;
        if(!mTail)    mHead = NULL;    // cannot be forgotten !
        return;
    }

    int top(){
        if(!mTail)    return 0;
        return mTail->val;
    }

    int getMin(){
        if(!mTail)    return 0;
        return mTail->minFront;
    }

public:
    MinStackII(): mHead(NULL), mTail(NULL){}
    virtual ~MinStackII(){
        while(mHead){
            node* tmp = mHead;
            mHead = mHead->next;
            tmp->next = NULL;
            mHead->pre = NULL;
            delete tmp;
        }
        mTail = NULL;
    }

private:
    node* mHead;
    node* mTail;
};
