/*
 * A city's skyline is the outer contour of the sihouette formed by all the buildings in that city when viewed from a distance.
 * Now given the locations and height of all the buildings as shown on a cityscape photo, output the skyline formed by these buildings collectively.
 * Input each building is represented as {[L, R, H]}, and output skyline is represented as {[x,y]}
 * Notes:
 * + input list is already sorted in ascending order by the left x position
 * + output list must be sorted by the x position
 * + there must be no consecutive horizontal lines of equal heights in output lines
 *
 * E.g. input [[2,9,10], [3,7,15], [5,12,12], [15,20,10], [19,24,8]]
 *     output [[2,10], [3,15], [7,12], [12,0], [15,10], [20,8], [24,0]]
 *
 * Analysis:
 * #1 consider case of two buildings:
 * (1)     |```|
 *     |```|```|```|
 *  in:  [1,4,1] == [1,2,1] + [2,3,1] + [3,4,1]
 *     + [2,3,2] == [2,3,2]
 *                = [1,2,1] + [2,3,2] + [3,4,1]
 *              <-> [1,1], [2,2], [3,1], [4,0]
 *
 * (2)     |```````|
 *     |```|```|   |
 *  in:  [1,3,1] == [1,2,1] + [2,3,1]
 *     + [2,4,2] == [2,3,2] + [3,4,2]
 *                = [1,2,1] + [2,4,2]
 *              <-> [1,1], [2,2], [4,0]
 *
 * (3) |`````````|
 *     |  |```|  |
 *  in:  [1,4,2] == [1,2,2] + [2,3,2] + [3,4,2]
 *     + [2,3,1] == [2,3,1]
 *                = [1,4,2]
 *              <-> [1,2], [4,0]
 *
 * (4) |``````|
 *     |   |`````|
 *  in:  [1,3,2] == [1,2,2] + [2,3,2]
 *     + [2,4,1] == [2,3,1] + [3,4,1]
 *                = [1,3,2] + [3,4,1]
 *              <-> [1,2], [3,1], [4,0]
 *
 * (5) |```|```|```|
 *  in:  [1,3,1] == [1,2,1] + [2,3,1]
 *     + [2,4,1] == [2,3,1] + [3,4,1]
 *                = [1,4,1]
 *              <-> [1,1], [4,0]
 *
 * (6) |```````|
 *     |```|   |
 *  in:  [1,2,1]
 *     + [1,3,2] == [1,2,2], [2,3,2]
 *                = [1,3,2]
 *              <-> [1,2], [3,0]
 *
 * #2 multi buildings to meet a new one building
 *
 *        |````````|
 *     |``|``|     |
 *     |  |  ``````|```|
 *  in:  [1,3,2]
 *     + [2,5,3]  == [2,5,3]
 *     + [2,6,1]  == [2,5,1] + [5,6,1]
 *                 = [1,2,2] + [2,5,3] + [5,6,1]
 *               <-> [1,2], [2,3], [5,1], [6,0]
 *
 *           |`````|
 *        |``|``|  |
 *     |``   |  |  |
 *     |     |  ```|```|
 *  in:  [1,4,2]  ==
 *     + [2,4,3]  ==
 *     + [3,5,4]  ==
 *     + [3,6,1]  ==
 *                 = [1,2,2] + [2,3,3] + [3,5,4] + [5,6,1]
 *               <-> [1,2], [2,3], [3,4], [5,1], [6,0]
 *
 *     |```````|
 *     |   |```|```|
 *     |   |```|```|```|
 *  in:  [1,3,3]  ==
 *     + [2,4,2]  ==
 *     + [2,5,1]  ==
 *                 = [1,3,3] + [3,4,2] + [4,5,1]
 *               <-> [1,3], [3,2], [4,1], [5,0]
 *
 *        |```````|
 *        |   |```|````````|
 *    |```|```|```|```|    |
 *    |   |   |   |   |    |
 *    |   |   |   |   |    |
 *
 *
 *    |`````````|
 *    |`````````|
 *    |`````````|
 *
 *
 *    |``````|
 *    |``````|```|
 *    |``````|```|```|
 *    |``````|```|```|```|
 *    |``````|```|```|```|```|
 *
 * */

