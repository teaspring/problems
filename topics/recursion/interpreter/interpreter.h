//******************* interpreter.h  *********************
//

#ifndef INTERPRETER
#define INTERPRETER

#include <iostream>
#include <cstring>
#include <cctype>
#include <list>
#include <algorithm>    // find()

using namespace std;

class IdNode{
    public:
        IdNode(char* s="", double e=0){
            id = new char[strlen(s) + 1];
            strcpy(id,s);
            value = e;
        }

        bool operator==(const IdNode& node) const{
            return strcmp(id, node.id) == 0;
        }
        bool operator!=(const IdNode& node) const{
            return !(*this == node);
        }
        bool operator<(const IdNode& node) const{
            return strcmp(id, node.id) < 0;
        }
        bool operator>(const IdNode& node) const{
            return strcmp(id, node.id) > 0;
        }
    
    private:
        char* id;
        double value;
        friend class Statement;
        friend ostream& operator<< (ostream&, const IdNode&);
};

class Statement{
    public:
        Statement(){
        }
        void getStatement();
    private:
        list<IdNode> idList;
        char ch;
        double factor();
        double term();
        double expression();
        void readId(char*);
        void issueError(const char* s){
            cerr << s << endl;
            exit(1);
        }
        double findValue(char*);
        void processNode(char*, double);
        friend ostream& operator<<(ostream&, const Statement&);
};
#endif
