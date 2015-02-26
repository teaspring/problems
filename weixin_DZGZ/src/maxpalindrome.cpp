/*
 * question on Sep22
 * find the longest palindrome in the string
 *
 * test data:
 * adaiziguizhongrenenrgnohziugiziadb
 * */

#include "../header/preliminary.h"

/*
 * check a substr is palindrome. in time O(n)
 * */
bool ispalindrome(const string& src, int end, int length){
    if(length > (int)src.size() || length < 1
       || end >= (int)src.size() || end < 0)
      return false;
    int v = end - length+1, u = end;
    while(v<= u && src[v] == src[u]){
        ++v;
        --u;
    }
    return v<=u ? false : true;
}
/*
 * force without optimization, time (n^3)
 * */
string maxpalindrome_1(const string& str){
    int n = str.size(), e=0, l=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(ispalindrome(str, i, i-j+1) && l < i-j+1){                
                l = i-j+1;
                e = i;
            }
        }
    }
    return str.substr(e-l+1,l);
}


/*
 * time O(n^2), space O(1)
 * relative simple, easy to read
 * */
void cmpwing(const string& str, int& v, int& u, int& b, int& maxl){
    int n = str.size();
    while(v>=0 && u<n && str[v] == str[u]){
        --v;
        ++u;
    }
    int l = u-v-1;        //u-v+1-2
    if(maxl < l){
        maxl = l;
        b = v;
    }
}

string maxpalindrome_2(const string& str){
    int maxlength=1, b=0, n=str.size();
    for(int i=1;i<n;i++){
        int v=i-1, u=i+1;                //substr of odd char counts 
        cmpwing(str, v, u, b, maxlength);
        v=i-1, u=i;                      //substr of even char counts
        cmpwing(str, v, u, b, maxlength);
    }
    return str.substr(b, maxlength);
}

/*
 * space O(n^2), time(n^2)
 * */
string maxpalindrome_3(const string& str){
    int n = str.size();
    int** ppLength = new int*[n];
    for(int i=0;i<n;i++){
        ppLength[i] = new int[n]();
        ppLength[i][0] = 1;                //[i][0]==1 means substr of length 1 ends at str[i] is palindrome 
    }
    int maxlength = 0, end = 0;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(str[j] == str[i] 
             &&(i-j<3 || ppLength[i-1][i-j-2] == 1)){
                ppLength[i][i-j] = 1;
                if(maxlength < i-j){
                    maxlength = i-j;
                    end = i;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        delete[] ppLength[i];
        ppLength[i] = 0;
    }
    delete[] ppLength;
    ppLength = 0;

    return str.substr(end-maxlength, maxlength+1);
}


/*
 * Manache algorithm, time O(n), space O(n), a very smart algorithm
 * */
inline int mymin(int a, int b){
    return a < b ? a : b;
}

char* maxpalindrome_4(const string& str){
    int n = str.size();
    char* pMix = new char[2*n+1];
    memset(pMix, 0, sizeof(char)*(2*n+1));
    pMix[0] = '#';
    for(int i=1, k=0;k<n || i<2*n+1;i++){
        if(pMix[i-1] == '#')
          pMix[i] = str[k++];
        else
          pMix[i] = '#';
    }
    int* p = new int[2*n+1]();
    p[0] = 1;                       //radius of palindrome with center at [i], including center
    int id=0;                       //center of the max palindrome till now
    int mx = id + p[id];            //edge of the max palindrome, outside palindrome
    for(int i=1;i<2*n+1;i++){
        if(mx > i)
            p[i] = mymin(p[2*id - i], mx-i);
        else
            p[i] = 1;

        while(i-p[i] >= 0 && i+p[i] < 2*n+1 && pMix[i-p[i]] == pMix[i+p[i]])
            ++p[i];
        if(p[id] < p[i]){
            id = i;
            mx = i + p[i];
        }
    }
    
    char* res = new char[p[id]];        // factually the real palindrome length is p[id]-1, create char* with tailer of '\0'
    memset(res, 0, sizeof(char)*p[id]);
    for(int i=id-p[id]+1, k=0; i<id+p[id];i++){
        if(pMix[i] == '#')
          continue;
        else
          res[k++] = pMix[i];
    }
    res[p[id]-1] = '\0';
    
    delete[] pMix;
    pMix = 0;
    delete[] p;
    p=0;
    return res;                //external user must delete the dynamic allocated object
}

int main(int agc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())
          break;
        string res = maxpalindrome_2(str);
        printf("method2: the max palindrome is %s\n", res.c_str());
        string res3 = maxpalindrome_3(str);
        printf("method3: the max palindrome is %s\n", res3.c_str());
        char* cstr = maxpalindrome_4(str);
        printf("method4: the max palindrome is %s\n", cstr);
        delete[] cstr;
        cstr = 0;
    }
    return 0;
}
