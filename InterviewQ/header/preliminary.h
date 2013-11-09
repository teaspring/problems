/******************preliminary.h**************************/
#include "stdio.h"
#include "stdlib.h"
#include <cstring>
#include <string>
#include <cctype>	
#include <iostream>

using namespace std;

char* calculateOperationSequence(int *originalArray, int *resultArray, int length);

void calcuEqualExam(int* inArr, int length, int target);

inline bool isSpace(char x){	//<cctype> supports isspace()
	return x == ' ' || x == '\r' || x == '\n' || x == '\b' || x == '\t';
}

void rtrim(char* a){
	int i = strlen(a)-1;
	while(isspace(a[i]))	i--;
	a[i+1] = '\0';
}

char* ltrim(char* a){
	char* addr = new char[strlen(a)+1];
	int i=0;
	while(isspace(a[i]))  i++;
	strcpy(addr, a+i);
	return addr;
}

char * getInputLine(char *buffer, int length){
	if(fgets(buffer,length, stdin)==NULL){	//c style
		return NULL;
	}
	rtrim(buffer);
	if(strlen(buffer)<=0)		return NULL;
	return buffer;
}

int splitAndConvert(char* strings,int *array){
	char* tokenPtr = strtok(strings,",");
	int i=0;
	while(tokenPtr!=NULL){
		array[i] = atoi(tokenPtr);
		i++;
		tokenPtr=strtok(NULL,",");		//strtok(NULL,char*), except first time, it use NULL later
	}
	return i;
}

/*
 * it support any unknown delimiter(\s,\n,','...) except digit
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


