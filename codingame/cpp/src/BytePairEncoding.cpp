#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>

using namespace std;

class Solution
{
    public:
    void process1(const string& src, string& dest, vector<string>& encoding_rules)
    {
        dest = src;
        char non_term_chr = '\0';
        while (1)
        {
            auto byte_pair = find_common_byte_pair(dest);
            if (byte_pair.length() == 0)  break;
            get_next_non_term(non_term_chr);
            string to_str(1, non_term_chr);
            replace_all_occurrance(dest, byte_pair, to_str);
            encoding_rules.push_back(format_encode_rule(byte_pair, non_term_chr));
        }
    }

    private:
    string find_left_most_common_pair(const vector<string>& vec, map<string, int> mp)
    {
        int max_val = 0;
        int max_key_idx = -1;
        for(auto it = vec.cbegin(); it < vec.cend(); it++)
        {
            if (!mp.contains(*it))   continue; // supposed will not happen
            int val = mp[*it];
            if (val > 1 && max_val < val) {
                max_val = val;
                max_key_idx = it - vec.cbegin();
            }
        }
        return max_key_idx > -1 ? vec.at(max_key_idx) : "";
    }

    string find_common_byte_pair(const string& src)
    {
        // map<> maintains the key-value pairs in order of sorted keys.
        map<string, int> all_byte_pairs;
        vector<string> all_keys;  // another vector to save the order when the keys are inserted
        string back_pair = ""; // previous byte_pair
        bool skipped_dupli = false;
        for(auto i = 0; i < src.length() - 1; ++i)
        {
            auto byte_pair = src.substr(i, 2);
            if (byte_pair.compare(back_pair) != 0 || skipped_dupli)
            {
                if (!all_byte_pairs.contains(byte_pair))
                {
                    all_byte_pairs[byte_pair] = 1;
                    all_keys.push_back(byte_pair);
                } else {
                    ++all_byte_pairs[byte_pair];
                }
                skipped_dupli = false;
            } else {
                skipped_dupli = true;
            }
            back_pair = byte_pair;
        }
        // find the left-most key of the largest value
        return find_left_most_common_pair(all_keys, all_byte_pairs);
    }

    void get_next_non_term(char& term)
    {
        term = (term == '\0' ? 'Z' : (term - 1));
    }

    void replace_all_occurrance(string& src, const string& from_str, const string& to_str)
    {
        while(src.find(from_str, 0) != string::npos) {
            auto start_pos = src.find(from_str);
            src.replace(start_pos, from_str.length(), to_str); // replace from_str to to_str
        }
    }

    string format_encode_rule(const string& byte_pair, const char& non_term_chr)
    {
        stringstream ss;
        ss << non_term_chr << " = " << byte_pair;
        return ss.str();
    }
};
