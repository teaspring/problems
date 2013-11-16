//********************** useInterpreter.cpp *********************
//
#include "interpreter.h"
using namespace std;

int main(int argc, char* argv[]){
    Statement stm;
    cout << "The program processes statements of the following format:\n"
         << "\t<id> = <expr>;\n\tprint <id>\n\tstatus\n\tend\n\n";
    while(1){                        //infinite loop is broken by exit(1)
        stm.getStatement();            //in getStatement() or upon finding an error
    }
    return 0;
}
