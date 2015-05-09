/*
 * determine if a Sudoku is valid. null cell is char '.'
 * */

#include <cstring>
#include <vector>

using namespace std;

class Solution{

public:
    /*
     * @param board is 9*9
     * */
    bool isValidSudoku(const vector<vector<char> > &board){
        const int n = board.size();

        vector<char> block;

        /*
         * check each row
         * */
        for(int i = 0; i < n; ++i){
            block.clear();

            for(int j = 0; j < n; ++j){
                char ch = board[i][j];
                if(ch != '.')    block.push_back(ch);
            }

            if(!check(block))    return false;
        }

        /*
         * check each column
         * */
        for(int j = 0; j < n; ++j){
            block.clear();

            for(int i = 0; i < n; ++i){
                char ch = board[i][j];
                if(ch != '.')    block.push_back(ch);
            }

            if(!check(block))    return false;
        }

        /*
         * check every 3*3 cube
         * */
        int cnt = 9;
        block.clear();

        // tricky to map every 9 cursor numbers to a 3*3 cube
        for (int t = 0; t < 81; t++){
            int l = t / 9; // l remains constant for every 9 numbers, and vary in [0, 8] in total
            int r = t % 9; // r is [0, 8] for every continuous 9 numbers

            // [cx][cy] is left up corner of the 3*3 cube that the int belongs to
            int cx = l / 3 * 3;  // f(x) = x / 3 * 3 is to floor x to multiplies of 3, like [0,3,6]
            int cy = l % 3 * 3;  // f(x) = x % 3 * 3 is to map every [0,1,2] to [0,3,6]

            char ch = board[cx + r / 3][cy + r % 3];  // real position on board

            if(ch != '.')    block.push_back(ch);

            cnt--;

            if(cnt == 0){
                if(!check(block))    return false;

                block.clear();
                cnt += 9;
            }
        }

        return true;
    }

private:
    /*
     * check a vector<> whether have < 9 or > 9 or duplicate int
     * */
    bool check(const vector<char>& vec){
        int pos[9];
        memset(pos, 0, sizeof(pos));

        const int n = vec.size();
        for(int i = 0; i < n; i++){
            int offset = vec[i] - '1';

            if(pos[offset] == 1 || offset < 0 || offset > 8)    return false;

            pos[offset] = 1;
        }

        return true;
    }
};

/* unit test is in ../cpp_unittest/validSudoku_unittest */
