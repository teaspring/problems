/*
 * problem 1. place n queens on an n*n chessboard such that no two queens attack each other
 * */

import java.io.*;
import java.util.*;

public class NQueens{
    private int N;
    private int[] columnForRow;
    
    private void printBoard(ArrayList<String[]> res){
        String[] board = new String[N];
        for(int i=0;i<N;i++){
            StringBuilder builder = new StringBuilder();
            for(int j=0;j<N;j++){
                builder.append(j==columnForRow[i] ? 'Q' : '.');
            }
            board[i] = builder.toString();
        }
        res.add(board);
    }

    private boolean check(int r){
        for(int i=0;i<r;i++){
            int tmp = columnForRow[i] - columnForRow[r];
            if(tmp==0        //same column
            || tmp == (i-r)  // '/' diagnol
            || tmp == (r-i)){ // '\' diagnol
                return false;
            }
        }
        return true;
    }

    private void placeQueen(int r, ArrayList<String[]> res){
        if(r==N){
            printBoard(res);
            return;
        }
        for(int i=0;i<N;i++){
            columnForRow[r] = i;
            if(check(r))    placeQueen(r+1, res);
        }
    }
    
    public ArrayList<String[]> solve(int n){
        N=n;
        columnForRow = new int[N];
        ArrayList<String[]> res = new ArrayList<String[]>();
        placeQueen(0, res);
        return res;
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input n:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            int n = Integer.parseInt(str);
            ArrayList<String[]> res = solve(n);
            for(String[] board : res){
                for(String s : board){
                    System.out.println(s);
                }
                System.out.println("-----------------");
            }
            System.out.println("total combinations: " + res.size());
        }
    }

    public static void main(String[] args){
        NQueens nq = new NQueens();
        nq.test_01();
    }
}
