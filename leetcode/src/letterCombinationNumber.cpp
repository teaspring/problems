/*
 * given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters is just like the telephone keyboard panel
 *
 * several questions need to ask during interview:
 * 1. how to process 0 and 1?
 * 2. what should the result be when no result? empty vector<> or empty string in vector<>?
 * */
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution{

public:
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
            " ",    // '0'
            "",     // '1'
            "abc",  // '2'
            "def",  // '3'
            "ghi",  // '4'
            "jkl",  // '5'
            "mno",  // '6'
            "pqrs", // '7'
            "tuv",  // '8'
            "wxyz"  // '9'
        };

        int count[10] = {1,0,3,3,3,3,3,4,3,4};

        const int n = digits.size();
        int number[n];
        bool canParse = true;

        for(int i = 0; i < n; i++){
            char ch = digits[i];
            if(!isdigit(ch)){
                canParse = false;
                break;
            }

            number[i] = atoi(&ch);
        }

        if(!canParse){  // exit if invalid char exists in digits
            res.push_back(string());
            return res;
        }

        int index[n];
        memset(index, 0, sizeof(index));

        // alternative solution is push optional char to vector<char> like stack<>
        while(1){
            char cstr[n+1];
            memset(cstr, 0, sizeof(cstr));
            cstr[n] = '\0';

            for(int i = 0; i < n; i++){
                if(number[i] == 1)    continue;
                cstr[i] = character[number[i]][index[i]];
            }

            res.push_back(string(cstr));

            int k = n-1;
            if(index[k] < count[number[k]] - 1){
                index[k]++;
                continue;
            }

            while(k >= 0 && index[k] >= count[number[k]] - 1){
                index[k] = 0;
                k--;
            }

            if(k < 0)        break;

            index[k]++;
        }

        return res;
    }
};

/* unit test is in ../cpp_unittest/letterCombinationNumber_unittest */
