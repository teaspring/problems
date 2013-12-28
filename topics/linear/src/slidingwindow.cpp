/*
* from leetcode.
* given integer array A[n], a sliding window of size w. when window moving from very left to right, the max value among
* the window make up B[n-w]. ask to find an optimal way to get B[n-w]
*/
#include "../header/preliminary.h"
#include <queue>

/*
* solution 1 is from the idea of heap. every time we save the w elements in priority_queue, every time sliding, remove one and add one
* in time O(n*lgw)
*/
typedef pair<int, int> Pair;
void maxSlidingWindow_01(int *A, int n, int w, int *B){
    priority_queue<Pair> Q;     //by default, priority_queue stores element in descending of element(max heap), here as key of pair<>
    for(int i=0;i<w;++i){
        Q.push(Pair(A[i], i));
    }
    for(int i=w;i<n;++i){
        Pair p = Q.top();
        B[i-w] = p.first;
        while(p.second <= i-w){  //in fact, no more loop than once
            Q.pop();
            p = Q.top();
        }
        Q.push(Pair(A[i], i));
    }
    B[n-w] = Q.top().first;
}

/*
* best solution based on solution 1. remove redundant elements and store only elements that need to be considered in the queue
* time can be O(n), because every element only push/pop deque once.
*/
void maxSlidingWindow_02(int *A, int n, int w, int *B){
    deque<int> Q;       //for index of A[]
    for(int i=0;i<w;++i){
        while(!Q.empty() && A[i] >= A[Q.back()]){    //pop those which never be chosen as max in current window
            Q.pop_back();
        }
        Q.push_back(i);    //new element is pushed from back, all inside deque are saved in ascending from front to back
    }

    for(int i=w;i<n;++i){
        B[i-w] = A[Q.front()];
        while(!Q.empty() && A[i] >= A[Q.back()]){
            Q.pop_back();
        }
        while(!Q.empty() && Q.front() <= i-w){   //pop the index which is out of next window starting from A[i+1-w].
            Q.pop_front();                       //in fact, no more loop than once
        }
        Q.push_back(i);
    }
    B[n-w] = A[Q.front()];
}

int main(int, char**){
    string str;
    while(1){
        cout<<"please input integer array of A[]:"<<endl;
        if(getline(cin, str)==0 || str.empty())
            break;
        int *arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        cout<<"input size of sliding window:"<<endl;
        if(getline(cin, str)==0 || str.empty())
            break;
        int w = atoi(str.c_str());
        int *B = new int[n-w+1]();
        maxSlidingWindow_01(arr, n, w, B);
        cout<<"solution 1: result B[] are: ";
        for(int i=0;i<n-w+1;++i)
            printf("%d ", B[i]);
        cout<<endl;
        
        memset(B, 0, sizeof(int)*(n-w+1));
        maxSlidingWindow_02(arr, n, w, B);
        cout<<"solution 2: result B[] are: ";
        for(int i=0;i<n-w+1;++i)
            printf("%d ", B[i]);
        cout<<endl;
        delete[] arr;
        delete[] B;
    }
    return 0;
}
