/*
* problem on Nov19
* given two string, one as source, another as ttern. please find count of ttern appearance in source string
* 
* test data:
* s("abbbc"), t("abc"), count is 3
* s("abbcabccb"), t("abc"), count is 10
*/
#include "stdio.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
 * recurse, in time O((n/m)^m), not good
 * */
void findsubchar(set<int>* pSet, int m, int* seq, int& k, int& count){
    if(k==m){
        ++count;
        for(int i=0;i<m;i++){
            printf("%d ", seq[i]);
        }
        printf("\n");
        return;
    }
    int a = seq[k-1];
    set<int>::const_iterator iter = pSet[k].begin();
    for(;iter != pSet[k].end();iter++){
        if(*iter > a){
            seq[k++] = *iter;
            findsubchar(pSet, m, seq, k, count);
            seq[--k] = -1;
        }
    }
    return;
}

int findsubseqs(const string& s, const string& t){
    int count=0;
    int m = t.size();
    set<int>* pSet = new set<int>[m];
    for(size_t i=0;i<s.size();i++){
        for(size_t j=0;j<t.size();j++){
            if(s[i] == t[j]){
                pSet[j].insert(i);
            }
        }
    }
    int i =0;
    int* seq = new int[m]();
    set<int>::const_iterator iter = pSet[0].begin();
    for(;iter != pSet[i].end();iter++){
        seq[i++] = *iter;
        findsubchar(pSet, m, seq, i, count);
        seq[--i] = -1;
    }
    delete[] pSet;
    pSet = 0;
    return count;
}

/*
 * author's answer, dynamic programming, space O(m*n), time O(m*n)
 * when coding on using size(length) as array index, take care when it is index and when it is size
 * */
int numsubsequence(const string& s, const string& t){
    if(s.size()==0 || t.size()==0)
      return 0;
    int** dp = new int*[t.size()+1];        //dp[i][j] means string t of size i appearance in string s of size j
    for(size_t i=0;i<=t.size();++i){
        dp[i] = new int[s.size()+1]();
    }
    for(size_t j=0;j<=s.size();++j){
        dp[0][j]=1;
    }
    for(size_t i=0;i<t.size();++i){
        for(size_t j=0;j<s.size();++j){
            dp[i+1][j+1] += dp[i+1][j];       //in tha 2D array, dp[i+1][j] is left value of dp[i+1][j+1]
            if(t[i]==s[j])                    //t[i] is just the tailer of string t of size[i+1], the same is s[j] to size[j+1]
              dp[i+1][j+1] += dp[i][j];       //dp[i][j+1] is left-upper of dp[i+1][j+1]
        }
    }
    int res = dp[t.size()][s.size()];

    for(size_t i=0;i<=t.size();++i){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;
    return res;
}

int main(int argc, char* argv[]){
    string s, t;
    while(1){
        if(getline(cin, s)==0 || s.empty()){
            break;
        }
        if(getline(cin, t)==0 || t.empty()){
            break;
        }
        int res = numsubsequence(s, t);
        printf("sub sequence count is %d\n", res);
    }
    return 0;
}
