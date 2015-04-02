/*
 * generate all combinations of well-formed parentheses, given n is pairs of parentheses
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "stdlib.h"

using namespace std;

class Solution{

public:
    /*
     * efficient solution, use char[] to construct string dynamically
     * */
    vector<string> generate(int n){
        vector<string> vec;
        char cstr[2*n + 1];
        outputParentheses(n, n, cstr, 0, vec);
        return vec;
    }

private:
    void outputParentheses(int l, int r, char cstr[], int count, vector<string>& res){
        if(l == 0 && r == 0){
            cstr[count] = '\0';
            res.push_back(string(cstr));
            return;
        }

        if(l > 0){
            cstr[count] = '(';
            outputParentheses(l-1, r, cstr, count+1, res); // do not change count in this method call
        }

        if(l < r){
            cstr[count] = ')';
            outputParentheses(l, r-1, cstr, count+1, res);
        }

        return;
    }
};

/* unit test is in ../cpp_unittest/generateparentheses_unittest */
