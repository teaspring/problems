/*
 * the string "paypalistring" is written in a zigzag pattern on a given number of rows like this:
 * p   a   t   g
 * a p l s r n
 * y   i   i
 * */

#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     *
     * */
    string zigzag(const string& str, int rows){
        if(rows == 0)    return string();
        if(rows == 1)    return string(str);

        const int n = str.size();

        vector<char> pvec[rows];
        bool up = false;

        // iterate str in zigzag order with rows
        for(int i = 0, r = 0; i < n; i++){  //  i is str cursor, r is row cursor

            pvec[r].push_back(str[i]);

            if(up){
                r--;

                if(r == -1){
                    r += 2;  // -1 turns to 1
                    up = false;
                }
            }else{
                r++;

                if(r == rows){
                    r -= 2; // n turns to n-2
                    up = true;
                }
            }
        }

        // construct the return string
        string res;

        for(int i = 0; i < rows; i++){    //take care of the string build and output
            const int l = pvec[i].size();

            char cstr[l+1];
            memset(cstr, 0, sizeof(cstr));

            for(int j = 0; j < l; j++){
                cstr[j] = pvec[i][j];
            }

            res.append(string(cstr));
        }

        return res;
    }
};

/* unit test is in ../cpp_unittest/zigzagGame_unittest */
