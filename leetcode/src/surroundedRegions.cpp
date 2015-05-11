/*
 * given a 2D board containing 'x' and '0', capture all regions surrounded by 'x'.
 * A region is captured by flipping all '0's into 'x's in that surrounded region.
 *
 * For example:
 * x x x x
 * x 0 0 x  // can be captured
 * x x 0 x  // can be captured
 * x 0 x x  // cannot be captured
 *
 * captured cell becomes '$'
 *
 * very smart solution !
 * mark all '0's can be traversed from top/bottom/left/right walls, then flip all the rest '0's to 'x'
 * */
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const int rs[4] = {-1, 0, 0, 1};
const int cs[4] = {0, 1, -1, 0};

class Solution{

public:
    /*
     *
     * */
    void solve(vector<vector<char> > &board){
        const int n = board.size();  // rows
        if(n < 3)    return;

        const int m = board[0].size();  // columns
        if(m < 3)    return;

        int **covered = new int*[n];
        for(int i = 0; i < n; i++){
            covered[i] = new int[m]();
        }

        // BFS traverse from top/bottom/left/right walls
        for(int j = 0; j < m; j++){  // scan from top wall
            if(board[0][j] != 'x' && !covered[0][j]){
                bfs(0, j, board, covered);
            }
        }

        for(int j = 0; j < m; j++){  // scan from bottom wall
            if(board[n-1][j] != 'x' && !covered[n-1][j]){
                bfs(n-1, j, board, covered);
            }
        }

        for(int i = 0; i < n; i++){  // scan from left wall
            if(board[i][0] != 'x' && !covered[i][0]){
                bfs(i, 0, board, covered);
            }
        }

        for(int i = 0; i < n; i++){  // scan from right wall
            if(board[i][m-1] != 'x' && !covered[i][m-1]){
                bfs(i, m-1, board, covered);
            }
        }

        // flip all '0's which is not marked
        for(int i = 1; i < n-1; i++){  // flip all '0's inside the 4 walls which has not been marked yet
            for(int j = 1; j < m-1; j++){
                if(board[i][j] != 'x' && !covered[i][j]){
                    board[i][j] = '@';
                }
            }
        }

        // clean
        for(int i = 0; i < n; i++){
            delete[] covered[i];
            covered[i] = NULL;
        }

        delete[] covered;
        covered = NULL;
    }

private:
    /*
     * BFS traverse from cell [r,c] to inside
     * */
    void bfs(int r, int c, const vector<vector<char> >& board, int **covered){
        const int n = board.size();     // rows
        const int m = board[0].size();  // columns

        covered[r][c] = 1;

        q.push(make_pair(r, c));

        while(!q.empty()){  // traverse following '0' on board starting from [r][c]

            r = q.front().first;
            c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){ // orentation to top/bottom/left/right
                int nr = r + rs[i];
                int nc = c + cs[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){ // valid position
                    if(board[nr][nc] != 'x' && !covered[nr][nc]){
                        covered[nr][nc] = 1;
                        q.push(make_pair(nr,nc));
                    }
                }
            }
        }   // when while clause exits, q turns empty
    }

private:
    queue<pair<int, int> > q;  // for BFS traverse
};

/* unit test is in ../cpp_unittest/surroundedRegions_unittest */
