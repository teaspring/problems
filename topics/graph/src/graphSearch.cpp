/*
 * */
#include "../include/genGraph.h"

class Solution{

public:
    /*
     * simple implementation of BFS
     * */
    vector<int> BFS01(Point* begin){
        vector<int>    res;

        queue<Point*> _q;
        _q.push(begin);

        while(!_q.empty()){
            Point *parent = _q.front();

            if(NULL != parent->Left)    _q.push(parent->Left);

            if(NULL != parent->Mid)     _q.push(parent->Mid);

            if(NULL != parent->Right)    _q.push(parent->Right);

            parent->Cov = Covered;
            res.push_back(parent->value);

            _q.pop();
        }

        return res;
    }

    /*
     *
     * */
    vector<int> DFS01(Point* begin){
        vector<int> res;

        stack<Point*> _stack;
        _stack.push(begin);

        while(!_stack.empty()){
            Point* parent = _stack.top();

            Point* child = FindNextChild(parent);

            if(NULL != child){
                child->Cov = Probed;
                _stack.push(child);
            }else{
                parent->Cov = Covered;
                res.push_back(parent->value);

                _stack.pop();
            }
        }

        return res;
    }

private:
    /*
     * used by DFS01()
     * */
    Point* FindNextChild(Point* pParent){
        if(pParent->Cov == Covered)        return NULL;

        Point *pp = pParent->Left;
        if(NULL != pp && pp->Cov == NoProbed)    return pp;

        pp = pParent->Mid;
        if(NULL != pp && pp->Cov == NoProbed)    return pp;

        pp = pParent->Right;
        if(NULL != pp && pp->Cov == NoProbed)    return pp;

        return NULL;
    }

};

/* unit test is in ../unittest/graphSearch_unittest */
