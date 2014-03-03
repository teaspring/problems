/*
 * given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where candidate number sum to T.
 * ps, the same number in candidates can be chosen from C unlimited number of times.
 * all numbers are positive integers, and elements in a combination must be non-decending order without duplicate combinations.
 * */
#include "../header/preliminary.h"
#include <algorithm>

void putStk2Vector(stack<int>& stk, vector<int>& vec){
    stack<int> stk2;
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    while(!stk2.empty()){
        stk.push(stk2.top());
        vec.push_back(stk.top());
        stk2.pop();
    }
    return;
}

void plusSum(vector<vector<int> >& res, 
             const vector<int>& candidates, 
             stack<int>& stk, 
             int target){
    if(target==0){
        vector<int> vec;
        putStk2Vector(stk, vec);
        res.push_back(vec);
        return;
    }
    int n = candidates.size();
    for(int i=0;i<n;++i){
        int d = candidates[i];
        if(target < d)    break;
        if(!stk.empty() && stk.top() > d)        continue;
        stk.push(d);
        plusSum(res, candidates, stk, target - d);
        stk.pop();
    }
    return;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());  //sort candidates in ascending order 
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
        vector<vector<int> > res = combinationSum(candi, t);
        displayVecVec(res);
    }
}

int main(int, char**){
    test_01();
    return 0;
}
