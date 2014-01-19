/*
 * from oj.leetcode.
 * given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 * 1.only one letter can be chanegd at a time
 * 2.each intermediate word must exist in the dictionary
 *
 * test data:
 * start="hit", end="cog", dict=[hot,dot,dog,lot,log,hat,bit,big,dit,dig,cat,hak,cak,cok,dok]
 * return:
 * [hit,hot,dot,dog,cog]
 * [hit,hot,lot,log,cog]
 * [hit,dit,dig,dog,cog]
 * [hit,hot,dot,dog,cog]
 * */

import java.lang.*;
import java.io.*;
import java.util.*;

public class findladders{
    private final int X = 0xffff;
    /*
    * Dijkstra algorithm. basically it is correct.in case the dict the conversion is unavailable, and the "start" is long, this solution is
    * good. But if in case the "start" is not long while dict has too much redundent string, this is worse than _02. after all, it is not
    * worth to create a adjcent matrix of all string in dict
    * */
    public int ladderLength_01(String start, String end, HashSet<String> dict){
        if(start.equals(end)){
            return 1;
        }else if(canConvert(start, end)){
            return 2;
        }

        if(dict.isEmpty()){
            return 0;
        }
        if(dict.contains(start)){
            dict.remove(start);
        }
        if(dict.contains(end)){
            dict.remove(end);
        }
        ArrayList<String> strArr = new ArrayList<String>();
        strArr.add(start);
        for(String s : dict){
            strArr.add(s);
        }
        strArr.add(end);
        ArrayList<ArrayList<Integer>> adjMtx = getAdjMatrix(strArr);

        final int n = strArr.size();
        int[] dist = new int[n];
        for(int i=0;i<n;i++){
            dist[i] = X;
        }
        LinkedList<Integer> q = new LinkedList<Integer>();        //used as queue
        boolean[] cover = new boolean[n];
        for(boolean b : cover){
            b = false;
        }
        q.addFirst(0);
        dist[0] = 0;
        
        while(!q.isEmpty()){        //Dijkstra algorithm, shortest path from src vertex to dst
            int u = q.pollLast();
            cover[u] = true;
            for(int v=0;v<n;v++){
                if(v==u || adjMtx.get(u).get(v) != 1)        continue;
                if(dist[u] + 1 < dist[v]){
                    dist[v] = dist[u] + 1;
                }
                if(!q.contains(v) && cover[v] == false)    q.addFirst(v);
            }
        }
        if(dist[n-1]==X)    return 0;        //dict[n-1]+1 is the ladder length
        return dist[n-1]+1;
    }
    
    public ArrayList<ArrayList<String>> findall_01(String start, String end, HashSet<String> dict){
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();    
        if(start.equals(end) || canConvert(start, end)){
            ArrayList<String> arr = new ArrayList<String>();
            arr.add(start);
            arr.add(end);
            res.add(arr);
            return res;
        }
        if(dict.isEmpty()){
            return res;
        }
        if(dict.contains(start)){
            dict.remove(start);
        }
        if(dict.contains(end)){
            dict.remove(end);
        }
        ArrayList<String> strArr = new ArrayList<String>();
        strArr.add(start);
        for(String s : dict){
            strArr.add(s);
        }
        strArr.add(end);
        ArrayList<ArrayList<Integer>> adjMtx = getAdjMatrix(strArr);

        final int n = strArr.size();
        ArrayList<HashSet<Integer>> prevPos = new ArrayList<HashSet<Integer>>();
        for(int i=0;i<n;i++){
            prevPos.add(new HashSet<Integer>());
        }
        int[] dist = new int[n];
        for(int i=0;i<n;i++){
            dist[i] = X;
        }
        LinkedList<Integer> q = new LinkedList<Integer>();        //used as queue
        boolean[] cover = new boolean[n];
        for(boolean b : cover){
            b = false;
        }
        q.addFirst(0);
        dist[0] = 0;
        
        while(!q.isEmpty()){
            int u = q.pollLast();
            cover[u] = true;
            for(int v=0;v<n;v++){
                if(v==u || adjMtx.get(u).get(v) != 1)        continue;
                if(dist[u] + 1 < dist[v]){
                    dist[v] = dist[u] + 1;
                    prevPos.get(v).clear();
                    prevPos.get(v).add(u);
                }else if(dist[u] + 1 == dist[v] && !prevPos.get(v).contains(u)){
                    prevPos.get(v).add(u);
                }
                if(!q.contains(v) && cover[v] == false)    q.addFirst(v);
            }
        }
        if(dist[n-1]==X)    return res;        //dict[n-1]+1 is the ladder length
        
        LinkedList<Integer> stk = new LinkedList<Integer>();    //as stack
        replayPath(prevPos, strArr, n-1, stk, res);
        return res;
    }

