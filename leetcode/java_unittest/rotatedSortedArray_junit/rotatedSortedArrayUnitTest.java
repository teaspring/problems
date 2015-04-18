/*
 * int rotatedSortedArray.search(int[], int key) // no duplicate
 * int rotatedSortedArray.searchII(int[], int key) // duplicate is allowed
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class rotatedSortedArrayUnitTest{
    private rotatedSortedArray game;

    @Before
    public void setUp(){
        game = new rotatedSortedArray();
    }

    @Test
    public void searchTest_1(){
        int arr[] = new int[]{5, 6, 1, 2, 3};
        for(int i = 0; i < arr.length; i++){
            int expected = i;
            int key = arr[i];
            Assert.assertEquals(expected, game.search(arr, key));
        }

        Assert.assertEquals(-1, game.search(arr, 0));
        Assert.assertEquals(-1, game.search(arr, 4));
        Assert.assertEquals(-1, game.search(arr, 7));
    }

    @Test
    public void searchTest_2(){
        int arr[] = new int[]{2, 3, 4, 6, 8, 1};
        for(int i = 0; i < arr.length; i++){
            int expected = i;
            int key = arr[i];
            Assert.assertEquals(expected, game.search(arr, key));
        }

        Assert.assertEquals(-1, game.search(arr, 0));
        Assert.assertEquals(-1, game.search(arr, 5));
        Assert.assertEquals(-1, game.search(arr, 9));
    }

    @Test
    public void searchIITest_1(){
        int arr[] = new int[]{1, 1, 5, 1, 1, 1, 1, 1};

        int key = 5;
        int expected = 2;
        Assert.assertEquals(expected, game.searchII(arr, key));

        Assert.assertEquals(-1, game.searchII(arr, 0));
        Assert.assertEquals(-1, game.searchII(arr, 2));
        Assert.assertEquals(-1, game.searchII(arr, 4));
        Assert.assertEquals(-1, game.searchII(arr, 8));
    }

    @Test
    public void searchIITest_2(){
        int arr[] = new int[]{5, 5, 6, 1, 2, 2, 3, 4, 4};

        Assert.assertEquals(2, game.searchII(arr, 6));
        Assert.assertEquals(3, game.searchII(arr, 1));
        Assert.assertEquals(6, game.searchII(arr, 3));
    }

    @Test
    public void searchIITest_3(){
        int arr[] = new int[]{2, 2, 3, 4, 5, 5, 1};

        Assert.assertEquals(2, game.searchII(arr, 3));
        Assert.assertEquals(3, game.searchII(arr, 4));
        Assert.assertEquals(6, game.searchII(arr, 1));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
