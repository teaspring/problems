/*
 * int maxstockprofit.maxProfitIII(ArrayList<Integer> prices)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class maxstockprofitUnitTest{
    private maxstockprofit game;

    @Before
    public void setUp(){
        game = new maxstockprofit();
    }

    @Test
    public void positiveTest_01(){
        int arr[] = new int[]{1, 2, 4, 3, 2, 1, 3, 2};
        ArrayList<Integer> prices = fillList(arr);

        int expected = 5;
        Assert.assertEquals(expected, game.maxProfitIII(prices));
    }

    private ArrayList<Integer> fillList(int[] arr){
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int v : arr){
            list.add(v);
        }
        return list;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
