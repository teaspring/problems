/*
 * given a matrix of m rows, n columns. return all elements in spiral order
 *
 * test data:
 * 1   2  3  4
 * 5   6  7  8
 * 9  10 11 12
 * 13 14 15 16
 * 17 18 19 20
 * output in spiral order: 1,2,3,4,8,12,16,20,19,18,17,13,9,5,6,7,11,15,14,10
 * */
import java.io.*;
import java.util.*;

public class spiralMatrix{
    public ArrayList<Integer> spiralOrder(int[][] matrix){
        ArrayList<Integer> res = new ArrayList<Integer>();
        int d = matrix.length;
        if(d==0)    return res;
        int w = matrix[0].length;
        if(w==0)    return res;
        
        int[] step = new int[]{1,-1,-1,1};
        int i=0, j=0, k=0;
        while(w>0 && d>0){
            if(k % 2 == 0){
                if(k==0){
                    for(int cnt=0; cnt<w; ++cnt){
                        res.add(matrix[i][j++]);
                    }
                    --j;
                }else if(k==2){
                    for(int cnt=0; cnt<w; ++cnt){
                        res.add(matrix[i][j--]);
                    }
                    ++j;
                }
                i += step[k];
                --d;
            }else{
                if(k==1){
                    for(int cnt=0; cnt<d; ++cnt){
                        res.add(matrix[i++][j]);
                    }
                    --i;
                }else if(k==3){
                    for(int cnt=0; cnt<d; ++cnt){
                        res.add(matrix[i--][j]);
                    }
                    ++i;
                }
                j += step[k];
                --w;
            }
            k = (k+1)%4;
        }
        return res;
    }

    /*
     * spiral matrix II: given n, generate a square matrix filled with elements from 1 to n^2 in spiral order
     * */
    public int[][] generateMatrix(int n){
        if(n<1)    return new int[0][0];   //note the invalid case
        int[][] matrix = new int[n][n];
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                matrix[i][j] = 0;
            }
        }
        
        int d=n, w=d;
        int[] step = new int[]{1,-1,-1,1};
        int i=0, j=0, k=0, a=1;
        boolean horizon = true;
        while(w>0 && d>0){
            if(horizon){
                if(k==0){
                    for(int cnt=0; cnt<w; ++cnt, ++j){
                        matrix[i][j] = a++;
                    }
                    --j;
                }else if(k==2){
                    for(int cnt=0; cnt<w; ++cnt, --j){
                        matrix[i][j] = a++;
                    }
                    ++j;
                }else{
                    break;
                }
                i += step[k];
                --d;
            }else{
                if(k==1){
                    for(int cnt=0; cnt<d; ++cnt, ++i){
                        matrix[i][j] = a++;
                    }
                    --i;
                }else if(k==3){
                    for(int cnt=0; cnt<d; ++cnt, --i){
                        matrix[i][j] = a++;
                    }
                    ++i;
                }else{
                    break;
                }
                j += step[k];
                --w;
            }
            k = (k+1)%4;
            horizon = !horizon;
        }
        return matrix;
    }

    public static void main(String[] args){
        return;
    }
}
