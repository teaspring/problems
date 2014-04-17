/*
 * determine if a string has all unique characters. and what if not use additional data structure
 * typical solution in use of int, bool[] and bit vector to process char
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
 * for simplicity,assume char set is ASCII(256 char, can be presented in 7 bit).if not, increase storage but logic can be kept. Good to point it out in interview.
 * tip: process char via int ASCII which is a known data set
 * */
bool isUniqueChars2(string str){
    bool char_set[256];
    memset(char_set, 0, sizeof(char) * 256);
    for(size_t i=0; i<str.length();i++){
        int val = str.charAt(i);
        if(char_set[val])    return false;
        char_set[val] = true;
    }
    return true;
}

/*
 *we can reduce space usage by using a bit vector.Assume if the string is only lower case 'a'-'z', which allows us to use an int(32 bit)
 * */
bool isUniqueChars(string str){
    int checker = 0;
    for(int i=0; i<str.length(); i++){
        int val = str.charAt(i) - 'a';
        if((checker & (1<<val)) > 0)
          return false;
        checker |= (1<<val);
    }
    return true;
}

/*
 * summary: to process char, via ASCII which is a known data set, convert char to int. int can be array index, so bool[] is an option.
 * if char to process is limited set,a-z,26 in total. bit vector as an int can be considered. an int is 32 bit, afford 26 bit
 * */

int main(int, char**){
    return 0;
}
