/*
 * given two numbers represented as strings, return multiplication of the two numbers as string
 * Q: support negative number string?
 * */
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class Solution{

public:
    /*
     * currently this method does not support negative number string
     * */
    string multiply(const string& num1, const string& num2){
        if(num1.empty() || num2.empty())    return string();

        const int m = num1.size();
        const int n = num2.size();

        if(m == 1 && num1[0] == '0')    return string("0");
        if(n == 1 && num2[0] == '0')    return string("0");

        char arr[m + n + 1];
        for(int i = 0; i < m + n + 1; ++i){
            arr[i] = '0';
        }

        int t = m + n - 1;  // index in result string. move to assign from end to begin  

        for(int j = n-1; j >= 0; --j){

            int b = num2[j] - '0', over = 0;

            t = (m+n-1) - (n-1-j);

            for(int i = m-1; i >= 0; --i){

                int a = num1[i] - '0';

                int c = arr[t]  - '0';

                int s = a*b + c + over;

                arr[t--] = '0' + s % 10;

                over = s/10;
            }

            if(over > 0)    arr[t--] = '0' + over;
        }

        return string(arr + t + 1, arr + m + n);  // tail char '\0' no need to initialize the string
    }
};


/* unit test is in ../cpp_unittest/multiplyStrings_unittest */

