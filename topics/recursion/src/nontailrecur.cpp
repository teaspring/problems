/*
 * nontail recursion
 * 1> one problem that can be implemented in recursion is printing an input line in reverse order
 * 2> transformation of recursion into iterartion usually involves explicit handling of a stack
 * */
#include <iostream>
using namespace std;

void reversech(){
    char ch;
    cin.get(ch);
    if(ch != '\n'){
        reversech();
        cout.put(ch);
    }
}

int main(int argc, char* argv[]){
    if(0){                                    // without recursion
        char stack[80];
        register int top = 0;
        cin.get(stack[top]);
        while(stack[top] != '\n'){
            cin.get(stack[++top]);
        }
        for(top -= 1; top >= 0; cout.put(stack[top--]));
    }else{
        reversech();
    }
    return 0;
}
