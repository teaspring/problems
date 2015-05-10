/*
 * problem I:
 * given a set of distinct integers S,  return all possible subsets.
 * e.g. S = [1,2,3]
 * output: 
 * [], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3] 
 *
 * problem II:
 * given a set with duplicate integers
 * e.g. S = [1,2,2]
 * output:
 * [], [1], [1,2], [1,2,2], [2], [2,2]
 * */

#include <vector>
#include <algorithm>
// #include <cstdlib>

using namespace std;

class Solution{

public:
    /*
     * problem I, given a set of distinct integers
     * */
    vector<vector<int> > subsets(vector<int>& S){
        sort(S.begin(), S.end());

        vector<vector<int> > result;

        vector<int> pipe;  // put value in S

        helper(S, 0, pipe, result);

        return result;
    }

    /*
     *
     * */
    vector<vector<int> > subsetsII(vector<int>& S){
        sort(S.begin(), S.end());

        vector<vector<int> > result;

        vector<int> pipe;  // put index in S

        helper_II(S, 0, pipe, result);

        return result;
    }

private:
    /*
     * used by subsets()
     * */
    void helper(const vector<int>& src, int i, vector<int>& pipe, vector<vector<int> >& res){

        if(i < 0)     return;

        res.push_back(pipe);

        const int n = src.size();
        if(i == n)    return;

        for(; i < n; ++i){
            pipe.push_back(src[i]);

            helper(src, i+1, pipe, res);

            pipe.pop_back();
        }
    }

    /*
     * used by subsetsII()
     * */
    void helper_II(const vector<int>& src, int i, vector<int>& vec, vector<vector<int> >& res){

        res.push_back(index2Value(src, vec));

        const int n = src.size();

        for(; i < n; ++i){

            const int m = vec.size();

            // when i > 0, m > 0 stands certainly
            if(i > 0 && i > vec[m-1] + 1 && (src[i-1] == src[i]))    continue;

            vec.push_back(i);  // vec to save index of src instead of value

            helper_II(src, i+1, vec, res);

            vec.pop_back();
        }
    }

    /*
     * convert a list of index to real value
     * */
    vector<int> index2Value(const vector<int>& src, const vector<int>& indexes){

        vector<int> values;

        const int n = indexes.size();

        for(int i = 0; i < n; ++i){
            values.push_back(src[indexes[i]]);
        }

        return values;
    }
};

/* unit test is in ../cpp_unittest/subsets_unittest */
