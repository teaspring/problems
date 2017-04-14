/*
 * given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where candidate number sum to T.
 * ps, 
 * 1.the same number in candidates can be chosen from C with only once
 * 2.all numbers are positive integers with repeated value in possible
 * 3.all elements in a combination must be non-decending order without duplicate combinations.
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{

public:
    vector<vector<int> > combinationSumII(vector<int>& num, int target){
        sort(num.begin(), num.end());  //sort in ascending order
        vector<vector<int> > res;
        vector<int> vec;
        plusSum(res, num, vec, target);
        return res;
    }

private:
    void plusSum(vector<vector<int> >& res, const vector<int>& candidates, vector<int>& vec, int target){
        if(target == 0){
            res.push_back(index2Values(candidates, vec));
            return;
        }

        const int n = candidates.size();
        int start = vec.empty() ? 0 : vec[vec.size() - 1] + 1;
        for(int i = start; i < n; ++i){
            if(target < candidates[i])        break;

            if(i > start &&  candidates[i] == candidates[i-1])    continue;  // skip duplicat combinations

            vec.push_back(i); // vec<> stores the index in candidates<>
            plusSum(res, candidates, vec, target - candidates[i]);
            vec.pop_back();
        }
        return;
    }

    vector<int> index2Values(const vector<int>& candidates, vector<int>& indexes){
        vector<int> values;
        int n = indexes.size();
        for(int i = 0; i < n; ++i){
            values.push_back(candidates[indexes[i]]);
        }
        return values;
    }
};
