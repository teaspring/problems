/*
 * from oj.leetcode, given an integer array and a target int, find the two numbers that adding up to target
 * output indices in vector, 1st is less than 2nd, neither is 0 based
 * assume exactly one solution exists
 *
 * solution: absolutely, array is unsorted and not good to sort it in solution.
 * */
#include "../header/preliminary.h"
#include <vector>
#include <map>

class Solution{
    public:
        vector<int> twoSum(vector<int> &numbers, int target);
};

/*
 * traverse in reverse, save required val of 1st index and 2nd index in a map.
 * */
vector<int> Solution::twoSum(vector<int> &numbers, int target){
    vector<int> res;
    map<int, int> mp;    //key = required integer of 1st index, value = 2nd index
    for(int i=numbers.size()-1;i>=0;--i){
        if(mp.find(numbers[i]) != mp.end()){
            res.push_back(i+1);
            res.push_back(mp[numbers[i]] + 1);
            break;
        }else{
            mp[target - numbers[i]] = i;
        }
    }
    mp.clear();
    return res;
}

int main(int, char**){
    string str;
    while(1){
        cout<<"input integer array:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        vector<int> numbers;
        for(int i=0;i<n;++i){
            numbers.push_back(arr[i]);
        }

        cout<<"input target int:"<<endl;
        if(getline(cin, str)==0 || str.empty())
          break;
        int target = atoi(str.c_str());
        Solution* pSol = new Solution();
        vector<int> res = pSol->twoSum(numbers, target);
        printf("index1=%d, index2=%d\n", res[0], res[1]);
    }
    return 0;
}
