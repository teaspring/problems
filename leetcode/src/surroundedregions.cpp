/*
 * given a 2D board containing 'x' and '0', capture all regions surrounded by 'x'. A region is captured by flipping all '0's into 'x's in
 * that surrounded region.
 * For example:
 * x x x x
 * x 0 0 x    //can be captured
 * x x 0 x  //can be captured
 * x 0 x x
 *
 * solution: very smart!
 * mark all '0's can be iterated from 4 walls(up/down/left/right), then flip all '0's without being marked
 * */
#include "../header/preliminary.h"
#include <queue>

const int rs[4]={-1,0,0,1};
const int cs[4]={0,1,-1,0};

void bfs(int r, int c, const vector<vector<char> >& board, int **covered){
    int n = board.size();       //row count
    int m = board[0].size();    //column count
    covered[r][c] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    while(!q.empty()){    //iterate '0' in board starting from [r][c] in BFS
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + rs[i];
            int nc = c + cs[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(board[nr][nc]=='0' && !covered[nr][nc]){
                    covered[nr][nc] = 1;
                    q.push(make_pair(nr,nc));
                }
            }
        }
    }
    return;
}

void solve(vector<vector<char> > &board){
    int n = board.size();      //row count
    if(n<3)        return;     //at least it must be a 3*3 board
    int m = board[0].size();   //column count
    if(m<3)        return;
    int **covered = new int*[n];
    for(int i=0;i<n;i++){
        covered[i] = new int[m]();
    }

    for(int j=0;j<m;j++){    //iterate from up wall
        if(board[0][j]=='0' && !covered[0][j]){
            bfs(0,j, board, covered);
        }
    }
    for(int j=0;j<m;j++){    //iterate from low wall
        if(board[n-1][j]=='0' && !covered[n-1][j]){
            bfs(n-1, j, board, covered);
        }
    }
    for(int i=0;i<n;i++){    //iterate from left wall
        if(board[i][0]=='0' && !covered[i][0]){
            bfs(i,0, board, covered);
        }
    }
    for(int i=0;i<n;i++){    //iterate from right wall
        if(board[i][m-1]=='0' && !covered[i][m-1]){
            bfs(i, m-1, board, covered);
        }
    }

    for(int i=1;i<n-1;i++){    //flip all '0's inside the 4 walls in board
        for(int j=1;j<m-1;j++){
            if(board[i][j] == '0' && !covered[i][j]){
                board[i][j] = 'x';
            }
        }
    }

    for(int i=0;i<n;i++){
        delete[] covered[i];
        covered[i] = 0;
    }
    delete[] covered;
    return;
}

void display(const vector<vector<char> >& vec){
    printf("-------------------\n");
    for(size_t i=0;i<vec.size();i++){
        for(size_t j=0;j<vec[i].size();j++){
            printf("%c ", vec[i][j]);
        }
        printf("\n");
    }
}

/*
 *  x x x
 *  x 0 x
 *  x x x
 * */
void test_01(){
    vector<vector<char> > vec;
    vector<char> v0;
    v0.push_back('x');
    v0.push_back('x');
    v0.push_back('x');
    vec.push_back(v0);
    vector<char> v1;
    v1.push_back('x');
    v1.push_back('0');
    v1.push_back('x');
    vec.push_back(v1);
    vector<char> v2;
    v2.push_back('x');
    v2.push_back('x');
    v2.push_back('x');
    vec.push_back(v2);
    display(vec);

    solve(vec);
    display(vec);
    return;
}

/*
 * x x x 0
 * x 0 0 x
 * x 0 x 0
 * x x 0 x
 * */
void test_02(){
    vector<vector<char> > vec;
    vector<char> v0;
    v0.push_back('x');
    v0.push_back('x');
    v0.push_back('x');
    v0.push_back('0');
    vec.push_back(v0);
    vector<char> v1;
    v1.push_back('x');
    v1.push_back('0');
    v1.push_back('0');
    v1.push_back('x');
    vec.push_back(v1);
    vector<char> v2;
    v2.push_back('x');
    v2.push_back('0');
    v2.push_back('x');
    v2.push_back('0');
    vec.push_back(v2);
    vector<char> v3;
    v3.push_back('x');
    v3.push_back('x');
    v3.push_back('0');
    v3.push_back('x');
    vec.push_back(v3);
    display(vec);

    solve(vec);
    display(vec);
    return;
}

int main(int, char**){
    test_02();
    return 0;
}
