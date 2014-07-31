/*
 * given two numbers represented as strings, return multiplication of the two numbers as string
 * */
#include "../header/preliminary.h"

string multiply(string num1, string num2){
    int m = num1.size();
    int n = num2.size();
    if(m==0 || n==0)    return string();
    if(num1 == "0" || num2 == "0")    return string("0");
    char arr[m+n+1];
    for(int i=0; i<m+n+1; ++i){
        arr[i] = '0';
    }
    arr[m+n] = '\0';
    int t = m+n-1;    // index in result string
    for(int j=n-1; j>=0; --j){
        int b = num2[j] - '0', over = 0;
        t = (m+n-1) - (n-1-j);
        for(int i=m-1; i>=0; --i){
            int a = num1[i] - '0';
            int c = arr[t]  - '0';
            int s = a*b + c + over;
            //printf("a=%d, b=%d, c=%d, s=%d, index t=%d\n", a, b, c, s, t);
            arr[t--] = '0' + s % 10;
            over = s/10;
        }
        if(over > 0)    arr[t--] = '0' + over;
    }
    return string(arr+t+1, arr+m+n);    // tail char '\0' no need to initialize the string
}

void test(){
    while(1){
        cout << "input num1 as string:" << endl;
        string num1;
        if(getline(cin, num1)==0 || num1.size()==0)    break;
        cout << "input num2 as string:" << endl;
        string num2;
        if(getline(cin, num2)==0 || num2.size()==0)    break;
        cout << multiply(num1, num2) << endl;
    }
}

int main(){
    test();
    return 0;
}
