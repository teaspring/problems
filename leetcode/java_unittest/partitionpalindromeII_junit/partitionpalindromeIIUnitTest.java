/*
 * partitionpalindromeII.minCut(String): int
 *
 * */

import java.util.Collection;
import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class partitionpalindromeIIUnitTest{
    private partitionpalindromeII game;

    @Before
    public void setUp(){
        game = new partitionpalindromeII();
    }

    @Test
    public void ZeroTest(){
        String s = new String("a");
        int expected = 0;
        Assert.assertEquals(expected, game.minCut(s));
    }

    @Test
    public void positiveTest_1(){
        String s = new String("aaa");
        int expected = 0;
        Assert.assertEquals(expected, game.minCut(s));
    }

    @Test
    public void positiveTest_2(){
        String s = new String("abad");
        int expected = 1;
        Assert.assertEquals(expected, game.minCut(s));
    }

    @Test
    public void positiveTest_3(){
        String s = new String("aaaaaaaaaaaab");
        int expected = 1;
        Assert.assertEquals(expected, game.minCut(s));
    }

    @Test
    public void positiveTest_4(){
        String s = new String("baaaaaaaaaaaa");
        int expected = 1;
        Assert.assertEquals(expected, game.minCut(s));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
