/*
 * ArrayList<String> anagrams.getAnagrams(String[])
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;


public class anagramsUnitTest{
    private anagrams game;

    @Before
    public void setUp(){
        game = new anagrams();
    }

    @Test
    public void positiveTest(){
        String arr[] = new String[]{"dog", "god", "dad", "add", "dod"};
        ArrayList<String> result = game.getAnagrams(arr);

        String res[] = new String[]{"add", "dad", "god", "dog"};
        ArrayList<String> expected = new ArrayList<String>(Arrays.asList(res));

        Assert.assertTrue(expected.containsAll(result));
        Assert.assertTrue(result.containsAll(expected));
    }

    @After
    public void settleDown(){
        game = null;
    }
}
