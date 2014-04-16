/*
 * given a string, list all substring of it, with length from 0 to n
 * solution: sort the string firstly
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void comb(const char *source, int n, int r){
    int *pos = new int[r+1];
    int i, k;
    k = 1;
    pos[k] = 1;
    while (k > 0){       
        while (source[pos[k]-2] == source[pos[k]-1]){
            pos[k]++;
        }
        if(pos[k] <= n){           
            if(k == r){
                for (i=1; i <= r; i++){
                    printf("%c", source[pos[i] - 1]);
                }
                printf("\n");
                pos[k]++;
            }else{
                k++;
                pos[k] = pos[k-1] + 1;
            }
        }else{
            k--;   // back
            pos[k]++;
        }
    }
    delete[] pos;
    return;
}

void test_01(){
    char *s = "abdcffefd";
    int len = strlen(s);
    char *sortedStr = new char[len+1];
    strcpy(sortedStr, s);
    sort(sortedStr, sortedStr+len);
    printf("%s\n\n", sortedStr);
    for (int i=1; i <= len; i++){
        comb(sortedStr, len, i);
    }
    delete[] sortedStr;
    return;
}

int main(int, char**){
    test_01();
    return 0;
}
