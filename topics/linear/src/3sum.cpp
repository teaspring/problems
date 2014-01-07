/*
 * from oj.leetcode, given an integer array, find the 3 numbers that adding up to 0. find all triplets in the array which gives sum of 0
 * output triplets like (a,b,c) without duplicate, while a<=b<=c
 * 
 * test data:
 * -1,0,1,2,-1,-4
 * */
#include "../header/preliminary.h"
#include <vector>
#include <map>
#include <algorithm>

bool myfunc(int a, int b){    //for sort in ascending
    return a<b;
}

class Solution{
    public:
        vector<vector<int> > threeSum(vector<int> &numbers);
};

/*
 * since the problem not need output index and no requirment of index order, so
 * 1. sort the array firstly 
 * 2. because array is sorted, no need of map, O(n) search for <b,c> while a is fixed
 * 3. remember to skip duplicate a,b,c separately during their index moving
 * */
vector<vector<int> > Solution::threeSum(vector<int> &num){
    typedef vector<int> numbers;
    vector<numbers> res;
    sort(num.begin(), num.end(), myfunc);
    int n = num.size();
    for(int j=0;j<n-2;++j){
        if(j>0 && num[j] == num[j-1])    //skip same a
          continue;
        int target = 0 - num[j];
        int v=j+1, u=n-1;
        while(v<u){  //here is to find all valid pairs <b,c> for fixed a, so linear search is good enough instead of binary
            if(v>j+1 && num[v] == num[v-1]){    //skip same b
                ++v;
                continue;
            }
            if(u<n-1 && num[u] == num[u+1]){    //skip same c
                --u;
                continue;
            }
            int sum = num[v] + num[u];
            if(sum == target){
                numbers tmp;
                tmp.push_back(num[j]);
                tmp.push_back(num[v]);
                tmp.push_back(num[u]);
                res.push_back(tmp); //as array is sorted and moving a/b/c skip their duplicate already, tmp will not be duplicate
                ++v;
                --u;
            }else if(sum < target){
                ++v;
            }else{
                --u;
            }
        }
    }
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

        Solution* pSol = new Solution();
        vector<vector<int> > res = pSol->threeSum(numbers);
        for(size_t i=0;i<res.size();++i){
            vector<int> triplet = res[i];
            if(triplet.size()<3)
              continue;
            printf("(%d, %d, %d)\n", triplet[0], triplet[1], triplet[2]);
        }
    }
    return 0;
}
