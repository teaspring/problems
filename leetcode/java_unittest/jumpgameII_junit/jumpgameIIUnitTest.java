/*
 * int jumpgameII.jump(int[])
 * */

import org.junit.*;
import org.junit.Assert;


public class jumpgameIIUnitTest{
    private jumpgameII game;

    @Before
    public void setUp(){
        game = new jumpgameII();
    }

    @Test
    public void negativeTest(){
        int arr1[] = new int[]{1, 1, 0, 0};
        Assert.assertEquals(-1, game.jump(arr1));

        int arr2[] = new int[]{0, 1, 1};
        Assert.assertEquals(-1, game.jump(arr2));

        int arr3[] = new int[]{0};
        Assert.assertEquals(0, game.jump(arr3));
    }

    @Test
    public void positiveTest(){
        int arr1[] = new int[]{1, 2};
        Assert.assertEquals(1, game.jump(arr1));

        int arr2[] = new int[]{2, 3, 1, 1, 4};
        Assert.assertEquals(2, game.jump(arr2));

        int arr3[] = new int[]{3, 4, 3, 2, 5, 4, 3};
        Assert.assertEquals(3, game.jump(arr3));

        int arr4[] = new int[]{5, 4, 0, 1, 3, 6, 8, 0, 9, 4, 9, 1, 8, 7, 4, 8};
        Assert.assertEquals(3, game.jump(arr4));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
