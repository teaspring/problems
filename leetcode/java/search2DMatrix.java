/*
 * write an efficient algorithm that searches for a value in an m*n matrix. The matrix is: 
 * 1.integers in each row are sorted in ascending order from left to right
 * 2.the first integer of each row is greater than the last integer of previous row
 * */
import java.io.*;
import java.util.*;

public class search2DMatrix{
    public boolean searchMatrix_01(int[][] matrix, int target){
        int n = matrix.length;
        if(n < 1)    return false;
        int m = matrix[0].length;
        int v=0, u=m*n, mid=v, i=0, j=0;    //search range [v,u)
        while(v < u){
            mid = (v+u)/2;
            i = mid / m;
            j = mid % m;
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                u = mid;
            }else{
                v = mid+1;
            }
        }
        return false;
    }

    public boolean searchMatrix_02(int[][] matrix, int target){
        int n = matrix.length;
        if(n < 1)    return false;
        int m = matrix[0].length;
        int v=0, u=m*n-1, mid=v, i=0, j=0;    //search range [v,u]
        while(v <= u){
            mid = (v+u)/2;
            i = mid / m;
            j = mid % m;
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                u = mid-1;
            }else{
                v = mid+1;
            }
        }
        return false;
    }

    public static void main(String[] args){
        return;
    }
}
