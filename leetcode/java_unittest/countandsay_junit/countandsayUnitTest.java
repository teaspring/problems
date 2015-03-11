/*
 * String countandsay.countAndSay(int)
 * */

import org.junit.*;
import org.junit.Assert;


public class countandsayUnitTest{
    private countandsay game;

    @Before
    public void setUp(){
        game = new countandsay();
    }

    @Test
    public void positiveTest(){
        Assert.assertEquals(new String("1"), game.countAndSay(1));
        Assert.assertEquals(new String("11"), game.countAndSay(2));
        Assert.assertEquals(new String("21"), game.countAndSay(3));
        Assert.assertEquals(new String("1211"), game.countAndSay(4));
        Assert.assertEquals(new String("111221"), game.countAndSay(5));
        Assert.assertEquals(new String("312211"), game.countAndSay(6));
        Assert.assertEquals(new String("13112221"), game.countAndSay(7));
        Assert.assertEquals(new String("1113213211"), game.countAndSay(8));
        Assert.assertEquals(new String("31131211131221"), game.countAndSay(9));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
