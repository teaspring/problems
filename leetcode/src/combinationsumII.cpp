/*
 * given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where candidate number sum to T.
 * ps, 
 * 1.the same number in candidates can be chosen from C with only once
 * 2.all numbers are positive integers with repeated value in possible
 * 3.all elements in a combination must be non-decending order without duplicate combinations.
 * */
#include "../header/preliminary.h"
#include <algorithm>

void putStk2Vector(const vector<int>& candidates, stack<int>& stk, vector<int>& vec){
    stack<int> stk2;
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    //printf("index: ");
    while(!stk2.empty()){
        stk.push(stk2.top());
        vec.push_back(candidates[stk.top()]);
        //printf("%d ", stk.top());
        stk2.pop();
    }
    //printf("\n");
    return;
}

void plusSum(vector<vector<int> >& res, 
             const vector<int>& candidates, 
             stack<int>& stk,  //stk to push index in candidates 
             int target){
    if(target==0){
        vector<int> vec;
        putStk2Vector(candidates, stk, vec);
        res.push_back(vec);
        return;
    }
    int n = candidates.size();
    int last = stk.empty() ? 0 : stk.top()+1;
    for(int i=last;i<n;++i){
        if(target < candidates[i])        break;
        if(i>last &&  candidates[i] == candidates[last])    continue;  //key to skip duplicat combinations
        stk.push(i);
        plusSum(res, candidates, stk, target - candidates[i]);
        stk.pop();
        last=i;
    }
    return;
}

vector<vector<int> > combinationSumII(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());  //sort in ascending order 
    vector<vector<int> > res;
    stack<int> stk;
    plusSum(res, candidates, stk, target);
    return res;
}

void displayVecVec(const vector<vector<int> >& combinations){
    for(size_t i=0; i<combinations.size(); ++i){
        for(size_t j=0; j<combinations[i].size(); ++j){
            printf("%d ", combinations[i][j]);
        }
        printf("\n");
    }
}

void test_01(){
    string str;
    while(1){
        printf("please input positive integer candidates:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> candi;
        for(int i=0;i<n;++i){
            candi.push_back(arr[i]);
        }

        printf("please input target integer:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int t = atoi(str.c_str());
        vector<vector<int> > res = combinationSumII(candi, t);
        displayVecVec(res);
    }
}

int main(int, char**){
    test_01();
    return 0;
}
