/*
 * write functions to convert integer2roman and roman2integer
 * I, II, III, IV, V, VI, VII, VIII, IX, X
 * note: in Roman numeral's definition, integer >= 3999 is invalid
 * */
#include "romannumeral.h"

/*
 * convert integer to Roman numeral string
 * */
string Solution::int2Roman(int num){
    char res[MaxSize];
    memset(res, 0, sizeof(MaxSize));

    int j = 0;
    int i = tags - 1;   // scan optional tag from greatest to least

    while(num > 0){
        if(num < digits[i]){
            --i;
        }else{
            res[j++] = alphas[i][0];

            if(i & 1){  // odd indexed Roman numeral tag has two chars
                res[j++] = alphas[i][1];
            }

            num -= digits[i];
        }
    }
    res[j] = '\0';

    return string(res);
}

/*
 * Roman numeral string places most significant numeral in most left
 * */
int Solution::roman2Int(const string& str){ // split string by fixed segment, plus to sum
    const int n = str.size();

    int res = 0;
    int i = 0;
    int j = tags - 1; // scan optional tag from greatest to least

    while(i < n && j >= 0){
        if(j & 1){ // to match two chars
            if(i < n-1 && str[i] == alphas[j][0] && str[i+1] == alphas[j][1]){
                res += digits[j];
                i += 2;
            }else{
                --j;
            }
        }else{  // to match one char
            if(str[i] == alphas[j][0]){
                res += digits[j];
                ++i;
            }else{
                --j;
            }
        }
    }

    return res;
}

const int Solution::digits[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

const char Solution::alphas[13][3] = {
        "I",   //1
        "IV",  //4
        "V",   //5
        "IX",  //9
        "X",   //10
        "XL",  //40
        "L",   //50
        "XC",  //90
        "C",   //100
        "CD",  //400
        "D",   //500
        "CM",  //900
        "M"    //1000
};

/* unit test is in ../cpp_unittest/romannumeral_unittest */
