/*
 * int gasstation.completeCircuit(int[] gas, int[] cost)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class gasstationUnitTest{
    private gasstation game;

    @Before
    public void setUp(){
        game = new gasstation();
    }

    @Test
    public void positiveTest_01(){
        int gas[] = new int[]{1, 2, 3, 4, 5};
        int cost[] = new int[]{3, 4, 5, 1, 2};
        int expected = 3;

        Assert.assertEquals(expected, game.completeCircuit(gas, cost));
    }

    @Test
    public void positiveTest_02(){
        int gas[] = new int[]{1, 2};
        int cost[] = new int[]{2, 1};
        int expected = 1;

        Assert.assertEquals(expected, game.completeCircuit(gas, cost));
    }

    @Test
    public void negativeTest_01(){
        int gas[] = new int[]{1};
        int cost[] = new int[]{2};
        int expected = -1;

        Assert.assertEquals(expected, game.completeCircuit(gas, cost));
    }

    @Test
    public void negativeTest_02(){
        int gas[] = new int[]{1, 2, 3};
        int cost[] = new int[]{2, 2, 3};
        int expected = -1;

        Assert.assertEquals(expected, game.completeCircuit(gas, cost));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
