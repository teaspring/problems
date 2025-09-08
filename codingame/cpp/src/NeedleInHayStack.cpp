#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cassert>
#include "utils.h"

using namespace std;

class Solution
{
    public:
    string find_needle_in_haystack(const string& hay_stack, const string& needle)
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
};