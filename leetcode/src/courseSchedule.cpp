/*
 * Problem 1:
 * there are total of n courses you have to take, 0 - (n-1). some of it has prerequisites, [0, 1] expresses to take course 0, you have to take course 1 firstly.
 * given the total number of courses and a list of prerequisite pairs, find whether it is possible to finish them all.
 * E.g. input '2, [0,1], [1,0]' is impossible
 * '3, [1,0]' is possible
 *
 * Problem 2:
 * given the total number of courses and a list of prerequisites pairs, return the ordering of courses you can take to finish all of them.
 * there may be 1+ available orders, return either one is OK; if it is impossible to finish all courses, return empty array
 * '4, [1,0], [2,0], [3,1], [3,2]' => either [0,1,2,3] or [0,2,1,3] is fine
 *
 * Implicit conditions:
 * 1.each base course can have multiple prerequisite relations, and each course as prerequisite can have multiple forward courses
 * 2.in argument prerequistes vector<pair<int, int>>, there may be duplicate pairs !
 *
 * analysis: the prerequisite pair<a, b> does not mean a must be following b, but to tell b should be taken in front of a. The relationships
 * reminds one of directed graphs, and the problem reduces to a topological sort order of courses.
 * */
#include <iostream>
#include <string>
#include <utility>  // std::pair<>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution{
public:
    // if only map<base, pre> is used, it can not handle case of 1 base <-> N pre, while pairs of same base will be covered
    // so that the correct solution is to use map<base, pre> and map<pre, base> both
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        unordered_map<int, int> mp; // with pair<base, pre>, it is base as key, and pre as value in map<>
        for(auto pa : prerequisites) {
            int base = pa.first, pre = pa.second;
            if(base > numCourses - 1 || pre > numCourses - 1)    return false;

            unordered_map<int, int>::iterator it = mp.find(pre);
            while(it != mp.end()) {
                if(it->second == base)    return false; // there is a dependence cycle
                it = mp.find(it->second);
            }
            mp[base] = pre;
        }

        mp.clear(); // reset to push pair<pre, base>, it is pre as key and base as value in map<>
        for(auto pa : prerequisites) {
            int base = pa.first, pre = pa.second;
            unordered_map<int, int>::iterator it = mp.find(base);
            while(it != mp.end()) {
                if(it->second == pre)    return false; // there is a dependence cycle
                it = mp.find(it->second);
            }
            mp[pre] = base;
        }

        return true;
    }

    // heavy containered problem/solution
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);

        queue<int> zeroes; // its elements are the course which prerequisites have been finished already
        for(int i = 0; i < numCourses; i++) {
            if(!degrees[i])    zeroes.push(i);
        }

        vector<int> toposort;
        for(int i = 0; i < numCourses; i++) {
            if(zeroes.empty())    return {};

            int zero = zeroes.front();
            zeroes.pop();
            toposort.push_back(zero);

            for(int neigh : graph[zero]) {
                if(!(--degrees[neigh])) {
                    zeroes.push(neigh);
                }
            }
        }
        return toposort;
    }

private:
    // return vector<set<int>> tells all base chars which has that prerequisite
    vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }

    // return vector<int> tells how many prerequisites of one base char
    // graph's size is numCourses
    vector<int> compute_indegree(vector<unordered_set<int> >& graph) {
        vector<int> degrees(graph.size(), 0);
        for(auto neighbors : graph) {
            for(int neigh : neighbors) {
                degrees[neigh]++;
            }
        }
        return degrees;
    }
};
