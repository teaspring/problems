/*
 * partitionpalindrome.partition(String): ArrayList<ArrayList<String>>
 *
 * */

import java.util.Collection;
import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class partitionpalindromeUnitTest{
    private partitionpalindrome game;

    @Before
    public void setUp(){
        game = new partitionpalindrome();
    }

    @Test
    public void NegativeTest(){
        String s = new String();

        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();

        ArrayList<ArrayList<String>> result = game.partition(s);
        assertArrayListExt(expected, result);
    }

    @Test
    public void positiveTest_1(){
        String s = new String("aba");

        String[] arr1 = new String[]{"a", "b", "a"};
        String[] arr2 = new String[]{"aba"};
        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();
        expected.add(fillArrayList(arr1));
        expected.add(fillArrayList(arr2));

        ArrayList<ArrayList<String>> result = game.partition(s);
        assertArrayListExt(expected, result);
    }

    @Test
    public void positiveTest_2(){
        String s = new String("aacaa");

        String[] arr1 = new String[]{"a", "a", "c", "a", "a"};
        String[] arr2 = new String[]{"aacaa"};
        String[] arr3 = new String[]{"aa", "c", "aa"};
        String[] arr4 = new String[]{"aa", "c", "a", "a"};
        String[] arr5 = new String[]{"a", "a", "c", "aa"};
        String[] arr6 = new String[]{"a", "aca", "a"};
        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();
        expected.add(fillArrayList(arr1));
        expected.add(fillArrayList(arr2));
        expected.add(fillArrayList(arr3));
        expected.add(fillArrayList(arr4));
        expected.add(fillArrayList(arr5));
        expected.add(fillArrayList(arr6));

        ArrayList<ArrayList<String>> result = game.partition(s);
        assertArrayListExt(expected, result);
    }

    /*
     * fill String[] to Collection<String>
     * */
    private void fillCollection(String[] arr, Collection<String> coll){
        coll.clear();
        for(String str : arr){
            coll.add(str);
        }
        return;
    }

    private ArrayList<String> fillArrayList(String[] arr){
        ArrayList<String> dst = new ArrayList<String>();
        for(String str : arr){
            dst.add(str);
        }
        return dst;
    }

    /*
     * to assert two ArrayList<ArrayList<String>> objects equals or not
     * */
    private boolean assertArrayListExt(ArrayList<ArrayList<String>> expected,
            ArrayList<ArrayList<String>> result){
        Assert.assertEquals(expected.size(), result.size());
        for(ArrayList<String> listExp : expected){
            boolean contains = false;
            for(ArrayList<String> listRes : result){
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
