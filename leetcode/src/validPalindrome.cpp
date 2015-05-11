/*
 * given a string, determine if it is a palindrome, consider only alphanumeric char and ignoring cases.
 *
 * NOTE: it is good to ask during interview, what about empty string? here we determine empty is true
 *
 * */
#include <string>
#include <cctype>

using namespace std;

class Solution{

public:
    bool isPalindrome(const string& s){
        if(s.empty())    return true;

        int i = 0, j = s.size() - 1;

        while(i < j){

            if(!isalpha(s[i]) && !isdigit(s[i])){
                ++i;
                continue;
            }

            if(!isalpha(s[j]) && !isdigit(s[j])){
                --j;
                continue;
            }

            char a = isalpha(s[i]) ? tolower(s[i]) : s[i];
            char b = isalpha(s[j]) ? tolower(s[j]) : s[j];

            if(a != b)    break;

            ++i;
            --j;
        }

        return i >= j;
    }
};

/* unit test is in ../cpp_unittest/validPalindrome_unittest */
