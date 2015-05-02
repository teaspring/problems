/*
 * given a string s consisting of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * if the last word does not exist, return 0;
 * a word is defined as a character sequence without space char.
 * */
#include <cstring>

using namespace std;

class Solution{

public:
    /*
     *
     * */
    int lengthOfLastWord(const char *s){  //remember save the last valid word length
        const int n = strlen(s);
        int l1 = 0, l2 = 0; // l2 and l1 are lengths of two consecutive words

        for(int i = 0; i < n; ++i){
            if(s[i] == ' '){
                if(l1 != 0){
                    l2 = l1;
                    l1 = 0;
                }
                continue;
            }
            ++l1;
        }

        return l1 > 0 ? l1 : l2;
    }
};

/* unit test is in ../cpp_unittest/lengthOfLastWord_unittest */
