/*
 * from CSDN student programming challenges, Jan 2014
 * given an integer x, find the least palindrome integer y:1.y > x; 2.sum of digits of y equals to sum of digits of x. x can be as big as 10^1000, so both input and output are string. if no result, output "impossible"
 *
 * test data:
 * x=1, y="impossible"
 * x=4, y=22
 * x=9, y=171
 * x=5386, y=6556
 * x=5387, y=16961
 * x=5988, y=6996
 * x=5989, y=29992
 * x=414, y=10701
 * x=444, y=525      ----special case for x is palindrome!!!
 * x=5555, y=6446    ----special
 * x=44444, y=45254  ----special
 * x=4441444, y=453135 -----
 * x=919, y=14941
 * x=819, y=909
 * x=8598, y=8778
 * x=7892438, y=8179718
 * x=892438, y=1398931
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

/*
 * special process for x as palindrome integer
 * */
int convertStr2IntArray(const string& str, int *arr, int m){    //convert a string to int array
    int n = str.size();
    memset(arr, 0, sizeof(int)*m);
    char *bar = new char[2];    //used to convert char to int
    int sum=0;
    for(int i=0;i<n;++i){
        memset(bar, 0, sizeof(char)*2);
        bar[0] = str[i];
        bar[1] = '\0';
        arr[i] = atoi(bar);
        sum += arr[i];
    }
    delete[] bar;
    return sum;
}

string convertIntArray2Str(int *arr, int n){    //convert an int array to string 
    string str(n, '0');
    for(int i=0;i<n;++i){
        str[i] = '0' + arr[i];
    }
    return str;
}

/*
 * too complicated, too much boundary cases to consider
 * */
string findPalindromeInt(const string& str){
    int n = str.size();
    int *srcArr = new int[n]();
    int sum = convertStr2IntArray(str, srcArr, n);
    int *dstArr = new int[n+2]();    //maximum length of output
    int m=n, rest=sum;
    bool freemake=false, hasresult=true;
    int d=m, i=0;
    if(sum%2 == 1 && n%2 == 0){
        m = n+1;
    }else{
        while(rest>0 && d>0){   //attempt in m==n
            if(srcArr[i] >= srcArr[n-1-i]){    //cover d == 1
                dstArr[i] = dstArr[m-1-i] = srcArr[i];
            }else{
                if(d>2){
                    dstArr[i] = dstArr[m-1-i] = srcArr[i] +1;
                }else{        //d==2
                    dstArr[i] = dstArr[m-1-i] = rest/d;
                }
            }

            if(i==n-1-i){
                rest -= dstArr[i];
                d -= 1;
            }else{
                rest -= 2*dstArr[i];
                d -= 2;
            }
        
            if(dstArr[i] > srcArr[i] && rest >= 0)
              freemake = true; 
            i++;
            if(freemake)    break;
        } 
    }
    
    if(!freemake){  //generate palindrome integer freely with longer size
        if(sum%2 == 1 && (n+1)%2==0){
            m = n+2;
        }else{
            m = n+1;
        }
        memset(dstArr, 0, sizeof(int)*m);
        i=0;
        rest = sum;
        d = m;
    }

    while(rest>=0 && d>0 && i<=m-1-i){  //generate palindrome integer of d digits while sum of digits eqauls to rest 
        if(d>1){
            int j = (i==0) ? 1 : 0;
            for(;(rest-2*j) > (d-2)*9 && j<10; ++j);    //j==10 is impossible!
            if(rest-2*j < 0){    //for x=1
                hasresult= false;
                break;
            }
            dstArr[i] = dstArr[m-1-i] = j;
            if(i==m-1-i){
                rest -= j;
            }else{
                rest -= 2*j;
            }
            d -= 2;
        }else{
            dstArr[i] = rest;        //rest>9 is impossible!
            d -= 1;
            rest -= rest;
        }
        ++i;
    }
    string rst;
    if(hasresult){
        rst.append(convertIntArray2Str(dstArr, m));
    }else{
        rst.append("impossible");
    }
    delete[] srcArr;
    delete[] dstArr;
    return rst;
}


int main(int,char**){
    string str;
    while(1){
        cout<<"please input integer x in string:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        printf("y is %s\n", findPalindromeInt(str).c_str());
    }
    return 0;
}
