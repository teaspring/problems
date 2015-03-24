/*
 * textJustification.fullJustify(String[] words, int L): List<String>
 * */

import java.util.ArrayList;
import java.util.List;
import org.junit.*;
import org.junit.Assert;

public class textJustificationUnitTest{
    private textJustification game;

    @Before
    public void setUp(){
        game = new textJustification();
    }

    @Test
    public void positiveTest_1(){
        String[] words = new String[]{"this", "is", "an", "example", "of", "text", "justification"};
        int L = 16;

        String[] expectedArr = new String[]{
            "this    is    an",
            "example  of text",
            "justification   "};
        List<String> expected = fillArrayList(expectedArr);

        assertStringList(expected, game.fullJustify(words, L));
    }

    @Test
    public void positiveTest_2(){
        String[] words = new String[]{"this", "would", "be", "justification"};
        int L = 14;

        String[] expectedArr = new String[]{
            "this  would be",
            "justification "};
        List<String> expected = fillArrayList(expectedArr);

        assertStringList(expected, game.fullJustify(words, L));
    }

    @Test
    public void positiveTest_3(){
        String[] words = new String[]{"to", "a", "few."};
        int L = 6;

        String[] expectedArr = new String[]{
            "to   a",
            "few.  "};
        List<String> expected = fillArrayList(expectedArr);

        assertStringList(expected, game.fullJustify(words, L));
    }

    @Test
    public void positiveTest_4(){
        String[] words = new String[]{"what", "must", "be", "shall", "be."};
        int L = 12;

        String[] expectedArr = new String[]{
            "what must be",
            "shall    be."};
        List<String> expected = fillArrayList(expectedArr);

        assertStringList(expected, game.fullJustify(words, L));
    }

    @Test
    public void positiveTest_5(){
        String[] words = new String[]{"Don't", "go", "around", "saying", "the", "world", "owes", "you", "a", "living"};
        int L = 30;

        String[] expectedArr = new String[]{
            "Don't  go  around  saying  the",
            "world     owes  you  a  living"};
        List<String> expected = fillArrayList(expectedArr);

        assertStringList(expected, game.fullJustify(words, L));
    }

    private ArrayList<String> fillArrayList(String[] arr){
        ArrayList<String> dst = new ArrayList<String>();
        for(String str : arr){
            dst.add(str);
        }
        return dst;
    }

    /*
     * to assert two ArrayList<ArrayList<String>> objects equals strictly in order
     * */
    private void assertStringList(List<String> expected, List<String> result){
        Assert.assertEquals(expected.size(), result.size());
        int n = expected.size();
        for(int i = 0; i < n; i++){
            Assert.assertEquals(expected.get(i), result.get(i));
        }
        return;
    }

    @After
    public void settleDown(){
        game = null;
    }
}
