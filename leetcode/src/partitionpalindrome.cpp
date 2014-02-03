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

/*
 * make substring palindrome vector<>, via dynamic programming, in time O(n^2)
 * */
void make_vpalin(const string& s, vector<vector<int> >& vpalin){
    int n = s.size();
    int **dp = new int*[n];
    for(int i=0;i<n;i++){
        dp[i] = new int[n+1]();    //length is [0,n]!!
    }
    for(int i=0;i<n;i++){
        dp[i][1] = 1;
        vpalin[i].push_back(i+1);    //vpalin[i] has one element (i+1) at least, so nothing can be skipped
    }
    for(int l=2;l<=n;l++){
        for(int end=n;end-l >= 0;end--){
            if(l<4 || dp[end-l+1][l-2]==1){
                if(s[end-l] == s[end-1]){
                    dp[end-l][l] = 1;
                    vpalin[end-l].push_back(end);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;
    return;
}

/*
 * make up the partition string
 * */
void partition_palin(vector<vector<string> >& res, const vector<vector<int> >& vpalin, const string& s, int start, stack<int> stk){
    if(start==(int)s.size()){
        stack<int> stk2;
        while(!stk.empty()){
            stk2.push(stk.top());
            stk.pop();
        }
        vector<string> vstr;
        int start = stk2.top();    //it must be 0
        stk.push(start);
        stk2.pop();
        while(!stk2.empty()){
            vstr.push_back(s.substr(start, stk2.top()-start));
            start = stk2.top();
            stk.push(start);
            stk2.pop();
        }
        res.push_back(vstr);
        return;
    }

    vector<int> vec = vpalin[start];
    for(size_t i=0;i<vec.size();i++){
        stk.push(vec[i]);
        partition_palin(res, vpalin, s, vec[i], stk);
        stk.pop();
    }
    return;
}

vector<vector<string> > partition(const string& s){
    vector<vector<string> > res;
    int n = s.size();
    if(n==0)    return res;
    if(n==1){
        vector<string> vec;
        vec.push_back(s);
        res.push_back(vec);
        return res;
    }
    vector<vector<int> > vpalin;
    for(int i=0;i<n;i++){
        vector<int> vec;
        vpalin.push_back(vec);
    }
    make_vpalin(s, vpalin);
    stack<int> stk;
    stk.push(0);
    partition_palin(res, vpalin, s, 0, stk);
    stk.pop();
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input string:"<<endl;
        if(getline(cin, str)==0 || str.empty())        break;
        vector<vector<string> > res = partition(str);
        for(size_t i=0;i<res.size();i++){
            vector<string> vec = res[i];
            for(size_t j=0;j<vec.size();j++){
                printf("%s ", vec[j].c_str());
            }
            printf("\n");
        }
    }
    return 0;
}

