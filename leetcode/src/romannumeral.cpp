/*
 * write functions to convert integer2roman and roman2integer
 * 
 * note: in Roman numeral's definition, integer >= 3999 is invalid
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

const int MaxSize = 50;
int digits[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};    // for int a[] initialization, OK for C code, local var in C++, but not for data member in C++ class
char alphas[][13] = {
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

/*
 * method 1, direct strategy
 * */
string int2Roman_01(int num){
    char *res = new char[MaxSize];
    memset(res, 0, sizeof(char)*MaxSize);
    int j=0, i=12;
    while(num > 0){
        if(num < digits[i]){
            --i;
        }else{
            res[j++] = alphas[i][0];
            if(i & 1){  // i%2 == 1
                res[j++] = alphas[i][1];
            }
            num -= digits[i];
        }
    }
    res[j] = '\0';
    string str(res);
    delete[] res;
    return str;
}

int roman2Int(const string& str){ //split string by fixed segment, plus to sum 
    int res = 0, n = str.size(), i=0, j=12;
    while(i<n && j>=0){
        if(j & 1){ // to match 2 chars
            if(i<n-1 && str[i]==alphas[j][0] && str[i+1] == alphas[j][1]){
                res += digits[j];
                i += 2;
            }else{
                --j;
            }
        }else{     // to match 1 char  
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

void test_int2roman(){
    string str;
    while(1){
        printf("please input integer:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int n = atoi(str.c_str());
        printf("%s\n", int2Roman_01(n).c_str());
    }
}

void test_roman2int(){
    string str;
    while(1){
        printf("please input roman numeral in upper case:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        printf("%d\n", roman2Int(str));
    }
}

int main(int, char**){
    test_roman2int();
    return 0;
}
