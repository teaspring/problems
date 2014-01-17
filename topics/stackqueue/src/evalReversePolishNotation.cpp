/*
 * from oj.leetcode. evaluate an arithmetic string in reverse Polish notation
 * arithmetic operator: +, -, *, /
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
#include <cctype>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens){
    stack<int> stk;
    int n = tokens.size();
    for(int i=0;i<n;++i){
        string str(tokens[i]);
        if(str.empty())    continue;
        int m = str.size();
        if(m > 1){
            stk.push(atoi(str.c_str()));
            continue;
        }else{
            char ch = str[0];
            if(isdigit(ch)){
                stk.push(atoi(&ch));
                continue;
            }
            if(stk.size() < 2){    //ch is operator, at least two integers must be in stack
                printf("error !\n");
                break;
            }
            int x1=0, x2=0;
            switch (str[0]){
                case '+':
                    /*
                    if(stk.empty()){
                        printf("error!\n");
                        return 0;
                    }
                    */
                    x1 = stk.top();
                    stk.pop();
                    x2 = stk.top();
                    stk.pop();
                    stk.push(x2 + x1);
                    break;
                case '-':
                    x1 = stk.top();
                    stk.pop();
                    x2 = stk.top();
                    stk.pop();
                    stk.push(x2 - x1);
                    break;
                case '*':
                    x1 = stk.top();
                    stk.pop();
                    x2 = stk.top();
                    stk.pop();
                    stk.push(x2 * x1);
                    break;
                case '/':
                    x1 = stk.top();
                    stk.pop();
                    x2 = stk.top();
                    stk.pop();
                    stk.push(x2/x1);
                    break;
                default:
                    break;
            }
        }
    }
    if(stk.empty()){    //final pop() must ensure stack not empty
        printf("error!\n");
        return 0;
    } 
    int res = stk.top();
    return res;
}

int main(int, char**){
    string str;
    while(1){
        vector<string> vec;
        while(getline(cin, str) != 0 && !str.empty()){
            vec.push_back(str);
        }
        printf("the evaluated result is %d\n", evalRPN(vec));
    }
    return 0;
}

