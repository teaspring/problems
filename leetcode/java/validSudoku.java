/*
 * determine if a (9*9) Sudoku is valid. the empty cell is '.' 
 * */
import java.io.*;
import java.util.*;

public class validSudoku{
    public void displayArray(char[] arr){
        for(char ch : arr){
            System.out.print(ch + " ");
        }
        System.out.println();
    }

    private boolean check(char[] arr){
        if(arr.length != 9)    return false;
        HashSet<Integer> hs = new HashSet<Integer>();
        for(char ch : arr){
            if(ch == '.')    continue;
            int d = Integer.parseInt(new Character(ch).toString());
            if(d<0 || d>9 || hs.contains(d))    return false;
            hs.add(d);
        }
        return true;
    }

    public boolean isValidSudoku(char[][] board){
        int n = board.length;
        if(n != 9)    return false;
        char[] block = new char[9];
        for(int i=0;i<9;i++){    //rows
            int c = 0;
            for(int j=0;j<9;j++){
                block[c++] = board[i][j];
            }
            if(!check(block))    return false;
        }
        
        for(int j=0;j<9;++j){  //columns
            int c=0;
            for(int i=0;i<9;++i){
                block[c++] = board[i][j];
            }
            if(!check(block))    return false;
        }

        for(int i=0,j=0; i<=6; j+=3){  //3*3 squares, in rows of 3 cells
            if(j>6){
                j=0;
                i+=3;
            }
            if(i>6)        break;
            int c=0;
            for(int t=i, k=j; t<=2+i; ++k){
                if(k > 2+j){
                    k=j;
                    ++t;
                }
                if(t > 2+i)    break;
                block[c++] = board[t][k];
            }
            if(!check(block))    return false;
        }
        return true;
    }

    public void test_01(){
        char[][] board = new char[9][9];
        char[] arr = new char[]{
            '.', '8', '7', '6', '5', '4', '3', '2', '1'
           ,'2', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'3', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'4', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'5', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'6', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'7', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'8', '.', '.', '.', '.', '.', '.', '.', '.'
           ,'9', '.', '.', '.', '.', '.', '.', '.', '.'
        };
        for(int i=0;i<81;i++){
            board[i/9][i%9] = arr[i];
        }
        System.out.println(isValidSudoku(board));
    }
    
    public static void main(String[] args){
        validSudoku vs = new validSudoku();
        vs.test_01();
        return;
    }
}
