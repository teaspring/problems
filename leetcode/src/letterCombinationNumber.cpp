/*
 * given a digit string,return all possible letter combinations that the number could represent.
 * A mapping of digit to letters is just like the telephone buttons
 *
 * several questions need to ask during interview:
 * 1. how to process 0 and 1?
 * 2. what should the result is when no result? empty vector<> or empty string in vector<>?
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
#include <vector>

using namespace std;

/*
 * solution same to <BeautyOfProgramming>, it uses iteration instead of recurse, with changing index
 * */
vector<string> letterCombinations(const string& digits){
    vector<string> res;
    if(digits.empty()){
        res.push_back(string());
        return res;
    }
    char character[10][5]={    //digit is 0-based as well
        " ",    //space for 0
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    int count[10] = {1,0,3,3,3,3,3,4,3,4};
    int n = digits.size();
    int *number = new int[n]();
    bool canParse=true;
    for(int i=0;i<n;i++){
        char ch = digits[i];
        if(!isdigit(ch)){
            canParse = false;
            break;
        }
        number[i] = atoi(&ch);
    }
    if(!canParse){
        delete[] number;
        res.push_back(string());
        return res;
    }
    int *index = new int[n]();    //initialize to all 0
    
    while(1){
        char cstr[n+1];
        memset(cstr, 0, sizeof(char)*n);
        for(int i=0; i<n;i++){
            if(number[i]==1)    continue;
            cstr[i] = character[number[i]][index[i]];
        }
        cstr[n] = '\0';    //necessary
        res.push_back(string(cstr));
        int k = n-1;
        if(index[k] < count[number[k]] - 1){
            index[k]++;
            continue;
        }
        while(k>=0 && index[k] >= count[number[k]]-1){
            index[k] = 0;
            k--;
        }
        if(k<0)        break;
        index[k]++;
    }
    delete[] number;
    delete[] index;
    return res;
}

int main(int, char**){
    string str;
    while(1){
        printf("please input digits:\n");
        if(getline(cin, str)==0 || str.empty())
          break;
        vector<string> res = letterCombinations(str);
        for(size_t i=0; i<res.size();i++){
            printf("%s, ", res[i].c_str());
        }
        printf("\n");
    }
    return 0;
}

