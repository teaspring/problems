/*
 * given an unsorted array of integers, find the length of the longest consecutive elements sequence. complete it in time O(n)
 * 
 * test case:
 * [100, 4, 200, 1, 3, 2], the longest consecutive sequence is [1,2,3,4], length is 4
 *
 * */

#include "../header/preliminary.h"
#include <unordered_map>

/*
 * hash_map<>(unordered_map<>) will be used definitely, but how to enable map[i] present consecutive sequence length covering it? how to 
 * process upper(right)/lower(left) bound?
 * */
int longestConsecutive(vector<int> &num){
    if(num.size()==0)    return 0;
    unordered_map<int, int> uii;
    int maxlen{1};
    for(auto &val : num){
        if(uii[val] != 0)    continue;  //NOTE: operator[] is overused, while key not in, after operator[] is called, size increases by 1
        uii[val] = 1;
        int leftbound{uii[val-1]}, rightbound{uii[val+1]};
        uii[val-leftbound] = uii[val+rightbound] = 1 + leftbound + rightbound;
        maxlen = max(maxlen, 1+leftbound+rightbound);
    }
    return maxlen;
}

/*
 * modified version which call find() instead of operator[]
 * */
int longestConsecutive_02(vector<int> &num){
    if(num.size()==0)    return 0;
    unordered_map<int, int> uii;
    int maxlen{1};
    unordered_map<int, int>::const_iterator it = uii.end();
    for(auto &val : num){
        it = uii.find(val);
        if(it != uii.end())    continue;
        uii[val] = 1;

        int leftbound = 0;
        it = uii.find(val-1);
        if(it != uii.end())    leftbound = it->second;
        int rightbound = 0;
        it = uii.find(val+1);
        if(it != uii.end())    rightbound = it->second;
        
        uii[val-leftbound] = uii[val+rightbound] = 1 + leftbound + rightbound;
        maxlen = max(maxlen, 1+leftbound+rightbound);
    }
    return maxlen;
}

int main(int, char**){
    string str;
    while(1){
        printf("input int array:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> vec;
        for(int i=0;i<n;i++){
            vec.push_back(arr[i]);
        }
        printf("length of longest consecutive sequence is %d\n", longestConsecutive_02(vec));
    }
    return 0;
}
