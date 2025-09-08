import java.util.HashMap;
import java.util.HashSet;

public class NeedleInHayStack {

    public String findNeedleInHayStack(String hayStack, String needle) {
        HashSet<Character> st = makeSetOfChar(needle);
        HashMap<Character, Integer> mp = new HashMap<>();
        int minWinSize = hayStack.length(), minWinBegin = 0;
        int begin = 0, end = 0;
        while (end < hayStack.length()) {
            // move end to widen the window
            while (end < hayStack.length()) {
                char ch = hayStack.charAt(end);
                if (st.contains(ch)) {
                    if (mp.containsKey(ch)) {
                        int currCnt = mp.get(ch);
                        mp.put(ch, currCnt + 1);
                    } else {
                        mp.put(ch, 1);
                    }
                }
                if (mp.size() == st.size()) break;
                end++;
            }
            // move begin to narrow the window
            while (mp.size() == st.size()) {
                char ch = hayStack.charAt(begin);
                if (mp.containsKey(ch)) {
                    int currCnt = mp.get(ch);
                    if (currCnt == 1)    break;
                    mp.put(ch, currCnt - 1);
                }
                begin++;
            }
            // update window
            int winSize = end - begin + 1;
            if (minWinSize > winSize) {
                minWinSize = winSize;
                minWinBegin = begin;
            }
            // move window
            if (end >= hayStack.length() - 1)   break;
            mp.remove(hayStack.charAt(begin));
            begin++;
            end++;
        }
        // result
        return String.format("%d %d", minWinBegin, minWinBegin + minWinSize - 1);
    }

    private HashSet<Character> makeSetOfChar(String needle) {
        HashSet<Character> res = new HashSet<>();
        final char hyphen = '-';
        String[] parts = needle.split(",");
        for (int i = 0; i < parts.length; i++) {
            String part = parts[i].trim();
            if (part.contains(String.valueOf(hyphen))) {
                int hyphenPos = part.indexOf(hyphen, 0);
                char begin = part.charAt(hyphenPos - 1);
                char end = part.charAt(hyphenPos + 1);
                for(char x = begin; x <= end; x++){
                    res.add(x);
                }
            } else {
                res.add(part.charAt(0));
            }
        }
        return res;
    }
}