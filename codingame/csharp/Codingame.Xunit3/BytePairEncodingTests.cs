using Xunit;

namespace Codingame.Xunit3;

public class BytePairEncodingTests
{
    [Fact]
    public void BytePairEncode_Simple()
    {
        var bpe = new Codingame.BytePairEncoding();
        var result = bpe.Process1("aaabdaaabac", out List<string> encodingRules);
        // assert
        Assert.Equal("XdXac", result);
        var expectedRules = new List<string> { "Z = aa", "Y = Za", "X = Yb" };
        Assert.Equal(expectedRules, encodingRules);
    }

    [Fact]
    public void BytePairEncode_Long()
    {
        var bpe = new Codingame.BytePairEncoding();
        // arrange
        string msg = "cdeaafdhhhcdecbfcbhfhdhhccfhedeadggchefhgcaffgdcagdfedaghgceafbdccegbfggafhdffbhahgadeabccabhfgeceff";
        var expectedRes = "cXYQhcZcbfcWVQUVeXdgTheVTYSdcPOedPhTeYbdUegbSgYhOfWahgaXbUaWSeceff";
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
        // act
        var result = bpe.Process1(msg, out List<string> encodingRules);
        // assert
        Assert.Equal(expectedRes, result);
        Assert.IsType<List<string>>(encodingRules);
        Assert.Equal(expectedRules, encodingRules);
    }
}
// $ dotnet run -v n[ormal]