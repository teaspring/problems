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
    public void positiveTest_01(){
        String arr[] = new String[]{"dog", "god", "dad", "add", "dod"};
        ArrayList<String> result = game.getAnagrams(arr);

        String res[] = new String[]{"add", "dad", "god", "dog"};
        ArrayList<String> expected = new ArrayList<String>(Arrays.asList(res));

        Assert.assertTrue(expected.containsAll(result));
        Assert.assertTrue(result.containsAll(expected));
    }

    @Test
    public void positiveTest_02(){
        String arr[] = new String[]{"about", "batuo", "outba", "bat", "auto", "tabo"};
        ArrayList<String> result = game.getAnagrams(arr);

        String res[] = new String[]{"batuo", "outba", "about"};
        ArrayList<String> expected = new ArrayList<String>(Arrays.asList(res));

        Assert.assertTrue(expected.containsAll(result));
        Assert.assertTrue(result.containsAll(expected));
    }

    @Test
    public void zeroTest(){
        String arr[] = new String[]{"ab", "b", "a", "ad", "bat"};
        ArrayList<String> result = game.getAnagrams(arr);

        Assert.assertTrue(result.isEmpty());
    }

    @After
    public void settleDown(){
        game = null;
    }
}
