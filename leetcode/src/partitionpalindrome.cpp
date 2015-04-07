/*
 * given a string s, partition s such that every substring of the partition is a palindrome. return all possible palindrome partition of s
 * 
 * test data:
 * a
 * aa
 * aba
 * abbaabcba
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

class Solution{

public:
    vector<vector<string> > partition(const string& s){
        vector<vector<string> > res;
        const int n = s.size();
        if(n == 0)    return res;
        if(n == 1){
            vector<string> vec;
            vec.push_back(s);
            res.push_back(vec);
            return res;
        }

        vector<vector<int> > vpalin;
        for(int i = 0; i < n; i++){
            vector<int> vec;
            vpalin.push_back(vec);
        }

        make_vpalin(s, vpalin);

        vector<int> vec;
        vec.push_back(0);
        partition_palin(res, vpalin, s, 0, vec);
        vec.pop_back();

        return res;
    }

private:
    /*
    * make substring palindrome vector<>, via dynamic programming, in time O(n^2)
    * */
    void make_vpalin(const string& s, vector<vector<int> >& vpalin){
        const int n = s.size();

        int dp[n][n+1]; // dp[][] tells whether s.substr() is palindrome or not
        for(int i = 0; i < n; i++){
            memset(dp[i], 0, sizeof(dp[i]));
        }

        for(int i = 0; i < n; i++){
            dp[i][1] = 1;
            vpalin[i].push_back(i+1); // vpalin[i] tells for substr starting at [i], which is palindrome
        }

        for(int l = 2; l <= n; l++){
            for(int end = n; end-l >= 0; end--){
                if(l < 4 || dp[end - l + 1][l-2] == 1){ // dp is necessary since vector<> not support contains()
                    if(s[end-l] == s[end-1]){
                        dp[end-l][l] = 1;
                        vpalin[end-l].push_back(end);
                    }
                }
            }
        }

        return;
    }

    /*
    * make up the partition string
    * */
    void partition_palin(vector<vector<string> >& res,
                         const vector<vector<int> >& vpalin,
                         const string& s,
                         int start,
                         vector<int>& idxs){
        if(start == (int) s.size()){ // reach end of s, time to push result
            vector<string> vstr;
            const int m = idxs.size();
            for(int i = 0; i < m-1; i++){
                vstr.push_back(s.substr(idxs[i], idxs[i+1] - idxs[i]));
            }
            res.push_back(vstr);
            return;
        }

        vector<int> vec = vpalin[start]; // pay extra structure for readability
        const int n = vec.size();
        for(int i = 0; i < n; i++){
            idxs.push_back(vec[i]);
            partition_palin(res, vpalin, s, vec[i], idxs);
            idxs.pop_back();
        }

        return;
    }
};
