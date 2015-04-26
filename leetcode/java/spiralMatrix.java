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
import java.util.ArrayList;

public class spiralMatrix{
    public ArrayList<Integer> spiralOrder(int[][] matrix){
        ArrayList<Integer> result = new ArrayList<Integer>();

        final int n = matrix.length;
        final int m = matrix[0].length;

        int[] edgeLengths = new int[]{m, n-1};
        final int[] xStep = new int[]{0, 1, 0, -1};
        final int[] yStep = new int[]{1, 0, -1, 0};

        int currX = 0, currY = -1;
        int mode = 0;
        while(true){
            mode %= 4;
            int l = edgeLengths[mode % 2];
            if(l == 0)    break;

            for(int i = 0; i < l; i++){
                currX += xStep[mode];
                currY += yStep[mode];
                result.add(matrix[currX][currY]);
            }

            edgeLengths[mode % 2]--;
            mode++;
        }

        return result;
    }

    /*
     * spiral matrix II: given n, generate a square matrix filled with elements from 1 to n^2 in spiral order
     * */
    public int[][] generateMatrix(int n, int m){
        int[][] result = new int[n][m];

        int[] edgeLengths = new int[]{m, n-1};
        final int[] xStep = new int[]{0, 1, 0, -1};
        final int[] yStep = new int[]{1, 0, -1, 0};

        int currX = 0, currY = -1;
        int mode = 0, val = 1;
        while(true){
            mode %= 4;
            int l = edgeLengths[mode % 2];
            if(l == 0)    break;

            for(int i = 0; i < l; i++){
                currX += xStep[mode];
                currY += yStep[mode];
                result[currX][currY] = val++;
            }

            edgeLengths[mode % 2]--;
            mode++;
        }

        return result;
    }
}

/* unit test is in ../java_unittest/spiralMatrix_junit */
