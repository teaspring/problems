/*
 * problem on Nov07. given a string of integer, ask to remove k from it to keep the left integers becomes the least without destroying their interactive order
 *
 * test data:
 * 13243221, k=5, result is 121
 * */

#include "../header/preliminary.h"

/*
 * solution: begin from remove 1st char, iterate from left to right, it is the one as head of first decending(str[i] > str[i+1])
 * time O(n*k), with some duplicate iteration
 * */
string removechar01(const string& str, int k){
    string res(str);
    int len=res.size();
    while(k){
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
void removechar02(string& str, int k){
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
        for(int j=i;j<len-1;j++){
            str[j] = str[j+1];
        }
        str[len-1] = '\0';
        --k;
        --i;
        --len;
    }
    return;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int a=0;
        if(scanf("%d", &a) == EOF)
          break;
        string res1 = removechar01(str, a);
        printf("result of solution1 is %s\n", res1.c_str());
        removechar02(str, a);
        printf("result of solution2 is %s\n", str.c_str());
    }
    return 0;
}
