#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * 
 * Input:
    CH2(1)CH2(1)CH1(1)CH2
    (1)         (1)   (1)
    CH2         CH2   CH2
    (1)         (1)   (1)
    CH2(1)CH2(1)CH1(1)CH2
 * Expected: VALID
 * ------------------------------------
 * Input:
    CH3(1)CH1(1)CH2(1)CH1(1)CH3
    (1)         (1)
    CH3         CH1(1)CH1(1)CH3
                (1)
                CH3
 * Expected: INVALID
 **/

class Solution {
    public:
    void process1(const vector<string>& src_lines, string& res)
    {
        // search each line via regex
        std::regex carbon_regex("(CH[0-4])");
        for (auto line_it = src_lines.begin(); line_it != src_lines.end(); line_it++)
        {
            auto carbon_begin = std::sregex_iterator(line_it->begin(), line_it->end(), carbon_regex);
            auto carbon_end = std::sregex_iterator();
            for (auto it = carbon_begin; it != carbon_end; it++)
            {
                std::smatch match = *it;
                std::string carbon = match.str();
                auto carbon_begin_pos = match.position(0); // position of this match obj inside the string
                auto line_row = line_it - src_lines.begin();
                if (!check_carbon_around(src_lines, carbon, line_row, carbon_begin_pos))
                {
                    res = "INVALID";
                    return;
                }
            }   
        }
        res = "VALID";
    }

    private:
    inline int get_bound_num(string&& bound)  // rvalue reference
    {
        if (bound.length() != 3)  return 0;
        return atoi(&bound.at(1)); // m of "(m)"    
    }

    /**
     * NOTE: iterator cannot be passed as param by value, because it will be invalidated
     * if the vector is modified, so we pass it by reference.
     */
    bool check_carbon_around(const vector<string>& allLines, // lvalue reference
        string& carbon,  // lvalue reference
        size_t line_row, // iterator of the line inside the vector of all lin es
        size_t carbon_begin_pos)
    {
        int carbon_rides = atoi(&carbon.at(2)); // n of "CHn"
        size_t up_bound_m = 0, right_bound_m = 0, down_bound_m = 0, left_bound_m = 0;

        auto lines_begin_it = allLines.begin(), lines_end_it = allLines.end();
        auto line_it = lines_begin_it + line_row;
        // up bound
        if (line_it > lines_begin_it && (line_it-1)->length() >= carbon_begin_pos + 3)
        {
            auto up_line_it = line_it - 1;
            up_bound_m = get_bound_num(up_line_it->substr(carbon_begin_pos, 3));
        }
        // right bound
        if (line_it->end() - line_it->begin() >= carbon_begin_pos + 3 + 3)
        {
            right_bound_m = get_bound_num(line_it->substr(carbon_begin_pos+3, 3));
        }
        // down bound
        if (line_it + 1 < lines_end_it && (line_it+1)->length() >= carbon_begin_pos + 3)
        {
            auto down_line_it = line_it + 1;
            down_bound_m = get_bound_num(down_line_it->substr(carbon_begin_pos, 3));
        }
        // left bound
        if (carbon_begin_pos >= 3)
        {
            left_bound_m = get_bound_num(line_it->substr(carbon_begin_pos-3, 3));
        }
        // sum up all the bounds around carbon and check
        return carbon_rides + up_bound_m + right_bound_m + down_bound_m + left_bound_m == 4;
    }
};
