import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.math.*;

class OrganicCompounds {
    // entry
    public boolean checkCompoundsValid(List<String> compLines) {
        Pattern carbonPat = Pattern.compile("CH[0-4]");
        for (int i = 0; i < compLines.size(); i++) {
            Matcher carbonMat = carbonPat.matcher(compLines.get(i));
            while (carbonMat.find()) {
                int bondEnd = carbonMat.end();
                if (!checkCarbon(compLines, i, bondEnd-3)) {
                    return false;
                }
            }
        }
        return true;
    }

    // check carbon: whether all the bounds number around it sum up with carbon number equals to 4 
    private boolean checkCarbon(List<String> allLines, int rowIdx, int beginColumn) {
        String carbon = allLines.get(rowIdx).substring(beginColumn, beginColumn+3);
        int carbonRides = Integer.valueOf(
            carbon.substring(2,3)); // n of "CHn", valid range is [0, 4]
        if (carbonRides < 0 || carbonRides > 4) return false;

        int upBondM = 0, rightBondM = 0, downBondM = 0, leftBondM = 0;
        // up bond
        if (rowIdx > 0 && allLines.get(rowIdx-1).length() >= beginColumn+3) // up line should be long enough
            upBondM = getBondNum(allLines.get(rowIdx-1).substring(beginColumn, beginColumn+3));
        // right bond
        if (beginColumn + 6 <= allLines.get(rowIdx).length())
            rightBondM = getBondNum(allLines.get(rowIdx).substring(beginColumn+3, beginColumn+6));
        // down bound
        if (rowIdx < allLines.size() - 1 && allLines.get(rowIdx+1).length() >= beginColumn+3) // down line should be long enough 
            downBondM = getBondNum(allLines.get(rowIdx+1).substring(beginColumn, beginColumn+3));
        // left bound
        if (beginColumn - 3 >= 0)
            leftBondM = getBondNum(allLines.get(rowIdx).substring(beginColumn-3, beginColumn));
        // check carbon and all bonds round it
        return (carbonRides + upBondM + rightBondM + downBondM + leftBondM) == 4;
    }

    // return 0 in case of invalid bound
    public static int getBondNum(String bond) {
        if (bond.strip().length() != 3) return 0;
        if (!bond.startsWith("(") || !bond.endsWith(")")) return 0;
        int m = Integer.valueOf(bond.substring(1, 2)); // m of "(m)", valid range is (0, 4]
        return (m > 0 && m <= 4) ? m : 0;
    }
}