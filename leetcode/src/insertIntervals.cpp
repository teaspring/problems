/*
 * given a set of non-overlapping intervals, insert a new interval into the intervals. 
 * You can assume that the intervals were initially sorted according to their start time.
 *
 * */

#include <vector>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e){}
};

class Solution{

public:
    /*
     * vector::insert(iteration position, const value_type& val) # insert new element before the one at position
     * find the position via binary search, then call vector::insert()
     * time O(lgn)
     * */
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval>::iterator v = intervals.begin(), u = intervals.end(); // v is inclusive, u is exclusive
        while(v < u){
            vector<Interval>::iterator m = v + (u - v) / 2;

            if(compareInterval(newInterval, *m) < 0
            && (m == intervals.begin() || compareInterval(*(m-1), newInterval) < 0)){ // find the position
                intervals.insert(m, newInterval);
                return  intervals;
            }

            if(compareInterval(newInterval, *m) > 0){
                v = m+1;
            }else{
                u = m;
            }
        }

        // now v == u
        if(v == intervals.end()){
            intervals.push_back(newInterval);
        }else{
            intervals.insert(v, newInterval);
        }

        return  intervals;
    }

private:
    /*
     * as the intervals have no overlap, compare their start is OK
     * */
    int compareInterval(const Interval& l, const Interval& r){
        if(l.start == r.start)    return 0;
        return l.start < r.start ? -1 : 1;
    }
};

/* unit test is in ../cpp_unittest/insertIntervals_unittest */
