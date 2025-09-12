#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>
#include "utils.h"

using namespace std;

class Solution
{
    public:
    // in use of map and set
    string find_needle_in_haystack_1(const string& hay_stack, const string& needle)
    {
        set<char> st;
        make_set_char(needle, st);
        assert(!st.empty()); // for debug
        // prepare
        map<char, int> mp;
        auto min_win_size = hay_stack.size();
        auto min_win_b = 0;
        auto b_it = hay_stack.cbegin();
        auto e_it = hay_stack.cbegin();
        while (e_it < hay_stack.cend())
        {
            // move e_it to widen the window
            while (e_it < hay_stack.cend())
            {
                if (st.find(*e_it) != st.end())
                {
                    if (mp.find(*e_it) != mp.end())
                    {
                        mp[*e_it] += 1;
                    } else
                    {
                        mp[*e_it] = 1;
                    }
                    if (mp.size() == st.size()) break;
                }
                e_it++;
            }
            // move b_it to narrow the window
            while (mp.size() == st.size())
            {
                if (mp.find(*b_it) != mp.end())
                {
                    if (mp[*b_it] == 1) break;
                    mp[*b_it] -= 1;
                }
                b_it++;
            }
            // update min window
            auto win_size = e_it - b_it + 1; // both inclusive
            if (min_win_size > win_size)
            {
                min_win_size = win_size;
                min_win_b = b_it - hay_stack.cbegin();
            }
            // move the window
            if (e_it >= hay_stack.cend() - 1)   break;
            mp.erase(*b_it);
            b_it++;
            e_it++;
        }
        // return
        stringstream ss;
        ss << min_win_b << " " << min_win_b + min_win_size - 1;
        return ss.str();
    }

    // in use of vector
    string find_needle_in_haystack_2(const string& hay_stack, const string& needle)
    {
        vector<bool> required_vt(256, false);
        make_required_vector(needle, required_vt);
        auto required_num = count(required_vt.cbegin(), required_vt.cend(), true);
        assert(required_num > 0);
        // prepare
        vector<int> collected_vt(256, 0);
        size_t informed = 0;
        auto min_win_size = hay_stack.size();
        auto min_win_b = 0;
        auto b_it = hay_stack.cbegin();
        auto e_it = hay_stack.cbegin();
        while (e_it < hay_stack.cend())
        {
            // move e_it to widen the window
            while (e_it < hay_stack.cend())
            {
                auto ch_code = (unsigned char)(*e_it);
                if (required_vt[ch_code])
                {
                    if (collected_vt[ch_code] == 0) informed++;
                    collected_vt[ch_code] += 1;
                    if (informed == required_num) break;
                }
                e_it++;
            }
            // move b_it to narrow the window
            while (informed == required_num)
            {
                auto ch_code = (unsigned char)(*b_it);
                if (required_vt[ch_code])
                {
                    if (collected_vt[ch_code] == 1) break;
                    collected_vt[ch_code] -= 1;
                }
                b_it++;
            }
            // update min window
            auto win_size = e_it - b_it + 1; // both inclusive
            if (min_win_size > win_size)
            {
                min_win_size = win_size;
                min_win_b = b_it - hay_stack.cbegin();
            }
            // move the window
            if (e_it >= hay_stack.cend() - 1)   break;
            collected_vt[(unsigned char)*b_it] = 0;
            informed--;
            b_it++;
            e_it++;
        }
        // return
        stringstream ss;
        ss << min_win_b << " " << min_win_b + min_win_size - 1;
        return ss.str();
    }

    private:
    void make_set_char(const string& needle, set<char>& st)
    {
        size_t pos = 0;
        const char comma  = ',';
        const char hyphen = '-';
        // ensure the existence of comma
        stringstream ss;
        ss << needle << comma;
        string my_needle = ss.str();
        // iterate segments which are splited by comma
        while(my_needle.find(comma, pos) != string::npos)
        {
            auto next_pos = my_needle.find(comma, pos);
            auto part = trim_str(my_needle.substr(pos, next_pos - pos));
            // range with '-'
            if (part.find(hyphen) != string::npos)
            {
                assert(part.length() == 3);
                auto hyphen_pos = part.find(hyphen);
                char b = part[hyphen_pos - 1];
                char e = part[hyphen_pos + 1];
                for (auto i = 0; i <= e - b; i++)
                {
                    st.insert(char(b + i));
                }
            } else 
            {
                st.insert(part[0]); // certainly be a single char
            }
            pos = next_pos + 1;
        }
    }

    // @param vt is supposed to be vector of capacity 256
    void make_required_vector(const string& needle, vector<bool>& vt)
    {
        size_t pos = 0;
        const char comma  = ',';
        const char hyphen = '-';
        // ensure the existence of comma
        stringstream ss;
        ss << needle << comma;
        string my_needle = ss.str();
        // iterate segments which are splited by comma
        while(my_needle.find(comma, pos) != string::npos)
        {
            auto next_pos = my_needle.find(comma, pos);
            auto part = trim_str(my_needle.substr(pos, next_pos - pos));
            // range with '-'
            if (part.find(hyphen) != string::npos)
            {
                assert(part.length() == 3);
                auto hyphen_pos = part.find(hyphen);
                char b = part[hyphen_pos - 1];
                char e = part[hyphen_pos + 1];
                for (auto i = 0; i <= e - b; i++)
                    vt[(unsigned char)(b + i)] = true;
            } else
            {
                vt[(unsigned char)part[0]] = true; // certainly be a single char
            }
            pos = next_pos + 1;
        }
    }
};