/*
 * implement next permutation which rearranges numbers into the lexicographically next greater permutation of numbers. 
 * if such arrangement is not possible, it must rearrange it as ascending order. all the changes must be in-place
 * test case:
 * 1,2,3 -> 1,3,2
 * 3,2,1 -> 1,2,3
 * 1,1,5 -> 1,5,1
 * 2,3,1 -> 3,1,2
 * */
import java.io.*;
import java.util.*;

public class nextPermutation{
    private void reverse(int[] num){
        int n = num.length;
        for(int i=0; i<(n/2); ++i){
            int tmp = num[i];    //swap [i] and [n-1-i]
            num[i] = num[n-1-i];
            num[n-1-i] = tmp;
        }
        return;
    }

    private void quicksort(int[] num, int b, int e){
        if(b >= e)    return;
        int p=b-1, q=b;
        while(q < e){
            if(num[q] < num[e]){
                ++p;
                int tmp = num[p];    //swap [p] and [q]
                num[p] = num[q];
                num[q] = tmp;
            }
            ++q;
        }
        ++p;
        int tmp = num[p];    //swap [p] and [e]
        num[p] = num[e];
        num[e] = tmp;
        quicksort(num, b, p-1);
        quicksort(num, p+1, e);
    }

    public void nextPerm(int[] num){
        int n = num.length;
        int i=n-2;
        for(; i>=0 && num[i] >= num[i+1]; --i);
        if(i<0){
            reverse(num);
            return;
        }
        int j=n-1;
        while(j > i+1){
            if(num[j] > num[i])        break;
            --j;
        }
        int tmp = num[i];    //swap [i] and [j]
        num[i] = num[j];
        num[j] = tmp;
        quicksort(num, i+1, n-1);
        return;
    }
    
    private void display(int[] arr){
        for(int a : arr){
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input integer array:");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            StringTokenizer t = new StringTokenizer(str, " ,");
            int[] arr = new int[t.countTokens()];
            int i=0;
            while(t.hasMoreTokens()){
                arr[i++] = Integer.parseInt(t.nextToken());
            }
            nextPerm(arr);
            //quicksort(arr, 0, i-1);
            display(arr);
        }
        return;
    }

    public static void main(String[] args){
        nextPermutation np = new nextPermutation();
        np.test_01();
        return;
    }
}
