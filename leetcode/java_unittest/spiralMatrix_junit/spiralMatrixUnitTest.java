/*
 * ArrayList<Integer> spiralMatrix.spiralOrder(int[][])
 *
 * int[][] generateMatrix(int n, int m)
 * */

import java.util.ArrayList;
import java.util.List;
import org.junit.*;
import org.junit.Assert;

public class spiralMatrixUnitTest{
    private spiralMatrix game;

    @Before
    public void setUp(){
        game = new spiralMatrix();
    }

    @Test
    public void spiralOrderTest_01(){
        int matrix[][] = new int[][]{
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };

        int arr[] = new int[]{1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10};
        ArrayList<Integer> expected = new ArrayList<Integer>();
        for(int i : arr){
            expected.add(i);
        }

        ArrayList<Integer> result = game.spiralOrder(matrix);
        assertList(expected, result);
    }

	@Test
    public void generateMatrixTest_01(){
        int rows = 4, cols = 5;
        int expected[][] = new int[][]{
            {1, 2, 3, 4, 5},
            {14,15,16,17,6},
            {13,20,19,18,7},
            {12,11,10,9, 8}
        };

        int[][] result = game.generateMatrix(rows, cols);
        assertArrArr(expected, result);
    }

    @After
    public void settleDown(){
        game = null;
    }

    /*
     * helper assert methods
     * */
    private void assertList(List<Integer> expected, List<Integer> result){
        Assert.assertEquals(expected.size(), result.size());
        final int n = expected.size();
        for(int i = 0; i < n; i++){
            Assert.assertEquals(expected.get(i), result.get(i));
        }
    }

    private void assertArrArr(int[][] expected, int[][] result){
        Assert.assertEquals(expected.length, result.length);
        final int n = expected.length;
        Assert.assertEquals(expected[0].length, result[0].length);
        final int m = expected[0].length;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                Assert.assertEquals(expected[i][j], result[i][j]);
            }
        }
    }
}
