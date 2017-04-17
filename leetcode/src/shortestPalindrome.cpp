/*
 * Given a string S, you are allowed to convert it to a palindrome by adding characters IN FRONT OF it. Find and return the palindrome you can find by performing this transformation.
 * For example:
 * "aacecaaa" => "aaacecaaa"
 * "abcd" => "dcbaabcd"
 * "a"  =>  "a"
 * "ab" =>  "bab"
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
        string pattern = s + '#' + rev_s; // NECESSARY to place an unused char in mid
        const int L = pattern.size();

        // prefix[i] = k means for the prefix substr with length i+1 from pattern[], its k length prefix matches k length suffix
        vector<int> prefix(L, 0);
        for(int i = 1; i < L; ++i) { // exactly the prefix array generation
            int k = prefix[i-1];
            while(k > 0 && pattern[k] != pattern[i]) {
                k = prefix[k-1];
            }
            prefix[i] = k + (pattern[k] == pattern[i]);
        }

        // if without '#' in mid of pattern, in case "aa" => "aaaa", prefix[L] = 3. while n = 2, it turns to rev_s.substr(0, -1)
        // string::substr(pos, len) for len < 0, it returns the whole str
        // if we have '#' in mid, "aa" => "aa#aa", prefix[L] = 2. while n = 2, it turns to rev_s.substr(0, 0)
        return rev_s.substr(0, n - prefix[L-1]) + s;
    }
};
