/********************* Back tracking *********************
 * eight queen problem, naturally for recursion. 
 * elegent sight: from the perspective of queen, when it is put on a square on chessboard, it possesses the entire row, entire column, and diagonals as its own temporary property.
 *        (0,0) (0,1) (0,2) (0,3)
 *        (1,0) (1,1) (1,2) (1,3)
 *        (2,0) (2,1) (2,2) (2,3)
 *left->(3,0) (3,1) (3,2) (3,3)<-right
 *    in the above 4*4 chessboard,
 *    each left diagonal, x+y is unique; all left diagonals vary [0,6]
 *    each right diagnoal, x-y is unique; all right diagonals vary [-3,3]     
 * */

#include <iostream>

using namespace std;

class ChessBoard{
    public:
        ChessBoard();        // 8*8 chessboard
        ChessBoard(int);    // n*n
        void findSolutions();
        ~ChessBoard();

    private:
        const bool available;
        const int squares, norm;
        bool *column, *leftDiagonal, *rightDiagonal;
        int *positionInRow, howMany;
        void putQueen(int);
        void printBoard(ostream&);
        void initializeBoard();
};

ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1){
    initializeBoard();
}

ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1){
    initializeBoard();
}

ChessBoard::~ChessBoard(){
    delete[] column;
    column=0;
    delete[] positionInRow;
    positionInRow=0;
    delete[] leftDiagonal;
    leftDiagonal=0;
    delete[] rightDiagonal;
    rightDiagonal=0;
}

void ChessBoard::initializeBoard(){
    register int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal  = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 - 1];
    for(i=0; i<squares; i++){
        positionInRow[i] = -1;
    }
    for(i=0; i<squares; i++){
        column[i] = available;
    }
    for(i=0; i<squares*2-1;i++){
        leftDiagonal[i] = rightDiagonal[i] = available;
    }
    howMany = 0;
}

void ChessBoard::putQueen(int row){
    for(int col=0; col<squares; col++){
        if(column[col] == available 
        && leftDiagonal[row + col] == available 
        && rightDiagonal[row - col + norm] == available){
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row + col] = !available;
            rightDiagonal[row - col + norm] = !available;
            if(row < squares-1){
                putQueen(row+1);
            }else{
                ++howMany;
                printBoard(cout);
            }
            column[col] = available;                        //pop back
            leftDiagonal[row + col] = available;
            rightDiagonal[row - col + norm] = available;            
        }
    }
}

void ChessBoard::printBoard(ostream& out){
    for(int i=0;i<squares;i++){
        int j = positionInRow[i];
        for(int k=0;k<squares;k++){
            if(k==j)
              out<<" 1";
            else
              out<<" 0";
        }
        out<<endl;
    }
    out<<"----------------------------------"<<endl;
}

void ChessBoard::findSolutions(){
    putQueen(0);
    cout << howMany << " solutions found.\n";
}

int main(int argc, char* argv[]){
    ChessBoard* board = new ChessBoard();
    board->findSolutions();
    delete board;
    board = 0;

    return 0;
}
