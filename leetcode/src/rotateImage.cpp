/*
 * given an n*n 2D matrix, rotate the image by 90 degrees clockwisely in place.
 * */
#include "../header/preliminary.h"

void swap(int &a, int &b){
    int tmp = b;
    b = a;
    a = tmp;
    return;
}

void rotateClockwiseQuarter(vector<vector<int> >& matrix){
    int n = matrix.size();
    if(n==0)    return;
    for(int i=0;i<n;i++){
        for(int j=0;j<(n>>1);j++){
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }
    return;
}

void showMatrix(const vector<vector<int> >& matrix){
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
    return;
}

void test_01(){
    string str;
    while(1){
        printf("please input positive n:\n");
        if(getline(cin, str)==0 || str.empty())    break;
        int n = atoi(str.c_str());
        if(n<1)    continue;
        vector<vector<int> > matrix;
        for(int i=0;i<n;i++){
            if(getline(cin, str)==0 || str.empty())    return;
            int *row = new int[str.size()]();
            int m = splitStr2IntArray(str, row);
            vector<int> vec;
            for(int j=0;j<m;j++){
                vec.push_back(row[j]);
            }
            matrix.push_back(vec);
            delete[] row;
            row=0;
        }
        printf("matrix input completed\n");
        rotateClockwiseQuarter(matrix);
        showMatrix(matrix);
    }
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
