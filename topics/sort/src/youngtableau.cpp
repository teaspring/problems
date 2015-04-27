/*
 * "IntroductionToAlgorithm, chapter6 heap sort, problem 6-3 YoungTableau"
 *
 * --from Wiki:
 * a 'standard' Young Tableau is a Young Tableau in which the numbers from an increasing sequence along each line and along each column.
 * the number of standard Young Tableau of size 1,2,3... are 1,2,4,10,26,...
 *
 * I think it is should not be refactored to be STANDARD until we confirm the definition of such Young Tableau
 * */
#include "../header/preliminary.h"

const static int LIMIT = 0xffff;

void myswap(int& a, int& b){
    int tmp = b;
    b = a;
    a = tmp;
}

class YoungTableau{
public:
    YoungTableau(int m, int n):M(m), N(n), ppTab(0){
        ppTab = new int*[M];
        for(int i = 0; i < M; i++){
            ppTab[i] = new int[N]();
            for(int j = 0; j < N; j++){
                ppTab[i][j] = LIMIT;
            }
        }
    }

    virtual ~YoungTableau(){
        for(int i = 0; i < M; i++){
            delete[] ppTab[i];
            ppTab[i] = NULL;
        }
        delete[] ppTab;
        ppTab = NULL;
    }

    void insert(int key);

    int  extract_max();

    int  extract_min();

    void showAll();

private:
    int M;
    int N;
    int** ppTab;

private:
    void min_heapify(int i, int j);

    void getTailer(int& tailx, int& taily);

    inline int downX(int x){
        return x+1;
    }

    inline int upX(int x){
        return x-1;
    }

    inline int leftY(int y){
        return y-1;
    }

    inline int rightY(int y){
        return y+1;
    }
};

/*
 * find tailer of the young tableau which is the last valid element
 * it should use binary search
 * */
void YoungTableau::getTailer(int& tailx, int& taily){
    tailx = 0;
    taily = N-1;

    for(;tailx < M && ppTab[tailx][0] != LIMIT; tailx++);

    tailx--;
    if(tailx < 0)    return;

    for(;taily > -1 && ppTab[tailx][taily] == LIMIT; taily--);
    return;
}

/*
 * insert a new element into Young Tableau
 * */
void YoungTableau::insert(int key){
    int x = 0, y = 0;
    getTailer(x,y);

    if(y == N-1){
        y = 0;
        x++;
    }else{
        y++;
    }

    if(x >= M)    return;   //full

    ppTab[x][y] = key;
    min_heapify(x, y);
}

/*
 *  __| find largest element next to (i,j) and swap it to here
 *  use recurse
 * */
void YoungTableau::min_heapify(int i, int j){
    if(i == 0 && j == 0)    return;
    while(1){
        int largestx = i, largesty = j;

        if(upX(i) >= 0 && ppTab[upX(i)][j] > ppTab[i][j]){
            largestx = upX(i);
            largesty = j;
        }

        if(leftY(j) >= 0 && ppTab[i][leftY(j)] > ppTab[largestx][largesty]){
            largestx = i;
            largesty = leftY(j);
        }

        if(largestx != i || largesty != j){
            myswap(ppTab[i][j], ppTab[largestx][largesty]);
            i = largestx;
            j = largesty;
        }else{
          break;
        }
    }
}

/*
 * find maximum element and pop it out
 * */
int YoungTableau::extract_max(){
    int x = 0, y = 0;
    getTailer(x, y);

    if(x < 0)    return -LIMIT;

    int max = ppTab[x][y];
    if(y < N-1 && x > 0 && ppTab[x-1][N-1] > max){  // 1.compare two options 2.compact the table if there is hole
        max = ppTab[x-1][N-1];
        myswap(ppTab[x][y], ppTab[x-1][N-1]);
        min_heapify(x-1, N-1);
    }
    ppTab[x][y] = LIMIT;
    return max;
}

/*
 * |--, find least element next to (i,j) and swap it to here
 * */
int YoungTableau::extract_min(){
    int min = ppTab[0][0];
    int tailx = 0, taily = 0;
    getTailer(tailx, taily);

    if(tailx < 0)    return LIMIT;

    myswap(ppTab[0][0], ppTab[tailx][taily]);
    ppTab[tailx][taily] = LIMIT;

    int x = 0, y = 0;
    while(1){ // move (x,y) downside if it larger than any element less than it
        int leastx = x, leasty = y;
        if(downX(x)<M && ppTab[downX(x)][y] < ppTab[x][y]){
            leastx = downX(x);
            leasty = y;
        }

        if(rightY(y)<N && ppTab[x][rightY(y)] < ppTab[leastx][leasty]){
            leastx = x;
            leasty = rightY(y);
        }

        if(leastx != x || leasty != y){
            myswap(ppTab[leastx][leasty], ppTab[x][y]);
            x = leastx;
            y = leasty;
        }else{
          break;
        }
    }
    return min;
}

/*
 * decompose N to around a*b which is a little greater than N
 * */
void decomposeInt(int num, int& m, int& n){
    m = 2;
    for(; num/m >= m; m++);
    n = num/m + 1;
    return;
}
