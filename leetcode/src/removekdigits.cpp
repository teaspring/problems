/*
 * given a string of integer, ask to remove k from it to keep the left integers becomes the least without destroying their interactive order
 *
 * test data:
 * 13243221, k=5, result is 121
 * */

#include "../header/preliminary.h"
#include <queue>

/*
 * solution: begin from remove 1st char, iterate from left to right, it is the one as head of first decending(str[i] > str[i+1])
 * time O(n*k), with some duplicate iteration
 * */
string removechar_01(const string& str, int k){
    string res(str);
    int len=res.size();
    while(k){    //IMPORTANT: start scanning from left(i=0) every time 
        int i=0;
        for(;i<len-1;i++){
            if(res[i] > res[i+1])
              break;
        }
        for(;i<len-1;i++){
            res[i] = res[i+1];
        }
        res[len-1] = '\0';
        --k;
        --len;
    }
    return res.substr(0, str.size());
}

/*
 * based on previous solution, eliminate the duplicate
 * time O(n+k)
 * */
void removechar_02(string& str, int k){
    int len = str.size();
    if(k > len)    return;
    if(k == len){
        str.clear();
        return;
    }
    int i=0;
    while(k){
        if(i<0) i=0;
        for(;i<len-1;i++){
            if(str[i] > str[i+1])
              break;
        }
        for(int j=i;j<len-1;j++){    //remove str[i]
            str[j] = str[j+1];
        }
        str[len-1] = '\0';
        --k;
        --i;    //IMPORTANT: go back by 1, start scanning from [i-1] as [i] is removed 
        --len;
    }
    return;
}

/*
 * solution 3 in use of priority_queue
 * */
struct element{
    char ch;
    int index;
public:
    element(char c, int i): ch(c), index(i){}
};

class mycomparision{
    bool reverse;
public:
    mycomparision(const bool& b = false): reverse(b){}
    bool operator() (const element& lhs, const element& rhs){
        if(reverse)     return (lhs.ch > rhs.ch);
        else            return (lhs.ch < rhs.ch);
    }
};

typedef priority_queue<element, vector<element>, mycomparision> pq_element;

/*
 * str: 13524682, k:4
 * push 1,3,5,2 to priority_queue, each element is value with index
 * push 4, save top(), then pop() if index of top() is less than index of saved
 * this method utilizes priority_queue for sort() so it is less efficient than method2 
 * */
string removechar_03(const string& str, int k){
    int n = str.size();
    if(k>=n)        return string();
    char cstr[n-k+1];
    memset(cstr, 0, sizeof(char)*(n-k+1));
    pq_element pq(mycomparision(true));        //greater-than returns true and put in back, top is minimum
    for(int i=0;i<k;i++){
        pq.push(element(str[i], i));   
    }
    for(int i=k;i<n;i++){
        pq.push(element(str[i], i));
        cstr[i-k] = pq.top().ch;
        int curr = pq.top().index;
        pq.pop();
        while(!pq.empty() && pq.top().index < curr){
            pq.pop();
        }
    }
    cstr[n-k] = '\0';
    return string(cstr);
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        printf("input string:\n");
        if(getline(cin, str)==0 || str.empty())        break;
        string kstr;
        printf("input k:\n");
        if(getline(cin, kstr)==0 || kstr.empty())    break;
        int a = atoi(kstr.c_str());
        string res1 = removechar_01(str, a);
        printf("solution1: %s\n", res1.c_str());
        string str2(str);
        removechar_02(str2, a);
        printf("solution2: %s\n", str2.c_str());
        string res3 = removechar_03(str, a);
        printf("solution3: %s\n", res3.c_str());
    }
    return 0;
}
