/*
 * given a string containing just the characters '(' and ')', find the length of longest valid(well-formed) parentheses substring
 *
 * test case:
 * (()(), result is 4
 * ((())()(, result is 6
 * */
#include "stdio.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:

    /*
     * 1st version of space O(n^2) and time O(n^2), causing Memory Limit Exceed error on oj.leetcode
    * */
    int longestValidParentheses_01(const string& s){
        const int n = s.size();
        if(n < 2)    return 0;

        int dp[n][n+1]; // longest valid length for substring [i, i + l)
        for(int i = 0; i < n; i++){
            memset(dp[i], 0, sizeof(dp[i]) / sizeof(int));
        }

        for(int l = 2; l <= n; ++l){
            for(int i = 0; i + l <= n; ++i){
                if(!(l & 1)){  // l % 2 == 0
                    if(l >= 4){
                        if(dp[i][2] + dp[i+2][l-2] == l
                        || dp[i][l-2] + dp[i+l-2][2] == l){
                            dp[i][l] = l;
                            continue;
                        }
                    }
                    if(dp[i+1][l-2] == l-2 && s[i]=='(' && s[i+l-1] == ')'){
                        dp[i][l] = l;
                        continue;
                    }
                }
                dp[i][l] = max(dp[i][l-1], dp[i+1][l-1]);
            }
        }

        int res = dp[0][n];
        return res;
    }

    /*
    * update _01, reduce the space to O(n) while time remaining O(n^2), causing Time Limit Exceed error!
    * */
    int longestValidParentheses_02(const string& s){
        const int n = s.size();
        if(n < 2)    return 0;

        int pTwo[n];   // pTwo[i] means valid parentheses length of substr starting at [i] with length 2
        memset(pTwo, 0, sizeof(pTwo) / sizeof(int));

        int dp[n][3];     // dp[][0],[][1],[][2] are arrays for substr starting at [i] with length l-2, l-1, l
        for(int i = 0; i < n; i++){
            memset(dp[i], 0, sizeof(dp[i]) / sizeof(int));
        }

        for(int i = 0; i < n; ++i){
            if(s[i] == '(' && s[i+1] == ')'){
                pTwo[i] = 2;
                dp[i][0] = 2; // currently l is 2
            }
        }

        int ic = 0, ia, ib; // ic for length of l
        for(int l = 3; l <= n; ++l){
            ia = ib; // ia for length of l-2
            ib = ic; // ib for length of l-1
            ic = (ic + 1) % 3;
            for(int i = 0; i + l <= n; ++i){
                if(!(l & 1)){  // l % 2 == 0
                    if(l >= 4){
                        if(pTwo[i] + dp[i+2][ia] == l
                        || dp[i][ia] + pTwo[i+l-2] == l){
                            dp[i][ic] = l;
                            continue;
                        }
                    }
                    if(dp[i+1][ia] == l-2 && s[i] == '(' && s[i+l-1] == ')'){
                        dp[i][ic] = l;
                        continue;
                    }
                }
                dp[i][ic] = max(dp[i][ib], dp[i+1][ib]);
            }
        }
        int res = dp[0][ic];
        return res;
    }

    /*
    * version accepted by oj.leetcode. use stack to save verified parenthesis pairs count
    * */
    int longestValidParentheses_03(const string& s){
        const int n = s.size();
        vector<int> stk;  // vector<> works as stack<>
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                stk.push_back(-1);
            }else{ // the new tail char is ')'
                int m = stk.size();
                if(m > 0){
                    if(stk[m - 1] == -1){
                        stk[m - 1] = 1;
                    }else if(m > 1){  //stk[m - 2] == -1 certainly
                        int now = stk[m - 1];
                        stk.pop_back();
                        stk.pop_back();
                        stk.push_back(now + 1);
                        m--; // necessary to update m if m is used later
                    }else{   // without new tail ')' contribution to stk, preceding is only positive int
                        stk.clear();
                        continue;
                    }
                    ans = max(ans, sumPrecedingPosi(stk));
                }
            }
        }
        return (ans << 1); // ans is pairs count, * 2 equals to length
    }

private:
    int sumPrecedingPosi(vector<int>& vect){
        int m = vect.size();
        if(m > 0 && vect[m - 1] > 0){
            if(m > 1 && vect[m - 2] > 0){
                int sum = vect[m - 1] + vect[m - 2];
                vect.pop_back();
                vect.pop_back();
                vect.push_back(sum);
                m--; // necessary to update m if m is used later
            }
        }
        return vect[m-1];
    }
};
/* unit test is in ../cpp_unittest/longestValidParentheses_unittest/ */
