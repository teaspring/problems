/*
 * int candy.minCandy_01(int[])
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class candyUnitTest{
    private candy game;

    @Before
    public void setUp(){
        game = new candy();
    }

    @Test
    public void positiveTest_01(){
        int ratings[] = new int[]{1, 2, 4, 4, 2, 3};
        int candies[] = new int[]{1, 2, 3, 2, 1, 2};
        int expected = 0;
        for(int c : candies){
            expected += c;
        }
        Assert.assertEquals(expected, game.minCandy_01(ratings));
        Assert.assertEquals(expected, game.minCandy_02(ratings));
    }

    @Test
    public void positiveTest_02(){
        int ratings[] = new int[]{1, 8, 8, 5, 5, 3, 2, 2, 2, 4, 6, 1};
        int candies[] = new int[]{1, 2, 2, 1, 3, 2, 1, 1, 1, 2, 3, 1};
        int expected = 0;
        for(int c : candies){
            expected += c;
        }
        Assert.assertEquals(expected, game.minCandy_01(ratings));
        Assert.assertEquals(expected, game.minCandy_02(ratings));
    }

    @Test
    public void zeroTest(){
        int ratings[] = new int[]{1};
        Assert.assertEquals(1, game.minCandy_01(ratings));
        Assert.assertEquals(1, game.minCandy_02(ratings));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