#include <iostream>
#include <vector>
#include <utility>  // pair<>
#include <stack>

using namespace std;

class Solution{
public:
    // My solution: idea to merge buildings. as the output represent is not convenient for process, we will not convert data to line
    // coordinates until completing the merge process
    vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())    return vector<pair<int,int>>();

        vector<vector<int>> _buildings = mergeBuildings(buildings);
        return buildings2Lines(_buildings);
    }

private:
    // by now, it can process only two buildings
    vector<vector<int>> mergeBuildings(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        if(buildings.empty())    return result;

        result.push_back(buildings[0]);

        const int N = buildings.size();
        for(int i = 1; i < N; ++i) {
            vector<int> curr = buildings[i];

            stack<vector<int>> stk;  // FILO !!
            while(!result.empty() && result[result.size()-1][0] > curr[0]) { // given input list is sorted already, here the result<> will not exceed 0 range
                stk.push(result[result.size()-1]);
                result.pop_back();
            }

            mergeTailBuilding(result, curr); // find the right place to insert(merge) curr

            while(!stk.empty()) {
                mergeTailBuilding(result, stk.top());
                stk.pop();
            }
        }
        return result;
    }

    // merge two overlapped buildings, pre[0] <= curr[0] < pre[1]
    void mergeTailBuilding(vector<vector<int>>& buildings, vector<int>& curr) {
        vector<int> pre = buildings[buildings.size() - 1];
        if (pre[1] <= curr[0]) {
            appendBuilding(buildings, curr);
            return;
        }

        buildings.pop_back(); // two buildings must have overlap, reappend pre again

        vector<int> bu;
        if(pre[0] < curr[0]) { // if pre[0] == curr[0], no need to add this part
            bu.push_back(pre[0]);
            bu.push_back(curr[0]);
            bu.push_back(pre[2]);
            appendBuilding(buildings, bu);
        }

        bu.clear();
        bu.push_back(curr[0]);
        bu.push_back(min(pre[1], curr[1]));
        bu.push_back(max(pre[2], curr[2])); // overlapped part
        appendBuilding(buildings, bu);

        bu.clear();
        if(pre[1] > curr[1]) {
            bu.push_back(curr[1]);
            bu.push_back(pre[1]);
            bu.push_back(pre[2]);
        } else {
            bu.push_back(pre[1]);
            bu.push_back(curr[1]);
            bu.push_back(curr[2]);
        }
        appendBuilding(buildings, bu);
    }

    // reduce the buildings while a new one is appended
    void appendBuilding(vector<vector<int>>& buildings, vector<int>& element) {
        if(element[0] == element[1])    return;

        if(buildings.empty()) {
            buildings.push_back(element);
            return;
        }

        const int N = buildings.size();
        vector<int> pre = buildings[N - 1];
        if(pre[1] < element[0]) { // not consecutive
            buildings.push_back(element);
            return;
        }

        // by now it must be pre[1] == element[0], two buildings are consecutive
        if (pre[2] != element[2]){ // two buildings have different heights
            buildings.push_back(element);
            return;
        }

        buildings[N-1][1] = element[1]; // two consecutive buildings have same height, merge them
    }

    vector<pair<int, int>> buildings2Lines(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        result.push_back(pair<int, int>(buildings[0][0], buildings[0][2]));

        const int N = buildings.size();
        for(int i = 1; i < N; i++) {
            vector<int> pre  = buildings[i-1];
            vector<int> curr = buildings[i];
            if(pre[1] != curr[0]) { // distance exist between two buildings
                result.push_back(pair<int, int>(pre[1], 0)); // line with height 0
            }
            result.push_back(pair<int, int>(curr[0], curr[2]));
        }
        result.push_back(pair<int, int>(buildings[N-1][1], 0));

        return result;
    }
};
