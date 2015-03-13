/*
 * ArrayList<ArrayList<Integer>> combinationsumII.combinationSumII(int[], int)
 * */

import org.junit.*;
import org.junit.Assert;
import java.util.ArrayList;

public class combinationsumIIUnitTest{
    private combinationsumII game;

    @Before
    public void setUp(){
        game = new combinationsumII();
    }

    @Test
    public void positiveTest_1(){
        int[] nums = new int[]{1, 1, 2, 2, 2, 3};
        int target = 6;
        ArrayList<ArrayList<Integer>> result = game.combinationSumII(nums, target);

        ArrayList<ArrayList<Integer>> expected = new ArrayList<ArrayList<Integer>>();

        int[] arr1 = new int[]{1, 1, 2, 2};
        int[] arr2 = new int[]{1, 2, 3};
        int[] arr3 = new int[]{2, 2, 2};
        expected.add(fillList(arr1));
        expected.add(fillList(arr2));
        expected.add(fillList(arr3));

        Assert.assertEquals(expected.size(), result.size());
        Assert.assertTrue(assertArrayListExt(expected, result));
        Assert.assertTrue(assertArrayListExt(result, expected));
    }

    private ArrayList<Integer> fillList(int[] arr){
        ArrayList<Integer> dst = new ArrayList<Integer>();
        for(int i=0; i < arr.length; i++){
            dst.add(arr[i]);
        }
        return dst;
    }

    /*
     * to assert two ArrayList<ArrayList<Integer>> objects equals or not
     * */
    private boolean assertArrayListExt(ArrayList<ArrayList<Integer>> expected,
            ArrayList<ArrayList<Integer>> result){
        for(ArrayList<Integer> listExp : expected){
            boolean contains = false;
            for(ArrayList<Integer> listRes : result){
                if(listExp.containsAll(listRes) && listRes.containsAll(listExp)){
                    contains = true;
                    break;
                }
            }
            if(!contains)    return false;
        }
        return true;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
