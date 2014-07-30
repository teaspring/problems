/*
 * given n and k, find combinations of k integers from [1,n]
 */
#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class combinations{
public:
    vector<vector<int> > combine(int n, int k){
        vector<int> pot;
        vector<vector<int> > result;
        combineOnce(pot, k, 1, n, result);
        return result;
    }

    void test(){
        string str;
        while(1){
            cout << "n=?" << endl;
            if(getline(cin, str)==0 || str.empty())    break;
            int n = atoi(str.c_str());
            cout << "k=?" << endl;
            if(getline(cin, str)==0 || str.empty())    break;
            int k = atoi(str.c_str());
            printf("n=%d, k=%d \n", n, k);
            vector<vector<int> > result = combine(n, k);
            display(result);
            str.clear();
        }
    }

    void display(vector<vector<int> >& result){
        cout << "[" << endl;
        for(size_t i = 0; i<result.size(); ++i){
            vector<int> line = result[i];
            cout << " [";
            if(line.size()==0)    continue;
            cout << line[0];
            for(size_t j=1; j < line.size(); ++j){
                cout << ", " << line[j];
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }

private:
    void combineOnce(vector<int>& curr, int k, int start, int end, vector<vector<int> >& res){
        if(k==0){
            res.push_back(curr);
            return;
        }
        if(start > end)    return;
        for(int i=start; i<=end; ++i){
            curr.push_back(i);
            combineOnce(curr, k-1, i+1, end, res);
            curr.pop_back();
        }
        return;
    }
};

int main(){
    combinations *cs = new combinations();
    cs->test();
    delete cs;
    cs = 0;
    return 0;
}

