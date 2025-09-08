using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace Codingame;
public class OrganicCompounds
{
    public bool CheckCompoundsValid(string[] compLines)
    {
        // search all the "CHn"
        string carbonPat = @"(CH[0-4])";
        for (var i = 0; i < compLines.Count(); i++)
        {
            var line = compLines.ElementAt(i);
            foreach (Match match in Regex.Matches(line, carbonPat, RegexOptions.IgnorePatternWhitespace))
            {
                var carbon = match.Value;
                var beginPos = match.Index;
                if (!CheckCarbonArounds(compLines, carbon, i, beginPos))
                    return false;
            }
        }
        return true;
    }

    private bool CheckCarbonArounds(string[] allLines, string carbon, int carbonRow, int carbonBeginPos)
    {
        // parse char of '3' to integer 3
        var carbonRides = 0;
        Int32.TryParse(carbon.ElementAt(2).ToString(), out carbonRides); // n of 'CHn'

        long upBoundM = 0, rightBoundM = 0, downBoundM = 0, leftBoundM = 0;
        var currLine = allLines[carbonRow];
        // up bound
        if (carbonRow > 0 && allLines[carbonRow - 1].Length >= carbonBeginPos + 3)
        {
            var upLine = allLines[carbonRow - 1];
            upBoundM = GetBoundNum(upLine.Substring(carbonBeginPos, 3));
        }
        // right bound
        if (allLines[carbonRow].Length >= carbonBeginPos + 6)
        {
            rightBoundM = GetBoundNum(currLine.Substring(carbonBeginPos + 3, 3));
        }
        // down bound
        if (carbonRow < allLines.Count() - 1 && allLines[carbonRow + 1].Length >= carbonBeginPos + 3)
        {
            var downLine = allLines[carbonRow + 1];
            downBoundM = GetBoundNum(downLine.Substring(carbonBeginPos, 3));
        }
        // left bound
        if (carbonBeginPos - 3 >= 0)
        {
            leftBoundM = GetBoundNum(currLine.Substring(carbonBeginPos - 3, 3));
        }
        // sum up all the bounds around the carbon
        //Console.WriteLine($"{carbonRides}, {upBoundM}, {rightBoundM}, {leftBoundM}");
        return carbonRides + upBoundM + rightBoundM + downBoundM + leftBoundM == 4;
    }

    // get m of "(m)"
    static long GetBoundNum(string bound)
    { 
        if (bound.Length != 3)  return 0;
        //return bound.ElementAt(1) - '0'; // vulnerable trick to parse char '\d' to integer, cuz no way to ensure that char represents an int!
        int.TryParse(bound.ElementAt(1).ToString(), out int m);
        return m;
    }
}