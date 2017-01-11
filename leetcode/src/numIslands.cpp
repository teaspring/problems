/*
 * given a 2d grid map of '1'(land) and '0'(water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horionztally or vertically.
 * assume all four edges of the grid are all surrounded by water.
 *
 * 11110
 * 11010
 * 11000
 * 00000, => 1
 *------------
 * 11000
 * 11000
 * 00100
 * 00011, => 3
 * */

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
    // depth-first search
    int numIslands_error_01(vector<vector<char> >& grid) {
        const int Rows = grid.size();
        if(Rows == 0)    return 0;
        const int Cols = grid[0].size();

        vector<vector<int> > tags;  // -2 for unprobed, -1 for probed, 0 for searched neighbours, 1/2/3.. for island index
        for(int i = 0; i < Rows; i++) {
            vector<int> tagRow;
            for(int j = 0; j < Cols; j++) {
                tagRow.push_back(-2);
            }
            tags.push_back(tagRow);
        }

        stack<int> stk; // save formalized coordinate in grid[][]
        stk.push(0);

        int islands = 0;
        while(!stk.empty()) {
            int form = stk.top();
            stk.pop();
            int i = form / Cols, j = form % Cols;

            if(grid[i][j] == '1') {
                tags[i][j] = islands + 1;
            }

            for(int alpha = -1; alpha < 1; alpha++) { // iterate 4 potential neighbours of [i][j]
                int h0 = i + alpha, v0 = j + alpha;
                for(int delta = 1; delta < 3; delta++) {
                    int h = h0 + ((delta >> 1) & 1);
                    int v = v0 + (delta & 1);
                    if (h < 0 || h >= Rows || v  < 0 || v >= Cols)    continue;

                    if(tags[h][v] == -2) {
                        tags[h][v] = -1; // probed, to search it later
                        stk.push(h * Cols + v);
                        continue;
                    }

                    if (grid[i][j] == '1' && tags[h][v] > 0) {
                        tags[i][j] = min(tags[i][j], tags[h][v]);  // update island to which grid[i][j] belongs
                    }
                }
            }

            if (grid[i][j] == '0') {
                tags[i][j] = 0;  // searched its neighbours already
            } else {
                islands = max(tags[i][j], islands);
            }
        }

        return islands;
    }

    // BFS
    int numIslands_error_02(vector<vector<char> >& grid) {
        const int Rows = grid.size();
        if(Rows == 0)    return 0;
        const int Cols = grid[0].size();

        int tags[Rows][Cols];
        memset(tags, 0, sizeof(tags));

        int islands = 0;
        for(int i = 0; i < Rows; i++) {
            for(int j = 0; j < Cols; j++) {
                if(grid[i][j] == '1') {
                    bool adjacentIsland = false;
                    if(i > 0 && grid[i-1][j] == '1') {
                        tags[i][j] = tags[i-1][j];
                        adjacentIsland = true;
                    }

                    if(j > 0 && grid[i][j-1] == '1') {
                        int less = min(tags[i][j], tags[i][j-1]);
                        tags[i][j] = tags[i][j-1] = less;
                        adjacentIsland = true;
                    }

                    if(!adjacentIsland) {
                        tags[i][j] = ++islands;
                    }
                }
            }
        }

        return islands;
    }

    // really working solution, BFS + DFS + ?
    int numIslands(vector<vector<char> >& grid) {
        const int Rows = grid.size();
        if(Rows == 0)    return 0;
        const int Cols = grid[0].size();

        int islands = 0;
        for(int i = 0; i < Rows; i++) {
            for(int j = 0; j < Cols; j++) {
                if(grid[i][j] == '1') {
                    clearRestOfLand(grid, i, j);
                    ++islands;
                }
            }
        }
        return islands;
    }

private:
    void clearRestOfLand(vector<vector<char> >& grid, int i, int j) {
        if(i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] == '0')    return;

        grid[i][j] = '0'; // drown the island !!!

        clearRestOfLand(grid, i-1, j);
        clearRestOfLand(grid, i, j-1);
        clearRestOfLand(grid, i+1, j);
        clearRestOfLand(grid, i, j+1);
    }
};
