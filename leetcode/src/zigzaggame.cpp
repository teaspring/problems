/*
 * the string "paypalistring" is written in a zigzag pattern on a given number of rows like this:
 * p   a   t   g
 * a p l s r n
 * y   i   i 
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"
#include <vector>
using namespace std;

string zigzag(const string& str, int rows){
    if(rows==0)        return string();
    if(rows==1)        return string(str);
    int n = str.size();
    vector<char> pvec[rows];
    bool up=false;
    for(int i=0, r=0; i<n;i++){
        pvec[r].push_back(str[i]);
        if(up)  r--;
        else    r++;
        
        if(r==-1){
            r = 1;
            up = false;
        }
        if(r==rows){
            r = rows-2;
            up = true;
        }
    }
    string res;
    for(int i=0;i<rows;i++){    //take care of the string build and output
        int l = pvec[i].size();
        char cstr[l+1];
        memset(cstr, 0, sizeof(char)*(l+1));
        for(int j=0;j<l;j++){
            cstr[j] = pvec[i][j];
        }
        res.append(string(cstr));
    }
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input rows:"<<endl;
        if(getline(cin, str)==0 || str.empty())    
          break;
        int rows = atoi(str.c_str());
        
        cout<<"please input string:"<<endl;
        if(getline(cin, str)==0 || str.empty())    
          break;
        printf("ZigZag game: %s\n", zigzag(str, rows).c_str());
    }
    return 0;
}
