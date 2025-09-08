using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;

namespace Codingame;
public class BytePairEncoding
{
    private string? GetMostCommonBytePair(string srcLine)
    {
        // OrderedDictionary can keep the insertion order of keys
        var myDict = new OrderedDictionary();
        var skippedDupli = false;
        string backBytePair = "";
        for (var i = 0; i < srcLine.Length - 1; i++)
        {
            var bytePair = srcLine.Substring(i, 2);
            if (!bytePair.Equals(backBytePair) || skippedDupli)
            {
                if (!myDict.Contains(bytePair))
                {
                    myDict.Add(bytePair, 1);
                }
                else
                {
                    myDict[bytePair] = Convert.ToInt32(myDict[bytePair]) + 1;
                }
                skippedDupli = false;
            }
            else
            {
                skippedDupli = true;
            }
            backBytePair = bytePair;
        }
        // query by LINQ
        var mostLeftBytePair =
            myDict.Cast<DictionaryEntry>()
                .Where(x => Convert.ToInt32(x.Value) > 1)  // filter
                .OrderByDescending(x => x.Value) // order by descending
                .Select(x => x.Key)
                .FirstOrDefault();
        myDict.Clear();
        return Convert.ToString(mostLeftBytePair);
    }
    private char NextNonTerm(char nonTerm)
    {
        return nonTerm == '\0' ? 'Z' : Convert.ToChar((int)nonTerm - 1);
    }

    // Entry point
    public string Process1(string srcStr, out List<string> encodingRules)
    {
        encodingRules = new List<string>(); // initialize out param
        string res = srcStr;
        char nonTerm = '\0';
        while (true)
        {
            var commBytePair = GetMostCommonBytePair(res);
            //Console.WriteLine($"str is {res}, commonBytePair is {commBytePair}");
            if (commBytePair == null || commBytePair.Length == 0) break;
            nonTerm = NextNonTerm(nonTerm);
            res = res.Replace(commBytePair, nonTerm.ToString());
            encodingRules.Add($"{nonTerm} = {commBytePair}");
        }
        return res;
    }
}
