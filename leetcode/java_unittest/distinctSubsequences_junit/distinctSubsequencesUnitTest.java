/*
 * int distinctSubsequences.numDistinct_01/02(String src, String pattern)
 * */

import org.junit.*;
import org.junit.Assert;

public class distinctSubsequencesUnitTest{
    private distinctSubsequences game;

    @Before
    public void setUp(){
        game = new distinctSubsequences();
    }

    @Test
    public void positiveTest(){
        String S = new String("rabbbit");
        String T = new String("rabit");
        Assert.assertEquals(3, game.numDistinct_01(S, T));
        Assert.assertEquals(3, game.numDistinct_02(S, T));
    }

    @Test
    public void zeroTest(){
        String S = new String("ABB");
        String T = new String("ABBB");
        Assert.assertEquals(0, game.numDistinct_01(S, T));
        Assert.assertEquals(0, game.numDistinct_02(S, T));
    }

    @Test
    public void negativeTest(){
        String S = new String("ABBCBBDBBF");
        String T = new String("ADC");
        Assert.assertEquals(0, game.numDistinct_01(S, T));
        Assert.assertEquals(0, game.numDistinct_02(S, T));
    }

    @Test
    public void emptyTest(){
        String S = new String();
        String T = new String();
        Assert.assertEquals(1, game.numDistinct_01(S, T));
        Assert.assertEquals(1, game.numDistinct_02(S, T));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
