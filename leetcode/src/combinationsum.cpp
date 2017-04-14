/*
 * given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where candidate number sum to T.
 * ps, the same number can be chosen from C unlimited number of times.
 * all numbers are positive integers, and elements in a combination must be non-decending order without duplicate combinations.
 *
 * test case:
 * S=[2,3,7], target=7
 * output: [2,2,3], [7]
 * */
#include <vector>
#include <algorithm>

using namespace std;

class Solution{

public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());  //sort candidates in ascending order

        vector<vector<int> > res;
        vector<int> vec;
        plusSum(res, candidates, vec, -1, target);
        return res;
    }

private:
    void plusSum(vector<vector<int> >& res, const vector<int>& candidates, vector<int>& vec, int lastIdx, int target){
        if(target == 0){
            res.push_back(vec);
            return;
        }

        int start = lastIdx < 0 ? 0 : lastIdx;
        const int n = candidates.size();

        for(int i = start; i < n; ++i){
            int d = candidates[i];
            if(target < d)    break;

            vec.push_back(d); // vec<> stores the val in candidates<>
            plusSum(res, candidates, vec, i, target - d);
            vec.pop_back();
        }
    }
};

