/*
 * find the longest common prefix string among an array of strings
 * */
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{

public:
    /*
     * time O(n^2)
     * */
    string longestCommonPrefix(const vector<string>& strs){
        if(strs.empty())    return string();

        const int n = strs.size();
        if(n == 1)    return string(strs[0]);
        int length = strs[0].size();

        for(int i = 1; i < n; i++){
            length = min(length, (int)strs[i].size());
        }

        char res[length + 1];
        memset(res, 0, sizeof(res));

        int i = 0;
        for(; i < length; ++i){
            int j = 1;
            for(; j < n && strs[j][i] == strs[j-1][i]; ++j);
            if(j < n)    break;

            res[i] = strs[0][i];
        }
        res[i] = '\0';

        return string(res);
    }
};
