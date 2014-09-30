/*
 * given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where candidate number sum to T.
 * ps, 
 * 1.the same number in candidates can be chosen from C with only once
 * 2.all numbers are positive integers with repeated value in possible
 * 3.all elements in a combination must be non-decending order without duplicate combinations.
 * */
#include "../include/preliminary.h"
#include <algorithm>

vector<int> index2Values(const vector<int>& candidates, vector<int>& indexes){
    vector<int> values;
    int n = indexes.size();
    for(int i=0; i<n; ++i){
        values.push_back(candidates[indexes[i]]);
    }
    return values;
}

void plusSum(vector<vector<int> >& res, const vector<int>& candidates, vector<int>& vec, int target){
    if(target==0){
        res.push_back(index2Values(candidates, vec));
        return;
    }
    int n = candidates.size();
    int last = vec.empty() ? 0 : vec[vec.size()-1] + 1;
    for(int i=last; i<n; ++i){
        if(target < candidates[i])        break;
        if(i>last &&  candidates[i] == candidates[last])    continue;  //key to skip duplicat combinations
        vec.push_back(i);
        plusSum(res, candidates, vec, target - candidates[i]);
        vec.pop_back();
        last=i;
    }
    return;
}

vector<vector<int> > combinationSum2(vector<int>& num, int target){
    sort(num.begin(), num.end());  //sort in ascending order 
    vector<vector<int> > res;
    vector<int> vec;
    plusSum(res, num, vec, target);
    return res;
}

/**********************test************************/
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
        vector<vector<int> > res = combinationSum2(candi, t);
        displayVecVec(res);
    }
}

int main(int, char**){
    test_01();
    return 0;
}
