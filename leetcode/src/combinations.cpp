/*
 * given n and k, find combinations of k integers from [1,n]
 */
#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > combinations(int n, int k){
        vector<vector<int> > result;
        vector<int> pot(k, 0);
        combineOnce(pot, k, 1, n, result);
        return result;
    }

private:
    // optional integers among [1,n]
    void combineOnce(vector<int>& curr, int r, int start, int end, vector<vector<int> >& res){
        if(r == 0){
            res.push_back(curr);
            return;
        }
        const int k = curr.size();
        if(start > end || k < r)    return;

        for(int i = start; i <= end; ++i){
            curr[k-r] = i;
            combineOnce(curr, r-1, i+1, end, res);
            curr[k-r] = 0;
        }
        return;
    }
};

