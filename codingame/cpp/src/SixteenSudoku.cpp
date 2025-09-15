/**
 * 16x16 Sudoku.
 * An empty cell is represented by . and the letters A to P are used to fill the grid.
 * Each line contains exactly one occurrence of each letter.
 * Each column contains exactly one occurrence of each letter.
 * Each block (4x4 cells) contains exactly one occurrence of each letter.
 *
 */
 #include <vector>
 #include <sstream>
 #include <cassert>
 #include <iostream>
 #include <set>
 #include <bit>

using namespace std;

class Solution 
{
    public:

    bool solve_sudoku(vector<string>& board)
    {
        // every uint16_t represents used chars within an area of 16 chars
        vector<uint16_t> row_used(16, 0), col_used(16, 0), square_used(16, 0);
        vector<pair<int, int>> empties; // test proves bit byte used here does not help on performance
        // init
        for (auto r = 0; r < 16; r++)
        {
            for (auto c = 0; c < 16; c++)
            {
                char ch = board[r][c];
                if (ch != '.')
                    set_used(r, c, ch, row_used, col_used, square_used);
                else
                    empties.emplace_back(r, c); // all of the empty cells
            }
        }
        return backtrack(board, row_used, col_used, square_used, empties, 0);
    }  

    private:

    inline int idx(char ch) { return ch - 'A'; }
    inline int block(int r, int c) { return (r / 4) * 4 + (c / 4); }
    //
    inline uint8_t store_rc(int r, int c) { return static_cast<unsigned char>(r) << 4 | (0x0F & static_cast<unsigned char>(c)); }
    inline int low_4bt(unsigned char x) { return x & 0x0F; }
    inline int high_4bt(unsigned char x) { return (x >> 4) & 0x0F; }

    void set_used(int r, int c, char ch,
        vector<uint16_t>& row_used,
        vector<uint16_t>& col_used,
        vector<uint16_t>& square_used)
    {
        int bit = 1 << idx(ch);
        row_used[r] |= bit;
        col_used[c] |= bit;
        square_used[block(r, c)] |= bit;
    }

    void unset_used(int r, int c, char ch,
        vector<uint16_t>& row_used,
        vector<uint16_t>& col_used,
        vector<uint16_t>& square_used)
    {
        int bit = ~(1 << idx(ch)); // bitwise NOT
        row_used[r] &= bit;
        col_used[c] &= bit;
        square_used[block(r, c)] &= bit;
    }

    // using the Minimum Remaining Value(MRV) heuristic, but via set<> which is not best performance
    bool backtrack(vector<string>& board, vector<set<char>>& row_used,
        vector<set<char>>& col_used, vector<set<char>>& square_used)
    {
        int min_choices = 17; // choose the cell with minimum options
        set<unsigned int> min_choices_st;
        int x = -1, y = -1;
        for (int r=0; r < 16; r++)
        {
            for (int c=0; c < 16; c++)
            {
                if (board[r][c] == '.')
                {
                    set<unsigned int> candidates;
                    for (char ch='A'; ch <= 'P'; ch++)
                    {
                        if (!row_used[r].contains(ch) && !col_used[c].contains(ch)
                            && !square_used[(r/4)*4 + c/4].contains(ch))
                        {
                            candidates.insert((unsigned int)ch);
                        }
                    }
                    if (candidates.empty()) return false; // prune
                    if (candidates.size() < min_choices) {
                        min_choices = candidates.size();
                        x = r, y = c;
                        min_choices_st.clear();
                        min_choices_st.merge(candidates);
                    }
                }
            }
        }
        if (x == -1)    return true;
        // MRV heuristic
        for (auto it = min_choices_st.cbegin(); it != min_choices_st.cend(); it++)
        {
            char ch = (char)*it;
            if (!row_used[x].contains(ch) && !col_used[y].contains(ch)
                && !square_used[(x/4)*4 + y/4].contains(ch))
            {
                row_used[x].insert(ch);
                col_used[y].insert(ch);
                square_used[(x/4)*4 + y/4].insert(ch);
                board[x][y] = ch;
                if (backtrack(board, row_used, col_used, square_used)) return true;
                board[x][y] = '.';
                row_used[x].erase(ch);
                col_used[y].erase(ch);
                square_used[(x/4)*4 + y/4].erase(ch);
            }
        }
        return false;
    }

    // really high performanced method
    bool backtrack(vector<string>& board,
        vector<uint16_t>& row_used, vector<uint16_t>& col_used, vector<uint16_t>& block_used,
        vector<pair<int, int>>& empties, int pos)
    {
        int min_choices = 17, min_pos = -1;
        for (int i = pos; i < empties.size(); ++i) {
            auto r = empties[i].first, c = empties[i].second;
            uint16_t used = row_used[r] | col_used[c] | block_used[block(r, c)]; // efficient way to collect all the used chars around the position
            int choices = 16 - popcount(used); // equaivalent with __builtin_popcount(), counts the number of 1 bits in an unsigned integer
            if (choices == 0) return false; // prune
            if (choices < min_choices) {
                min_choices = choices;
                min_pos = i;
                if (choices == 1) break; // can't get better than 1
            }
        }
        if (min_pos == -1) return true; // empties is empty, solved

        // Swap to process the cell with min_choices now
        swap(empties[pos], empties[min_pos]);
        int r = empties[pos].first, c = empties[pos].second;
        uint16_t used = row_used[r] | col_used[c] | block_used[block(r, c)];
        for (int i = 0; i < 16; ++i) {
            if (!(used & (1 << i))) {
                char ch = 'A' + i;
                board[r][c] = ch;
                set_used(r, c, ch, row_used, col_used, block_used);
                if (backtrack(board, row_used, col_used, block_used, empties, pos + 1)) return true;
                unset_used(r, c, ch, row_used, col_used, block_used);
                board[r][c] = '.';
            }
        }
        swap(empties[pos], empties[min_pos]); // restore order
        return false;
    }
};
