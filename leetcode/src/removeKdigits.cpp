/*
 * given a string of integer, ask to remove k from it to keep the left integers becomes the least option.
 * Note: initial order of chars cannot be broken
 *
 * test data:
 * 13243221, k = 5, result is 121
 * */
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct element{
    char ch;
    int index;
public:
    element(char c, int i): ch(c), index(i){}
};

class mycomparision{
public:
    mycomparision(const bool& b = false): reverse(b){}

    /*
     * bool (a, b) returns true if a should go before b in such strict weak order
     * and in priority_queue, top() is [end - 1]
     * */
    bool operator() (const element& lhs, const element& rhs){
        return reverse ? lhs.ch > rhs.ch : lhs.ch < rhs.ch;
    }

private:
    bool reverse;
};

/*
 * priority_queue: the 1st element should be the greatest one in container - top()
 * */
typedef priority_queue<element, vector<element>, mycomparision> pq_element;

class Solution{
public:
    /*
     * idea: begin from 1st char, iterate from left to right, it is the one as head of first decending(str[i] > str[i+1])
     * time O(n*k), with duplicate iteration
     * */
    string removechar_01(const string& str, int k){
        string res(str);
        int len = res.size();

        while(k){   // start scanning from left (i=0) every time
            int i = 0;
            for(; i < len-1 && res[i] <= res[i+1]; i++); // breaking at res[i] > res[i+1]

            for(;i < len-1; i++){
                res[i] = res[i+1];
            }
            res[len-1] = '\0';

            --k;
            --len;
        }

        return res.substr(0, str.size());
    }

    /*
     * based on previous idea, eliminate the duplicate
     * time O(n+k)
     * */
    void removechar_02(string& str, int k){
        int len = str.size();
        if(k > len)    return;

        if(k == len){
            str.clear();
            return;
        }

        int i = 0;
        while(k > 0){
            if(i < 0)    i = 0;

            for(;i < len-1 && str[i] <= str[i+1]; i++); // breaking at str[i] > str[i+1]

            for(int j = i; j < len-1; j++){    // remove str[i]
                str[j] = str[j+1];
            }
            str[len-1] = '\0';

            --k;
            --i;  // go back by 1, start scanning from [i-1] as [i] is removed
            --len;
        }
    }

    /*
     * str: 13524682, k:4
     * solution 3 uses priority_queue
     * push 1,3,5,2 to priority_queue, each element is value with index
     * push 4, save top(), then pop() if index of top() is less than index of saved
     * this method utilizes priority_queue for sort() so it is less efficient than method2 
     * */
    string removechar_03(const string& str, int k){
        int n = str.size();
        if(k >= n)        return string();

        char cstr[n - k + 1];
        memset(cstr, 0, sizeof(cstr));

        pq_element pq(mycomparision(true));  // greater-than returns true and put in back, top is minimum

        for(int i = 0; i < k; i++){
            pq.push(element(str[i], i));
        }

        for(int i = k; i < n; i++){
            pq.push(element(str[i], i));

            cstr[i-k] = pq.top().ch;
            pq.pop();
        }

        cstr[n-k] = '\0';
        return string(cstr);
    }
};

/* unit test is in ../cpp_unittest/removekdigits_unittest */
