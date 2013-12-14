/*
 * from leetcode
 * determine whether an integer is palindrome, without extra space
 * 
 * >> it is that "without extra space" hint me with recurse
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

bool ispalindrome(int n, int x, int m){
	if(n)
	  return ispalindrome(n/10, 10*x + n%10, m);
	else
	  return x == m;
}

bool palindromeint(int n){
	return ispalindrome(n, 0, n);
}

int main(int, char**){
	string str;
	while(1){
		if(getline(cin, str)==0 || str.empty())
		  break;
		int n = atoi(str.c_str());
		bool res = palindromeint(n);
		cout<<(res ? "true" : "false")<<endl;
	}
	return 0;
}
