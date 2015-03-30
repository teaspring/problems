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
        vector<int> pot;
        vector<vector<int> > result;
        combineOnce(pot, k, 1, n, result);
        return result;
    }

private:
    void combineOnce(vector<int>& curr, int k, int start, int end, vector<vector<int> >& res){
        if(k == 0){
            res.push_back(curr);
            return;
        }
        if(start > end)    return;

        for(int i = start; i <= end; ++i){
            curr.push_back(i);
            combineOnce(curr, k-1, i+1, end, res);
            curr.pop_back();
        }
        return;
    }
};

