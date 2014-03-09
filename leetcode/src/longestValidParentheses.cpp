/*
 * given a string containing just the characters '(' and ')', find the length of longest valid(well-formed) parentheses substring
 * 
 * test case:
 * (()(), result is 5
 * ((())()(, result is 6
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 1st version, get Memory Limit Exceed error on oj.leetcode
 * */
int longestValidParentheses_01(const string& s){
    int n = s.size();
    if(n < 2)    return 0;
    int **dp = new int*[n];        //dp[i][l] means the length of longest valid parentheses for substring starting at [i] with length l
    for(int i=0;i<n;i++){
        dp[i] = new int[n+1]();
    }
    for(int l=2;l<=n;++l){
        for(int i=0;i+l <= n;++i){
            if(!(l&1)){  //l%2 == 0
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
    
    for(int i=0;i<n;i++){
        delete[] dp[i];
        dp[i]=0;
    }
    delete[] dp;
    dp=0;
    return res;
}

/*
 * modification based on _01, reduce the space complexity to O(n), but it caused Time Limit Exceed error !
 * */
int longestValidParentheses_02(const string& s){
    int n = s.size();
    if(n < 2)    return 0;
    int *pTwo = new int[n]();       //pTwo[i] means valid parentheses length of substr starting at [i] with length 2
    int **dp = new int*[n];        //dp[][0],[][1],[][2] are arrays for substr starting at [i] with length l-2, l-1, l
    for(int i=0;i<n;i++){
        dp[i] = new int[3]();
    }
    for(int i=0;i<n;++i){
        if(s[i]=='(' && s[i+1]==')'){
            pTwo[i] = 2;
            dp[i][0] = 2;    //currently l==2
        }
    }
    int ic=0, ia, ib;    //ic for length of l
    for(int l=3;l<=n;++l){
        ia = ib; //ia for length of l-2
        ib = ic; //ib for length of l-1
        ic = (ic+1)%3;
        for(int i=0;i+l <= n;++i){
            if(!(l&1)){  //l%2 == 0
                if(l >= 4){
                    if(pTwo[i] + dp[i+2][ia] == l       //if(dp[i][2] + dp[i+2][l-2] == l
                    || dp[i][ia] + pTwo[i+l-2] == l){   //|| dp[i][l-2] + dp[i+l-2][2] == l){
                        dp[i][ic] = l;                      //dp[i][l] = l;
                        continue;
                    }
                }
                if(dp[i+1][ia] == l-2 && s[i]=='(' && s[i+l-1]==')'){//if(dp[i+1][l-2] == l-2 && s[i]=='(' && s[i+l-1] == ')'){
                    dp[i][ic] = l;                                       //dp[i][l] = l;
                    continue;
                }
            }
            dp[i][ic] = max(dp[i][ib], dp[i+1][ib]);//dp[i][l] = max(dp[i][l-1], dp[i+1][l-1]);
        }
    }
    int res = dp[0][ic];
    
    for(int i=0;i<n;i++){
        delete[] dp[i];
        dp[i]=0;
    }
    delete[] dp;
    dp=0;
    return res;
}

/*
 * solution from web, worthy to study
 * */
int longestValidParentheses_03(const string& s){
    vector<int> stk;
    int ans=0, n=s.size();
    for(int i=0;i<n;++i){
        if(s[i] == '('){
            stk.push_back(-1);
        }else{
            if(stk.size() > 0){
                if(stk[stk.size() - 1] == -1){
                    stk[stk.size() - 1] = 1;
                    ans = max(ans, 1);
                    while(stk.size() > 1){
                        if(stk[stk.size()-1] > 0 && stk[stk.size()-2] > 0){
                            int sum = stk[stk.size()-1] + stk[stk.size()-2];
                            stk.pop_back();
                            stk.pop_back();
                            stk.push_back(sum);
                            ans = max(ans, sum);
                        }else
                          break;
                    }
                }else{
                    if(stk.size()>1 && stk[stk.size()-2]==-1){
                        int now = stk[stk.size()-1];
                        stk.pop_back();
                        stk.pop_back();
                        stk.push_back(now +1);
                        ans = max(ans, now+1);
                        while(stk.size() > 1){
                            if(stk[stk.size()-1] > 0 && stk[stk.size()-2]>0){
                                int sum = stk[stk.size()-1] + stk[stk.size()-2];
                                stk.pop_back();
                                stk.pop_back();
                                stk.push_back(sum);
                                ans = max(ans, sum);
                            }else
                              break;
                        }
                    }else
                      stk.clear();
                }
            }    
        }
    }
    return (ans<<1);
}

/*
 * optimization based on solution 3
 * fail on case ()(())
 * */
int longestValidParentheses_04(const string& s){
    vector<int> stk;
    int ans=0, n=s.size();
    for(int i=0;i<n;++i){
        if(s[i] == '('){
            stk.push_back(-1);
            continue;
        }

        if(stk.size()>0){  //coming ')'
            int m = stk.size();
            if(stk[m-1] == -1){  // ...'(' waiting for ')'
                stk[m-1] = 1;
                ans = max(ans, 1);
            }else if(m > 1 && stk[m-2] == -1){  // ...(() waiting for ')'
                int sum = stk[m-1] + 1;
                stk.pop_back();
                stk.pop_back();
                stk.push_back(sum);
                ans = max(ans, sum);
            }else{            //invalid ')'
                if(stk[m-1] > 0){    //multiple seperators equals to one
                    stk.push_back(0);  //seperator
                }
                continue;
            }
            
            while(stk.size()>1 && stk[stk.size()-2] > 0){
                m = stk.size();
                int sum = stk[m-1] + stk[m-2];
                stk.pop_back();
                stk.pop_back();
                stk.push_back(sum);
                ans = max(ans, sum);
            }
        }
    }
    return ans << 1;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input parentheses string:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        printf("%d\n", longestValidParentheses_03(str));
        printf("%d\n", longestValidParentheses_04(str));
    }
    return 0;
}
