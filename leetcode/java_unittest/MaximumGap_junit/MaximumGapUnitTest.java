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
        Assert.assertEquals(4, mg.maximumGap(arr1));

        int arr2[] = new int[]{-1, -1, -1, -1};
        Assert.assertEquals(0, mg.maximumGap(arr2));
    }

    @After
    public void settleDown(){
        mg = null;
    }
}
