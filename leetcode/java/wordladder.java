/*
 * oj.leetcode,given two words(start and end) and a dictionary, such that
 * 1.only one letter can be changed once
 * 2.each intermediate word must exist in the dictionary
 * 
 * WordLadder I,  find length of shortest transformation sequence from start to end
 * case:
 * start="dog", end="dig", dict={}
 * transformation: "dog" -> "dig"
 * return: 2
 *
 * WordLadder II, find all shortest transformation sequence(s) from start to end
 * case:
 * start="hit", end="cog", dict={hot,dot,dog,lot,log,hat,bit,big,dit,dig,cat,hak,cak,cok,dok}
 * return:
 * [hit,hot,dot,dog,cog]
 * [hit,hot,lot,log,cog]
 * [hit,dit,dig,dog,cog]
 * [hit,dit,dot,dog,cog]
 * */

import java.lang.*;
import java.io.*;
import java.util.*;

public class wordladder{

    /*
     * tips:
     * 1. char[] is faster than String manipulation
     * 2. JavaDoc says ArrayDeque faster than LinkedList in most cases
     * */
    public int ladderLength(String start, String end, HashSet<String> dict){
        if(start.equals(end))         return 1;

        Queue<String> q = new ArrayDeque<String>(); // FIFO, store intermediate words and start + end
        q.add(start);
        Set<String> visited = new HashSet<String>();
        Queue<Integer> steps = new LinkedList<Integer>(); // FIFO, steps[i] is the transform steps of q[i]
        steps.add(1);
        final int n = start.length();

        while(!q.isEmpty()){
            String word = q.poll();
            visited.add(word);
            int stp = steps.poll();
            char[] wordChar = word.toCharArray();   // char Array is faster than String
            for(int i=0; i < n; ++i){  // change one char once
                char saved = wordChar[i];
                for(char c = 'a'; c <= 'z'; ++c){
                    if(c == saved)    continue;
                    wordChar[i] = c;
                    String str = new String(wordChar);
                    if(str.equals(end))    return stp + 1;
                    if(dict.contains(str)
                    && !visited.contains(str)  /* every words polled from q */
                    && !q.contains(str)){  /* words in q right now */
                        q.add(str);
                        steps.add(stp + 1);
                    }
                }
                wordChar[i] = saved;
            }
        }
        return 0;
    }

    /*
     * BFS, accepted by oj.leetcode on time and memory limit
     * */
    public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict){
        Queue<String> q   = new LinkedList<String>();    // for BFS
        q.offer(start);

        Set<String> unVisited = new HashSet<String>(dict); // all optional intermediate words
        unVisited.add(end);  // ensure end in unVisited
        unVisited.remove(start);

        // [values] are all optional ladders transform to [key] with one char change
        HashMap<String, Queue<String>> adjMap = new HashMap<String, Queue<String>>();
        for(String word : unVisited){
            adjMap.put(word, new LinkedList<String>());
        }

        Set<String> visitedThisLev = new HashSet<String>();

        int currLev = 1;  // ladders count at current level(depth)
        int nextLev = 0;  // ladders count of next level(depth)
        int depth = 1;  // depth of transformation, equals to ladder length as well
        boolean found = false;

        while(!q.isEmpty()){  // BFS
            String currLadder = q.poll();
            ArrayList<String> nextLadders = getNextLadder(currLadder, unVisited);
            for(String nextLadder : nextLadders){ // next valid ladder(in unVisited) with one char change from currLadder
                if(visitedThisLev.add(nextLadder)){
                    nextLev++;
                    q.offer(nextLadder);
                }

                adjMap.get(nextLadder).offer(currLadder);  // save in map: nextLadder --> currLadder

                if(nextLadder.equals(end) && !found)    found = true;
            }

            if(--currLev == 0){ // ladders of current level have been processed already
                depth++;

                if(found)    break; // break only if all ladders at current level have been processed already

                unVisited.removeAll(visitedThisLev); // later ladders not include this level ladders
                visitedThisLev.clear();
                currLev = nextLev;
                nextLev = 0;
            }
        }

        ArrayList<ArrayList<String>> r = new ArrayList<ArrayList<String>>();  // results
        if(found){
            Stack<String> stk = new Stack<String>();
            stk.push(end);  // end is seed of DFS, backtrack to start
            getLadders(start, end, stk, r, adjMap, depth - 1);
        }
        return r;
    }

    /*
     * return all unvisited words with one char change with currLadder
     * */
    private ArrayList<String> getNextLadder(String currLadder, Set<String> unVisited){
        ArrayList<String> nextLadders = new ArrayList<String>();
        char[] wordChar = currLadder.toCharArray();
        final int n = wordChar.length;

        for(int i = 0; i < n; i++){
            char saved = wordChar[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(ch == saved)    continue;

                wordChar[i] = ch;

                String str = new String(wordChar);
                if(unVisited.contains(str))    nextLadders.add(str);
            }

            wordChar[i] = saved;
        }

        return nextLadders;
    }

    /*
     * DFS to get all path from @currLadder to @start in length of @len
     * @params adjMap: transfromation map of intermediate ladders
     * */
    private void getLadders(String start, String curr, Stack<String> stk,
            ArrayList<ArrayList<String>> result, HashMap<String, Queue<String>> adjMap, int len){
        if(len == 0 && curr.equals(start)){
            ArrayList<String> path = new ArrayList<String>(stk);
            Collections.reverse(path); // to put [start] at head
            result.add(path);
        }else if(len > 0){
            Queue<String> adjs = adjMap.get(curr); // [values] are all laddders which can transform to [key] in one char change
            for(String lad : adjs){
                stk.push(lad);
                getLadders(start, lad, stk, result, adjMap, len - 1);
                stk.pop();
            }
        }
    }
}

/* unit test code is in ../java_unittest/wordladder_junit */
