/*************stkTree.cpp***************/
//input: source {1,2,3}, target {2,1,3}; note: source array pop from left most, target array push from right
//output: stack pop/push actions
//
#include "../header/preliminary.h"

char* calculateOperationSequence(int src[], int dst[], int length){
    int idx1=0, idx2=0, k=-1;            //k is top of array stack
    const int NN = 200;
    int* stkArr = new int[NN]();         //stack implementation of array
    
    char* path = new char[NN];           //it must be dynamic array which resides in heap instead of function stack
    memset(path,0,sizeof(char)*NN);      //so it will not be eliminated when function returns
    char* tmp = path;

    stkArr[++k] = src[idx1];             //push
    sprintf(tmp, "%s", "push");
    sprintf(tmp+4, "%d", src[idx1]);
    tmp+=5;
    idx1++;   
    while(idx2<length){
        if(k>-1 && stkArr[k] == dst[idx2]){     //pop
            stkArr[k--]=0;                   
            sprintf(tmp, "%s", "|pop");
            sprintf(tmp+4, "%d", dst[idx2]);
            tmp+=5;
            idx2++;
        }
        else if(idx1<length){                   //push
            stkArr[++k] = src[idx1];
            sprintf(tmp, "%s", "|push");
            sprintf(tmp+5, "%d", src[idx1]);
            tmp+=6;
            idx1++;
        }
        else    break;           
    }

    if(idx2<length){  
      memset(path, 0, sizeof(char)*NN);
      sprintf(path, "%s","None");
    }
    delete[] stkArr;
    stkArr = 0;
    return path;
}

int main(int argc, char* argv[]){
    char line[1000] = {0} ;
    while(getInputLine(line,1000)){
        int originalArray[30] = {0};
        int originalArrayLength = splitAndConvert(line,originalArray);
        if(originalArrayLength==0){
            break;
        }

        getInputLine(line, 1000);
        int resultArray[30] = {0};
        int resultArrayLength = splitAndConvert(line,resultArray);
        if(resultArrayLength==0){
            break;
        }
        char* operationSequence = calculateOperationSequence(originalArray, resultArray, resultArrayLength);
        cout<<operationSequence<<endl;
        delete operationSequence;        //added by me 
    }
    return 0; 
}

