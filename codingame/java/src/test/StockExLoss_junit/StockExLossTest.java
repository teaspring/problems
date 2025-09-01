import java.util.*;
import org.junit.*;
import org.junit.Assert;

public class StockExLossTest {
    private StockExLoss game;

    @Before
    public void setUp(){
        game = new StockExLoss();
    }

    @Test
    public void positiveTest_01(){
        List<Integer> prices = new ArrayList<>(
            Arrays.asList(3, 2, 4, 2, 1, 5)
        );
        Assert.assertEquals(-3, game.process1(prices));
    }

    @Test
    public void positiveTest_02(){
        List<Integer> prices = new ArrayList<>(
            Arrays.asList(3, 2, 10, 7, 15, 14)
        );
        Assert.assertEquals(-3, game.process1(prices));
    }
    @Test
    public void negativeTest_01(){
        List<Integer> prices = new ArrayList<>(
            Arrays.asList(3, 4, 7, 9, 10)
        );
        Assert.assertEquals(0, game.process1(prices));
    }
}

