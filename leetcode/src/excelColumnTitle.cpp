/*
 * Problem I: convert Excel sheet column title to number
 * A -> 1
 * B -> 2
 * AA -> 27
 * AZ -> 52
 *
 * Problem II: convert number to Excel sheet column title
 * 1 -> A
 * 26 -> Z
 * 27 -> AA
 * 52 -> AZ
 * */

#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int titleToNumber(string s) {
        const int n = s.length();
        int num = 0;
        for(int i=0; i < n; ++i) {
            int offset = s.at(i) - 'A' + 1;
            num = 26 * num + offset;
        }
        return num;
    }

    /**
     * the point is the number for Excel title is 1-based, not 0-based
     * */
    string numToTitle(int num) {
        const int n = 100;  // assume this length is enough
        char cstr[n];
        memset(cstr, 0, sizeof(cstr));

        int l = 0, sum = num;
        while(sum) {
            int r = (sum - 1) % 26;
            cstr[l++] = 'A' + r;
            sum = (sum - 1) / 26;
        }
        cstr[l] = '\0';
        
        for(int i = 0; i < l/2; ++i) { // reverse cstr[]
            char ch = cstr[i];
            cstr[i] = cstr[l-1-i];
            cstr[l-1-i] = ch;
        }
        return string(cstr);
    }
};
