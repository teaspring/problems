/*
* trace in a two dimension array, via Depth-First-Search
* stack(LIFO) is the ideal option of data structure naturally
*/

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

const int MAX_ROW = 5;
const int MAX_COL = 5;

/*
* below to solve a maze trace problem
*/
struct point { 
    int row;
    int col;
    point(int r=0, int c=0): row(r), col(c){}
} myStack[512];

int top = 0;

void push(struct point p){
    myStack[top++] = p;
}

struct point pop(void){
    return myStack[--top];
}

bool Is_Empty(void){
    return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

void print_maze(void){
    for(int i = 0; i < MAX_ROW; ++i){
        for(int j = 0; j < MAX_COL; ++j){
            printf("%d ", maze[i][j]);
        }
        putchar('\n');
    }
    printf("*********\n");
}

point predecessor[MAX_ROW][MAX_COL];

void initializePredecessor(){
    for(int i=0; i<MAX_ROW; ++i){
        for(int j=0; j<MAX_COL; ++j){
            predecessor[i][j] = point(-1, -1);
        }
    }
    return;
}

void visit(int row, int col, struct point pre){
    point visit_point(row, col);
    maze[row][col] = 2;
    predecessor[row][col] = pre;
    push(visit_point);
}

void traceMaze(void){
    point p(0, 0);
    maze[p.row][p.col] = 2;
    push(p);    
    
    while(!Is_Empty()){
        p = pop();
        if(p.row == MAX_ROW - 1  /* goal */
        && p.col == MAX_COL - 1)
          break;
        if(p.col+1 < MAX_COL     /* right */
        && maze[p.row][p.col+1] == 0)
          visit(p.row, p.col+1, p);
        if(p.row+1 < MAX_ROW     /* down */
        && maze[p.row+1][p.col] == 0)
          visit(p.row+1, p.col, p);
        if(p.col-1 >= 0          /* left */
        && maze[p.row][p.col-1] == 0)
          visit(p.row, p.col-1, p);
        if(p.row-1 >= 0          /* up */
        && maze[p.row-1][p.col] == 0)
          visit(p.row-1, p.col, p);
        print_maze();
    }
    
    initializePredecessor();
    if(p.row == MAX_ROW - 1 && p.col == MAX_COL - 1){
        printf("(%d, %d)\n", p.row, p.col);
        while(predecessor[p.row][p.col].row != -1){
            p = predecessor[p.row][p.col];
            printf("(%d, %d)\n", p.row, p.col);
        }
    }else{
        printf("No path!\n");
    }
}

int main(int, char**){
    traceMaze();
    return 0;
}
