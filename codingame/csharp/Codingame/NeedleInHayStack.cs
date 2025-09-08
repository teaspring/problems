/*
You are given a wall of characters, herein code-named the haystack, from which we want to find a needle, a sampling
sub-string containing specific wanted elements.

All lines from the haystack should be concatenated into a long string. The haystack contains at most 36 different kinds
of elements, represented by lower-case letters a-z and digits 0-9.

Wanted elements:
To define the wanted elements, we adopt a syntax commonly used by printers for defining pages, with modifications,like this:

[0-9] means [0 1 2 3 4 5 6 7 8 9] (all base-10 digits)
[a-e] means [a b c d e] (a sequence in alphabetical order)
[a-c,x-z,2,4,6,8] means [a b c x y z 2 4 6 8] (use hyphen and comma, without spaces)
[a-e,b] means [a b c d e] (in case of overlapping, deduplicate the result)

Wanted needle

The ordering of elements is unimportant in our case. For example, if the wanted elements are [2-5], the target is to find
a sub-string from the long haystack string such that the sub-string contains characters [2,3,4,5] in any order.
Duplicates of characters are fine. Mixing in unwanted elements is also fine. A sub-string "3xx15443yy2" is a good match
because all the four wanted digits are included. When the haystack is large enough, there can be many matches.
We want the shortest sub-string fulfilling the requirements. "5443yy2" is a better match than the above one because
it is shorter.

E.g.
"aaaaddaaabbbbbc"
"a-c"   => "8 14"
"c,a,b" => "8 14"
"d, b-c, a" => "5 14"
*/
using System.Collections.Generic;

namespace Codingame;

public class NeedleInHayStack
{
    public string FindNeedle(string hayStack, string needle)
    {
        var needleSet = makeCharSet(needle);
        //
        var min_win_size = hayStack.Length;
        var min_win_b = 0;
        int b = 0, e = 0;
        var mp = new Dictionary<char, int>();
        while (e < hayStack.Length)
        {
            // move e to widen the window
            while (e < hayStack.Length)
            {
                var c = hayStack[e];
                if (needleSet.Contains(c))
                {
                    if (!mp.ContainsKey(c)) mp[c] = 1;
                    else mp[c] += 1;
                }
                if (mp.Count == needleSet.Count) break;
                e += 1;
            }
            // move b to narrow the window
            while (mp.Count == needleSet.Count)
            {
                var c = hayStack[b];
                if (mp.ContainsKey(c))
                {
                    if (mp[c] == 1) break;
                    else mp[c] -= 1;
                }
                b += 1;
            }
            // update min window
            var win_size = e - b + 1;
            if (min_win_size > win_size)
            {
                min_win_size = win_size;
                min_win_b = b;
            }
            if (e >= hayStack.Length - 1) break;
            // move window
            mp.Remove(hayStack[b]); // hayStack[b] must be only one occurrance
            b += 1;
            e += 1;
        }
        return $"{min_win_b} {min_win_b + min_win_size - 1}"; // both are inclusive
    }

    private HashSet<char> makeCharSet(string needle)
    {
        var st = new HashSet<char>();
        var subs = needle.Split(',');
        foreach (var sub in subs)
        {
            var part = sub.Trim();
            if (part.Contains('-'))
            {
                var ends = part.Split('-'); // ends is string[]
                for (var i = 0; i <= (int)ends[1][0] - (int)ends[0][0]; i++)
                {
                    st.Add((char)(ends[0][0] + i));
                }
            }
            else
            {
                char.TryParse(part, out char c);
                st.Add(c);
            }
        }
        return st;
    }
}