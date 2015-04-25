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
 * problem II: given n, generate a spiral matrix filled with 1 to n^2 in spiral order
 * e.g., for n = 3,
 * return:
 * 1 2 3
 * 8 9 4
 * 7 6 5
 * */
#include <vector>

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

        int idx = 0;
        while(1){
            idx %= 4;
            int l = lineLengths[idx % 2];
            if(l == 0)    break;

            for(int i = 0; i < l; i++){
                currX += xStep[idx];
                currY += yStep[idx];
                result.push_back(matrix[currX][currY]);
            }

            lineLengths[idx % 2]--;
            idx++;
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
        int idx = 0;

        vector<int> result;
        int currX = 0, currY = -1; // to make first element is [0][0]
        spiralEdge(matrix, currX, currY, idx % 4, lineLengths, xStep, yStep, result);

        return result;
    }

    /*
     * solution 1 to problem II
     * */
    vector<vector<int> > generateMatrix(int n){
        vector<vector<int> > matrix;
        if(n<1)        return matrix;
        int d = n, w = n;
        fillMatrix(matrix, n);
    
        int step[] = {1,-1,-1,1};
        int i=0, j=0, k=0, a=1;
        bool horizon = true;
        while(w>0 && d>0){
            if(horizon){
                if(k==0){
                    for(int cnt=0; cnt<w; ++cnt, ++j){
                        matrix[i][j] = a++;
                    }
                    --j;
                }else if(k==2){
                    for(int cnt=0; cnt<w; ++cnt, --j){
                        matrix[i][j] = a++;
                    }
                    ++j;
                }else{
                    break;
                }
                i += step[k];
                --d;
            }else{
                if(k==1){
                    for(int cnt=0; cnt<d; ++cnt, ++i){
                        matrix[i][j] = a++;
                    }
                    --i;
                }else if(k==3){
                    for(int cnt=0; cnt<d; ++cnt, --i){
                        matrix[i][j] = a++;
                    }
                    ++i;
                }else{
                    break;
                }
                j += step[k];
                --w;
            }
            k = (k+1)%4;
            horizon = !horizon;
        }
        return matrix;
    }

private:
    /*
     * used by spiralOrder_2()
     * */
    void spiralEdge(vector<vector<int> >& matrix, int currX, int currY, int idx,
                int lengths[], const int xStep[], const int yStep[], vector<int>& result){
        int l = lengths[idx % 2];
        if(l == 0)    return;

        int deltaX = xStep[idx];
        int deltaY = yStep[idx];
        for(int i = 0; i < l; i++){
            currX += deltaX;
            currY += deltaY;
            result.push_back(matrix[currX][currY]);
        }

        lengths[idx % 2]--;
        idx++;
        spiralEdge(matrix, currX, currY, idx % 4, lengths, xStep, yStep, result);
    }

    /*
     * used by generateSpiral()
     * */
    void fillMatrix(vector<vector<int> >& matrix, int n){
        if(n<1)        return;
        for(int i=0; i<n; ++i){
            vector<int> vec;
            for(int j=0; j<n; ++j){
                vec.push_back(0);
            }
            matrix.push_back(vec);
        }
        return;
    }
};

/* unit test is in ../cpp_unittest/spiralmatrix_unittest */

/*
void test_01(){
    int arr0[] = {1,2,3,4};
    vector<int> vec0(arr0, arr0 + 4);
    int arr1[] = {5,6,7,8};
    vector<int> vec1(arr1, arr1 + 4);
    int arr2[] = {9,10,11,12};
    vector<int> vec2(arr2, arr2 + 4);
    int arr3[] = {13,14,15,16};
    vector<int> vec3(arr3, arr3 + 4);
    vector<vector<int> > matrix;
    matrix.push_back(vec0);
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    displayVector(spiralOrder(matrix));
    return;
}
*/

