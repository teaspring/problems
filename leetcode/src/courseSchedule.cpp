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
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        unordered_map<int, int> mp; // with pair<base, prerequi>, in map, base as key, and prerequisite as value
        const int n = prerequisites.size();
        for(int i = 0; i < n; ++i) {
            int pre = prerequisites[i].second, base = prerequisites[i].first;
            if(pre > numCourses - 1 || base > numCourses - 1)    return false;

            unordered_map<int, int>::iterator it = mp.find(pre);
            while(it != mp.end()) {
                if(it->second == base)    return false;
                it = mp.find(it->second);
            }
            mp[base] = pre;
        }
        return true;
    }

    // a heavy containered problem/solution
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
