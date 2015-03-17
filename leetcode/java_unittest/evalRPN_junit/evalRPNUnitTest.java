/*
 * int evalRPN.eval(String[])
 * */

import java.util.ArrayList;
import java.util.Arrays;
import java.lang.IllegalArgumentException;
import java.util.EmptyStackException;
import org.junit.*;
import org.junit.Assert;
import org.junit.rules.ExpectedException;

public class evalRPNUnitTest{
    private evalRPN game;

    @Rule
    public ExpectedException thrown = ExpectedException.none();

    @Before
    public void setUp(){
        game = new evalRPN();
    }

    @Test
    public void positiveTest_01(){
        String[] tokens = new String[]{"2", "1", "+", "", "3", "5", "*", "-"};
        final int expected = (2 + 1) - (3 * 5);
        Assert.assertEquals(expected, game.eval(tokens));
    }

    @Test
    public void positiveTest_02(){
        String[] tokens = new String[]{"2", "13", "5", "2", "/", "8", "-", "+", "*"};
        final int expected = 2 * (13 + ((5 / 2) - 8));
        Assert.assertEquals(expected, game.eval(tokens));
    }

    @Test
    public void singleTest(){
        String[] tokens = new String[]{"2", ""};
        Assert.assertEquals(2, game.eval(tokens));
    }

    @Test
    public void ExceptionTest_EmptyStack(){
        String[] tokens = new String[]{"2", "13", "-", "*"};
        thrown.expect(EmptyStackException.class);
        game.eval(tokens);
    }

    @Test
    public void ExceptionTest_IllegalArgument(){
        String[] tokens = new String[]{"", "", ""};
        thrown.expect(IllegalArgumentException.class);
        game.eval(tokens);
    }

    @After
    public void settleDown(){
        game = null;
    }
}
