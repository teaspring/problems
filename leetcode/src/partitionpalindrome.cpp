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
    void make_vpalin(const string& str, vector<vector<int> >& vpalin){
        const int n = str.size();

        vector<vector<int> > dp(n, vector<int>(n+1, 0)); // int dp[n][n+1], dp[i][j] tells whether s.substr(i,j-i) is palindrome or not, both of i and j are char index among str

        for(int i = 0; i < n; i++){
            dp[i][1] = 1;
            vpalin[i].push_back(i+1); // vpalin[i] tells for substr starting at [i], which is palindrome
        }

        for(int l = 2; l <= n; l++){ // iterate the length from short to long
            for(int s = 0; s + l <= n; ++s) {  // s is start char index
                if(l < 4 || dp[s+1][s + l-1] == 1){ // dp[][] facilitates vpalin[]
                    if(str[s] == str[s + l-1]){
                        dp[s][s+l] = 1;
                        vpalin[s].push_back(s+l);
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
