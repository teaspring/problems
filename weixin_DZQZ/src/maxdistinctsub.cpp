/*
 * problem on Nov 11.
 * given a string of alpha char, find the max substr without duplicate char
 *
 * test data:
 * abcacdfcarfr, result is 5(one option is dfcar)
 * */

#include "stdio.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * in time nearly O(n^3), inefficient in determine whether str[j] appears in substr[i,j)
*/
int maxdistinctsub_1(const string& str){
    int n=str.size();
    int max=1;
    int* plength = new int[n]();    //plength[i] means most sub length which begins with i
    plength[n-1] = 1;
    int a=0, b=1;                   //the duplicate chars
    for(int i=0;i<n-1;i++){
        if(i>0){
            if(a==i){
                plength[i] = b-a;
                continue;
            }else if(a<i){
                plength[i] = b-i+1;
            }else{
                plength[i] = plength[i-1]-1;
            }
        }
        else{
          plength[i] = 1;
        }
        int j=plength[i];
        for(;i+j<n;j++){
            int k = i;
            for(;k<i+j && str[k] != str[i+j];k++);
            if(k<i+j){                //find duplicate
                a = k;
                b = i+j;
                break;
            }
        }
        plength[i] = j;
        if(j > max)
          max = j;
        if(max == n-i)    break;                //no result greater than max can appear in rest
    }
    delete[] plength;
    plength=0;
    return max;
}

/*
 * dynamic programming, but in time O(n^2), not the best 
 * */
int longestSubstrNoDuplicate(const string& str){
    int n = str.size();
    int *alpha = new int[26]();			//alpha[i] is the occurance index of alpha char(i=x-'a')
    for(int i=0;i<26;++i){
        alpha[i] = -1;
    }
    int *pos = new int[n]();			//pos[i] is the last occurance index of str[i]
    for(int i=0;i<n;++i){
        int j = str[i]-'a';
        pos[i] = alpha[j];
        alpha[j] = i;
    }
    int **dp = new int*[n];
    for(int i=0;i<n;++i){				//dp[i][j] is the longest substr length without duplicate char for sub string [i,i+j)
        dp[i] = new int[n+1]();
        dp[i][1] = 1;
    }
    int maxlength=1, start=0;
    for(int j=2;j<=n;++j){
        for(int i=0;i+j<=n;++i){
            if(pos[i+j-1] < i && dp[i][j-1] == j-1){
                dp[i][j] = j;
                if(maxlength < j){
                    maxlength = j;
                    start = i;
                }
            }else{
                dp[i][j] = max(dp[i+1][j-1], dp[i][j-1]);
            }
        }
    }

    delete[] alpha;
    alpha=0;
    delete[] pos;
    pos=0;
    for(int i=0;i<n;++i){
        delete[] dp[i];
        dp[i] = 0;
    }
    delete[] dp;
    dp=0;

    printf("method3: result is %s of length %d\n", str.substr(start, maxlength).c_str(), maxlength);
    return maxlength;
}

/*
 * correct DP in time O(n), the best!
 * */
string longestSubstrWithoutRepeat(const string& str){
	int n = str.size();
	if(n==0)	return 0;
	int* pos = new int[26]();
	for(int i=0;i<26;++i)
	  pos[i] = -1;
	int* dp = new int[n]();
	dp[0] = 1;
	pos[str[0] - 'a'] = 0;
	int maxlength=1, end=0;
	for(int i=1;i<n;++i){
		dp[i] = i - pos[str[i] - 'a'];
		if(dp[i] > dp[i-1] + 1)
		  dp[i] = dp[i-1]+1;
		if(maxlength < dp[i]){
			maxlength = dp[i];
			end = i;
		}
		pos[str[i] - 'a'] = i;
	}
	delete[] dp;
	dp=0;
	delete[] pos;
	pos=0;
	return str.substr(end-maxlength+1, maxlength);
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        string sub = longestSubstrWithoutRepeat(str);
		printf("the longest substr without duplicate char is %s\n", sub.c_str());
    }
    return 0;
}
