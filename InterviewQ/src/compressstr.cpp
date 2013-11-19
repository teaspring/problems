/*
 * ever appears in Y! interview
 * compress string of integer and alpha.
 * e.g. ACCCDD -> A3C2D
 *
 * */
#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

void compressstr(const string& str, char* res){
    size_t i=0, pos=0;
    char ch = toupper(str[i++]);
    int count=1;
    for(;i<=str.size();i++){
        if(toupper(str[i]) != ch || i==str.size()){    //don't forget to process the last char before exit
            if(count>1){
                int m=1, n=count;                    //write integer to char if > 1
                while(n/10){
                    m *= 10;
                    n /= 10;
                }
                n=count;
                while(m){
                    res[pos++] = '0' + n/m;
                    n = n%m;
                    m /= 10;
                }
            }
            res[pos++] = ch;
            if(i<str.size()){
                ch = toupper(str[i]);
                count=1;
            }
        }else{
            ++count;
        }
    }
    res[pos]='\0';
    return;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        char* dst = new char[str.size()+1];
        memset(dst, 0, sizeof(char)*(str.size()+1));
        compressstr(str, dst);
        printf("compressed string is %s\n", dst);
        delete[] dst;
        dst=0;
    }
    return 0;
}

