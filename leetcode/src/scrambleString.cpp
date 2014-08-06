/*
 * scrambleString.h
 */

#include "../header/preliminary.h"

class ScrambleString{
public:
    bool isScramble(string s1, string s2){
        if(s1.empty() || s2.empty() || s1.length() != s2.length())    return false;
        if(s1 == s2)    return true;
        int n = s1.length();
        const char* arr1 = s1.c_str();
        const char* arr2 = s2.c_str();
        vector<char> vec1(arr1, arr1 + n);
        vector<char> vec2(arr2, arr2 + n);
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        vector<char>::iterator it1 = vec1.begin(), it2 = vec2.begin();
        while(it1 != vec1.end()){
            if(*(it1++) != *(it2++))    return false;
        }

        for(int i=1; i<n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i))
            && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))){
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i))
            && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))){
                return true;
            }
        }
        return false;
    }

    void test_01(){
        string s1("great");
        string s2("agtre");
        cout << (isScramble(s1, s2) ? "true" : "false") << endl;
    }
};

int main(){
    ScrambleString s;
    s.test_01();
    return 0;
}

