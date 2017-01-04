/*
 * All DNA is composed of a series of nucleotides abbreviated as A,C,G, and T.
 * Write a function to find all the 10-letter-long sequences(substr) that occur more than once in a DNA molecule.
 *
 * test cases:
 * "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT" => ["AAAAACCCCC", "CCCCCAAAAA"]
 * "AACCAAAGTTACACCAAAGTTAGTA"  => ["ACCAAAGTTA"]
 * */

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    /*
     * Idea: it is not universal string map and search, it only focuses on A, C, G, T
     * in ASCII, in decimal,  A: 65, C: 67, G: 71, T: 84; in octal, A: 0101, C: 0103, G: 0107, T: 0124.
     * the last octal digit of each char is different, so only the 3 bits of each char is valid compar information
     * str[i] & 7 to get the last decimal digit
     * */
    vector<string> findRepeatedDnaSequences(const string& str) {
        unordered_set<int> st;
        vector<string> res;
        const int n = str.size();
        int t = 0,  i = 0;

        // this loop can be compacted to later loop without error; but it is better to be here
        while(i < 9) {
            t = t << 3 | (str[i++] & 7);  // t collects the last decimal digit of first 9 head chars
        }

        for(; i < n; ++i) {
            // if the 10-char str occurs more than once, this if-clause will be true only once
            // 0x3fffffff as 30 bits bitmask, 3 bits for each octal digit
            t = (t << 3 & 0x3fffffff) | (str[i] & 7);
            // another option of this container is unordered_map<int, int> mp, if(mp[t]++ == 1)...
            if(!st.insert(t).second) {
                res.push_back(str.substr(i - 9, 10));
            }
        }
        return res;
    }
};
