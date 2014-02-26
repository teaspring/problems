/*
 * rotate a n*n 2D matrix as an image. in 90 degrees clockwisely in place.
 * */
import java.io.*;
import java.util.*;

public class rotateImage{
    public void rotate(int[][] matrix){
        int n = matrix.length;
        if(n==0)    return;
        for(int i=0;i<n;i++){
            for(int j=0;j < n/2;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = tmp;
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = tmp;
            }
        }
        return;
    }
    
    public static void swap(int a, int b){   //useless, because Java does not support reference of native type
        int tmp = b;
        b = a;
        a = tmp;
        return;
    }

    public static void test_01(){
        int a = 1, b =2;
        System.out.println("a=" + a + ", b=" + b);
        swap(a, b);
        System.out.println("a=" + a + ", b=" + b);
    }

    public static void main(String[] args){
        rotateImage.test_01();
        return ;
    }
}
