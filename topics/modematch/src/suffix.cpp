/* 
 * Problem: POI2000 pow
 * Memo: Longest Common Substring(LCP)
*/
#include "stdio.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXL=10011, MAXN=6;

struct SuffixArray{
    struct RadixElement{
        int id,k[2];
    }RE[MAXL],RT[MAXL];

    int N,A[MAXL],SA[MAXL],Rank[MAXL],Height[MAXL],C[MAXL];
    
    void RadixSort(){
        int i,y;
        for (y=1;y>=0;y--){
            memset(C,0,sizeof(C));
            for (i=1;i<=N;i++) C[RE[i].k[y]]++;
            for (i=1;i<MAXL;i++) C[i]+=C[i-1];
            for (i=N;i>=1;i--) RT[C[RE[i].k[y]]--]=RE[i];
            for (i=1;i<=N;i++) RE[i]=RT[i];
        }
        for (i=1;i<=N;i++){
            Rank[ RE[i].id ]=Rank[ RE[i-1].id ];
            if (RE[i].k[0]!=RE[i-1].k[0] || RE[i].k[1]!=RE[i-1].k[1]){
                Rank[ RE[i].id ]++;
            }
        }
    }

    void CalcSA(){
        int i,k;
        RE[0].k[0]=-1;
        for (i=1; i <= N; ++i){
            RE[i].id    = i;
            RE[i].k[0]  = A[i];
            RE[i].k[1]  = 0;
        }
        RadixSort();
        for (k=1;k+1<=N;k*=2){
            for (i=1;i<=N;i++){
                RE[i].id   = i;
                RE[i].k[0] = Rank[i];
                RE[i].k[1] = i+k <= N ? Rank[i+k] : 0;
            }
            RadixSort();
        }
        for (i=1;i<=N;i++){
            SA[ Rank[i] ]=i;
        }
    }

    void CalcHeight(){
        int i,k,h=0;
        for (i=1;i<=N;i++){
            if (Rank[i]==1){
                h=0;
            }else{
                k = SA[Rank[i]-1];
                if(--h<0)     h=0;
                for(;A[i+h]==A[k+h];h++);
            }
            Height[Rank[i]]=h;
        }
    }
}SA;

int N, Ans,Bel[MAXL];
char S[MAXL];

void init(){
    int i;
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    scanf("%d",&N);
    SA.N = 0;
    for (i=1;i<=N;i++){
        scanf("%s",S);
        for (char *p=S; *p; ++p){
            SA.A[++SA.N] = *p-'a'+1;
            Bel[SA.N] = i;
        }
        if (i<N){
            SA.A[++SA.N] = 30 + i;
        }
    }
}

bool check(int A){
    int i,j,k;
    bool ba[MAXN];
    for (i=1; i<=SA.N; ++i){
        if (SA.Height[i] >= A){
            for(j=i;SA.Height[j]>=A && j<=SA.N;j++);
            j--;
            memset(ba,0,sizeof(ba));
            for(k=i-1;k<=j;k++){
                ba[Bel[SA.SA[k]]] = true;
            }
            for(k=1; ba[k] && k<=N; ++k);
            if(k == N+1)        return true;
            i=j;
        }
    }
    return false;
}

void solve(){
    int a, b, m;
    SA.CalcSA();
    SA.CalcHeight();
    a = 0;
    b = SA.N;
    while(a+1 < b){
        m = (a+b)/2;
        if(check(m)){
            a=m;
        }else{
            b=m-1;
        }
    }
    if(check(b))    a=b;
    Ans=a;
}

int main(int, char**){
    init();
    solve();
    printf("%dn",Ans);
    return 0;
}

