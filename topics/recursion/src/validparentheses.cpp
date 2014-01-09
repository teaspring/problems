/*
 * fro oj.leetcode
 * given string containing just '(',')','{','}','[',']', determine if the input string is valid
 * the brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * 
 * take care to write bug-free code for the fist time!!!
 * 
 * test data:
 * "", yes
 * (), yes
 * )(, no
 * ()[]{}, yes
 * ([)], no
 * (([))], no
 *
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(const string& str, int i, stack<int>& stk){
    if(str.empty())                return true;
    int n = str.size();
    if(i<0)     return false;
    if(i==n){
        return stk.empty();
    }
    switch(str[i]){
        case '(':
            stk.push(1);
            break;
        case ')':
            if(stk.empty() || stk.top() != 1)     return false;
            stk.pop();
            break;
        case '[':
            stk.push(2);
            break;
        case ']':
            if(stk.empty() || stk.top() != 2)     return false;
            stk.pop();
            break;
        case '{':
            stk.push(3);
            break;
        case '}':
            if(stk.empty() || stk.top() != 3)     return false;
            stk.pop();
            break;
        default:
            break;
    }
    return check(str, i+1, stk);
}

bool isvalid(const string& str){
    stack<int> stk;
    return check(str, 0, stk);
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())
          break;
        printf("%s\n", isvalid(str) ? "true" : "false");
    }
    return 0;
}
