/*
 * given a string S, find the longest palindrome substring in S.
 * Assum that the maximum length of S is 1000, and there exists one unique longest palindrome substring.
 *
 * traditional DP provides a time O(n^2) solution
 *
 * Manacher provides a time O(n) solution, smart and elegent
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

class Solution{
public:
    /*
     * classic DP solution, time O(n^2), space O(n^2)
     * */
    string maxpalindrome(const string& str){
        const int n = str.size();

        int dp[n][n+1]; // dp[i][j] means palindrome length of str starting at i with length of j
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i){
            dp[i][1] = 1;
        }

        int sum = 1, begin = 0;
        for(int j = 2; j <= n; ++j){
            for(int i = 0; i+j <= n; ++i){
                if(dp[i+1][j-2] == j-2){
                    if(str[i] == str[i+j-1]){
                        dp[i][j] = j;
                        if(sum < j){
                            sum = j;
                            begin = i;
                        }
                    }else{
                        dp[i][j] = j-2;
                    }
                }else{
                    dp[i][j] = max(dp[i+1][j-1], dp[i][j-1]);
                }
            }
        }

        return str.substr(begin, sum);;
    }

    /*
    * Manache algorithm to this problem, very smart and elegent solution, time O(n), space O(n)
    * */
    string Manacher(const string& S){
        if(S.empty())    return string();

        const int n = S.size();
        const int N = 2 * n + 1;

        char pMix[N]; // extend char[n] to char[2*n+1] by inserting dummy char '#'
        memset(pMix, 0, sizeof(pMix));

        pMix[0] = '#';
        for(int i = 0, k = 1; i < n || k < N; k++){
            if(pMix[k-1] == '#'){
                pMix[k] = S[i++];
            }else{
                pMix[k] = '#';
            }
        }

        int p[N]; // p[i] means radius of longest palindrome centering at [i], which include center
        memset(p, 0, sizeof(p));
        p[0] = 1;

        int id = 0;  // center of longest palindrome
        int mx = id + p[id]; // exclusive edge index of it

        for(int i = 1; i < N; i++){
            if(mx > i){ // check mx > i firstly! if (mx > i) stands, (2*id - i >= 0) stands definitely
                p[i] = min(p[2*id - i], mx - i);
            }else{
                p[i] = 1;
            }

            while(i - p[i] >= 0
                  && i + p[i] < N
                  && pMix[i - p[i]] == pMix[i + p[i]]){
                p[i]++;
            }

            if(p[i] > p[id]){
                id = i;
                mx = i + p[i];
            }
        }

        char cstr[2*p[id] + 1];
        memset(cstr, 0, sizeof(cstr));

        int k = 0; // get the valid char array length
        for(int i = id - p[id] + 1; i < id + p[id]; i++){
            if(pMix[i] == '#')    continue;
            cstr[k++] = pMix[i];
        }
        cstr[k] = '\0';

        return string(cstr);
    }
};

/* unit test is in ../cpp_unittest/longestPalindrome_unittest */

/*
int main(int argc, char** args){
    if(0 && argc > 1){
        fstream infile(args[1]);
        if(!infile){
            cerr<<"cannot open file";
            infile.close();
            return 0;
        }

        const int N = 10001;
        char cstr[N];
        memset(cstr, 0, sizeof(cstr));

        infile.getline(cstr, N);
        printf("%s\n", longestPalindrome(cstr).c_str());
        infile.close();
    }
    return 0;
}
*/
