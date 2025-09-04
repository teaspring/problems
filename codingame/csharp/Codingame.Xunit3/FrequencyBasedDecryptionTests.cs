using Xunit;

namespace Codingame.Xunit3;

public class FrequencyBasedFrequencyTests
{
    [Fact]
    public void Decrypt_Hello()
    {
        var fbd = new Codingame.FrequencyBasedDecryption();
        var msg = "Khoor Zruog ! Frqjudwxodwlrqv, brx kdyh vxffhvvixoob ghfubswhg ph ! Kdyh ixq zlwk wklv sxccoh";
        var expected = "Hello World ! Congratulations, you have successfully decrypted me ! Have fun with this puzzle";
        // assert
        var res = fbd.DecryptByLetterFreq(msg);
        Assert.Equal(expected, res);
    }

    [Fact]
    public void Decrypt_I_rub()
    {
        var fbd = new Codingame.FrequencyBasedDecryption();
        var msg = "Q zcjjml apwctlmza eqbp xmwxtm epw axwsm wn nzqmvlapqx, jcb epw lql vwb pidm bpm aium ditcma ia um ib itt. Bpwam epw uism gwc ticop epmv mdmzgbpqvo qa owqvo emtt, jcb epw eqtt vmdmz jm bpmzm epmv uqanwzbcvm lzweva gwc. - Vmsnmc";
        var expected = "I rubbed shoulders with people who spoke of friendship, but who did not have the same values as me at all. Those who make you laugh when everything is going well, but who will never be there when misfortune drowns you. - Nekfeu";
        // act and assert
        var res = fbd.DecryptByLetterFreq(msg);
        Assert.Equal(expected, res);
    }
}