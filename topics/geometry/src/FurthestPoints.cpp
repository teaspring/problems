/*
* search the point collection and find the furthest distance between any two of them
*/
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include "math.h"
#include <algorithm>

using namespace std;

struct Point{
    int X;
    int Y;
};
const int Number = 20;
const int finalCount = 8;
Point pointArray[Number];

double inline GetPointDistance(Point& a, Point& b);
int GetRandInteger(int mode);
void DisplayPointArray(Point arr[Number]);

int FindFurthestPointPair(int indArray[finalCount], int& index1, int& index2){
    double furthestD = 0.0;
    for(int i=0; i<finalCount; i++){
        for(int j=i; j<finalCount; j++){
            if(j==i)    continue;
            double tmp = GetPointDistance(pointArray[indArray[i]], pointArray[indArray[j]]);
            if(furthestD < tmp){
                furthestD = tmp;
                index1 = indArray[i];
                index2 = indArray[j];
            }
        }
    }
    return furthestD;
}

double GetPointDistance(Point& a, Point& b){
    return sqrt((double)(a.X - b.X)*(a.X - b.X) + (double)(a.Y - b.Y)*(a.Y - b.Y));
}

int GetRandInteger(int mode){
    int res = rand() % mode;
    return res % 2 == 1 ? res : 0 - res; 
}

void SearchFurthestDistance(){
    memset(pointArray, 0, sizeof(pointArray));
    for(int i = 0; i<Number; i++){
        pointArray[i].X = GetRandInteger(100);
        pointArray[i].Y = GetRandInteger(100);
    }
    cout << "The point array is ";
    DisplayPointArray(pointArray);

    int index[finalCount];
    memset(index, 0, sizeof(index));
    for(int i=0; i < finalCount; i++){
        index[i] = abs(GetRandInteger(finalCount));
    }
    
    cout<< "The covered points are ";
    for(int i=0; i<finalCount; i++){
        cout << index[i] << " ,";
    }
    cout << endl;

    int ind1, ind2;
    int distance = FindFurthestPointPair(index, ind1, ind2);
    cout << "The longs distance is " << distance 
         << ", and the points are (" << pointArray[ind1].X 
         << " ," << pointArray[ind1].Y << "), (" << pointArray[ind2].X << " ," << pointArray[ind2].Y << ")" << endl;
}

void DisplayPointArray(Point arr[Number]){        
    for(int i=0; i<Number; i++){
        if(i/10 == 0)        cout << endl;
        cout << "(" <<arr[i].X << " ," <<arr[i].Y << "), ";        
    }
    cout << endl;
}

int main(int, char**){
    return 0;
}
