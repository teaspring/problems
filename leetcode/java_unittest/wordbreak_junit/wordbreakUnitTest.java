/*
 * wordbreakI:
 * boolean wordbreak.canBreak(String s, Set<String>)
 *
 * */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.Set;
import org.junit.*;
import org.junit.Assert;

public class wordbreakUnitTest{
    private wordbreak game;

    @Before
    public void setUp(){
        game = new wordbreak();
    }

    @Test
    public void wordbreakI_positiveTest_1(){
        String S = new String("leetcode");

        String[] arr_succ = new String[]{"lee", "tco", "d", "leet", "code"};
        Set<String> dict_succ = new HashSet<String>();
        for(String s : arr_succ){
            dict_succ.add(s);
        }

        Assert.assertTrue(game.canBreak(S, dict_succ));
    }

    @Test
    public void wordbreakI_negativeTest_1(){
        String S = new String("leetcode");

        String[] arr_fail = new String[]{"lee", "tco", "d", "oe", "cod", "leet"};
        Set<String> dict_fail = new HashSet<String>();
        for(String s : arr_fail){
            dict_fail.add(s);
        }

        Assert.assertFalse(game.canBreak(S, dict_fail));
    }

    @Test
    public void wordbreakI_zeroTest(){
        String S = new String();
        Set<String> dict = new HashSet<String>();
        dict.add("o");
        Assert.assertTrue(game.canBreak(S, dict));
    }

    private ArrayList<String> fillList(String[] arr){
        ArrayList<String> dst = new ArrayList<String>();
        for(int i=0; i < arr.length; i++){
            dst.add(arr[i]);
        }
        return dst;
    }

    /*
     * to assert two ArrayList<ArrayList<String>> objects equals or not
     * */
    private boolean assertArrayListExt(ArrayList<ArrayList<String>> expected,
            ArrayList<ArrayList<String>> result){
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
