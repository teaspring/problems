/*
 * given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where candidate number sum to T.
 * ps, the same number in candidates can be chosen from C unlimited number of times.
 * all numbers are positive integers, and elements in a combination must be non-decending order without duplicate combinations.
 *
 * test case:
 * S=[2,3,7], target=7
 * output: [2,2,3], [7]
 * */
#include "../include/preliminary.h"
#include <algorithm>

void plusSum(vector<vector<int> >& res, const vector<int>& candidates, vector<int>& vec, int target){
    if(target==0){
        res.push_back(vec);
        return;
    }
    int n = candidates.size();
    for(int i=0;i<n;++i){
        int d = candidates[i];
        if(target < d)    break;
        if(!vec.empty() && vec[vec.size()-1] > d)        continue;
        vec.push_back(d);
        plusSum(res, candidates, vec, target - d);
        vec.pop_back();
    }
    return;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());  //sort candidates in ascending order 
    vector<vector<int> > res;
    vector<int> vec;
    plusSum(res, candidates, vec, target);
    return res;
}

/*********************test**************************/
void displayVecVec(const vector<vector<int> >& combinations){
    int n = combinations.size();
    for(int i=0; i<n; ++i){
        int m = combinations[i].size();
        printf("[");
        if(m>0)        printf("%d", combinations[i][0]);
        for(int j=1; j<m; ++j){
            printf(", %d", combinations[i][j]);
        }
        printf("]\n");
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
