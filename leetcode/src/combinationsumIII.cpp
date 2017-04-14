/*
 * find all possible combinations of k numbers that add up to a number n, given that only numbers [1,9] can be used which can be used only once; each combination should be a unique set of numbers
 * E.g.
 * k = 3, n = 7,  => [1,2,4]
 * k = 3, n = 9,  => [1,2,6], [1,3,5], [2,3,4]
 * k = 4, n = 12, ==> [1,2,3,6], [1,2,4,5]
 * */
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > combinationSumIII(int k, int n) {
        vector<vector<int> > res;
        vector<int> vec;
        addOnce(res, vec, k, n);
        return res;
    }

private:
    void addOnce(vector<vector<int> >& res, vector<int>& vec, const int k, int target) {
        int cnt = vec.size();
        int tail = cnt == 0 ? 0 : vec[cnt-1];

        if(cnt == k) { // vec is full, no more to add again
            if(target == 0) {
                res.push_back(vec);
            }
            return;
        }

        int opt = tail + 1;
        if(opt > target)    return;

        if(cnt == k-1)    opt = target; // for last cell
        while(opt <= 9) {
            vec.push_back(opt);
            addOnce(res, vec, k, target - opt);
            vec.pop_back();
            ++opt;
        }
    }
};
