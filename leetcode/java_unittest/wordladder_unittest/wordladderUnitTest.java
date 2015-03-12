/*
 * wordladderI: int wordladder.ladderLength(String, String, HashSet<String>)
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

    @After
    public void settleDown(){
        game = null;
    }
}
