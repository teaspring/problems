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

/*
 * solution1 with bug:
 * P[i][j] - minimum initial health points starting from room [0][0]
 * Sum[i][j] - health points for knight with minimum initial P[i][j] to reach room [i][j]
 * V[i][j] - health threats or power-up for room [i][j]
 *
 * if V[i][j] >= 0, P[i][j] = min{P[i-1][j], P[i][j-1]
 * if V[i][j] < 0,
 * as Sum[i-1][j] + delta1 + V[i][j] >= 1, delta1 = max{0, 1-V[i][j]-Sum[i-1][j]}
 * delta2 = max{0, 1-V[i][j]-Sum[i][j-1]}
 * P[i][j] = min(delta1 + P[i-1][j], delta2 + P[i][j-1])
 * Sum[i][j] = V[i][j] + down or right ? Sum[i-1][j] : Sum[i][j-1]
 * */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int calculateMinimumHP_bug(vector<vector<int> > &dungeon){
        int n = dungeon.size();
        if(n == 0)    return 0;
        int m = dungeon[0].size();
        int P[n][m];  // P[i][j] is minimum initial health point for knight move from top left to [i][j]
        int Sum[n][m];  // Sum[i][j] is the sum of health points of knight move from top left with initial P[i][j]
        memset(P, 0, sizeof(P)/sizeof(int));
        memset(Sum, 0, sizeof(Sum)/sizeof(int));
        P[0][0]   = 1 + (dungeon[0][0] > 0 ? 0 : 0 - dungeon[0][0]);
        Sum[0][0] = 1 + (dungeon[0][0] > 0 ? dungeon[0][0] : 0);
        for(int i = 1; i<n; ++i){
            P[i][0] = P[i-1][0] + max(0, 1 - dungeon[i][0] - Sum[i-1][0]);
            Sum[i][0] = Sum[i-1][0] + (P[i][0] - P[i-1][0]) + dungeon[i][0];
        }
        for(int j = 1; j<m; ++j){
            P[0][j] = P[0][j-1] + max(0, 1 - dungeon[0][j] - Sum[0][j-1]);
            Sum[0][j] = Sum[0][j-1] + (P[0][j] - P[0][j-1]) + dungeon[0][j];
        }

        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                if(dungeon[i][j] > 0){
                    if(P[i-1][j] < P[i][j-1]){  // downward
                        P[i][j] = P[i-1][j];
                        Sum[i][j] = Sum[i-1][j] + dungeon[i][j];
                    }else{  // rightward
                        P[i][j] = P[i][j-1];
                        Sum[i][j] = Sum[i][j-1] + dungeon[i][j];
                    }
                }else{
                    int delta1 = max(0, 1 - dungeon[i][j] - Sum[i-1][j]);
                    int delta2 = max(0, 1 - dungeon[i][j] - Sum[i][j-1]);
                    if(delta1 + P[i-1][j] < delta2 + P[i][j-1]){ // downward
                        P[i][j] = delta1 + P[i-1][j];
                        Sum[i][j] = Sum[i-1][j] + delta1 + dungeon[i][j];
                    }else{  // rightward
                        P[i][j] = delta2 + P[i][j-1];
                        Sum[i][j] = Sum[i][j-1] + delta2 + dungeon[i][j];
                    }
                }
            }
        }
        return P[n-1][m-1];
    }

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
     *  unfortunately, this solution fails for unitttest case Function Test -> Positive04 :(
     * */
    
    int calculateMinimumHP(vector<vector<int> > &dungeon){
        int n = dungeon.size();
        if(n == 0)    return 0;
        int m = dungeon[0].size();
        vector<vector<int> >  twiRows[2];
        vector<vector<int> >  leftBound;
        vector<int> startRoom;
        int p0 = 0, sum0 = 0;
        nextStep(1, 1, 1, 1, dungeon[0][0], p0, sum0);
        startRoom.push_back(p0);
        startRoom.push_back(sum0);
        startRoom.push_back(p0);  // room[0][0] has no predecessor
        startRoom.push_back(sum0);
        int currR = 0;
        twiRows[currR].push_back(startRoom);
        leftBound.push_back(startRoom);

        for(int j=1; j<m; j++){  // for row[0]
            int p1   = twiRows[currR][j-1][0];
            int sum1 = twiRows[currR][j-1][1];
            int p2   = twiRows[currR][j-1][2];
            int sum2 = twiRows[currR][j-1][3];
            int np = 0, nsum = 0;
            nextStep(p1, sum1, p2, sum2, dungeon[0][j], np, nsum);
            vector<int> room;
            room.push_back(np);
            room.push_back(nsum);
            room.push_back(np);  // for row[0], every room has only one predecessor
            room.push_back(nsum);
            twiRows[currR].push_back(room);
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
            currR = 1 - currR;
            twiRows[currR].clear();
            twiRows[currR].push_back(leftBound[i]);
            for(int j=1; j<m; j++){
                int np1 = 0, nsum1 = 0, np2 = 0, nsum2 = 0;
                nextStep(twiRows[1 - currR][j][0],
                         twiRows[1 - currR][j][1],
                         twiRows[1 - currR][j][2],
                         twiRows[1 - currR][j][3],
                         dungeon[i][j],
                         np1,
                         nsum1);
                nextStep(twiRows[currR][j-1][0],
                         twiRows[currR][j-1][1],
                         twiRows[currR][j-1][2],
                         twiRows[currR][j-1][3],
                         dungeon[i][j],
                         np2,
                         nsum2);
                vector<int> room;
                room.push_back(np1);
                room.push_back(nsum1);
                room.push_back(np2);
                room.push_back(nsum2);
                twiRows[currR].push_back(room);
            }
        }
        return min(twiRows[currR][m-1][0], twiRows[currR][m-1][2]);
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
        }else{ // (np1, nsum1) > or < (np2, nsum2)
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
/*
void test(){
    int arr1[] = {1, -3, 3};
    int arr2[] = {0, -2, 0};
    int arr3[] = {-3, -3, -3};
    vector<vector<int> > dungeon;
    dungeon.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));
    dungeon.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));
    Solution s;
    s.calculateMinimumHP(dungeon);
 }

int main(){
    test();
}
*/
