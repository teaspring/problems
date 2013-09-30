/*
 * problem on Sep24
 * given the convertion from digit to char 1-a, 2-b, 3-c...26-z
 * open question: how to handle 0?
 *
 * note: recursive method always has duplicate sub problem, so dynamic programming with extra array can eliminate the duplicate
 * test data:
 * 12259
 * 9
 * 1023
 * */
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace  std;

/*
 * recurse, many duplicate sub problem
 * */
void digit2char(int N, int div, char* cstr, int pos){
    //printf("N = %d, div = %d\n", N, div);
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

/*
 * dynamic programming
 * */
void outputChars(int** ppChar, int r, int rows, int pos, char* res){
    if(r>=rows){
	res[pos] = '\0';
	cout<<res<<endl;
	res[pos] = 0;
	return;
    }

    for(int j=0;j<2;j++){
	if(ppChar[r][j] > 0){
	    res[pos] = 'a' + ppChar[r][j]-1;
	    outputChars(ppChar, r+j+1, rows, pos+1, res);
	    res[pos] = 0;
	}		
    }
    return;
}

void convertDigits_2(int num){
    int d = 1, c = 1;
    while(num /d > 9){
 	d *= 10;
	++c;
    }
    int** pOpt = new int*[c];
    for(int i=0;i<c;i++){
	pOpt[i] = new int[2]();			//digits of ones or tens
    }
    for(int div=d, N=num, pos=0;N>0 && div >= 1;){
	int r = N/div;
	if(r > 0 && r < 10){			//1-9
   	    pOpt[pos][0] = r;
	}
	if(div >= 10){
	    r = N/(div/10);
	    if(r > 9 && r < 27){		//10-26
		pOpt[pos][1] = r;
	    }
	}
	N %= div;
	div /= 10;
	pos++;
    }
    char* cstr = new char[c+1]();
    memset(cstr, 0, c+1);
    outputChars(pOpt, 0, c, 0, cstr);

    delete[] cstr;
    cstr = 0;
    for(int i=0;i<c;i++){
	delete[] pOpt[i];
	pOpt[i] = 0;
    }
    delete[] pOpt;
    pOpt = 0;
    return;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
	if(getline(cin, str) == 0 || str.empty())
	    break;
	printf("recurse with duplicate:\n");
	convertDigits(atoi(str.c_str()));

	printf("recurse with dynamic programming:\n");
	convertDigits_2(atoi(str.c_str()));
    }
    return 0;
}

