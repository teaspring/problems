/*
 * question on Sep14
 * given string, check parenthesis validness. It must be done via recurse without any loop in code.
 * 
 * test data:
 * (), yes
 * )(, no
 * (abc(d), no
 * (a)(b), yes
 * (a(b))c(, no
 * a(b)), no
 *
 * */
#include "stdio.h"
#include <iostream>
#include <string>
using namespace std;

int check(const string& str, size_t pos, int score){
    if(pos >= str.size() || score < 0)
      return score;
    switch(str[pos]){
        case ')':
            return check(str, pos+1, score-1);
        case '(':
            return check(str, pos+1, score+1);
        default:
            return check(str, pos+1, score);
    }
}

int main(int argc, char* argv[]){
    string str;
    while(1){
		if(getline(cin, str) == 0 || str.empty())
		  break;
		int sum = check(str, 0, 0);
		if(sum != 0)
		  cout<<"no"<<endl;
		else
		  cout<<"yes"<<endl;
	}
    return 0;
}

