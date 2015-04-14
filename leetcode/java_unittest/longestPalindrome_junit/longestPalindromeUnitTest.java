/*
 * String longestPalindrome.Manacher(String str)
 *
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class longestPalindromeUnitTest{
    private longestPalindrome game;

    @Before
    public void setUp(){
        game = new longestPalindrome();
    }

    @Test
    public void Manacher_positive01(){
        final String str = new String("dbdogodcde");
        final String expected = new String("dogod");
        String result = game.Manacher(str);

        Assert.assertEquals(expected, result);
    }

    @Test
    public void Manacher_positive02(){
        final String str = new String("dbdogodcggddggsgsdghhsdfsdfe");;
        final String expected = new String("ggddgg");
        String result = game.Manacher(str);

        Assert.assertEquals(expected, result);
    }

    @After
    public void settleDown(){
        game = null;
    }
}
