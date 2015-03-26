/*
 * int longestValidParentheses.longestValidLength(String s)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class longestValidParenthesesUnitTest{
    private longestValidParentheses game;

    @Before
    public void setUp(){
        game = new longestValidParentheses();
    }

    @Test
    public void positiveTest_01(){
        String s = new String("()(())");
        final int expected = 6;

        Assert.assertEquals(expected, game.longestValidLength(s));
    }

    @Test
    public void positiveTest_02(){
        String s = new String("((())()(");
        final int expected = 6;

        Assert.assertEquals(expected, game.longestValidLength(s));
    }

    @Test
    public void positiveTest_03(){
        String s = new String("()())(()()))");
        final int expected = 6;

        Assert.assertEquals(expected, game.longestValidLength(s));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
