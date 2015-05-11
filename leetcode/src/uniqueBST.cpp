/*
 * problem 1:
 * given n, how many structurally unique BST's(binary search tree) that store values 1...n?
 * e.g. n=3, there are a total of 5 unique BST's
 * */

#include <cstring>

using namespace std;

class Solution{

public:
    /*
     * simple DP
     * */
    int numTrees(int n){
        if(n < 1)    return 0;

        int subs[n+1];
        memset(subs, 0, sizeof(subs));

        subs[1] = subs[0] = 1;

        for(int i = 2; i <= n; ++i){ // i is totol node count in tree, 1-based
            for(int l = 0; l < i; ++l){
                subs[i] += subs[l] * subs[i-1 - l];  // left sub tree has l nodes while right sub tree has (i-1-l)
            }
        }

        return subs[n];
    }
};

/* unit test is in ../cpp_unittest/uniqueBST_unittest */
