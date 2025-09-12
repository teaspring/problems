import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.Assertions;

class SudokuSolverTest {
    private SudokuSolver game;

    @BeforeEach
    public void setUp(){
        game = new SudokuSolver();
    }

    @Test
    @DisplayName("solveSudoku() easy case")
    void solveSudoku_simple() {
        // arrange
        String[] boardArray = {
            "120070560",
            "507932080",
            "000001000",
            "010240050",
            "308000402",
            "070085010",
            "000700000",
            "080423701",
            "034010028"
        };
        List<String> board = Arrays.asList(boardArray);
        // act
        boolean valid = game.solveSudoku(board);
        Assertions.assertTrue(valid);
        // assert
        String[] expectedArray = {
            "123874569",
            "567932184",
            "849651237",
            "916247853",
            "358196472",
            "472385916",
            "291768345",
            "685423791",
            "734519628"
        };
        Assertions.assertArrayEquals(expectedArray, board.toArray());
    }

    @Test
    @DisplayName("solveSudoku() hard case")
    void solveSudoku_hard() {
        // arrange
        String[] boardArray = {
            "800000000",
            "003600000",
            "070090200",
            "050007000",
            "000045700",
            "000100030",
            "001000068",
            "008500010",
            "090000400"
        };
        List<String> board = Arrays.asList(boardArray);
        // act
        boolean valid = game.solveSudoku(board);
        Assertions.assertTrue(valid);
        // assert
        String[] expectedArray = {
            "812753649",
            "943682175",
            "675491283",
            "154237896",
            "369845721",
            "287169534",
            "521974368",
            "438526917",
            "796318452"
        };
        Assertions.assertArrayEquals(expectedArray, board.toArray());
    }
}