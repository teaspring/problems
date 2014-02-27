/*
 * given an array and a value, remove all instances of that value in place and return the new length
 * */
import java.io.*;
import java.util.*;

public class removeElement{
    public int remove(int[] A, int elem){
        int i=-1, j=0;
        for(; j<A.length; ++j){
            if(A[j] == elem)    continue;
            A[++i] = A[j];
        }
        return i+1;
    }

    public static void main(String[] args){
        return;
    }
}
