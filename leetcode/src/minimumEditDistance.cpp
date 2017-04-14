/*
 * given two words in string, find the minimum edit distance for converting word1 to word2.
 * once conversion must be one of below:
 * 1.delete one letter
 * 2.insert one letter
 * 3.replace one letter with another
 *
 * solution: DP
 * dp[i][j] = min{
 *      dp[i-1][j] + 1,  # delete last char of word1
 *      dp[i][j-1] + 1,  # insert char to tail of word1
 *      dp[i-1][j-1] + (word1[i] == word2[j] ? 0 : 1)   # replacement
 * }
 */
#include <string>
#include <vector>
#include <iostream>  // min()

using namespace std;

class Solution{

public:
    int minDistance(const string& word1, const string& word2){
        if(word1.empty() || word2.empty())    return max(word1.size(), word2.size());

        const int m = word1.size();
        const int n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0)); // int dp[m+1][n+1], dimension is length of word1/word2, dp[0][0] = 0 naturally

        for(int i = 1; i < m+1; ++i){
            dp[i][0] = i;
        }

        for(int j = 1; j < n+1; ++j){
            dp[0][j] = j;
        }

        for(int i = 1; i < m+1; ++i){   // i-1 is index of argument
            for(int j = 1; j < n+1; ++j){
                int opt1 = 1 + min(dp[i-1][j], dp[i][j-1]); // delete once or insert once at tail
                int opt2 = dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1); // replacement at tail
                dp[i][j] = min(opt1, opt2);
            }
        }

        return dp[m][n];
    }
};

/* unit test is in ../cpp_unittest/minimumEditDistance_unittest */
