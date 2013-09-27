/*
 * question on Sep24
 * given the convertion from digit to char 1-a, 2-b, 3-c...26-z
 * open question: how to handle 0?
 *
 * test data:
 * 12259:
 * 9
 * */
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace  std;

void digit2char(int N, int div, char* cstr, int pos){
	if(N==0){
		cstr[pos] = '\0';
		cout<<cstr<<endl;
		cstr[pos] = 0;
		return;
	}

	int r = N/div;
	if(r>0 && r<10){
		cstr[pos] = 'a' + r-1;
		digit2char(N - r*div, div/10, cstr, pos+1);
		cstr[pos] = 0;
	}else if(r == 0){
		return;
	}

	if(div>=10){
		r = N/(div/10);
		if(r>9 && r<27){
			cstr[pos] = 'a' + r-1;
			digit2char(N - r*(div/10), div/100, cstr, pos+1);
			cstr[pos] = 0;
			return;
		}
	}
}

void convertDigits(int num){
	int d = 1, c = 1;
	while(num/d > 9){
		d *= 10;
		++c;
	}
	char* res = new char[c+1];
	memset(res, 0, sizeof(char)*(c+1));
	digit2char(num, d, res, 0);

	delete[] res;
	res = 0;
}

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str) == 0 || str.empty())
		  break;
		convertDigits(atoi(str.c_str()));
	}
	return 0;
}

