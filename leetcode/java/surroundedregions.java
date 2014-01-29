/*
 * given a 2D board containing 'x' and '0', capture all regions surrounded by 'x'. A region is captured by flipping all '0's into 
 * 'x's in that surrounded region.
 * E.g. 
 * x x x 
 * x 0 x
 * x x x 
 *
 * solution: very smart!
 * (1).traverse the '0's connected from 4 walls(up/down/left/right) via BFS, mark them
 * (2).traverse all points, flip all '0's that not marked yet.
 * */
import java.io.*;
import java.util.*;

public class surroundedregions{
    private class pair{
        int x;
        int y;
        pair(int a, int b){
            x = a;
            y = b;
        }
    }
    private final int[] dx = {-1,0,0,1};
    private final int[] dy = {0,1,-1,0};

    private void bfs(int r, int c, char[][] board, int[][] covered){
        int n = board.length;    //get it for use later
        int m = board[0].length;
        covered[r][c] = 1;
        Queue<pair> q = new LinkedList<pair>();
        q.offer(new pair(r, c));
        while(!q.isEmpty()){
            pair p = q.poll();
            for(int i=0;i<4;i++){
                int nr = p.x + dx[i];
                int nc = p.y + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc<m){    //determine if the index valid
                    if(board[nr][nc]=='0' && covered[nr][nc]==0){
                        covered[nr][nc] = 1;
                        q.offer(new pair(nr, nc));
                    }
                }
            }
        }
    } 
    public void solve(char[][] board){
        int n = board.length;
        if(n < 3)    return;
        int m = board[0].length;
        if(m < 3)    return;
        int[][] covered = new int[n][m];
        for(int i=0;i<n;i++){
            if(board[i][0]=='0' && covered[i][0]==0){
                bfs(i,0, board, covered);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='0' && covered[i][m-1]==0){
                bfs(i,m-1, board, covered);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='0' && covered[0][j]==0){
                bfs(0,j, board, covered);
            }
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='0' && covered[n-1][j]==0){
                bfs(n-1,j, board, covered);
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='0' && covered[i][j]==0){
                    board[i][j] = 'x';
                }
            }
        }
        return;
    }
    
    public void display(char[][] board){
        System.out.println("------------------------");
        int n = board.length;
        if(n<1)    return;
        int m = board[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        return;
    }
    /*
     * 0 x x
     * x 0 x
     * x x 0
     * */
    public void test_01(){
        char[][] board = new char[3][3];
        board[0][0] = '0';
        board[0][1] = 'x';
        board[0][2] = 'x';
        board[1][0] = 'x';
        board[1][1] = '0';
        board[1][2] = 'x';
        board[2][0] = 'x';
        board[2][1] = 'x';
        board[2][2] = '0';
        display(board);
        
        solve(board);
        display(board);
    }

    public static void main(String[] args){
        surroundedregions sr = new surroundedregions();
        sr.test_01();
        return;
    }
}
