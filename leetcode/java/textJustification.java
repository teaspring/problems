/*
 * textJustification.h
 * principles:
 * 1. pack as many words in a line as you can, pad extra spaces ' ' between words if necessary
 * 2. extra spaces between words should be evenly. if the number of spaces do not divide evenly, put more spaces on left slots than right
 * 3. the last line should be left justified and no extra spaces between words
 * 4. if a line other than the last line contains only one word, left justified
 *
 * test case:
 * words: ["this", "is", "an", "example", "of", "text", "justification."]
 * L: 16
 * return:
 * "this    is    an",
 * "example  of text",
 * "justification.  "
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.lang.StringBuilder;

public class textJustification{

    public List<String> fullJustify(String[] words, int L){
        List<String> res = new ArrayList<String>();
        int i = 0, n = words.length;
        while(i < n){ // i is next available word index in words[]
            int solidL = words[i].length();
            int gap = 1, cw = 1; // interval is normal spaces between words; cw is word counts in this line

            while(i + cw < n){  // (i + cw) equals to counts of covered words, and next available word index both
                int delta = gap + words[i + cw].length();
                if(solidL + delta > L)    break;
                solidL += delta;
                ++cw;
            }

            // construct the interval spaces array
            int[] intervals = new int[cw];
            int rest = L - solidL;
            if(cw == 1){
                intervals[cw - 1] = rest;
            }else{
                int evenSpace = gap + rest / (cw - 1);
                intervals[0]  = evenSpace + rest % (cw - 1);
                for(int j = 1; j < cw - 1; j++){
                    intervals[j] = evenSpace;
                }
                intervals[cw - 1] = 0;
            }

            res.add(fillLine(words, L, i, cw, intervals));
            i += cw;
        }
        return res;
    }

    /*
    * @param start:  head word index in this line
    * @param count:  words count in this line
    * @param benefit:
    * @param interval:
    * * */
    private String fillLine(String[] words, int L, int start, int count, int[] spaces){
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < count; ++i){
            builder.append(words[start + i]);

            int x = spaces[i];
            while(x-- > 0){
                builder.append(" ");
            }
        }
        return builder.toString();
    }

	/* unit test case is in ../java_unittest/textJustification_junit/ */
}
