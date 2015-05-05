/*
 * given an n*n 2D matrix, rotate the image by 90 degrees clockwisely in place.
 * */
#include <vector>

using namespace std;

class Solution{

public:
    void rotateClockwiseQuarter(vector<vector<int> >& matrix){
        if(matrix.empty())    return;

        const int n = matrix.size();

        for(int j = 0; j < n; j++){
            for(int i = 0; i < (n>>1); i++){
                swap(matrix[i][j], matrix[n-1 - i][j]); // rotate column 90'
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

private:
    void swap(int &a, int &b){
        int tmp = b;
        b = a;
        a = tmp;
    }
};

/* unit test is in ../cpp_unittest/rotateImage_unittest */
