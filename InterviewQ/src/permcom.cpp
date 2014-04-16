/*
 * permutation of combination
 * */
#include "stdio.h"

int combine(int n, int m){
    if(n < m) return 0;
    if(n == m) return 1;
    if(m == 1) return n;

    int res = 0;
    for(int i=1;i<=n-m+1;i++){
        res += combine(n-i, m-1);
    }
    return res;
}

int permCount(int n, int m){
    if(n < m) return 0;
    if(n == m) return 1;
    if(m == 1) return n;

    int res = 0;
    for(int i=1;i<=n;i++){
        res += permCount(n-1, m-1);
    }
    return res;

}

void test_01(){
    int n=0, m=0;
    while(scanf("%d,%d", &n, &m)){
      if(m==0 || m == 0)    break;
      int res = combine(n,m);
      printf("combine: %d\n", res);
      res = permCount(n,m);
      printf("permCount: %d\n", res);
      n = 0;
      m = 0;
    }
    return;
}

int main(int argc, char* argv[]){
    test_01();
    return 0;
}


