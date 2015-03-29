/*
 * String strStr.strstr(String str, String pattern)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class strStrUnitTest{
    private strStr game;

    @Before
    public void setUp(){
        game = new strStr();
    }

    @Test
    public void negativeTest_01(){
        String str = new String("aaababaaa");
        String pattern = new String("aaaa");

        Assert.assertNull(game.strstr(str, pattern));
    }

    @Test
    public void negativeTest_02(){
        String str = new String("aab");
        String pattern = new String("aaab");

        Assert.assertNull(game.strstr(str, pattern));
    }

    @Test
    public void positiveTest_01(){
        String str = new String("aabaabaaac");
        String pattern = new String("aabaaa");

        String expected = new String("aabaaac");
        Assert.assertEquals(expected, game.strstr(str, pattern));
    }

    @Test
    public void positiveTest_02(){
        String str = new String("aabaa");
        String pattern = new String();

        String expected = new String("aabaa");
        Assert.assertEquals(expected, game.strstr(str, pattern));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
