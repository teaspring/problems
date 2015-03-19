/*
 * wordbreakI:
 * boolean wordbreak.canBreak(String s, Set<String>)
 *
 * wordbreakII:
 * ArrayList<String> wordbreak.wordbreakall(String s, Set<String> dict)
 *
 * */

import java.util.List;
import java.util.Collection;
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
        fillCollection(arr_succ, dict_succ);

        Assert.assertTrue(game.canBreak(S, dict_succ));
    }

    @Test
    public void wordbreakI_negativeTest_1(){
        String S = new String("leetcode");

        String[] arr_fail = new String[]{"lee", "tco", "d", "oe", "cod", "leet"};
        Set<String> dict_fail = new HashSet<String>();
        fillCollection(arr_fail, dict_fail);

        Assert.assertFalse(game.canBreak(S, dict_fail));
    }

    @Test
    public void wordbreakI_zeroTest(){
        String S = new String();
        Set<String> dict = new HashSet<String>();
        dict.add("o");
        Assert.assertTrue(game.canBreak(S, dict));
    }

    @Test
    public void wordbreakII_positiveTest_01(){
        String s = new String("catsanddog");
        String[] arr = new String[]{"cat", "cats", "and", "sand", "dog"};
        Set<String> dict = new HashSet<String>();
        fillCollection(arr, dict);
        List<String> result = game.wordbreakall(s, dict);

        String[] expectedArr = new String[]{"cats and dog", "cat sand dog"};
        List<String> expected = new ArrayList<String>();
        fillCollection(expectedArr, expected);
        assertListExt(expected, result);
    }

    @Test
    public void wordbreakII_edgeTest_01(){
        String s = new String("aaaaab");
        String[] arr = new String[]{"b", "a", "aa", "aaa", "aaaa", "aaaaa"};
        Set<String> dict = new HashSet<String>();
        fillCollection(arr, dict);
        List<String> result = game.wordbreakall(s, dict);

        String[] expectedArr = new String[]{"a a a a a b",
                                            "a a a aa b",
                                            "a a aa a b",
                                            "a aa a a b",
                                            "aa a a a b",
                                            "a a aaa b",
                                            "a aaa a b",
                                            "aaa a a b",
                                            "a aaaa b",
                                            "aaaa a b",
                                            "a aa aa b",
                                            "aa a aa b",
                                            "aa aa a b",
                                            "aaa aa b",
                                            "aa aaa b",
                                            "aaaaa b"};
        List<String> expected = new ArrayList<String>();
        fillCollection(expectedArr, expected);
        assertListExt(expected, result);
    }

    private void fillCollection(String[] arr, Collection<String> coll){
        coll.clear();
        for(String str : arr){
            coll.add(str);
        }
        return;
    }
    /*
     * to assert two List<String> objects equals or not
     * */
    private boolean assertListExt(List<String> expected, List<String> result){
        Assert.assertEquals(expected.size(), result.size());
        Assert.assertTrue(expected.containsAll(result));
        Assert.assertTrue(result.containsAll(expected));
        return true;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
