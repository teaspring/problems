/*
 * use a single array to implement three stacks
 * */

/*
 *solution1: if no additional requirement of space usage by individual stacks, split the array to 3 sections with each for one stack
 stack 1: [0, n/3)
 stack 2: [n/3, 2n/3)
 stack 3: [2n/3, n)
 * */

int stackSize = 300;
int *buffer = new int[stackSize * 3]();
int stackPointer[] = {-1, -1, -1};    //index array to track top element of each stack

void push(int stackNum, int value){
    if(stackNum < 0 || stackNum > 2)    return;
    /* find the index of top element in the array*/
    int index = stackNum * stackSize + stackPointer[stackNum] + 1;
    if(index >= stackSize * 3)    return;
    stackPointer[stackNum]++;
    buffer[index] = value;
}

int pop(int stackNum){
    if(stackNum < 0 || stackNum > 2)    return 0;
    int index = stackNum * stackSize + stackPointer[stackNum];
    stackPointer[stackNum]--;
    int val = buffer[index];
    buffer[index] = 0;
    return val;
}

int peek(int stackNum){
    if(stackNum < 0 || stackNum > 2)            return 0;    
    int index = stackNum*stackSize + stackPointer[stackNum];
    if(index < 0 || index >= stackSize * 3)     return 0;
    return buffer[index];    
}

bool isEmpty(int stackNum){
    if(stackNum < 0 || stackNum > 2)    return false;
    return stackPointer[stackNum] < 0;
}

int main(int, char**){
    return 0;
}
