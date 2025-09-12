using System;

namespace Codingame.Xunit3;

public class SudokuSolverTests
{
    [Fact]
    public void SolveSudoku_Simple()
    {
        // arrange
        string[] board = [
            "120070560",
            "507932080",
            "000001000",
            "010240050",
            "308000402",
            "070085010",
            "000700000",
            "080423701",
            "034010028"
        ];
        var ss = new SudokuSolver();
        var res = ss.SolveSudoku(board);
        // assert
        Assert.True(res);
        string[] expected = [
            "123874569",
            "567932184",
            "849651237",
            "916247853",
            "358196472",
            "472385916",
            "291768345",
            "685423791",
            "734519628"
        ];
        for (var i = 0; i < 9; i++)
        {
            Assert.Equal(expected[i], board[i]);
        }
    }

    [Fact]
    public void SolveSudoku_Hard()
    {
        // arrange
        string[] board = [
            "800000000",
            "003600000",
            "070090200",
            "050007000",
            "000045700",
            "000100030",
            "001000068",
            "008500010",
            "090000400"
        ];
        var ss = new SudokuSolver();
        var res = ss.SolveSudoku(board);
        // assert
        Assert.True(res);
        string[] expected = [
            "812753649",
            "943682175",
            "675491283",
            "154237896",
            "369845721",
            "287169534",
            "521974368",
            "438526917",
            "796318452"
        ];
        for (var i = 0; i < 9; i++)
        {
            Assert.Equal(expected[i], board[i]);
        }
    }
}