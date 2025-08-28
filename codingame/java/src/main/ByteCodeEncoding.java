package com.codingame;

/*
Calculate the byte pair encoding of an input string.
Byte pair encoding is a basic data compression algorithm.
Starting with an input string, we repeatedly replace the most common pair of consecutive bytes (characters) with a new, unused byte.
We will refer to these replacement bytes as non-terminal bytes (represented by upper-case letters) and bytes from the original input string as terminal bytes (represented by lower-case letters).
The algorithm terminates when no pair of consecutive bytes is repeated anywhere in the modified string. Since each iteration reduces the length of the string by at least 2, the algorithm will definitely terminate.
We will use the recursive version of the algorithm, in which replaced pairs can include non-terminal characters. (Note: this algorithm generates a context-free grammar: https://en.wikipedia.org/wiki/Context-free_grammar)

For a more detailed explanation, see https://en.wikipedia.org/wiki/Byte_pair_encoding
If, at an iteration step in the algorithm, there is more than one byte pair with highest frequency, we choose the first (leftmost) pair.
For the non-terminal characters, we start with Z and work our way backwards through the alphabet.
We need to keep track of the replacement "rules" (and their order) so that the original string can be reconstructed.

Example :
Input string: aaabdaaabac

Step 1:
a) the most common byte pair is aa (note: we only count (and replace) non-overlapping repetitions, so there are 2 occurrences of this byte pair)
b) first non-terminal character = Z => replace all instances of aa with Z
c) new rule: Z = aa
d) new string: ZabdZabac

Step 2:
a) the most common byte pair is Za (note: Za and ab both occur twice, so we choose the leftmost)
b) second non-terminal character = Y => replace all instances of Za with Y
c) new rule: Y = Za
d) new string: YbdYbac

Step 3:
a) the most common byte pair is Yb (2 occurrences)
b) third non-terminal character = X => replace all instances of Yb with X
c) new rule: X = Yb
d) new string: XdXac

There are now no repeated byte pairs, so the algorithm terminates.
The final output should be:
XdXac
Z = aa
Y = Za
X = Yb

Note that in general either of the characters on the right-hand side of a rule can be terminal or non-terminal, so this grammar is not regular or even linear.
 */

import java.util.*;

public class ByteCodeEncoding {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        // load input
        StringBuilder srcStrs = new StringBuilder();
        for (int i = 0; i < n; i++) {
            srcStrs.append(in.next());
        }
        String srcStr = srcStrs.toString(); // srcStr length is supposed to be n * m
        // process
        List<String> prodRules = new ArrayList<>();
        ByteCodeEncoding solution = new ByteCodeEncoding();
        String nonTerm = "";
        String resStr = srcStr;
        while(true)
        {
            String mostCommonStr = solution.findMostCommonPair(resStr);
            if (mostCommonStr.isEmpty())    break;
            nonTerm = solution.getNextNonTerminalChar(nonTerm);
            resStr = resStr.replace(mostCommonStr, nonTerm); // replace
            //System.out.println(String.format("%s replaced by %s, become %s", mostCommonStr, nonTerm, resStr));
            prodRules.add(String.format("%s = %s", nonTerm, mostCommonStr));
        }
        // output
        System.out.println(resStr);
        System.out.println(String.join("\n", prodRules));
    }

    /**
     * sliding window in size of 2 chars
     */
    public String findMostCommonPair(String src) {
        if (src.length() < 2)   return "";
        String prevBytePair = "";
        boolean skipOverlapDupli = false; // used to avoid consecutive overlapping pair while accepting non-overlapping duplicate pair
        // LinkedHashMap to define the iteration ordering in which the keys were inserted
        Map<String, Integer> allWinBytes = new LinkedHashMap<>();
        for (int i = 0; i < src.length() - 1; i++) {
            String bytePair = src.substring(i, i+2);
            if (!bytePair.equals(prevBytePair) || skipOverlapDupli) {
                if (!allWinBytes.containsKey(bytePair)) {
                    allWinBytes.put(bytePair, 1);
                } else {
                    allWinBytes.replace(bytePair, allWinBytes.get(bytePair) + 1);
                }
                skipOverlapDupli = false;
            } else {
                skipOverlapDupli = true;
            }
            prevBytePair = bytePair;
        }
        return allWinBytes.entrySet()
                .stream()
                .filter(e -> e.getValue() > 1) // > 1 means most common bytes exists
                .max(Map.Entry.comparingByValue()) // static comparingByValue()
                .map(Map.Entry::getKey)// non-static getKey()
                .orElse("");
    }

    public String getNextNonTerminalChar(String currNonTerm)
    {
        return currNonTerm.isEmpty() ? "Z" :
                Character.toString((char)(currNonTerm.charAt(0) - 1));
    }
}
