/*
 * generate all combinations of well-formed parentheses
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "stdlib.h"

using namespace std;

string makeout(stack<int>& stk){
    stack<int> stk2;
    int i=0;
    while(!stk.empty()){
        stk2.push(stk.top());
        ++i;
        stk.pop();
    }
    char *cstr = new char[i+1];
    i=0;
    while(!stk2.empty()){
        cstr[i++] = stk2.top() == 1 ? '(' : ')';
        stk.push(stk2.top());
        stk2.pop();
    }
    cstr[i] = '\0';
    string str(cstr);
    delete[] cstr;
    return str;
}

void append(vector<string>& res, stack<int>& stk, int posiN, int negaN){
    if(posiN==0 && negaN==0){
        res.push_back(makeout(stk));
        return;
    }
    if(posiN > 0){
        stk.push(1);
        append(res, stk, posiN-1, negaN);
        stk.pop();
    }
    if(posiN < negaN){
        stk.push(-1);
        append(res, stk, posiN, negaN-1);
        stk.pop();
    }
}

vector<string> generateParentheses(int n){
    vector<string> res;
    if(n<1)    return res;
    stack<int> stk;
    append(res, stk, n, n);
    return res;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input integer n:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        vector<string> res = generateParentheses(n);
        
        for(size_t i=0;i<res.size();i++){
            printf("%s, ", res[i].c_str());
        }
        printf("\n");
    }
    return 0;
}
