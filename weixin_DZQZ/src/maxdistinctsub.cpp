/*
 * problem on Nov 11.
 * given a string of alpha char, find the max substr without duplicate char
 *
 * test data:
 * abcacdfcarfr, result is 5(one option is dfcar)
 * */

#include "../header/preliminary.h"

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
 * answer of author, but is error!
 * case to prove errorness: abcae, abba
 * */
int longestSubstrWithoutRepeat(const string& str){
    int start=0, n=str.size();
    int end = n;
    int *pos = new int[n]();
    for(int i=0;i<n;++i){
        pos[i] = -1;
    }
    int maxlength=-1;
    for(int i=0;i<n;++i){
        int j=str[i] - 'a';
        if(pos[j]==-1){
            pos[j] = i;
        }else{
            int tmp = i - pos[j];
            if(maxlength < tmp){
                start = pos[j];
                end =i;
                maxlength = tmp;
            }
            pos[j] = i;
        }
    }
    printf("method2: result is %s of length %d\n", str.substr(start, end-start).c_str(), maxlength);

    delete[] pos;
    pos = 0;
    return maxlength;
} 

/*
 * correct dynamic programming, in time O(n^2)
 * */
int longestSubstrNoDuplicate(const string& str){
    int n = str.size();
    int *alpha = new int[26]();
    for(int i=0;i<26;++i){
        alpha[i] = -1;
    }
    int *pos = new int[n]();
    for(int i=0;i<n;++i){
        int j = str[i]-'a';
        pos[i] = alpha[j];
        alpha[j] = i;
    }
    int **dp = new int*[n];
    for(int i=0;i<n;++i){
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

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int x = maxdistinctsub_1(str);
        printf("method1: the result is %d\n", x);
        x = longestSubstrWithoutRepeat(str);
        x = longestSubstrNoDuplicate(str);
    }
    return 0;
}
