/*
 * given two words in string, find the minimum edit distance for converting word1 to word2. once conversion must be one of below:
 * 1.delete one letter
 * 2.insert one letter
 * 3.replace one letter with another
 *
 * solution: DP
 * dp[i][j] = min{
 *      dp[i-1][j] + 1,       // delete
 *      dp[i][j-1] + 1,       // insert
 *      dp[i-1][j-1] + word1[i] == word2[j] ? 1 : 0    // substution
 * }
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class EditDistance{
public:
    int minDistance(const string& word1, const string& word2){
        int m = word1.size();
        int n = word2.size();
        if(m==0 || n==0)    return max(m, n);
        int dp[m+1][n+1];    //define one more row and column to facilitate processing [i-1][] and [][j-1]
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=m; ++i){
            dp[i][0] = i;
        }
        for(int j=0; j<=n; ++j){
            dp[0][j] = j;
        }
        for(int i=1; i<=m; ++i){   // i-1 is index of argument
            for(int j=1; j<=n; ++j){
                dp[i][j] = min(1 + min(dp[i-1][j], dp[i][j-1]),
                               dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
            }
        }
        return dp[m][n];
    }

    void test_01(){   // 1 operation
        string word1("");
        string word2("a");
        cout << minDistance(word1, word2) << endl;
    }

    void test_02(){   // 1 operation
        string word1("a");
        string word2("b");
        cout << minDistance(word1, word2) << endl;
    }

    void test_03(){   // 2 operations
        string word1("abc");
        string word2("acd");
        cout << minDistance(word1, word2) << endl;
    }

    void test_04(){   // 1 substitution
        string word1("abc");
        string word2("adc");
        cout << minDistance(word1, word2) << endl;
    }
};

int main(int, char**){
    EditDistance *ed = new EditDistance();
    ed->test_01();
    ed->test_02();
    ed->test_03();
    ed->test_04();
    delete ed;
    ed = 0;
    return 0;
}
