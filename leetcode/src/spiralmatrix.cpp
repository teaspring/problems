/*
 * given a matrix of mx x n elements(m rows, n columns), return all elements of the matrix in spiral order
 *
 * problem I: given a matrix of n*m, output its elements in spiral order
 * e.g.
 * 1  2  3  4 
 * 5  6  7  8
 * 9 10 11 12
 * output in spiral order: 1,2,3,4,8,12,11,10,9,5,6,7
 *
 * problem II: given n and m, generate a spiral matrix of n * m filled with 1 to n*m in spiral order
 * e.g., for n = 3,
 * return:
 * 1 2 3
 * 8 9 4
 * 7 6 5
 * */

#include <vector>
#include <cstring>

using namespace std;

class Solution{

public:
    /*
     * solution 1 to problem I
     * */
    vector<int> spiralOrder_1(vector<vector<int> >& matrix){
        if(matrix.empty())    return vector<int>();

        const int n = matrix.size();
        const int m = matrix[0].size();
        int lineLengths[] = {m, n-1};

        const int xStep[] = {0, 1, 0, -1};
        const int yStep[] = {1, 0, -1, 0};

        vector<int> result;
        int currX = 0, currY = -1; // to make first element is [0][0]

        int mode = 0;
        while(1){
            mode %= 4;
            int l = lineLengths[mode % 2];
            if(l == 0)    break;

            for(int i = 0; i < l; i++){
                currX += xStep[mode];
                currY += yStep[mode];
                result.push_back(matrix[currX][currY]);
            }

            lineLengths[mode % 2]--;
            mode++;
        }

        return result;
    }

    /*
     * soluton 2 to problem I. recurse is a good option for this solution
     * */
    vector<int> spiralOrder_2(vector<vector<int> >& matrix){
        if(matrix.empty())    return vector<int>();

        const int n = matrix.size();
        const int m = matrix[0].size();
        int lineLengths[] = {m, n-1};

        const int xStep[] = {0, 1, 0, -1};
        const int yStep[] = {1, 0, -1, 0};
        int mode = 0;

        vector<int> result;
        int currX = 0, currY = -1; // to make first element is [0][0]
        spiralEdge(matrix, currX, currY, mode % 4, lineLengths, xStep, yStep, result);

        return result;
    }

    /*
     * solution 1 to problem II
     * obviously it should operate on a int[][], and initialize vector<<> > to return
     * */
    vector<vector<int> > generateMatrix(int n, int m){
        vector<vector<int> > matrix;
        if(n < 1)        return matrix;

        int mat[n][m];
        memset(mat, 0, sizeof(mat)/sizeof(int));

        int lineLengths[] = {m, n-1};

        const int xStep[] = {0, 1, 0, -1};
        const int yStep[] = {1, 0, -1, 0};
        int mode = 0, val = 1;

        int currX = 0, currY = -1; // to make first element is [0][0]
        while(1){
            mode %= 4;
            int l = lineLengths[mode % 2];
            if(l == 0)    break;

            for(int i = 0; i < l; i++){
                currX += xStep[mode];
                currY += yStep[mode];
                mat[currX][currY] = val++;
            }

            lineLengths[mode % 2]--;
            mode++;
        }

        for(int i = 0; i < n; i++){
            matrix.push_back(vector<int>(mat[i], mat[i] + m));
        }
        return matrix;
    }

private:
    /*
     * used by spiralOrder_2()
     * */
    void spiralEdge(vector<vector<int> >& matrix, int currX, int currY, int mode,
                int lengths[], const int xStep[], const int yStep[], vector<int>& result){
        int l = lengths[mode % 2];
        if(l == 0)    return;

        int deltaX = xStep[mode];
        int deltaY = yStep[mode];
        for(int i = 0; i < l; i++){
            currX += deltaX;
            currY += deltaY;
            result.push_back(matrix[currX][currY]);
        }

        lengths[mode % 2]--;
        mode++;
        spiralEdge(matrix, currX, currY, mode % 4, lengths, xStep, yStep, result);
    }
};

/* unit test is in ../cpp_unittest/spiralmatrix_unittest */
