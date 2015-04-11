/*
 * n is in [1, 9], k is in [1, n!]
 *
 * String kthPermutation.getPermutation_1(int n, int k) // correct but inefficient
 *
 * String kthPermutation.getPermutation_2(int n, int k) // efficient than solution1
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
    public void solution1_positiveTest_01(){
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
            Assert.assertEquals(expected, game.getPermutation_1(n, k));
        }
    }

    @Test
    public void solution2_positiveTest_01(){
        int n = 4;
        final int maxK = game.nFactorial(n);

        for(int k = 1; k < maxK ; k++){
            String expected = game.getPermutation_1(n, k);
            String result   = game.getPermutation_2(n, k);

            Assert.assertEquals(expected, result);
        }
    }

    @Test
    public void solution2_positiveTest_02(){
        int n = 7;
        final int maxK = game.nFactorial(n);

        for(int k = 1; k < maxK ; k++){
            String expected = game.getPermutation_1(n, k);
            String result   = game.getPermutation_2(n, k);

            Assert.assertEquals(expected, result);
        }
    }

    @After
    public void settleDown(){
        game = null;
    }
}
