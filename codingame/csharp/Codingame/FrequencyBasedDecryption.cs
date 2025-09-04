namespace Codingame;

public class FrequencyBasedDecryption
{
    private Dictionary<char, float> EngLetterFreq;

    public FrequencyBasedDecryption()
    {
        EngLetterFreq = new Dictionary<char, float>();
        EngLetterFreq.Add('B', 1.67f);
        EngLetterFreq.Add('C', 3.18f);
        EngLetterFreq.Add('D', 3.99f);
        EngLetterFreq.Add('E', 12.56f);
        EngLetterFreq.Add('F', 2.17f);
        EngLetterFreq.Add('G', 1.80f);
        EngLetterFreq.Add('H', 5.27f);
        EngLetterFreq.Add('I', 7.24f);
        EngLetterFreq.Add('J', 0.14f);
        EngLetterFreq.Add('K', 0.63f);
        EngLetterFreq.Add('L', 4.04f);
        EngLetterFreq.Add('M', 2.60f);
        EngLetterFreq.Add('N', 7.38f);
        EngLetterFreq.Add('O', 7.47f);
        EngLetterFreq.Add('P', 1.91f);
        EngLetterFreq.Add('Q', 0.09f);
        EngLetterFreq.Add('R', 6.42f);
        EngLetterFreq.Add('S', 6.59f);
        EngLetterFreq.Add('T', 9.15f);
        EngLetterFreq.Add('U', 2.79f);
        EngLetterFreq.Add('V', 1.00f);
        EngLetterFreq.Add('W', 1.89f);
        EngLetterFreq.Add('X', 0.21f);
        EngLetterFreq.Add('Y', 1.65f);
        EngLetterFreq.Add('Z', 0.07f);
    }

    private float GetLetterFreqWeight(char ch)
    {
        if (!char.IsAsciiLetter(ch)) return 0.0f;
        float res;
        if (EngLetterFreq.TryGetValue(char.ToUpper(ch), out res))
        {
            return res;
        }
        return 0.0f;
    }

    private char ShiftCharByN(char ch, int n, bool isLower)
    {
        if (!char.IsAsciiLetter(ch)) return ch;
        while (n < 0)
        {
            n += 26;
        }
        var res = Convert.ToChar('A' + (char.ToUpper(ch) - 'A' + n) % 26);
        return isLower ? char.ToLower(res) : res;
    }

    private int AnalyzeBestShift(string src)
    {
        var maxScore = 0.0f;
        var delta = -1;
        char[] srcCharArray = src.ToCharArray();
        for (var i = 0; i < 26; i++)
        {
            var score = srcCharArray
                        .Select(x => GetLetterFreqWeight(ShiftCharByN(x, -i, false)))
                        .Sum();
            if (score > maxScore)
            {
                maxScore = score;
                delta = i;
            }
        }
        return delta;
    }

    // entry point
    public string DecryptByLetterFreq(string src)
    {
        var d = AnalyzeBestShift(src);
        char[] srcCharArray = src.ToCharArray();
        return new string(
            srcCharArray.Select(x => ShiftCharByN(x, -d, char.IsLower(x)))
                        .ToArray()
        );
    }
}