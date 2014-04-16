/*
* LongestCommonSubsequence, LCS. First Recurse method, then optimization one by one
*/
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <list>
#include <stack>
#include <cstring>

using namespace std;

static int i = 0;

//first method uses recursive, with time complexity O(3^N)!!!
void RecursionLCS(const string& str1, const string& str2,  string& lcs){
    cout<<"stack call !" << ++i<< ", str1: " <<str1.c_str()<<", str2: "<<str2.c_str()<<endl;
    if(str1.length() == 0 || str2.length() == 0)
    return; 

    if(str1[0] == str2[0]){
        lcs += str1[0];
        RecursionLCS(str1.substr(1), str2.substr(1), lcs);
    }else{
        string strTmp1,strTmp2,strTmp3; 
        RecursionLCS(str1.substr(1), str2, strTmp1);
        RecursionLCS(str1, str2.substr(1), strTmp2);
        //RecursionLCS(str1.substr(1), str2.substr(1), strTmp3); //this branch is totally duplicate

        string strLongest = strTmp1.length() > strTmp2.length() ? strTmp1 : strTmp2;
        if(strLongest.length() < strTmp3.length()){
            strLongest = strTmp3;
        }
        if(lcs.length() < strLongest.length()){
            lcs = strLongest;
        }
     }
}

//second method use tw0-depth loop to comare two string
string LeftAllignLongestSubString(const string& str1, const string& str2){
    string result;
    int size = str1.length() > str2.length() ? str2.length() : str1.length();
    int i =0;
    for(;i<size;i++){
        if(str1[i] != str2[i])        break;
    }
    return str1.substr(0, i); //string.substr(i,j), return [i, j)
}

void LoopLCS(const std::string& str1, const std::string& str2,  std::string&  lcs){
    string::size_type i,j;
    for(i = 0; i < str1.length(); i++){
         for(j = 0; j < str2.length(); j++){
             string lstr = LeftAllignLongestSubString(str1.substr(i), str2.substr(j));
             if(lstr.length() > lcs.length()){
                lcs = lstr;
             }
         }
     }
}

//third method, initialize a matric of the two string compare, then calculate the longest 1 in each ¶Ô½ÇÏß
const int MAX_STRING_LEN = 20;
void InitializeRelation(const string& str1, const string& str2, int* d[MAX_STRING_LEN]){
    int rows = str1.length();
    int columns = str2.length();
    for(int i = 0; i<rows; i++){
        for(int j = 0;j<columns; j++){
            if(str1[i] == str2[j]){
                d[i][j] = 1;
            }else{
                d[i][j] = 0;
            }
        }
    }    
}

int GetLongestPosition(const int d[MAX_STRING_LEN][MAX_STRING_LEN], int& m, int& n, int startRow, int startColumn, int* start){
    *start = -1;
    int tmpLen=0, tmpStart=-1, length = 0;
    while(startRow < m && startColumn < n){
        if(d[startRow++][startColumn++] == 1){
            if(tmpStart == -1){
                tmpStart = startRow > startColumn ? startRow-1 : startColumn-1; 
            }
            tmpLen++;
        }else {
            if(tmpLen > length ){
                length = tmpLen;
                *start = tmpStart;
            }
            tmpStart = -1;
            tmpLen = 0;
        }
    }
    
    if(tmpLen > length ){
        length = tmpLen;
        *start = tmpStart;
    }
    return length;
}

bool GetLongestSubStringPosition(int d[MAX_STRING_LEN][MAX_STRING_LEN], int m,  int n, int *start, int *length){
    int tmp = 0, begin=0;
    int length_hori = 0, length_vert = 0, start_hori = 0, start_vert = 0;
    for(int k = 0; k < n; k++){
        tmp = GetLongestPosition(d, m, n, 0, k, &begin);
         if(tmp > length_hori){
             length_hori = tmp;
             start_hori = begin;
         }
    }
    for(int k = 1; k < m; k++){
        tmp = GetLongestPosition(d, m, n, k, 0, &begin);
        if(tmp > length_vert){
            length_vert = tmp;
            start_vert = begin;
         }
     }

     if(length_hori > length_vert){
        *start = start_hori; 
        *length = length_hori;
        return false;
     }else{
        *start = start_vert;
        *length = length_vert;
        return true;
     }
 }

void RelationLCS(const std::string& str1, const std::string& str2,  std::string&  lcs){
    int d[MAX_STRING_LEN][MAX_STRING_LEN];
    int length = 0, start=0; 
       //initialize the matrix
    int rows = str1.length();
    int columns = str2.length();
    for(int i = 0; i<rows; i++){
        for(int j = 0;j<columns; j++){
            if(str1[i] == str2[j]){
                d[i][j] = 1;
            }else{
                d[i][j] = 0;
            }
        }
    }
    //output d[][]
    cout<<"the matrix is: "<<endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<d[i][j]<<"\t";
        }
        cout<<endl;
    }

    bool isStr1 = GetLongestSubStringPosition(d, str1.length(), str2.length(), &start, &length);
    lcs = isStr1 ? str1.substr(start, length) : str2.substr(start, length);
}

int main(int, char**){
    return 0;
}
