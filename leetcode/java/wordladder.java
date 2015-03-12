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
 * [hit,hot,dot,dog,cog]
 * */

import java.lang.*;
import java.io.*;
import java.util.*;

public class wordladder{

    /*
     * tips:
     * 1. in frequent use, char[] is faster than String manipulation
     * 2. JavaDoc says ArrayDeque faster than LinkedList in most cases
     * */
    public int ladderLength(String start, String end, HashSet<String> dict){
        if(start.equals(end))         return 1;

        Queue<String> q = new ArrayDeque<String>(); // FIFO, store intermediate words and start + end
        q.add(start);
        Set<String> visited = new HashSet<String>();
        Queue<Integer> steps = new LinkedList<Integer>(); // FIFO, steps[i] is the transform steps of q[i]
        steps.add(1);
        final int N = start.length();

        while(!q.isEmpty()){
            String word = q.poll();
            visited.add(word);
            int stp = steps.poll();
            char[] wordChar = word.toCharArray();   // char Array is faster than String
            for(int i=0; i < N; ++i){  // change one char once
                char saved = wordChar[i];
                for(char c = 'a'; c <= 'z'; ++c){
                    if(c == saved)    continue;
                    wordChar[i] = c;
                    String str = new String(wordChar);
                    if(str.equals(end))    return stp + 1;
                    if(dict.contains(str)
                    && !visited.contains(str)  /* every word polled from q ever */
                    && !q.contains(str)){  /* word stored in q right now */
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
     * BFS, accepted by oj.leetcode
     * */
    public ArrayList<ArrayList<String>> findLadders_02(String start, String end, HashSet<String> dict){
        HashMap<String, Queue<String>> adjMap
            = new HashMap<String, Queue<String>>();  // conversion of word ladders
        int currLen = 0;
        boolean found = false;
        ArrayList<ArrayList<String>> r = new ArrayList<ArrayList<String>>();  // results
        Queue<String> queue   = new LinkedList<String>();    // for BFS
        Set<String> unVisited = new HashSet<String>(dict);   // all optional intermeida words
        unVisited.add(end);
        Set<String> visitedThisLev = new HashSet<String>();
        
        queue.offer(start);
        int currLev = 1;  // ladders count at current level
        int nextLev = 0;  // ladders count of next level
        for(String word : unVisited){
            adjMap.put(word, new LinkedList<String>());
        }
        unVisited.remove(start);  // <unVisited> saves all words converted from start

        while(!queue.isEmpty()){  // BFS
            String currLadder = queue.poll();
            for(String nextLadder : getNextLadder(currLadder, unVisited)){ // currLadder -> nextLadder
                if(visitedThisLev.add(nextLadder)){  // for this level
                    nextLev++;  // count of next level ladders
                    queue.offer(nextLadder);
                }
                adjMap.get(nextLadder).offer(currLadder);  // save in map: nextLadder --> currLadder
                if(nextLadder.equals(end) && !found){
                    found = true;
                    currLen += 2;
                }    
            }
            // System.out.println("currLen=" + currLen + " , nextLev=" + nextLev + ", currLadder=" + currLadder
            //        + ", unVisited=" + unVisited.toString() + ", visitedThisLev=" + visitedThisLev.toString());
            if(--currLev == 0){  // complete process of currLadder polled from queue
                if(found)    break;  // it breaks at first time when currLev reduced to 0 and found is true
                unVisited.removeAll(visitedThisLev); // next leverl ladders will not include this level ladders!!
                visitedThisLev.clear();
                currLev = nextLev;
                nextLev = 0;
                currLen++;  // this level of intermediate word ladders are processed already
            }
        }
        if(found){
            LinkedList<String> p = new LinkedList<String>();
            p.addFirst(end);  // from end to start
            getLadders(start, end, p, r, adjMap, currLen);
        }
        return r;
    }

    /*
     * utility: return all unvisited words which differ 1 with @currLadder
     * */
    private ArrayList<String> getNextLadder(String currLadder, Set<String> unVisited){
        ArrayList<String> nextLadder = new ArrayList<String>();
        StringBuffer replace = new StringBuffer(currLadder);
        for(int i=0; i < currLadder.length(); i++){
            char old = replace.charAt(i);
            for(char ch = 'a'; ch <= 'z';ch++){   // replace one char in [a-z] for once
                if(ch == old)    continue;  // one statement for 1/26 possibility :(
                replace.setCharAt(i, ch);
                String replaced = replace.toString();
                if(unVisited.contains(replaced)){  // if it is optional intermedia word
                    nextLadder.add(replaced);
                }
            }
            replace.setCharAt(i, old);
        }
        return nextLadder;
    }

    /*
     * utility: DFS to get all path from @currLadder to @start in length of @len
     * @params p: used as stack
     * @params adjMap: conversion of words
     * */
    private void getLadders(String start, String currLadder, LinkedList<String> p,
            ArrayList<ArrayList<String>> solu, HashMap<String, Queue<String>> adjMap, int len){
        if(currLadder.equals(start)){
            solu.add(new ArrayList<String>(p));
        }else if(len > 0){
            Queue<String> adjs = adjMap.get(currLadder);
            for(String lad : adjs){
                p.addFirst(lad);  // adjMap key is dst while value is <src>, so lad must be added in head
                getLadders(start, lad, p, solu, adjMap, len-1);
                p.pollFirst();
            }
        }
    }

    // utility for input
    private static HashSet<String> parseStrArray(String str){
        HashSet<String> st = new HashSet<String>();
        StringTokenizer t = new StringTokenizer(str, " ,");
        while(t.hasMoreTokens()){
            st.add(t.nextToken().toString().trim());
        }
        return st;
    }

    /* unit test code is in ../java_unittest/wordladder_junit */
    /*
    public void test(){
        Scanner scan = new Scanner(System.in);
        while(true){            
            System.out.println("input start string:");
            String start = scan.nextLine().trim();
            if(start.isEmpty())       break;
            
            System.out.println("input end string:");
            String end = scan.nextLine().trim();
            if(end.isEmpty())         break;
            
            System.out.println("input dictionary strings:");
            String dictStr = scan.nextLine();
            if(dictStr.isEmpty())     break;
            HashSet<String> dict = parseStrArray(dictStr);
            
            int steps = ladderLength_02(start, end, dict);    // WordLadder_I
            System.out.println("the shortest ladder is " + steps);
            
            ArrayList<ArrayList<String>> result = findLadders_02(start, end, dict);    // WordLadder_II
            for(int i=0; i<result.size(); ++i){
                System.out.println(result.get(i).toString());
            }
        }
        return;
    }
    */
}
