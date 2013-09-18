/*
 * question on July31
 * problem1: input an integer array of a bar figure, find the maximum rectangle
 * Aug04, O(n^3) algorithm; updated, 40 min 
 * 
 * problem2: input a grid(2-d table), 1 is white and 0 is black, find the maximum while rectangle
 * Aug04, additional 30min to fix two bugs
 * */
#include "../preliminary.h"
#include <stack>

struct recElement{
	int begin;
	recElement(int b):begin(b){}
};

/*
 * real O(n).It makes use of following cell.trick is in calculating max rectangle during stack pop.
 * test data:
 * 1,4,3,2,4,1
 * 1,3,2,2,3,0
 * 1,2,3,4,5,6		//good test 
 * 6,5,4,3,2,1		//good test
 * */
int getMaxRectangleExt(int* arr, int N, int& height, int& width, int& beg){
	stack<int> stk;
	int maxArea=0;
	for(int i=0;i<N;i++){
		if(stk.empty())
		  stk.push(i);
		else{
			int curr = stk.top();
			while(curr>-1 && arr[curr] > arr[i]){
				stk.pop();
				int pre= stk.empty() ? -1 : stk.top();		//potential bug!
				int tmp = arr[curr] * (i - pre - 1);
				if(tmp > maxArea){
					maxArea = tmp;
					beg = pre+1;
					width = i - pre -1;
					height = arr[curr];
				}				 
				curr = pre;
			}			
			stk.push(i);
		}
	}
	while(!stk.empty()){
		int curr = stk.top();
		stk.pop();
		int pre=0;
		if(!stk.empty())
			pre = stk.top();
		int tmp = arr[curr]*(N-1 - pre);			//potential bug!
		if(tmp<=maxArea)	continue;
		maxArea = tmp;
		beg = pre+1;
		width = N-1 - pre;
		height = arr[curr];
	}
	return maxArea;
}

/*
 * O(n^2), shorter and easier to read.
 * test data: 
 * 1,4,3,2,4,1
 * 1,3,2,2,3,0
 * 1,2,3,4,5,6
 * 6,5,4,3,2,1
 * */
int getMaxRectangle(int* arr, int N, int& height, int& width, int& begin){
	int max = 0;
	for(int i=0;i<N;i++){
		int h=*(arr+i);				//each cell only applies rectangle of its height
		if(h==0)	continue;
		int k=i;					//potential bug!
		for(;k<N && *(arr+k)>=h;k++);
		k--;						//potential bug!
		int s=i;					//rememeber to extend the mark horizontally forward and backward
		for(;s>-1 && *(arr+s)>=h;s--);
		s++;		  
		int tmp = h*(k-s+1);
		if(tmp>max){
			max = tmp;
			height = h;
			width = k-s+1;		//bar figure, each element is a bar of width of 1
			begin = s;
		}
	}
	return max;
}

/*
 * process 2D array, get the maximum rectangle. convert it to subproblem of 1D array
 * test data:
 * 4
 * 1,1,0,0,1,0
 * 0,1,1,1,1,1
 * 1,1,1,1,1,0
 * 0,0,1,1,0,0
 * */
void getMaxRec2D(int** arr, int rowCount, int colCount, int& row, int& col, int& height, int& width){
	int* layouts[rowCount];
	int maxArea=0;
	for(int i=0;i<rowCount;i++){
		layouts[i] = new int[colCount]();		//"()" calls initialize for "new" array of integer
	}
	for(int i=0;i<rowCount;i++){				//not functional
		for(int j=0;j<colCount;j++)
		  cout<<*(layouts[i]+j)<<" ";
		cout<<endl;
	}
	for(int j=0;j<colCount;j++){
		for(int i=rowCount-1;i>-1;i--){
			if(*(*(arr+i)+j) == 1){
				for(int k=i;k<rowCount && *(*(arr+k)+j)!=0;k++)
				  (*(layouts[k]+j))++;
			}
			else
			  *(layouts[i]+j)=0;
		}
	}
	for(int i=0;i<rowCount;i++){
		for(int j=0;j<colCount;j++)
		  cout<<*(layouts[i]+j)<<" ";
		cout<<endl;

		int h,w,hori;
		int tmp = getMaxRectangleExt(layouts[i], colCount,h,w,hori);
		if(tmp > maxArea){
			maxArea = tmp;
			row = i;
			col = hori;
			height = h;
			width = w;
		}
	}	
	return;
}

int main(int argc, char* argv[]){
	string str;
	const int INF = 0x00ff;
	while(1 && getline(cin, str)){				//1D array
		if(str.size() == 0)	break;
		int src[INF];
		
		char cstr[INF];
		memset(cstr, 0, sizeof(cstr));
		for(size_t i=0;i<str.size();i++){
			cstr[i]=str[i];
		}
		cstr[str.size()] = '\0';
		int leng = splitAndConvert(cstr, src);
		for(int i=0;i<leng;i++)
		  cout<<src[i]<<" ";
		cout<<endl;
		int h=0,w=0,b=0;
		getMaxRectangleExt(src, leng, h, w, b);
		cout<<"the max rectangle in the bar figure begins at "<<b<<", height is "<<h<<" and width is "<<w<<endl;
	}
	
	int rows= 0;
	while(0){
		if(scanf("%d\n", &rows)==EOF || rows<1)
			break;
		int t = rows;
		int* src[rows];
		int leng=0;
		while(t-- && getline(cin, str)){				//1D array
			if(str.size() == 0)	break;
			src[rows-1-t] = new int[INF];		
			char cstr[INF];
			memset(cstr, 0, sizeof(cstr));
			for(size_t i=0;i<str.size();i++){
				cstr[i]=str[i];
			}
			cstr[str.size()] = '\0';
			leng = splitAndConvert(cstr, src[rows-1-t]);
		}
		int h=0,w=0,r=0,c=0;
		getMaxRec2D(src, rows, leng,r,c,h,w);
		cout<<"the max rectangle in the 2D array begins at leftlower ["<<r<<","<<c<<"], height is "<<h<<" and width is "<<w<<endl;
	}
}

