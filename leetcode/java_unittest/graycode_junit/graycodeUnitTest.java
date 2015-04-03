/*
 * int graycode.generate_01(int n)
 *
 * int graycode.generate_02(int n)
 * */

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class graycodeUnitTest{
    private graycode game;

    @Before
    public void setUp(){
        game = new graycode();
    }

    @Test
    public void positiveTest_01(){
        int n = 3;
        Integer[] arr = new Integer[]{
            0, /* 000 */
            1, /* 001 */
            3, /* 011 */
            2, /* 010 */
            6, /* 110 */
            7, /* 111 */
            5, /* 101 */
            4};/* 100 */
        List<Integer> expected = Arrays.asList(arr);

        ArrayList<Integer> result01 = game.generate_01(n);
        Assert.assertTrue(assertListInt(expected, result01));

        ArrayList<Integer> result02 = game.generate_02(n);
        Assert.assertTrue(assertListInt(expected, result02));
    }

    @After
    public void settleDown(){
        game = null;
    }

    private boolean listContains(List<Integer> expected, int x){
        final int n = expected.size();
        for(int i = 0; i < n; i++){
            if(expected.get(i) == x)    return true;
        }
        return false;
    }

    private boolean assertListInt(List<Integer> expected, List<Integer> result){
        Assert.assertEquals(expected.size(), result.size());
        final int n = expected.size();

        for(int i = 0; i < n; i++){
            listContains(expected, result.get(i));
            listContains(result, expected.get(i));
        }
        return true;
    }
}
