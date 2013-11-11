#include "../header/preliminary.h"
using namespace std;

/* 
 * question:
 * input:1 2 3 4 10
 * output:1+2+3+4=10
 * input:1 2 3 4 5
 * output:Invalid
 * function signature is limited by default. recursion is not permitted
 * param: length of the input parameters excluding target
 * */
void calcuEqualExam(int* inArr, int length, int target){
    char* operands = new char[length-1]();
    memset(operands, 0, sizeof(char)*(length-1));
    operands[0]='+';
    int idx=1;
    while(operands[0] != 0){
        for(;idx<length-1;idx++)         //complement '+' starting from idx
          operands[idx]='+';
        int sum = inArr[0];
        for(idx=0;idx<length-1;idx++){
            if(operands[idx] == '+')
              sum += inArr[idx+1];
            else
              sum -= inArr[idx+1];
        }
        if(sum == target) break;
        idx--;
        for(;idx>-1 && operands[idx]=='-';idx--)    //reset all '-' backward from tail
          operands[idx]=0;
        if(idx>-1)    operands[idx]='-';            //set the last '+' to '-'
        idx++;        
    }
    if(operands[0]==0)
      cout<<"Invalid";
    else{
        cout<<inArr[0];
        for(int i=0;i<length-1;i++)
          cout<<operands[i]<<inArr[i+1];
        cout<<'='<<target<<endl;
    }
    delete[] operands;
    operands = 0;
    return;
}


/*
 * here recursive function seems too easy and not permitted
 *length of input[]. for {7,2,4,9}, length is 4, target is arr[length-1], path[] size is length-2 
 * */
bool calcuEqual(int* arr, int length,  int sum, int i, char* path){    //for {7 2 4 9}, length of input[] is 4 while length-2 for path[]
    if(i>length-3)
      return sum == arr[length-1];
    path[i] = '+';
    bool res = calcuEqual(arr,length,sum+arr[i+1],i+1,path);
    if (!res){
        path[i]='-';    
        return calcuEqual(arr,length,sum-arr[i+1],i+1,path);
    }
    return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
        if(getline(cin, str)==0 || str.empty())
          break;
        int* arr = new int[str.size()]();
        int n = splitStr2IntArray(str, arr);
        calcuEqualExam(arr, n-1, arr[n-1]);

        delete[] arr;
        arr=0;
    }
    return 0;
}
