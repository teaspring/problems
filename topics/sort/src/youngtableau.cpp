/*
 * "IntroductionToAlgorithm, chapter6 heap sort, problem 6-3 YoungTableau"
 *
 * test data input:
 * 11 10 9 8 7 6 5 4 3 2 1
 * 2 3 10 31 21 14 6 1 11 23 30 9 18 
 * */
#include "../header/preliminary.h"

const static int LIMIT = 0x0fff;

void myswap(int& a, int& b){
	int tmp = b;
	b = a;
	a = tmp;
}

class YoungTableau{
public:
	YoungTableau(int m, int n):M(m), N(n), ppTab(0){
		init();
	}
	~YoungTableau(){
		clean();
	}
	void insert(int key);
	int  extract_max();
	int  extract_min();
	void showAll();
	bool search(int);
private:
	int M;
	int N;
	int** ppTab;
	void clean();
	void init();
	void min_heapify(int i, int j);
	void getTailer(int& tailx, int& taily);
	bool searchInBound(int x, int y, int key);		
	bool searchInBoundRecur(int x, int y, int key);
		
	inline int downx(int x){
		return x+1;
	}
	inline int upx(int x){
		return x-1;
	}
	inline int lefty(int y){
		return y-1;
	}
	inline int righty(int y){
		return y+1;
	}
};

void YoungTableau::init(){
	ppTab = new int*[M];
	for(int i=0;i<M;i++){
		ppTab[i] = new int[N]();
		for(int j=0;j<N;j++){
			ppTab[i][j] = LIMIT;
		}
	}
}

void YoungTableau::clean(){
	for(int i=0;i<M;i++){
		delete[] ppTab[i];
		ppTab[i] = 0;
	}
	delete[] ppTab;
	ppTab = 0;
}

void YoungTableau::getTailer(int& tailx, int& taily){				//find tailer of the young tableau, the last valid element
	tailx = 0;
	taily = N-1;
	for(;tailx<M && ppTab[tailx][0]<LIMIT;tailx++);
	tailx--;
	if(tailx < 0)	return;
	for(;taily>-1 && ppTab[tailx][taily]==LIMIT;taily--);
	return;
}

void YoungTableau::insert(int key){
	int x=0, y=0;
	getTailer(x,y);
	if(y==N-1){
		y = 0;
		x++;
	}else
	  y++;
	if(x>=M)	return;			//full
	ppTab[x][y] = key;
	min_heapify(x, y);
}

/*
 *  __| find largest element next to (i,j) and swap it to here
 * */
void YoungTableau::min_heapify(int i, int j){
	if(i==0 && j==0)	return;
	while(1){
		int largestx = i, largesty = j;
		if(upx(i)>=0 && ppTab[upx(i)][j] > ppTab[i][j]){
			largestx = upx(i);
			largesty = j;
		}
		if(lefty(j)>=0 && ppTab[i][lefty(j)] > ppTab[largestx][largesty]){
			largestx = i;
			largesty = lefty(j);
		}
		if(largestx != i || largesty != j){
			myswap(ppTab[i][j], ppTab[largestx][largesty]);
			i = largestx;
			j = largesty;
		}else
		  break;
	}
}

int YoungTableau::extract_max(){
	int x=0, y=0;
	getTailer(x, y);
	if(x<0)	return 0-LIMIT;
	int max = ppTab[x][y];
	if(y<N-1 && x>0 && ppTab[x-1][N-1] > max){			//1.compare two options 2.compact the table if there is hole
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
	if(tailx < 0)	return LIMIT;
	myswap(ppTab[0][0], ppTab[tailx][taily]);
	ppTab[tailx][taily] = LIMIT;
	int x=0, y=0;
	while(1){											//move (x,y) downside if it larger than any element less than it
		int leastx = x, leasty = y;
		if(downx(x)<M && ppTab[downx(x)][y] < ppTab[x][y]){
			leastx = downx(x);
			leasty = y;
		}
		if(righty(y)<N && ppTab[x][righty(y)] < ppTab[leastx][leasty]){
			leastx = x;
			leasty = righty(y);
		}
		if(leastx != x || leasty != y){
			myswap(ppTab[leastx][leasty], ppTab[x][y]);
			x = leastx;
			y = leasty;
		}else
		  break;
	}
	return min;
}

/*
 * this iterative function has bug.
 * 1  2  5
 * 3  4  8
 * 6  7  11
 * 9  10
 * when search 5 in the box of 1<-->11, it returns false because it choose to 7's branch. when 8's and 7's are all greater than 5, both should be searched
 *
 * solution is recurse
 * */
bool YoungTableau::searchInBound(int x, int y, int key){
	while(x>-1 && y>-1 && ppTab[x][y] >= key){
		if(ppTab[x][y] == key)	return true;
		if(x == 0 || ppTab[x-1][y] < key){
			y = y-1;
			continue;
		}
		if(y == 0 || ppTab[x][y-1] < key){
			x = x-1;
			continue;
		}

		if(ppTab[x-1][y] > ppTab[x][y-1]){
			y = y-1;
			continue;
		}else
		{
			x = x-1;
			continue;
		}		
	}
	return false;
}

bool YoungTableau::searchInBoundRecur(int x, int y, int key){
	if(x>-1 && y>-1 && ppTab[x][y] >= key){
		if(ppTab[x][y] == key)	return true;
		return searchInBoundRecur(x-1, y, key) || searchInBound(x, y-1, key);
	}
	return false;
}

bool YoungTableau::search(int key){
	int tailx=0, taily=0;
	getTailer(tailx, taily);
	if(tailx < 0)	return false;
	int i = tailx, j = taily;
	return searchInBoundRecur(i,j,key) || (taily<N-1 ? searchInBoundRecur(tailx-1, N-1, key) : false);
}

void YoungTableau::showAll(){
	printf("the Young Tableau is:\n");
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(ppTab[i][j]==LIMIT)
			  printf("%c ", '*');
			else
			  printf("%d ", ppTab[i][j]);
		}
		printf("\n");
	}
}

void decomposeInt(int num, int& m, int& n){			//decompose N to around a*b which is a little greater than N 
	m = 2;
	for(; num/m >= m; m++);
	n = num/m + 1;
	return;
}

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str) == 0 || str.empty())
		  break;
		int* arr = new int[str.size()]();			//to facilitate following test case, the input int count must not be less than 6
		int size = splitStr2IntArray(str, arr);
		int m=1, n=1;
		decomposeInt(size, m, n);
		
		YoungTableau* pYTable = new YoungTableau(m, n);
		for(int i=0; i<size;i++){
			pYTable->insert(arr[i]);
		}
		pYTable->showAll();
		
		for(int i=0;i<size;i++){
			int res = pYTable->search(arr[i]);
			printf("now %d should be in Young Tableau: %s\n", arr[i], res ? "true" : "false");
		}
		
		for(int i=0;i<3;i++){						//extract top3 max elements
			int max = pYTable->extract_max();
			printf("current maximum element is %d\n", max);
			
			int res = pYTable->search(max);
			printf("now %d should not be in Young Tableau: %s\n", max, res ? "true" : "false");
		}
		pYTable->showAll();

		for(int i=0;i<2;i++){
			int min = pYTable->extract_min();
			printf("current minimum element is %d\n", min);
			pYTable->showAll();
		}
			
		delete pYTable;
		pYTable = 0;
		delete[] arr;
		arr = 0;
	}
	return 0;
}
