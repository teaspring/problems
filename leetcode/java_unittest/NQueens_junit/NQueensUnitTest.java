/*
 * NQueens(int n)
 *
 * ArrayList<String[]> NQueens.solve()
 *
 * int NQueens.totalOptions()
 * */

import org.junit.*;
import org.junit.Assert;
import java.util.ArrayList;

public class NQueensUnitTest{

    @Before
    public void setUp(){
    }

    @Test
    public void negativeTest_1(){
        NQueens game = new NQueens(3);

        int expected = 0; // impossible to place 3 queens on 3*3 board
        Assert.assertEquals(expected, game.totalOptions());

        game = null;
    }

    @Test
    public void positiveTest_1(){
        NQueens game = new NQueens(4);

        String[] arr1 = new String[]{
            "..Q.",
            "Q...",
            "...Q",
            ".Q.."};

        String[] arr2 = new String[]{
            ".Q..",
            "...Q",
            "Q...",
            "..Q."};

        ArrayList<String[]> expected = new ArrayList<String[]>();
        expected.add(arr1);
        expected.add(arr2);

        assertArrayListExt(expected, game.solve());

        game = null;
    }

    /*
     *
     * */
    private boolean equalsStrArray(String[] arr1, String[] arr2){
        if(arr1.length != arr2.length)    return false;

        final int n = arr1.length;
        for(int i = 0; i < n; i++){
            if(!arr1[i].equals(arr2[i]))    return false;
        }
        return true;
    }

    /*
     *
     * */
    private boolean listContains(ArrayList<String[]> expected, String[] strArr){
        for(String[] arr : expected){
            if(equalsStrArray(arr, strArr))    return true;
        }
        return false;
    }

    /*
     * to assert two ArrayList<ArrayList<Integer>> objects equals or not
     * */
    private void assertArrayListExt(ArrayList<String[]> expected,
            ArrayList<String[]> result){
        Assert.assertEquals(expected.size(), result.size());

        for(String[] strArr : result){
            Assert.assertTrue(listContains(expected, strArr));
        }

        for(String[] strArr : expected){
            Assert.assertTrue(listContains(result, strArr));
        }
        return;
    }

    @After
    public void settleDown(){
    }
}
