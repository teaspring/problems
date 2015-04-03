/*
 * int search2DMatrix.search_01(int[][] matrix, int x)
 *
 * int search2DMatrix.search_02(int[][] matrix, int x)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class search2DMatrixUnitTest{
    private search2DMatrix game;
    private int[][] matrix;

    @Before
    public void setUp(){
        game = new search2DMatrix();
        matrix = constructMatrix();
    }

    @Test
    public void positiveTest_01(){
        Assert.assertTrue(game.search_01(matrix, 3));
        Assert.assertTrue(game.search_02(matrix, 3));
    }

    @Test
    public void positiveTest_02(){
        Assert.assertTrue(game.search_01(matrix, 11));
        Assert.assertTrue(game.search_02(matrix, 11));
    }

    @Test
    public void positiveTest_03(){
        Assert.assertTrue(game.search_01(matrix, 50));
        Assert.assertTrue(game.search_02(matrix, 50));
    }

    @Test
    public void positiveTest_04(){
        Assert.assertTrue(game.search_01(matrix, 1));
        Assert.assertTrue(game.search_02(matrix, 1));
    }

    @Test
    public void positiveTest_05(){
        Assert.assertTrue(game.search_01(matrix, 23));
        Assert.assertTrue(game.search_02(matrix, 23));
    }

    @Test
    public void negativeTest_01(){
        Assert.assertFalse(game.search_01(matrix, 4));
        Assert.assertFalse(game.search_02(matrix, 4));
    }

    @Test
    public void negativeTest_02(){
        Assert.assertFalse(game.search_01(matrix, 8));
        Assert.assertFalse(game.search_02(matrix, 8));
    }

    @Test
    public void negativeTest_03(){
        Assert.assertFalse(game.search_01(matrix, 51));
        Assert.assertFalse(game.search_02(matrix, 51));
    }

    @Test
    public void negativeTest_04(){
        Assert.assertFalse(game.search_01(matrix, 0));
        Assert.assertFalse(game.search_02(matrix, 0));
    }

    @After
    public void settleDown(){
        game = null;
        matrix = null;
    }

    private int[][] constructMatrix(){
        return new int[][]{
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };
    }
}
