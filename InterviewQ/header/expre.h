/*
 * Object Oriention design of question of expression interpret
 * expression: term +/- term
 * term: factor *\/ factor
 * factor: (-)n, or (expression)
 * */
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdlib.h>
using namespace std;

class expreInter{
public:
    expreInter(string str):inStr(str),pos(0),ch(0){}
    ~expreInter(){}
    void interpret();
private:
    int factor();
    int term();
    int expression();

    string inStr;
    size_t pos;
    char ch;    
};
