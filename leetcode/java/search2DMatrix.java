/*
 * write an efficient algorithm that searches for a value in an m*n matrix. The matrix is: 
 * 1.integers in each row are sorted in ascending order from left to right
 * 2.the first integer of each row is greater than the last integer of previous row
 * */
import java.io.*;
import java.util.*;

public class search2DMatrix{

    public boolean search_01(int[][] matrix, int target){
        final int n = matrix.length;
        if(n < 1)    return false;

        final int m = matrix[0].length;
        int v = 0, u = m*n;    //search range [v,u)

        while(v < u){
            int mid = (v + u) / 2;
            int i = mid / m;
            int j = mid % m;

            if(matrix[i][j] == target){
                return true;
            }

            if(matrix[i][j] > target){
                u = mid;  // u decreases
            }else{
                v = mid + 1; // v increases
            }
        }

        return false;
    }

    public boolean search_02(int[][] matrix, int target){
        final int n = matrix.length;
        if(n < 1)    return false;

        final int m = matrix[0].length;
        int v = 0, u = m*n - 1;    //search range [v,u]
        while(v <= u){
            int mid = (v + u) / 2;
            int i = mid / m;
            int j = mid % m;

            if(matrix[i][j] == target){
                return true;
            }

            if(matrix[i][j] > target){
                u = mid - 1; // u decreases
            }else{
                v = mid + 1;  // v increases
            }
        }

        return false;
    }
}

/* unit test is in ../java_unittest/search2DMatrix_junit/ */
