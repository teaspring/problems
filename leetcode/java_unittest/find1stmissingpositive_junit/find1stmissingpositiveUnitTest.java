/*
 * int find1stmissingpositive.findMissingPositive(int[])
 * */

import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class find1stmissingpositiveUnitTest{
    private find1stmissingpositive game;

    @Before
    public void setUp(){
        game = new find1stmissingpositive();
    }

    @Test
    public void positiveTest_01(){
        int arr[] = new int[]{1, 2, 0};
        int expected = 3;

        Assert.assertEquals(expected, game.findMissingPositive(arr));
    }

    @Test
    public void positiveTest_02(){
        int arr[] = new int[]{4, 2, 3};
        int expected = 1;

        Assert.assertEquals(expected, game.findMissingPositive(arr));
    }

    @Test
    public void positiveTest_03(){
        int arr[] = new int[]{3, 2, 1};
        int expected = 4;

        Assert.assertEquals(expected, game.findMissingPositive(arr));
    }

    @Test
    public void positiveTest_04(){
        int arr[] = new int[]{4, 1, 4, 3};
        int expected = 2;

        Assert.assertEquals(expected, game.findMissingPositive(arr));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
