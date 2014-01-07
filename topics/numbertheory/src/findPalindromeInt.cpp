/*
 * from CSDN student programming challenges, Jan 2014
 * given an integer x, find the least palindrome integer y:1.y > x; 2.sum of digits of y equals to sum of digits of x. x can be as big as 10^1000, so both input and output are string. if no result, output "impossible"
 *
 * test data:
 * x=1, impossible ----type 1 
 * x=10, impossible
 * x=4, y=22       ----type 2
 * x=9, y=171
 * x=5989, y=29992 ----type 3, sum is odd when d is even
 * x=5387, y=16961  
 * x=333, y=414    ----type 4, x as palindrome      
 * x=44444, y=45254  ----type 4.1, normal
 * x=414, y=10701    ----type 4.2, center is 1 not enough to complement neighbor
 * x=919, y=14941
 * x=89898, y=98889  ----type 4.3, digit is 9 can not increase
 * x=5566, y=5665    ----type 5.1.1
 * x=6475, y=6556
 * x=5656, y=5665    ----type 5.1.2
 * x=6565, y=7447    ----type 5.1.3
 * x=42146, y=42524
 * x=7892438, y=7909097 ----type 5.2, freemake for center 3 digits with rest=9
 * x=5988, y=6996
 * x=42646, y=43834
 * x=892438, y=908809   ----type 5.3, freemake for center 4 digits with rest=16
 * 
 * note: since this function needs too much test cases, it is better to write google-test for it
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "stdlib.h"

using namespace std;

/*
 * special test cases for: 1. x as palindrome; 2.x=5566,x=5656...
 * */
bool convertStr2IntArray(const string& str, int *arr, int m, int& sum){    //convert a string to int array
    int n = str.size();
    memset(arr, 0, sizeof(int)*m);
    char *bar = new char[2];    //used to convert char to int
    sum=0;
    bool ispalindrome=true;
    for(int i=0;i<n;++i){
        if(i<=(n-1)/2 && ispalindrome && str[i] != str[n-1-i])
          ispalindrome = false;
        memset(bar, 0, sizeof(char)*2);
        bar[0] = str[i];
        bar[1] = '\0';
        arr[i] = atoi(bar);
        sum += arr[i];
    }
    delete[] bar;
    return ispalindrome;
}

string convertIntArray2Str(int *arr, int n){    //convert an int array to string 
    string str(n, '0');
    for(int i=0;i<n;++i){
        str[i] = '0' + arr[i];
    }
    return str;
}

/*
 * key of this problem is to merge so many branch cases
 * */
string findPalindromeInt(const string& str){
    int n = str.size();
    int *srcArr = new int[n]();
    int sum = 0;
    bool bpalindrome = convertStr2IntArray(str, srcArr, n, sum);
    int *dstArr = new int[n+2]();    //maximum length of output
    int m=n, rest=sum, srcrest=sum;
    bool freemake=false, hasresult=true;
    int d=m, i=0;
    if(sum%2 == 1 && n%2 == 0){
        m = n+1;
    }else{
        if(bpalindrome){  //palindrome x
            for(int j=0;j < (n+1)/2;j++){
                dstArr[j] = srcArr[j];
                dstArr[n-1-j] = dstArr[j];    //palindrome!
            }
            int t = (n-1)/2;
            for(;t>0;--t){    //backtrack, get 1 or 2 from [t] to complement [t-1]
                int offset = (t==n-1-t) ? 2 : 1;
                if(dstArr[t] >= offset && dstArr[t-1]<9){
                    break;
                }
            }
            if(t>0){    //modify palindrome integer from its center digit to make the least greater palindrome
                dstArr[t-1] += 1;
                dstArr[t] -= 1;
                dstArr[n-t] += 1;
                dstArr[n-t-1] -= 1;
                d=0;
                rest=0;
                srcrest=0;
                freemake=true;  //it can return as y is found
            }
        }else{  //non-palindrome x
            while(rest>0 && d>0 && !freemake){   //currently m==n
                if(d>1){
                    int tmp = srcArr[i];
                    for(;tmp<10 && (rest-2*tmp)>(d-2)*9;tmp++);
                    if(tmp==10 
                    || (rest-2*tmp)<0            //x=7892438, i=2
                    || ((rest-2*tmp)==0 && d>2)  //x=892438, i=1
                    || (tmp==srcArr[i] && rest < srcrest) //x=6565, if dstArr[0] = 6
                    ){
                        if(i<1){
                            break;    //to free make with longer size
                        }else{
                            for(;i>0 && dstArr[i-1]==9;--i){  //backtrack
                                rest += 2*dstArr[i-1];
                                d += 2;
                                srcrest += (srcArr[i-1] + srcArr[n-i]);
                            }
                            if(i==0){
                                break;    //to free make with longer size
                            }else{
                                dstArr[i-1] += 1;
                                dstArr[n-i] += 1;
                                rest -= 2;
                                freemake=true;    //free make for d digits in center, stating from [i] 
                            }
                        }
                    }else{
                        dstArr[i] = dstArr[n-1-i] = tmp;
                        rest -= 2*tmp;
                        srcrest -= (srcArr[i] + srcArr[n-1-i]);
                        d -= 2;
                        if(tmp > srcArr[i]
                        || (rest==0 && d==0))//this clause can return as y is found
                        {
                            freemake = true; //start free make from digit i+1
                        }
                        i++;    //enlarge i if dstArr[i] is set
                    }
                }else{    //d==1
                    dstArr[i] = rest;
                    d -= 1;
                    rest = 0;
                    srcrest = 0;
                    freemake = true;
                }
            }
        }
    }
    
    if(!freemake){  //generate least palindrome integer freely with longer size
        if(sum%2 == 1 && (n+1)%2==0){
            m = n+2;
        }else{
            m = n+1;
        }
        memset(dstArr, 0, sizeof(int)*m);
        i=0;
        rest = sum;
        d = m;
        freemake = true;    //enable freemake 
    }

    while(rest>=0 && d>0 && i<=m-1-i){  //generate palindrome integer of d digits while sum of digits eqauls to rest 
        if(d>1){
            int j = (i==0) ? 1 : 0;  //[0] can not be 0
            for(;(rest-2*j) > (d-2)*9 && j<10; ++j);    //j>9 is impossible!
            if(rest-2*j < 0){    //for x=1
                hasresult= false;
                break;
            }
            dstArr[i] = dstArr[m-1-i] = j;
            rest -= 2*j;
            d -= 2;
        }else{
            dstArr[i] = rest;   //rest>9 is impossible!
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
