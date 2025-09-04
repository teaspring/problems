import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class StockExLossTest {
    private StockExLoss game;

    @BeforeEach
    void setUp(){
        game = new StockExLoss();
    }

    @Test
    @DisplayName("maxLossAbs() short size")
    void maxLossAbs_simple(){
        // arrange
        List<Integer> prices = new ArrayList<>(
            Arrays.asList(3, 2, 4, 2, 1, 5)
        );
        // act & assert
        Assertions.assertEquals(-3, game.maxLossAbs(prices));
    }

    @Test
    @DisplayName("maxLossAbs() no loss")
    void maxLossAbs_noLoss(){
        // arrange
        List<Integer> prices = new ArrayList<>(
            Arrays.asList(3, 4, 7, 9, 10)
        );
        // act & assert
        Assertions.assertEquals(0, game.maxLossAbs(prices));
    }
}