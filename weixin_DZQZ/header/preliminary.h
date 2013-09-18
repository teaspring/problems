/******************preliminary.h**************************/
#include "stdio.h"
#include "stdlib.h"
#include <cstring>
#include <string>
#include <cctype>	
#include <iostream>

using namespace std;

/*
 * 1. support any unknown delimiter(\s,\n,','...) except digit
 * 2. support minus integer, multiple digits but float 
 * */
int splitStr2IntArray(string& str, int *array){
    int leng = 0;
	string::size_type  pos = 0;		//string::size_type and std::size_t are alternative
    int minus = 1;
	while(pos<str.size()){	
      if(str[pos] == '-' && pos<(str.size()-1) && isdigit(str[pos+1])){		//support minus
		minus = -1;
	  }else if(isdigit(str[pos])){
		string::size_type begin = pos;
        while(pos<str.size() && isdigit(str[pos]))	//at exit, pos is the one following last digit
		  pos++;
        char* tmp = new char[pos-begin+1];
        for(string::size_type i=0;i<pos-begin;i++)
          tmp[i] = str[i+begin];
        tmp[pos-begin] = '\0';
        array[leng++] = minus*atoi(tmp);
		minus = 1;
        delete tmp;
		tmp = 0;
      }
      pos++;
    }
	return leng;
}

int splitStr2IntArrayExt(string& str, int *array){
    int leng = 0;
	string::size_type  pos = 0;		//string::size_type and std::size_t are alternative
    int minus = 1;
	while(pos<str.size()){
      if(str[pos] == '-' && pos<(str.size()-1) && isdigit(str[pos+1])){
		minus = -1;
	  }else if(isdigit(str[pos])){
		int val = 0;
        while(pos<str.size() && isdigit(str[pos])){
			char ch = str[pos];		  
			val = (val==0) ? atoi(&ch) : 10*val + atoi(&ch);	//it works
			pos++;
		}
		array[leng++] = minus*val;
		minus = 1;
      }
      pos++;
    }
	return leng;
}


