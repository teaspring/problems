/*
 * ArrayList<String> generateParentheses.generate(int)
 * */

import java.util.ArrayList;
import java.util.List;
import org.junit.*;
import org.junit.Assert;

public class generateParenthesesUnitTest{
    private generateParentheses game;

    @Before
    public void setUp(){
        game = new generateParentheses();
    }

    @Test
    public void positiveTest_01(){
        int n = 3;
        String arr[] = new String[]{"((()))", "(()())", "()(())", "()()()", "(())()"};
        ArrayList<String> expected = fillStringList(arr);
        ArrayList<String> result = game.generate(n);

        Assert.assertTrue(assertListString(expected, result));
    }

    @After
    public void settleDown(){
        game = null;
    }

    private ArrayList<String> fillStringList(String[] arr){
        ArrayList<String> result = new ArrayList<String>();
        for(String s : arr){
            result.add(s);
        }
        return result;
    }

    private boolean assertListString(List<String> expected, List<String> result){
        Assert.assertEquals(expected.size(), result.size());

        for(String s : expected){
            Assert.assertTrue(result.contains(s));
        }

        for(String s : result){
            Assert.assertTrue(expected.contains(s));
        }

        return true;
    }
}
