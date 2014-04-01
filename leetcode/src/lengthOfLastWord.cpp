/*
 * given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * if the last word does not exist, return 0;
 * a word is defined as a character sequence without space char.
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int lengthOfLastWord(const char *s){  //remember save the last valid word length
    int l1 = 0, l2 = 0, n = strlen(s);
    for(int i=0; i<n; ++i){
        if(s[i] == ' '){
            if(l1 != 0){
                l2 = l1;
                l1 = 0;
            }
            continue;
        }
        ++l1;
    }
    return l1 > 0 ? l1 : l2;
}

void test_01(){
    string str;
    while(1){
        printf("please input char sequence consisting of char and space\n");
        if(getline(cin, str)==0 || str.empty())        break;
        printf("length of last word is %d\n", lengthOfLastWord(str.c_str()));
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
