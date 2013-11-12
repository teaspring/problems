/*
 ****************<DataStructureInC++> chapter4 stack & queue******************
 * Maze in Stack, a mouse exit a maze
 * test data:
 * 111111
 * 111001
 * 1000e1
 * 100m11
 * 111111
 */
#include <iostream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

template<typename T>
class Stack : public stack<T>{
public:
    T pop(){
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
};

class Cell{
public:
    Cell(int i=0, int j=0){
        x = i; y = j;
    }
    bool operator==(const Cell& c) const{            //right operand is const
        return x == c.x && y == c.y;
    }
    bool operator<(const Cell& c) const{    // to satisfy the compiler;
        return true;
    }
private:
    int x, y;
    friend class Maze;
};

class Maze{
    public:
        Maze();
        void exitMaze();
    private:
        Cell currentCell, exitCell, entryCell;
        const char exitMarker, entryMarker, visited, passage, wall;
        Stack<Cell> mazeStack;
        char **store;            // array of strings;
        void pushUnvisited(int, int);
        friend ostream& operator<<(ostream&, const Maze&);
        int rows, cols;
};

Maze::Maze(): exitMarker('e'), entryMarker('m'), visited('.'),
            passage('0'), wall('1')
{
    Stack<char*> mazeRows;
    char str[80], *s;
    int col=0, row=0;
    cout << "Enter a rectangle maze using the following "
         << "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
         << "Enter one line at time; end with Ctrl-z:\n";
    while(cin >> str){
        row++;
        cols = strlen(str);
        s = new char[col+3];        // two more cells for borderline columns;
        
        mazeRows.push(s);
        strcpy(s+1, str);
        s[0] = s[cols+1] = wall;    // fill the borderline cells with 1;
        s[cols+2] = '\0';
        if(strchr(s, exitMarker) != 0){
            exitCell.x = row;
            exitCell.y = strchr(s, exitMarker) -s;
        }

        if(strchr(s, entryMarker) != 0){
            entryCell.x = row;
            entryCell.y = strchr(s, entryMarker) - s;
        }
    }
    rows = row;
    store = new char*[rows+2];            // create a 1D array of pointers
    store[0] = new char[cols+3];        // a borderline row
    for(; !mazeRows.empty(); row--){
        store[row] = mazeRows.pop();
    }
    store[rows+1] = new char[cols+3];    // another borderline row
    store[0][cols+2] = store[rows+1][cols+2] = '\0';
    for(col=0; col <= cols+1; col++){
        store[0][col] = wall;            //fill the borderline rows with 1
        store[rows+1][col] = wall;
    }
}

void Maze::pushUnvisited(int row, int col){
    if(store[row][col] == passage || store[row][col] == exitMarker){
        mazeStack.push(Cell(row, col));
    }
}

void Maze::exitMaze(){
    int row, col;
    currentCell = entryCell;
    while(!(currentCell == exitCell)){
        row = currentCell.x;
        col = currentCell.y;
        cout << *this;                    //print a snapshot
        if(!(currentCell == entryCell))
          store[row][col] = visited;
        pushUnvisited(row-1, col);
        pushUnvisited(row+1, col);
        pushUnvisited(row, col-1);
        pushUnvisited(row, col+1);
        if(mazeStack.empty()){
            cout << *this;
            cout << "Failure\n";
            return;
        }
        else currentCell = mazeStack.pop();
    }
    cout << *this;
    cout << "Success\n";
}
            
ostream& operator<<(ostream& out, const Maze& maze){
    for(int row=0; row <= maze.rows+1; row++)
      out << maze.store[row] << endl;
    out << endl;
    return out;        
}

int main(int argc, char* argv[]){
    Maze().exitMaze();
    return 0;
}
