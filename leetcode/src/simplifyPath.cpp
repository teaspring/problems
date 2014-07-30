/*
 * given a path, simplify it
 *
 * test case:
 * /a/b/../../c/,   /c
 * /../,            / 
 * /a//b/../,       /a
 * //,              /
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


class SimplifyPath{
public:
    string simplifyPath(string path){
        int n = path.size();
        if(n == 0)    return string();
        int i = 0 , j = 1, length = 0;
        vector<string> vec;
        while(j <= n){
            if(j == n || path[j] == '/'){
                if(path[i] == '/'){
                    if(i < j-1){
                        length += process(path.substr(i+1, j-(i+1)), vec);
                    }
                    i = j;
                }
            }
            ++j;
        }
        return generate(vec, length);
    }

    void test_01(){
        string str;
        while(1){
            cout << "please input path to simplify:" << endl;
            getline(cin, str);    // ASCII 13 is Carriage Return character
            if(str.empty())    break;
            cout << simplifyPath(str) << endl;
            str.clear();
        }
    }

private:
    int process(string str, vector<string>& vec){
        int length = 0;
        if(str.size() == 0 || str == "." || str == "/")    return length;
        if(str == ".."){
            if(!vec.empty()){
                length = vec[vec.size()-1].size();
                vec.pop_back();
                return -length;
            }else{
                return 0;
            }
        }
        length = str.size();
        vec.push_back(str);
        return length;
    }

    string generate(const vector<string>& chips, int len){
        int n = chips.size();
        if(n == 0)    return string("/");
        len  += n + 1;
        char arr[len];
        int t = 0;
        for(int i = 0; i<n; ++i){
            arr[t++] = '/';
            for(size_t j = 0; j < chips[i].size(); ++j){
                arr[t++] = chips[i][j];
            }
        }
        arr[t] = '\0';
        return string(arr);
    }
};

int main(int, char**){
    SimplifyPath *sp = new SimplifyPath();
    sp->test_01();
    delete sp;
    sp = 0;
    return 0;
}
