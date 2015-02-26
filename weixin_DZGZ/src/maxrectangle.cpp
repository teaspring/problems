/*
 * question on July31
 * problem1: input an integer array of a bar figure, find the maximum rectangle
 * 
 * test data:
 * 1,4,3,2,4,1
 * 1,3,2,2,3,0
 * 1,2,3,4,5,6        //good test case
 * 6,5,4,3,2,1        //good test case
 * 
 * problem2: input a grid(2-d table), 1 is white and 0 is black, find the maximum white rectangle
 * */
#include "../header/preliminary.h"
#include <stack>

struct recElement{
    int begin;
    recElement(int b):begin(b){}
};

/* 
 * time O(n).
 * It makes use of following cell.trick is in calculating max rectangle during stack pop.
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
                int pre= stk.empty() ? -1 : stk.top();        //careful
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
        int tmp = arr[curr]*(N-1 - pre);            //careful
        if(tmp<=maxArea)    continue;
        maxArea = tmp;
        beg = pre+1;
        width = N-1 - pre;
        height = arr[curr];
    }
    return maxArea;
}

/*
 * time O(n^2), shorter and easier to read.
 * test data: 
 * 1,4,3,2,4,1
 * 1,3,2,2,3,0
 * 1,2,3,4,5,6
 * 6,5,4,3,2,1
 * */
int getMaxRectangle(int* arr, int N, int& height, int& width, int& begin){
    int max = 0;
    for(int i=0;i<N;i++){
        int h=*(arr+i);                //each cell only applies rectangle of its height
        if(h==0)    continue;
        int k=i;
        for(;k<N && *(arr+k)>=h;k++);
        k--;
        int s=i;                    //rememeber to extend the mark horizontally forward and backward
        for(;s>-1 && *(arr+s)>=h;s--);
        s++;          
        int tmp = h*(k-s+1);
        if(tmp>max){
            max = tmp;
            height = h;
            width = k-s+1;        //bar figure, each element is a bar of width of 1
            begin = s;
        }
    }
    return max;
}

/*
 * process 2D array, get the maximum rectangle. convert it to subproblem of 1D array
 *
 * test data:
 * 4
 * 1,1,0,0,1,0
 * 0,1,1,1,1,1
 * 1,1,1,1,1,0
 * 0,0,1,1,0,0
 * */
void getMaxRec2D(int** arr, int rowCount, int colCount, int& row, int& col, int& height, int& width){
    int** layouts = new int*[rowCount];
    int maxArea=0;
    for(int i=0;i<rowCount;i++){
        layouts[i] = new int[colCount]();        //"()" calls initialize for "new" array of integer
    }
    for(int i=0;i<rowCount;i++){                //not functional
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

    for(int i=0;i<rowCount;i++){
        delete[] layouts[i];
        layouts[i] = 0;
    }
    delete[] layouts;
    layouts = 0;
    return;
}

int main(int argc, char* argv[]){
    string str;
    while(1){                //1D array
        if(getline(cin, str) == 0 || str.empty())
          break;
        int* src = new int[str.size()]();        
        int leng = splitStr2IntArray(str, src);
        int h=0,w=0,b=0;
        getMaxRectangleExt(src, leng, h, w, b);
        printf("max rectangle in bar figure begins at %d, with height of %d and width is %d\n", b,h,w);

        delete[] src;
        src = 0;
    }
    
    int rows= 0;
    while(0){                //2D matrix
        if(scanf("%d\n", &rows)==EOF || rows<1)
            break;
        int** src = new int*[rows];
        int leng=0;
        for(int i=0;i<rows;i++){
            if(getline(cin, str) || str.empty())    
              break;
            src[i] = new int[str.size()]();        
            leng = splitStr2IntArray(str, src[i]);
        }
        int h=0,w=0,r=0,c=0;
        getMaxRec2D(src, rows, leng,r,c,h,w);
        printf("max rectangle in 2D array begins at leftlower [%d, %d], with height of %d and width of %d\n", r,c,h,w);
        
        for(int i=0;i<rows;i++){
            delete[] src[i];
            src[i] = 0;
        }
        delete[] src;
        src = 0;
    }
    return 0;
}

