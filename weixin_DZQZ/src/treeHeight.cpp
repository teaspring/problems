/*
 * question on Aug27
 * input: int arr[n].all nodes reside in a tree, unnecessary to be binary tree. arr[i] means parent node of node i.arr[root]==-1.
 * output: tree height
 * case1:
 * 11,2,3,-1,3,2,7,2,9,4,4,1
 *					3
 *				   / \
 *				  2   4
 *				 /|\  | \
 *				5 7 1 10 9
 *				  | |     \
 *				  6 11     8
 *				    |
 *				    0
 * */
#include "../header/preliminary.h"

int setNodeDist(int* distArr, int* parArr, int n, int i){		//as extra array to save node distance to root, recursive has no repeat
	if(i>=n)	return 0;
	if(parArr[i] == -1){
		distArr[i] = 1;
	}else{
		if(distArr[i] == 0)
			distArr[i] = setNodeDist(distArr, parArr, n, parArr[i]) + 1;		  
	}
	return distArr[i];
}

/*
 * my own solution, time O(n) and space O(n). it is better than time O(n^2) and space O(1) 
 * */
int treeHeight(int* arr, int n){
	int height = 0;
	int* dists = new int[n]();				//array is enough to save node distance to root 
	for(int i=0;i<n;++i){
		setNodeDist(dists, arr, n, i);
		if(height < dists[i])
		  height = dists[i];
	}
	delete[] dists;
	dists = 0;
	return height;
}

int main(int argc, char* argv[]){
	string str;
	while(1){
		if(getline(cin, str)==0 || str.size()==0)	
		  break;
		int* arr = new int[str.size()]();
		int n = splitStr2IntArray(str, arr);
		int h = treeHeight(arr, n);
		printf("the tree height is %d\n", h);
		delete[] arr;
		arr = 0;
	}
	return 0;
}

