/*
 * merge:
 * given a collection of intervals, merge all overlapping intervals
 * 
 * test cases:
 * given  [1,3], [2,6], [8,10], [15,18]
 * return [1,6], [8,10], [15,18]
 *
 * given [1,3], [2,4]
 * */
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int s, int e):start(s), end(e){} 
};

typedef bool (*cmpFcn)(const Interval&, const Interval&);  //function pointer for compare function of Interval


class Solution{

public:
    /*
     * sort collection, then merge overlapping ones
     * how to sort:
     * <algorithm> std::sort(,,bool(*cmp)(,))
     * self defined sort
     * */
    vector<Interval> merge(vector<Interval>& intervals){
        sort(intervals.begin(), intervals.end(), &cmpInterval);  // std::sort() not accepted by oj.leetcode
        //my_quicksort(intervals, 0, intervals.size() - 1, &cmpInterval);

        vector<Interval> res;
        for(vector<Interval>::const_iterator iter = intervals.begin();
            iter != intervals.end();
            ++iter){

            if(res.empty()){
                res.push_back(Interval(iter->start, iter->end));
                continue;
            }

            const int m = res.size();
            if(res[m-1].end >= iter->start){  // merge next interval to current tail
                res[m-1].end = max(res[m-1].end, iter->end);
            }else{  // no overlap, so add new interval
                res.push_back(Interval(iter->start, iter->end));
            }
        }
        return res;
    }

private:
    /*
     * if not static, compiler error:
     * ISO C++ forbids taking address of an unqualified or parenthesized non-static
     * member function to form a pointer to member function
     * */
    static int cmpInterval(const Interval& i1, const Interval& i2){ // for ascending order
        if(i1.start == i2.start){
            return i1.end < i2.end;
        }else{
            return i1.start < i2.start;
        }
    }

    void my_swap(Interval& i1, Interval& i2){
        Interval tmp(i2.start, i2.end);

        i2.start = i1.start;
        i2.end   = i1.end;

        i1.start = tmp.start;
        i1.end   = tmp.end;
    }

    /*
     * @param s, e : both inclusive index
     * */
    void my_quicksort(vector<Interval>& intervals, int s, int e, cmpFcn cmp){  // range of [s, e]
        if(s >= e)    return;

        int q = s-1, p = s, t = e;
        while(p < t){
            if(cmp(intervals[p], intervals[t])){ //cmp() return true if i1 is less than i2, so i1 should be swapped to head
                ++q;
                my_swap(intervals[q], intervals[p]);
            }
            ++p;
        }

        ++q;
        my_swap(intervals[q], intervals[p]);

        my_quicksort(intervals, s, q-1, cmp);
        my_quicksort(intervals, q+1, e, cmp);
    }
};

/* unit test is in ../cpp_unittest/mergeIntervals_unittest */
