/*
 * question on Aug26
 * given a word list in dictionary, ask for the character order of this language
 *
 * working on it 5 hours
 *
 * hint: 
 * 1.input dictionary words are sorted already
 * 2.every adjacent words contributes once compare result of two char
 *
 * test data: 
 * c, cac, cb, bcc, ba        (c->a->b)
 * ca,cb,ab,bcf,bcc,bb,bd   (f->c->a->b->d)
 *
 * thinking about the question prerequisites:
 * 1. every edge is connectd, no isolated edge. E.g a->b->c, with l->n
 * 2. all the vertex must be able to sort. E.g. n->o->r->s->u, with l->r
 * the findings come from dictionrary in real world:
 * abnormal, abolish, abortion, abrupt, absurd, abundance, academy, accessary.
 *
 * reverse question: given char list sorted in order, given plenty of words, how to sort them?
 * */
#include "../header/preliminary.h"
#include <time.h>
#include <sys/time.h>

const int INF = 0xff;
const int Vocab = 26;            //character count mostly

int adjMtx[Vocab][Vocab];                    //digraph
int *pNum   = new int[Vocab]();
int *pTSNum = new int[Vocab]();
int ti = 0, tj = 0;

template<typename T>
void mySwap(T *pa, T *pb){
    T tmp = *pb;
    *pb = *pa;
    *pa = tmp;
    tmp = 0;
}

void myQuickSort(int *arr, int n, char* cArr){
    if(n<2)    return;
    int *p=arr-1, *q=arr;
    int t = arr[n-1];
    while(q<arr+n-1){
        if(*q > t){                //descending order
            ++p;
            mySwap<int>(p, q);
            mySwap<char>(cArr+(p-arr), cArr+(q-arr));
        }
        ++q;
    }
    ++p;
    mySwap<int>(p, q);                            //sentinel
    mySwap<char>(cArr+(p-arr), cArr+(q-arr));        
    
    myQuickSort(arr, p-arr, cArr);
    myQuickSort(arr+(p+1-arr), q-p, cArr+(p+1-arr));
}

//traverse the adjacent matrix in topology sort
void TS(int v, int vertN){        //topology sort is invalid when cycle exists
    pNum[v] = ++ti;
    int* adjV = adjMtx[v];        //edge from v to u
    for(int u=0;u<vertN;++u){
        if(adjV[u] != 1)
          continue;
        if(pNum[u] == 0)
          TS(u, vertN);
        else if(pTSNum[u] == 0){    //u has started to traverse but not completed. Along its successor path, it reaches itself again!
            printf("cycle detected!");
            return;
        }
    }
    pTSNum[v] = ++tj;                //pTSNum[v] is set means v is traversed following all of its successors.
}

/*
 * topology sort is extermely important
 * */
void topologySort(int vN, char* cArr){
    for(int i=0;i<vN;++i){        //reset
        pNum[i]   = 0;
        pTSNum[i] = 0;
    }
    ti=0, tj=0;
    for(int i=0;i<vN;++i){
        if(pNum[i]==0)
          TS(i, vN);
    }
    myQuickSort(pTSNum, vN, cArr);
}

//for CAC and CB, A is ahead of B
//for b and bcc, as b has less letters, so b is ahead of bcc definitely, no valid information is provided.
void compare2Words(const string& str1, const string& str2, char* less, char* greater){
    size_t i = 0;
    for(;i<str1.size() && i<str2.size();++i){
        if(str1[i] == str2[i])
          continue;
        else{
            *less = str1[i];
            *greater = str2[i];
            return;
        }          
    }
    if(i==str1.size() || i<str2.size()){
        *less = -1;
        *greater = -1;
    }      
    return;    
}

int isCharIn(char* arr, int n, const char& c){
    int i=0;
    for(;i<n && arr[i] != 0; ++i){
        if(arr[i] == c)    
          return i;
    }

    if(arr[i] == 0){
        arr[i] = c;
        return i;
    }else
      return -1;
}

void resetAdjMtx(int mtx[Vocab][Vocab], int n = Vocab){
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j){
        if(i==j)
          mtx[i][j] = 0;
        else
          mtx[i][j] = INF;
      }
}
void wordOrder(string* pWords, int wN){
    char* cArr = new char[Vocab]();
    memset(cArr, 0, sizeof(char)*Vocab);
    resetAdjMtx(adjMtx);                //reset the adjacent matrix
    int vN=0;
    for(int i=0;i<wN-1;++i){
        char a=0, b=0;
        compare2Words(pWords[i], pWords[i+1], &a, &b);
        if(a==b)    continue;
        int ia = isCharIn(cArr, Vocab, a);
        int ib = isCharIn(cArr, Vocab, b);
        if(ia == -1 || ib == -1)
          continue;
        if(ia > vN)
          vN = ia;
        if(ib > vN)
          vN = ib;
        if(adjMtx[ia][ib] != 1)
          adjMtx[ia][ib] = 1;            
    }
    ++vN;
    topologySort(vN, cArr);                //use global 2-array adjMtx[][]

    cout<<"In this language, the char order is ";        //out
    for(int i=0;i<vN-1;++i){
        cout<<cArr[i]<<"->";
    }
    cout<<cArr[vN-1]<<endl;
    delete[] cArr;
    cArr = 0;
}

int main(int agrc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str) == 0 || str.empty())
          break;
        string* pWords = new string[str.size()/2]();
        size_t pos = 0;
        int wdCount = 0;
        while(pos<str.size()){
            if(isspace(str[pos])){
                ++pos;
                continue;
            }
            size_t start = pos;
            while(pos<str.size() && !isspace(str[pos]))
              ++pos;            
            pWords[wdCount] = str.substr(start, pos-start);
            ++wdCount;
        }
        timeval tim;
        gettimeofday(&tim, NULL);
        double t1 = tim.tv_sec + (tim.tv_usec/1000000.0);        
        wordOrder(pWords, wdCount);
        gettimeofday(&tim, NULL);
        double t2 = tim.tv_sec + (tim.tv_usec/1000000.0);
        printf("time cost is %.6lf seconds\n", t2-t1);
        delete[] pWords;
        pWords = 0;
    }
    delete[] pNum;
    pNum = 0;
    delete[] pTSNum;
    pTSNum = 0;
    return 0;
}
