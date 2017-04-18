/*
 * A city's skyline is the outer contour of the sihouette formed by all the buildings in that city when viewed from a distance.
 * Now given the locations and height of all the buildings as shown on a cityscape photo, output the skyline formed by these buildings collectively.
 * Input each building is represented as {[L, R, H]}, and output skyline is represented as {[x,y]}
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
 *     |  |  ```|  |
 *
 *        |``````|
 *        |```|  |
 *     |``|   |  |
 *     |  |   ```|```|
 *
 * */

#include <iostream>
#include <vector>
#include <utility>  // pair<>

using namespace std;

class Solution{
public:
    vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())    return vector<pair<int,int>>();

        vector<vector<int>> _buildings = mergeBuildings(buildings);
        return buildings2Lines(_buildings);
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

private:
    // by now, it can process only two buildings
    vector<vector<int>> mergeBuildings(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        if(buildings.empty())    return result;

        result.push_back(buildings[0]);
        const int N = buildings.size();
        for(int i = 1; i < N; ++i) {
            vector<int> pre = result[result.size() - 1];
            vector<int> curr = buildings[i];

            if (pre[1] <= curr[0]) {
                appendBuilding(result, curr);
            } else { // pre[1] > curr[0]
                result.pop_back();

                if(pre[0] < curr[0]) { // if pre[0] == curr[0], no need to add this part
                    vector<int> bu1(pre[0]);
                    bu1.push_back(curr[0]);
                    bu1.push_back(pre[2]);
                    appendBuilding(result, bu1);
                }

                vector<int> bu(curr[0]);
                bu.push_back(min(pre[1], curr[1]));
                bu.push_back(max(pre[2], curr[2])); // overlapped part
                appendBuilding(result, bu);

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
                appendBuilding(result, bu);
            }
        }

        return result;
    }

    // reduce the buildings while each new one is appended
    void appendBuilding(vector<vector<int>>& buildings, vector<int>& element) {
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

        // now it must be pre[1] == element[0], two buildings are consecutive
        if (pre[2] != element[2]){ // two buildings have different heights
            buildings.push_back(element);
            return;
        }

        buildings[N-1][1] = element[1]; // two consecutive buildings have same height, merge them
    }
};
