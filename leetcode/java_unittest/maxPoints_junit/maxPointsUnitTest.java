/*
 * int maxPoints.mPoints(Point[])
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class maxPointsUnitTest{
    private maxPoints game;

    @Before
    public void setUp(){
        game = new maxPoints();
    }

    @Test
    public void positiveTest_01(){
        int[] indexes = {1,1, 3,3, 0,0, 4,5, 4,4, 3,3, 2,2, 1,2, 2,1, 3,4};

        final int n = indexes.length;
        maxPoints.Point[] points = new maxPoints.Point[n/2]; // NOTE the syntax to initialize inner class list

        for(int i = 0; i < points.length; i++){
            points[i] = game.new Point(indexes[2*i], indexes[2*i + 1]); // NOTE the syntax to initialize inner class instance
        }

        int expected = 6;
        Assert.assertEquals(expected, game.mPoints(points));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
