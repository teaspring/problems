/*
 * given a path, simplify it
 *
 * test case:
 * /a/b/../../c/ return /c
 * /../,         return /
 * /a//b/../,    return /a
 * //,           return /
 */

#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const string dot(".");
static const string dots("..");

class Solution{

public:
    /*
     *
     * */
    string simplifyPath_01(const string& path){
        if(path.empty())    return string();

        const int n = path.size();

        vector<string> vec;

        int i = 0 , j = 1, length = 0;

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

    /*
     * use a stack(vector indeed)
     * */
    string simplifyPath_02(const string& path){
        if(path.empty())    return string();

        vector<string> list;

        const int n = path.size();
        int i = -1, j = 0;
        while(j <= n){
            if(i == -1){
                while(j < n && path[j] == '/'){
                    j++;
                }

                i = j++;  // [i] is 1st non '/' char following '/'
            }else{
                while(j < n && path[j] != '/'){
                    j++;
                }

                // [j-1] is next '/' post [i] or j == n
                int len = j-i;
                string curr = path.substr(i, len);

                i = -1;
                j++;

                // filter "." and ".."
                if(strcmp(curr.c_str(), dot.c_str()) == 0)    continue;

                if(strcmp(curr.c_str(), dots.c_str()) == 0){
                    if(!list.empty()){
                        list.pop_back();
                    }
                    continue;
                }

                list.push_back(curr);
            }
        }

        return retainDir(list, n);
    }

private:
    /*
     * used by solution 01
     * */
    int process(string str, vector<string>& vec){
        if(str.size() == 0 || str == "." || str == "/")    return 0;

        if(str == ".."){
            if(vec.empty())    return 0;

            int length = vec[vec.size() - 1].size();
            vec.pop_back();
            return -length;
        }

        vec.push_back(str);
        return str.size();
    }

    /*
     * used by solution 01
     * */
    string generate(const vector<string>& chips, int len){
        if(chips.empty())    return string("/");

        const int n = chips.size();

        len  += n + 1;

        char arr[len];
        memset(arr, 0, sizeof(arr));

        int t = 0;
        for(int i = 0; i < n; ++i){
            arr[t++] = '/';
            for(size_t j = 0; j < chips[i].size(); ++j){
                arr[t++] = chips[i][j];
            }
        }
        arr[t] = '\0';
        return string(arr);
    }

    /*
     * used by solution 2
     * */
    string retainDir(const vector<string> list, int maxLen){
        const int n = list.size();

        char cstr[maxLen + 1];
        memset(cstr, 0, sizeof(cstr));

        int j = 0;
        for(int i = 0; i < n; i++){
            cstr[j++] = '/';

            int l = list[i].size();
            int t = 0;
            while(t < l){
                cstr[j++] = list[i][t++];
            }
        }

        if(j == 0)    cstr[j++] = '/';

        cstr[j] = '\0';
        return string(cstr);
    }
};

