/*
 * wordladderI: int wordladder.ladderLength(String, String, HashSet<String>)
 *
 * wordladderII: ArrayList<ArrayList<String>> findLadders(String, String, HashSet<String>)
 * */

import java.util.Collection;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.HashSet;
import org.junit.*;
import org.junit.Assert;


public class wordladderUnitTest{
    private wordladder game;

    @Before
    public void setUp(){
        game = new wordladder();
    }

    @Test
    public void wordladderI_positiveTest_1(){
        String start = new String("dik");
        String end = new String("oak");
        HashSet<String> dict = new HashSet<String>();
        String[] arr = new String[]{"dog", "dig", "dad", "oad", "oig", "oag"};
        fillCollection(arr, dict);

        Assert.assertEquals(5, game.ladderLength(start, end, dict));
    }

    @Test
    public void wordladderI_zeroTest_1(){
        String start = new String("dig");
        String end = new String("dig");
        HashSet<String> dict = new HashSet<String>();

        Assert.assertEquals(1, game.ladderLength(start, end, dict));
    }

    @Test
    public void wordladderI_zeroTest_2(){
        String start = new String("dig");
        String end = new String("dog");
        HashSet<String> dict = new HashSet<String>();

        Assert.assertEquals(2, game.ladderLength(start, end, dict));
    }

    @Test
    public void wordladderI_negativeTest(){
        String start = new String("dig");
        String end = new String("dot");
        HashSet<String> dict = new HashSet<String>();

        Assert.assertEquals(0, game.ladderLength(start, end, dict));
    }

    @Test
    public void wordladderII_positiveTest_1(){
        String start = new String("dog");
        String end = new String("dad");

        HashSet<String> dict = new HashSet<String>();
        String[] arr = new String[]{"dod", "dag", "did"};
        fillCollection(arr, dict);

        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();
        String[] arr1 = new String[]{"dog", "dod", "dad"};
        String[] arr2 = new String[]{"dog", "dag", "dad"};
        expected.add(fillArrayList(arr1));
        expected.add(fillArrayList(arr2));

        ArrayList<ArrayList<String>> result = game.findLadders(start, end, dict);

        Assert.assertTrue(assertArrayListExt(expected, result));
        Assert.assertTrue(assertArrayListExt(result, expected));
    }

    @Test
    public void wordladderII_positiveTest_2(){
        String start = new String("hit");
        String end = new String("cog");
        HashSet<String> dict = new HashSet<String>();
        String[] arr = new String[]{"hot", "dot", "dog", "lot", "log", "hat", "bit",
            "big", "dit", "dig", "cat", "hak", "cak", "cok", "dok"};
        fillCollection(arr, dict);

        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();

        String[] arr1 = new String[]{"hit", "hot", "dot", "dog", "cog"};
        String[] arr2 = new String[]{"hit", "hot", "lot", "log", "cog"};
        String[] arr3 = new String[]{"hit", "dit", "dig", "dog", "cog"};
        String[] arr4 = new String[]{"hit", "dit", "dot", "dog", "cog"};
        expected.add(fillArrayList(arr1));
        expected.add(fillArrayList(arr2));
        expected.add(fillArrayList(arr3));
        expected.add(fillArrayList(arr4));

        ArrayList<ArrayList<String>> result = game.findLadders(start, end, dict);

        Assert.assertTrue(assertArrayListExt(expected, result));
        Assert.assertTrue(assertArrayListExt(result, expected));
    }

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
