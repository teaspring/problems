/*
 * n is in [1, 9], k is in [1, n!]
 * String kthPermutation.getPermutation(int n, int k)
 * */

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.*;
import org.junit.Assert;

public class kthPermutationUnitTest{
    private kthPermutation game;

    @Before
    public void setUp(){
        game = new kthPermutation();
    }

    @Test
    public void positiveTest_01(){
        int n = 3;
        String[] answers = new String[]{
            "123",
            "132",
            "213",
            "231",
            "312",
            "321"
        };

        for(int k = 1; k < 7; k++){
            String expected = answers[k-1];
            Assert.assertEquals(expected, game.getPermutation(n, k));
        }
    }

    @After
    public void settleDown(){
        game = null;
    }
}
