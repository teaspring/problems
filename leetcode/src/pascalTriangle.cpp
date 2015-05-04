/*
 * given numRows, generate the first numRows of Pascal's triangle
 * e.g. given nRows=5, return below:
 * 1
 * 1,1
 * 1,2,1
 * 1,3,3,1
 * 1,4,6,4,1
 * */

#include <vector>

using namespace std;

class Solution{

public:
    vector<vector<int> > generate(int nRows){
        vector<vector<int> > res;
        if(nRows < 1)    return res;

        vector<int> base;
        base.push_back(1);
        res.push_back(base);

        for(int i = 1; i < nRows; ++i){ // i is row index, and row i has i+1 elements
            vector<int> vec;
            vec.push_back(res[i-1][0]);

            for(int j = 1; j < i; ++j){ // row i-1 has one element less than row i
                vec.push_back(res[i-1][j-1] + res[i-1][j]);
            }

            vec.push_back(res[i-1][i-1]);

            res.push_back(vec);
        }

        return res;
    }
};

/* unit test is in ../cpp_unittest/pascalTriangle_unittest */
