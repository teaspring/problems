/*
 * given an array of strings, return all groups of strings that are anagrams. e.g dog and god are anagrams
 * test case:
 * input:dog, god, cat, tac, abc
 * output: dog, god, cat, tac
 * */
import java.io.*;
import java.util.*;

public class anagrams{
    private String wordkey(String word){  // count sort
        int[] A = new int[26];
        int n = word.length();
        for(int i=0; i < n; i++){
            A[word.charAt(i) - 'a']++;
        }
        for(int i=1; i < 26; i++){
            A[i] += A[i-1];
        }
        char[] B = new char[n];
        for(int i=0; i < n; i++){
            int idxChar = word.charAt(i) - 'a';
            B[A[idxChar] - 1] = word.charAt(i);
            A[idxChar]--;
        }
        return new String(B);
    }

    public ArrayList<String> getAnagrams(String[] strs){
        ArrayList<String> res = new ArrayList<String>();
        int n = strs.length;
        if(n < 2)    return res;
        HashMap<String, List<Integer>> mmp
            = new HashMap<String, List<Integer>>();  //replacement of multimap<>
        for(int i=0; i < n; i++){
            String kstr = wordkey(strs[i]);
            if(!mmp.containsKey(kstr)){
                mmp.put(kstr, new ArrayList<Integer>());
            }
            mmp.get(kstr).add(i);
        }
        
        for(String k : mmp.keySet()){  // Set<KeyType> 
            if(mmp.get(k).size() < 2)    continue;
            for(Integer i : mmp.get(k)){
                res.add(strs[i]);
            }
        }
        return res;
    }

    /* unit test code is in ../java_unittest/anagrams_unittest/  */
    
    /*
    private void showList(List<String> lst){
        for(String s : lst){
            System.out.print(s + " ");
        }
        System.out.println();
    }

    public void test_01(){
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("please input String[]");
            String str = scan.nextLine().trim();
            if(str.isEmpty())    break;
            StringTokenizer t = new StringTokenizer(str, " ,");
            int n = t.countTokens();
            String[] strs = new String[n];
            for(int i=0;i<n;i++){
                strs[i] = t.nextToken();
            }
            ArrayList<String> res = anagrams(strs);
            showList(res);
        }
    }
    */
}
