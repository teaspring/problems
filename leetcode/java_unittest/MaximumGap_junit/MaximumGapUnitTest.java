/*
 * int MaximumGap.maximumGap(int[])
 * */

import org.junit.*;
import org.junit.Assert;


public class MaximumGapUnitTest{
    private MaximumGap mg;

    @Before
    public void setUp(){
        mg = new MaximumGap();
    }

    @Test
    public void positiveTest(){
        int arr1[] = new int[]{3, 4, 1, -1, 2, 0, 8};
        int expected = 4;

        Assert.assertEquals(expected, mg.maximumGap(arr1));

        int arr2[] = new int[]{-1, -1, -1, -1};
        expected = 0;
        Assert.assertEquals(expected, mg.maximumGap(arr2));
    }

    @After
    public void settleDown(){
        mg = null;
    }
}
