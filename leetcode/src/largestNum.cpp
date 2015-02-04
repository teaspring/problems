/*
 * given a list of non negative integers, arrange them to form the largest number
 * E.g. given [3,30,34,5,9], the largest formed number is 9534330
 * note: return string instead of int
 *
 * ps, this solution is accepted by oj.leetcode, it runs 7ms for 220 test cases, which is in top of all accepted C++ solutions.
 * */

# include "stdio.h"
# include <iostream>
# include <string>
# include <vector>
using namespace std;

/*
 * 1. use string/char* as key of integer, as they support [] operation for compare in sort
 * 2. char* is chosen rather than string, as it can avoid excessive resource in swap operations in quick sort.
 * */
class Solution{
public:
    string largestNumber(vector<int> &num){
        int n = num.size();
        if(n < 1)    return string();
        vector<int> vec;
        char* seq[n];
        int lengths[n];
        int L = 0;    // total length of all char*
        bool allZero = true;
        for(int i=0; i<n; i++){ // init char* for int element
            int val = num[i];
            if(val == 0){
                vec.push_back(0);
            }else{
                allZero = false;
                while(val > 0){  // save 123 in vector<> as 3,2,1
                    vec.push_back(val % 10);
                    val /= 10;
                }
            }
            int l = vec.size();
            char* curr = new char[l+1];
            curr[l] = '\0';
            for(int j=0; j < l; j++){  // save reversed vec in curr
                curr[j] = '0' + vec[l-1 - j];
            }
            seq[i] = curr;
            lengths[i] = l;
            L += l;
            vec.clear();
        }
        if(allZero){  // all zero case is special
            for(int i=0; i<n; i++){
                delete[] seq[i];
                seq[i] = 0;
            }
            return string("0");
        }
        quick_sort(seq, n, lengths);
        // generate string from seq[]
        char result[L+1];
        result[L] = '\0';
        int t = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j < lengths[i]; ++j){
                result[t++] = seq[i][j];
            }
        }
        for(int i=0; i<n; i++){
            delete[] seq[i];
            seq[i] = 0;
        }
        return string(result);
    }

private:
    int compDeciFromHigh(char* decL, int nL, char* decR, int nR){
        int i=0;
        while(i < nL && i < nR){
            if(decL[i] != decR[i]){
                return decL[i] > decR[i] ? 1 : -1;
            }
            i++;
        }
        int res = 0;
        if(nL == nR)    return res;
        int deltaLen = max(nL, nR) - i;  // i == min(nL, nR)
        // next: compare the tail of long str and the short str
        if(i == nL){  // left str is short
            res = compDeciFromHigh(decL, nL, decR + nL, deltaLen);
        }else{  // right str is short
            res = compDeciFromHigh(decL + nR, deltaLen, decR, nR);
        }
        return res;
    }

    void quick_sort(char* seq[], int n, int* lengths){
        if(n < 2)    return;
        int p = 0, q = -1, t = n-1;
        while(p < t){
            if(compDeciFromHigh(seq[p], lengths[p],
                    seq[t], lengths[t]) > 0){  // move higher decimal ahead
                q++;
                swap_chpp(&(seq[q]), &(seq[p]));
                swap_ip(lengths + q, lengths + p);
            }
            p++;
        }
        q++;
        swap_chpp(&(seq[q]), &(seq[t]));
        swap_ip(lengths + q, lengths + t);

        quick_sort(seq, q, lengths);
        quick_sort(seq + (q+1), n-1 - q, lengths + (q+1));
        return;
    }

    void swap_chpp(char **p, char **q){
        char *tmp = *p;
        *p = *q;
        *q = tmp;
        tmp = 0;
    }

    void swap_ip(int *p, int *q){
        int tmp = *p;
        *p = *q;
        *q = tmp;
    }
};
