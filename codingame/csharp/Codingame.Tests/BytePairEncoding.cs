using Xunit;
using Codingame;

namespace Codingame.Tests;

public class BytePairEncoding
{
    [Fact]
    public void Test1()
    {
        var bpe = new Codingame.BytePairEncoding();
        List<string> encodingRules;
        var result = bpe.Process1("aaabdaaabac", out encodingRules);
        // assert
        Assert.Equal("XdXac", result);
        var expectedRules = new List<string> { "Z = aa", "Y = Za", "X = Yb" };
        Assert.Equal(expectedRules, encodingRules);
    }

    [Fact]
    public void Test2()
    { 
        var bpe = new Codingame.BytePairEncoding();
        string msg = "cdeaafdhhhcdecbfcbhfhdhhccfhedeadggchefhgcaffgdcagdfedaghgceafbdccegbfggafhdffbhahgadeabccabhfgeceff";
        List<string> encodingRules;
        var result = bpe.Process1(msg, out encodingRules);
        // assert
        var expectedRes = "cXYQhcZcbfcWVQUVeXdgTheVTYSdcPOedPhTeYbdUegbSgYhOfWahgaXbUaWSeceff";
        Assert.Equal(expectedRes, result);
        var expectedRules = new List<string>
        {
            "Z = de",
            "Y = af",
            "X = Za",
            "W = bh",
            "V = fh",
            "U = cc",
            "T = gc",
            "S = fg",
            "R = dh",
            "Q = Rh",
            "P = ag",
            "O = df"
        };
        Assert.Equal(expectedRules, encodingRules);
    }
}