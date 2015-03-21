/*
 * double findmedian.findMedianSortedArray(int[], int[])
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class findmedianUnitTest{
    private final double eps = 1e-5d;
    private findmedian game;

    @Before
    public void setUp(){
        game = new findmedian();
    }

    @Test
    public void ZeroTest(){
        int A[] = new int[]{};
        int B[] = new int[]{};
        double expected = 0;

        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SameSizeTest_01(){
        int A[] = new int[]{1, 2};
        int B[] = new int[]{3, 4};
        double expected = 2.5;

        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SameSizeTest_02(){
        int A[] = new int[]{1, 2};
        int B[] = new int[]{4, 5};
        double expected = 3.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SameSizeTest_03(){
        int A[] = new int[]{1, 3};
        int B[] = new int[]{2, 4};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SameSizeTest_04(){
        int A[] = new int[]{1, 2};
        int B[] = new int[]{1, 2};
        double expected = 1.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SameSizeTest_05(){
        int A[] = new int[]{1, 4};
        int B[] = new int[]{2, 3};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SameSizeTest_06(){
        int A[] = new int[]{1, 3, 5, 8};
        int B[] = new int[]{2, 4, 6, 7};
        double expected = 4.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void EmptyTest_01(){
        int A[] = new int[]{};
        int B[] = new int[]{1, 2, 3, 4};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void EmptyTest_02(){
        int A[] = new int[]{1, 2, 3};
        int B[] = new int[]{};
        double expected = 2.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_01(){
        int A[] = new int[]{1};
        int B[] = new int[]{1};
        double expected = 1.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_02(){
        int A[] = new int[]{1};
        int B[] = new int[]{2, 3, 4};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_03(){
        int A[] = new int[]{1};
        int B[] = new int[]{2, 3, 4, 5};
        double expected = 3.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_04(){
        int A[] = new int[]{2};
        int B[] = new int[]{1, 3, 4};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_05(){
        int A[] = new int[]{3};
        int B[] = new int[]{1, 2, 4};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_06(){
        int A[] = new int[]{1, 2, 3, 5, 6};
        int B[] = new int[]{4};
        double expected = 3.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void SingleTest_07(){
        int A[] = new int[]{1, 2, 3, 4};
        int B[] = new int[]{5};
        double expected = 3.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void DiffSize_01(){
        int A[] = new int[]{1, 1};
        int B[] = new int[]{2, 3, 4, 5};
        double expected = 2.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void DiffSize_02(){
        int A[] = new int[]{1, 2, 3};
        int B[] = new int[]{4, 5};
        double expected = 3.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void DiffSize_03(){
        int A[] = new int[]{6, 7, 8};
        int B[] = new int[]{1, 2, 3, 4, 5};
        double expected = 4.5;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void DiffSize_04(){
        int A[] = new int[]{0, 1, 2};
        int B[] = new int[]{4, 5, 6, 7};
        double expected = 4.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @Test
    public void DiffSize_05(){
        int A[] = new int[]{4, 5, 6, 7};
        int B[] = new int[]{3, 8, 9};
        double expected = 6.0;
        Assert.assertEquals(expected, game.findMedianSortedArrays(A, B), eps);
    }

    @After
    public void settleDown(){
        game = null;
    }
}
