/*
 * given n points on a 2D plane, find maximum number of points on one straight line
 *
 * cases:
 * 1. if calculating slope, process p1.x == p2.x
 * 2. if there is duplicate points
 * 3. all points are duplicate
 * */
#include "../header/preliminary.h"

using namespace std;

struct Point{
    int x;
    int y;
    Point() : x(0), y(0){}
    Point(int a, int b) : x(a), y(b){}
};

struct Line{
    int start;
    int end;
    Line(int s=0, int e=0) : start(s), end(e){}
};

bool point_cmp(Point p1, Point p2){
    if(p1.x < p2.x){
        return true;
    }else if(p1.x > p2.x){
        return false;
    }else{
        return p1.y <= p2.y;
    }
}

class Solution{
public:
    int maxPoints(vector<Point> &points){
        sort(points.begin(), points.end(), point_cmp);  // sorted
        int n = points.size();
        if(n <= 2)    return n;
        /*
        for(int i=0; i<n; i++){
            cout << "(" << points[i].x << ", " << points[i].y << "),";
        }
        cout << endl;
        */
        vector<Point> upoints;  // unique points without duplicate
        int dups[n];            // duplicate count of unique point
        upoints.push_back(points[0]);
        int m = 1;    // m is count of all unique points
        dups[m-1] = 1;
        for(int i=1; i<n; i++){
            if(points[i].x == points[i-1].x
            && points[i].y == points[i-1].y){
                dups[m-1]++;
            }else{
                m++;
                dups[m-1] = 1;
                upoints.push_back(points[i]);
            }
        }
        /*
        for(int i=0; i<m; i++){
            cout << "(" << upoints[i].x << ", " << upoints[i].y << "),";
        }
        cout << endl;
        for(int i=0; i<m; i++){
            cout << dups[i] << ", ";
        }
        cout << endl;
        */
        if(m==1)    return n;  //only 1 unique point, unnecessary to get slope any more!
        map<float, vector<Line> > slopes;
        for(int i=0; i<m-1; ++i){    // calculate slope within unique points
            for(int j=i+1; j<n; ++j){
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

private:
    float slope(Point &p1, Point &p2){ // slope of two unique points, take care of p1.x == p2.x
        return p1.x == p2.x ? 0xffff : (float)(p1.y - p2.y) / (float)(p1.x - p2.x);
    }

    int maxNodesOnLine(vector<Line> &lines, int dups[]){
        int n = lines.size();
        int res = 2, curr = 2;
        for(int i=1; i<=n; ++i){  // implicit tip: process the edge i==n !
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
};

void test_01(){
    string str;
    while(1){
        cout << "please input points of integer x and y" << endl;
        if(getline(cin, str)==0 || str.empty())    break;
        int arr[str.size()];
        int n = splitStr2IntArray(str, arr);
        vector<Point> points;
        for(int i=0; i<n/2; i++){
            points.push_back(Point(arr[2*i], arr[2*i+1]));
        }
        Solution s;
        cout << "maximum points on one line: " << s.maxPoints(points) << endl;
    }
    return;
}

int main(){
    test_01();
    return 0;
}
