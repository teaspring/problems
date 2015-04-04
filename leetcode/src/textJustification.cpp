/*
 * textJustification.h
 * principles:
 * 1. pack as many words in a line as you can, pad extra spaces ' ' between words if necessary
 * 2. extra spaces between words should be evenly. if the number of spaces do not divide evenly, put more spaces on left slots tha right
 * 3. the last line should be left justified and no extra spaces between words
 * 4. if a line other than the last line contains only one word, left justified
 */

#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{

public:
    vector<string> fullJustify(vector<string>& words, int L){
        vector<string> res;
        int i = 0, n = words.size();
        while(i < n){
            int solidL = words[i].size();
            int gap = 1, cw = 1;

            while(i + cw < n){  // (i + cw) equals to counts of covered words, and next available word index both
                int delta = gap + words[i + cw].length();
                if(solidL + delta > L)    break;
                solidL += delta;
                ++cw;
            }

            // construct the interval spaces array
            int intervals[cw]; // in this line, cw words, (cw-1) valid intervals. create int[cw] to facilitate iterate
            int rest = L - solidL;
            if(cw == 1){
                intervals[cw - 1] = rest;
            }else{
                int evenSpace = gap + rest / (cw - 1);
                intervals[0]  = evenSpace + rest % (cw - 1);
                for(int j = 1; j < cw - 1; j++){
                    intervals[j] = evenSpace;
                }
                intervals[cw - 1] = 0;
            }

            res.push_back(fillLine(words, L, i, cw, intervals));
            i += cw;
        }
        return res;
    }

private:
    /*
    * NOTE: distribute benefit in left slots evenly!!
    * * */
    string fillLine(vector<string>& words, int L, int start, int count, int* spaces){
        char arr[L+1];
        int t = 0;
        for(int i = 0; i < count; ++i){
            for(size_t j = 0; j < words[start + i].size(); j++){
                arr[t++] = words[start + i][j];
            }

            int x = spaces[i];
            while(x-- > 0){
                arr[t++] = ' ';
            }
        }
        arr[L] = '\0';
        return string(arr);
    }
};

/* unit test is in ../cpp_unittest/textJustification_unittest/ */
