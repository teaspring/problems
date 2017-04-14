/*
 * Given a string S, you are allowed to convert it to a palindrome by adding characters IN FRONT OF it. Find and return the palindrome you can find by performing this transformation.
 * For example:
 * "aacecaaa" => "aaacecaaa"
 * "abcd" => "dcbaabcd"
 * */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // remember definition of palindrome: a reversed str equals to itself
    // idea from prefix array generation among KMP str search algorithm !
    string shortestPalindrome(string s) {
        const int n = s.size();
        string rev_s(s);
        reverse(rev_s.begin(), rev_s.end());
        string pattern = s + "#" + rev_s; // why to place "#" in mid of the str?

        // prefix[i] = k means for the prefix substr with length i+1 from pattern[], its k length prefix matches k length suffix
        vector<int> prefix(2*n + 1, 0);
        for(int i = 1; i < 2*n + 1; ++i) {
            int k = prefix[i-1];
            while(k > 0 && pattern[k] != pattern[i]) {
                k = prefix[k-1];
            }
            prefix[i] = k + (pattern[k] == pattern[i]);
        }
        return rev_s.substr(0, n - prefix[2*n]) + s;
    }
};

