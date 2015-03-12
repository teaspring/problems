/*
 * wordladderI: int wordladder.ladderLength(String, String, HashSet<String>)
 *
 * wordladderII: ArrayList<ArrayList<String>> findLadders(String, String, HashSet<String>)
 * */

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
        String start = "dik";
        String end = "oak";
        HashSet<String> dict = new HashSet<String>();
        String[] arr = new String[]{"dog", "dig", "dad", "oad", "oig", "oag"};
        for(String s : arr){
            dict.add(s);
        }
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
    public void wordladderII_positiveTest_1(){
        String start = "dog";
        String end = "dad";
        HashSet<String> dict = new HashSet<String>();
        String[] arr = new String[]{"dod", "dag", "did"};
        for(String s : arr){
            dict.add(s);
        }

        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();

        String[] arr1 = new String[]{"dog", "dod", "dad"};
        ArrayList<String> path1 = new ArrayList<String>();
        fillList(path1, arr1);
        expected.add(path1);

        String[] arr2 = new String[]{"dog", "dag", "dad"};
        ArrayList<String> path2 = new ArrayList<String>();
        fillList(path2, arr2);
        expected.add(path2);

        ArrayList<ArrayList<String>> result = game.findLadders(start, end, dict);

        Assert.assertEquals(expected.size(), result.size());
    }

    @Test
    public void wordladderII_positiveTest_2(){
        String start = "hit";
        String end = "cog";
        HashSet<String> dict = new HashSet<String>();
        String[] arr = new String[]{"hot", "dot", "dog", "lot", "log", "hat", "bit", "big", "dit", "dig", "cat", "hak", "cak", "cok", "dok"};
        for(String s : arr){
            dict.add(s);
        }

        ArrayList<ArrayList<String>> expected = new ArrayList<ArrayList<String>>();

        String[] arr1 = new String[]{"hit", "hot", "dot", "dog", "cog"};
        ArrayList<String> path1 = new ArrayList<String>();
        fillList(path1, arr1);
        expected.add(path1);

        String[] arr2 = new String[]{"hit", "hot", "lot", "log", "cog"};
        ArrayList<String> path2 = new ArrayList<String>();
        fillList(path2, arr2);
        expected.add(path2);

        String[] arr3 = new String[]{"hit", "dit", "dig", "dog", "cog"};
        ArrayList<String> path3 = new ArrayList<String>();
        fillList(path3, arr3);
        expected.add(path3);

        String[] arr4 = new String[]{"hit", "hot", "dot", "dog", "cog"};
        ArrayList<String> path4 = new ArrayList<String>();
        fillList(path4, arr4);
        expected.add(path4);

        ArrayList<ArrayList<String>> result = game.findLadders(start, end, dict);

        for(ArrayList<String> path : result){
            Assert.assertTrue(expected.contains(path));
        }
        for(ArrayList<String> path : expected){
            Assert.assertTrue(result.contains(path));
        }
        Assert.assertTrue(result.containsAll(expected));
        Assert.assertTrue(expected.containsAll(result));
    }

    private void fillList(ArrayList<String> dst, String[] arr){
        for(int i=0; i < arr.length; i++){
            dst.add(arr[i]);
        }
        return;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
