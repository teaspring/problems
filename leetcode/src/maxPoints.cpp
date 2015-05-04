/*
 * given n points on a 2D plane, find maximum number of points on one straight line
 *
 * cases:
 * 1. if calculating slope, process p1.x == p2.x
 * 2. if there is duplicate points
 * 3. all points are duplicate
 * */
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
    Point(int a, int b) : x(a), y(b){}
};

struct Line{
    int start;
    int end;
    Line(int s = 0, int e = 0) : start(s), end(e){}
};

class Solution{

public:
    /*
     *
     * */
    int maxPoints_01(vector<Point> &points){
        sort(points.begin(), points.end(), point_cmp);  // sorted

        const int n = points.size();
        if(n <= 2)    return n;

        vector<Point> upoints;  // unique points without duplicate
        upoints.push_back(points[0]);

        int dups[n];  // duplicate count of unique point
        dups[0] = 1;

        int m = 1;    // m is count of all unique points

        for(int i = 1; i < n; i++){
            if(points[i].x == points[i-1].x
            && points[i].y == points[i-1].y){
                dups[m-1]++;
            }else{
                m++;
                dups[m-1] = 1;
                upoints.push_back(points[i]);
            }
        }

        if(m == 1)    return n;  //only 1 unique point, unnecessary to get slope any more!

        map<float, vector<Line> > slopes;

        for(int i = 0; i < m-1; ++i){    // calculate slope within unique points
            for(int j = i+1; j < n; ++j){
                float f = slope(upoints[i], upoints[j]);
                if(slopes.count(f) == 0){
                    vector<Line> vec;
                    slopes[f] = vec;
                }
                slopes[f].push_back(Line(i, j));
            }
        }

        int res = 2;
        for(map<float, vector<Line> >::iterator iter = slopes.begin();
            iter != slopes.end(); ++iter){
            res = max(res, maxNodesOnLine(iter->second, dups));
        }
        return res;
    }

    /*
     *
     * */
    int maxPoints_02(vector<Point> &points){
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
    // used by maxPoints_01()
    float slope(Point &p1, Point &p2){ // slope of two unique points, take care of p1.x == p2.x
        return p1.x == p2.x ? 0xffff : (float)(p1.y - p2.y) / (float)(p1.x - p2.x);
    }

    // used by maxPoints_01()
    int maxNodesOnLine(vector<Line> &lines, int dups[]){
        const int n = lines.size();
        int res = 2, curr = 2;

        for(int i = 1; i <= n; ++i){  // implicit tip: process the edge i==n !
            if(i == n || lines[i].start != lines[i-1].start){
                curr += dups[lines[i-1].start] - 1;  // complement the duplicate points
                res = max(res, curr);
                curr = 2;
            }else{
                curr++;
            }
        }
        return res;
    }

    static bool point_cmp(Point p1, Point p2){
        if(p1.x < p2.x){
            return true;
        }else if(p1.x > p2.x){
            return false;
        }else{
            return p1.y <= p2.y;
        }
    }

    // used by maxPoints_02()
    int getGCD(int a, int b){
        return b == 0 ? a : getGCD(b, a % b);
    }

};

/* unit test is in ../cpp_unittest/maxPoints_unittest */
