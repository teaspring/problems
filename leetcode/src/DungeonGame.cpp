/*
 * the demons captured the princess(P) and imprisoned her in the bottom-right corner of a dungeon. the dungeon consists of M*N rooms laid out in a 2D grid. Our valiant knight(K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
 * he can only move rightward and downward, and each room contains threats or power-ups.
 * write a funtion to determine the knight's minimum initial health points so that he is able to rescue the princess.
 *
 * -2(K), -3,  3
 *  -5,  -10,  1
 *  10,   30, -5(P)
 *  result: the initial health of the knight must be at least 7 if he walks right, right, down, down.
 * */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    /*
     * solution 2:
     * [ 1, -3, 3;         
     *   0, -2, 0;  
     *  -3, -3,-3;]
     *
     * [   (1,2) |    (3,1) |   (3,4) |
     *     1,    |    -3,   |   3;    |
     *  (1,2)    |(3,1)     |(3,4)    |
     *  -------------------------------
     *     (1,2) |    (5,1) |   (3,4) |
     *     0,    |    -2,   |   0;    |
     *  (1,2)    |(2,1)     |(2,1)    |
     *  -------------------------------
     *     (3,1) |    (5,1) |   (3,1) |
     *     -3,   |    -3,   |   -3;   |
     *  (3,1)    |(6,1)     |(8,1)    |]
     *  so the result is 3
     *
     * compared to solution 1, the main difference is it think of every cell has two optional pairs of
     * (minInitHP, sumHP). one of it has the smallest initHP for current room itself, the other pair has
     * sufficient HP to help afford potential minus threats in next room.
     * */
    int calculateMinimumHP(vector<vector<int> > &dungeon){
        int n = dungeon.size();
        if(n == 0)    return 0;
        int m = dungeon[0].size();
        vector<vector<int> >  horiRow;
        vector<vector<int> >  leftBound;
        vector<int> startRoom;
        int p0 = 0, sum0 = 0;
        nextStep(1, 1, 1, 1, dungeon[0][0], p0, sum0);
        startRoom.push_back(p0);
        startRoom.push_back(sum0);
        startRoom.push_back(p0);  // room[0][0] has no predecessor
        startRoom.push_back(sum0);
        horiRow.push_back(startRoom);
        leftBound.push_back(startRoom);

        for(int j=1; j<m; j++){  // for row[0]
            int p1   = horiRow[j-1][0];
            int sum1 = horiRow[j-1][1];
            int p2   = horiRow[j-1][2];
            int sum2 = horiRow[j-1][3];
            int np = 0, nsum = 0;
            nextStep(p1, sum1, p2, sum2, dungeon[0][j], np, nsum);
            vector<int> room;
            room.push_back(np);
            room.push_back(nsum);
            room.push_back(np);  // for row[0], every room has only one predecessor
            room.push_back(nsum);
            horiRow.push_back(room);
        }

        for(int i=1; i<n; i++){  // for column[0]
            int p1   = leftBound[i-1][0];
            int sum1 = leftBound[i-1][1];
            int p2   = leftBound[i-1][2];
            int sum2 = leftBound[i-1][3];
            int np = 0, nsum = 0;
            nextStep(p1, sum1, p2, sum2, dungeon[i][0], np, nsum);
            vector<int> room;
            room.push_back(np);
            room.push_back(nsum);
            room.push_back(np);  // for column[0], every room has only one predecessor
            room.push_back(nsum);
            leftBound.push_back(room);
        }

        for(int i=1; i<n; i++){
            horiRow[0].clear();
            for(int k = 0; k < 4; k++){
                horiRow[0].push_back(leftBound[i][k]);
            }
            for(int j=1; j<m; j++){
                int np1 = 0, nsum1 = 0, np2 = 0, nsum2 = 0;
                nextStep(horiRow[j][0],
                         horiRow[j][1],
                         horiRow[j][2],
                         horiRow[j][3],
                         dungeon[i][j],
                         np1,
                         nsum1);
                nextStep(horiRow[j-1][0],
                         horiRow[j-1][1],
                         horiRow[j-1][2],
                         horiRow[j-1][3],
                         dungeon[i][j],
                         np2,
                         nsum2);
                horiRow[j].clear();
                horiRow[j].push_back(np1);
                horiRow[j].push_back(nsum1);
                horiRow[j].push_back(np2);
                horiRow[j].push_back(nsum2);
            }
        }
        return min(horiRow[m-1][0], horiRow[m-1][2]);
    }

private:
    /*
     * p1:   for path1 from predecessor(e.g. up room), min init HP
     * sum2: for path1 from predecessor(e.g. up room), sum HP with init HP p1
     * p2:   for path2 from predecessor(e.g. left room), min init HP
     * sum2: for path2 from predecessor(e.g. left room), sum HP with init HP p2
     * val: HP value of current room
     * np: 
     * */
    void nextStep(int p1, int sum1, int p2, int sum2,
            int val, int& np, int& nsum){
        int np1 = 0, nsum1 = 0, np2 = 0, nsum2 = 0;
        directStep(p1, sum1, val, np1, nsum1);
        directStep(p2, sum2, val, np2, nsum2);
        if(nsum1 == nsum2){  // key block to determine next step choice
            nsum = nsum1;
            np = min(np1, np2);
        }else if(np1 == np2){
            np = np1;
            nsum = max(nsum1, nsum2);
        }else if((np1 < np2 && nsum1 > nsum2) || (np1 > np2 && nsum1 < nsum2)){
            np = min(np1, np2);
            nsum = max(nsum1, nsum2);
        }else{   // (np1, nsum1) > or < (np2, nsum2)
            np = min(np1, np2);
            nsum = min(nsum1, nsum2);
        }
        return;
    }

    void directStep(int p, int sum, int val, int& np, int& nsum){
        int delta = (val >= 0 ? 0 : max(0, 1 - val - sum));
        np = p + delta;
        nsum = sum + delta + val;
        return;
    }
};

/* unit test is in ../cpp_unittest/dungeonGame_unittest/ */

