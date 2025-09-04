using Xunit;

namespace Codingame.Xunit3;

public class HackingRobberCityTests
{
    [Fact]
    public void DecryptSrcMsg_Simple()
    {
        // arrange
        string msg1 = "391813c092a2d5ac9acb705dfe41be3df08de67d1145cbcc3f";
        string msg2 = "03adeae2c8c2f2336c8a8d312733c2456e76e0b2d9068adc3f";
        string msg3 = "72d0954e354045f09461dc4c911d0b58ff8963efb12c34303f";
        // act
        var hrb = new Codingame.HackingRobberCity();
        var result = hrb.Process1(msg1, msg2, msg3);
        // assert
        string expected = "Hello bob ! How are you ?";
        Assert.IsType<string>(result);
        Assert.Equal(expected, result);
    }

    [Fact]
    public void DecryptSrcMsg_Medium()
    {
        // arrange
        string msg1 = "6cda2e033736a529f682473750fcf82813174997fa5ea8cf600327b77c024bde948a0713c235da2d2e8acc473c746521";
        string msg2 = "91eca2b11937389d047f1788c6e9b615a6d10e98501d70eaf8e0478bc567867c4b20584f21152379fa068af6ac4e6521";
        string msg3 = "b411e1924660edc48bdd27dab6732753d4aa2b768a25b750f687405d9912acdbffde307c804f9439a1e22fd2f14e6521";
        // act
        var hrb = new Codingame.HackingRobberCity();
        var result = hrb.Process1(msg1, msg2, msg3);
        // assert
        string expected = "I'm happy we finally found a way to communicate!";
        Assert.IsType<string>(result);
        Assert.Equal(expected, result);
    }
}