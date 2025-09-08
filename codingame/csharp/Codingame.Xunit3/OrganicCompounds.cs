using System;

namespace Codingame.Xunit3;

public class OrganicCompounds
{
    [Fact]
    public void CheckCompounds_Valid()
    {
        // arrange
        string[] compLines = [
            "CH2(1)CH2(1)CH1(1)CH2",
            "(1)         (1)   (1)",
            "CH2         CH2   CH2",
            "(1)         (1)   (1)",
            "CH2(1)CH2(1)CH1(1)CH2"
        ];
        // act & assert
        var oc = new Codingame.OrganicCompounds();
        Assert.True(oc.CheckCompoundsValid(compLines));
    }

    [Fact]
    public void CheckCompounds_Invalid()
    {
        // arrange
        string[] compLines = [
            "CH3(1)CH1(1)CH2(1)CH1(1)CH3",
            "(1)         (1)",
            "CH3         CH1(1)CH1(1)CH3",
            "            (1)",
            "            CH3"
        ];
        // act & assert
        var oc = new Codingame.OrganicCompounds();
        Assert.False(oc.CheckCompoundsValid(compLines));
    }
}