    public ArrayList<ArrayList<Integer>> getAdjMatrix(ArrayList<String> strArr){    //assume src vertex is [0] and dest is [n-1]
        final int n = strArr.size();
        ArrayList<ArrayList<Integer>>    adjMtx = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<n;++i){
            adjMtx.add(new ArrayList<Integer>(n));
            for(int j=0;j<n;++j){
                if(i==j){
                    adjMtx.get(i).add(0);
                }else{
                    adjMtx.get(i).add(X);
                }
            }
        }
        for(int u=0;u<n;++u){
            for(int v=u+1;v<n;++v){
                if(canConvert(strArr.get(u), strArr.get(v))){
                    adjMtx.get(u).set(v,1);
                    adjMtx.get(v).set(u,1);
                }else{
                    adjMtx.get(u).set(v,X);
                    adjMtx.get(v).set(u,X);
                }
            }
        }
        return adjMtx;
    }

    public boolean canConvert(String s1, String s2){
        if(s1.length() != s2.length())    return false;
        int diff=0;
        for(int i=0;i < s1.length();++i){
            if(s1.charAt(i) != s2.charAt(i))
                diff++;
        }
        return diff==1;
    }

    public void replayPath(ArrayList<HashSet<Integer>> prevPos, ArrayList<String> strArr, int ind, 
            LinkedList<Integer> stk1, ArrayList<ArrayList<String>> res){
        if(ind==0){
            ArrayList<String> ladder = new ArrayList<String>();
            ladder.add(strArr.get(0));
            LinkedList<Integer> stk2 = new LinkedList<Integer>();
            while(!stk1.isEmpty()){
                int i = stk1.pop();
                stk2.push(i);
                ladder.add(strArr.get(i));
            }
            res.add(ladder);
            while(!stk2.isEmpty()){
                stk1.push(stk2.pop());
            }
            return;
        }else{
            stk1.push(ind);
            for(int i : prevPos.get(ind)){
                replayPath(prevPos, strArr, i, stk1, res);
            }
            stk1.pop();
        }
        return;
    }

    private static HashSet<String> parseStrArray(String str){
        HashSet<String> st = new HashSet<String>();
        StringTokenizer t = new StringTokenizer(str, " ,");
        while(t.hasMoreTokens()){
            String s = t.nextToken().toString();
            if(!st.contains(s)){
                st.add(s);
            }
        }
        return st;
    }

    /*
     * this solution considers every candicate which changes one char for once.
     * 1. in case the dict has too much redundent string, and the size of "start" is not large, this is more efficient than _01
     * 2. in frequent use, char[] is faster than String manipulation
     * 3. Java Doc suggests ArrayDeque is faster than LinkedList in most cases
     *
     * note: this is accepted on oj. but actually, the structure steps can be replaced by several variables... 
     * */
    public int ladderLength_02(String start, String end, HashSet<String> dict){
        if(start.equals(end))         return 1;
        if(canConvert(start, end))    return 2;
        if(dict.isEmpty())            return 0;

        Set<String> visited = new HashSet<String>();
        Queue<String> q = new ArrayDeque<String>();
        q.add(start);
        Queue<Integer> steps = new LinkedList<Integer>();
        steps.add(0);
        final int N = start.length();

        while(!q.isEmpty()){
            String word = q.poll();
            visited.add(word);
            int stp = steps.poll();
            char[] wordChar = word.toCharArray();        //it is faster than manipulation of String
            for(int i=0;i<N;++i){
                char saved = wordChar[i];
                for(char c='a';c <= 'z';++c){
                    int st = stp;
                    wordChar[i] = c;
                    String str = new String(wordChar);
                    if(str.equals(end))        return st+2;
                    if(dict.contains(str) && !visited.contains(str) && !q.contains(str)){
                        q.add(str);
                        st++;
                        steps.add(st);
                    }
                }
                wordChar[i] = saved;
            }
        }
        return 0;
    }

    /*
     * correct and accepted by oj.leetcode. 
     * BFS to get next ladder
     * */
    public ArrayList<ArrayList<String>> findLadders_02(String start, String end, HashSet<String> dict){
        HashMap<String, Queue<String>> adjMap = new HashMap<String, Queue<String>>();//contains all the adjacent words discovered in its prev
        int currLen=0;
        boolean found=false;
        ArrayList<ArrayList<String>> r = new ArrayList<ArrayList<String>>();//results
        Queue<String> queue = new LinkedList<String>();    //Queue for BFS
        Set<String> unVisited = new HashSet<String>(dict);    //unvisited words
        unVisited.add(end);
        Set<String> visitedThisLev = new HashSet<String>();
        
        queue.offer(start);
        int currLev=1; //ladders count at current level
        int nextLev=0; //ladders count of next level
        for(String word : unVisited){
            adjMap.put(word, new LinkedList<String>());
        }
        unVisited.remove(start);    //nobody tells whether start is in dict
        
        while(!queue.isEmpty()){//BFS, every time change one char of it among a-z 26 characters
            String currLadder = queue.poll();
            for(String nextLadder : getNextLadder(currLadder, unVisited)){
                if(visitedThisLev.add(nextLadder)){
                    nextLev++;    //every new nextLadder converted from currLadder contributes to nextLev
                    queue.offer(nextLadder);
                }
                adjMap.get(nextLadder).offer(currLadder);    //save in map: nextLadder-->currLadder 
                if(nextLadder.equals(end) && !found){
                    found=true;
                    currLen += 2;
                }    
            }
            System.out.println("currLen=" + currLev + " , nextLev=" + nextLev + ", currLadder=" + currLadder + ", unVisited=" + unVisited.toString() + ", visitedThisLev=" + visitedThisLev.toString());
            if(--currLev==0){
                if(found)    break;
                unVisited.removeAll(visitedThisLev);    //expand in BFS from start to further, so current visited word does not need later
                visitedThisLev.clear();
                currLev = nextLev;
                nextLev=0;
                currLen++;
            }
        }
        if(found){
            LinkedList<String> p = new LinkedList<String>();
            p.addFirst(end);    //from end to start
            getLadders(start, end, p, r, adjMap, currLen);
        }
        return r;
    }

    private ArrayList<String> getNextLadder(String currLadder, Set<String> unVisited){//
        ArrayList<String> nextLadder = new ArrayList<String>();
        StringBuffer replace = new StringBuffer(currLadder);
        for(int i=0;i<currLadder.length();i++){
            char old = replace.charAt(i);
            for(char ch='a'; ch<='z';ch++){
                if(ch==old)    continue;
                replace.setCharAt(i, ch);
                String replaced = replace.toString();
                if(unVisited.contains(replaced)){
                    nextLadder.add(replaced);
                }
            }
            replace.setCharAt(i, old);
        }
        return nextLadder;
    }

    //DFS to get all possible path from start to end
    //@params p: choose LinkedList<> to push/pop like stack, and initialize ArrayList<> like queue
    private void getLadders(String start, String currLadder, LinkedList<String> p, ArrayList<ArrayList<String>> solu,
            HashMap<String, Queue<String>> adjMap, int len){
        if(currLadder.equals(start)){
            solu.add(new ArrayList<String>(p));
        }else if(len>0){
            Queue<String> adjs = adjMap.get(currLadder);
            for(String lad : adjs){
                p.addFirst(lad);
                getLadders(start, lad, p, solu, adjMap, len-1);
                p.pollFirst();
            }
        }
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        findladders lad = new findladders();
        while(true){            
            System.out.println("input start string:");
            String start = scan.nextLine().trim();
            if(start.length()==0)        break;
            
            System.out.println("input end string:");
            String end = scan.nextLine().trim();
            if(end.length()==0)        break;
            
            System.out.println("input dictionary strings:");
            String dictStr = scan.nextLine();
            if(dictStr.length()==0)        break;
            HashSet<String> dict = parseStrArray(dictStr);
            
            int steps = lad.ladderLength_02(start, end, dict);
            System.out.println("the shortest ladder is " + steps);
            
            ArrayList<ArrayList<String>> result = lad.findLadders_02(start, end, dict);
            for(int i=0;i<result.size(); i++){
                System.out.println(result.get(i).toString());
            }
        }
    }
}

