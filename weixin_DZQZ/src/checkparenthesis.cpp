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

void check(const string& str, size_t pos, int& score){
	if(pos >= str.size() || score < 0)
	  return;
	switch(str[pos]){
		case ')':
			return check(str, pos+1, --score);
		case '(':
			return check(str, pos+1, ++score);
		default:
			return check(str, pos+1, score);
	}
}

int main(int argc, char* argv[]){
	string str;
	if(getline(cin, str) == 0 || str.empty())
	  return 0;
	int sum = 0;
	check(str, 0, sum);
	if(sum != 0)
	  cout<<"no"<<endl;
	else
	  cout<<"yes"<<endl;
	return 0;
}

