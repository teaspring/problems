/*
 * given n points on a 2D plane, find maximum number of points on one straight line
 *
 * cases:
 * 1. if calculating slope, process p1.x == p2.x
 * 2. if there is duplicate points
 * 3. all points are duplicate
 * */

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
    Point(int a, int b) : x(a), y(b){}
};

class Solution{

public:
    /*
     * fix a line with one point and slope, OK, how to present slope ? as it is not integer and float has decision dependency
     * the idea with two integer x and y pair to present slope is very good, elegent
     * */
    int maxPoints(vector<Point> &points){
        const int n = points.size();
        if(n < 2)    return n;

        map<int, map<int, int> > mp;  // to record points on a line
        int result = 2;

        for(int i = 0; i < n; i++){
            mp.clear();
            int overlap = 0, cmax = 0;

            for(int j = i+1; j < n; j++){
                int x = points[j].x - points[i].x;
                int y = points[j].y - points[i].y;

                if(x == 0 && y == 0){
                    overlap++;
                    continue;
                }

                int gcd = getGCD(x, y);

                if(gcd != 0){
                    x /= gcd;
                    y /= gcd;
                }

                if(mp.find(x) != mp.end()){
                    map<int, int> innerMap = mp.find(x)->second; // NOTE: here innerMap is a copy of map<> in mp!
                    if(innerMap.find(y) == innerMap.end()){
                        mp[x][y] = 1;
                    }else{
                        mp[x][y]++;
                    }
                }else{
                    mp[x][y] = 1;
                }

                cmax = max(cmax, mp[x][y]);
            }

            result = max(result, cmax + overlap + 1);
        }

        return result;
    }

private:
    int getGCD(int a, int b){
        return b == 0 ? a : getGCD(b, a % b);
    }

};

/* unit test is in ../cpp_unittest/maxPoints_unittest */
