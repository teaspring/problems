/*
 * from oj.leetcode. Design and implement a data structure for Least Recently Used(LRU) cache. it supports get() and set():
 * 1. int get(key) - Get the value(always be positive) of the key if the key exists in the cache, otherwise return -1;
 * 2. void set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should
 * invalidate the least recently used item before inserting a new item.
 *
 * solution 1: self-defined double linked list(DLL), insert new node at tail. every get() move referred node to tail, so that the head
 * becomes "least recently used" node till now.
 * soltuion 2: use LinkedHashMap.
 *
 * */
import java.io.*;
import java.util.*;

public class LRUCache{
    node mHead;
    node mTail;
    int mCapacity;
    HashMap<Integer, node> mHMap;

    private class node{
        int Key;
        int Value;
        node prev;
        node next;
        public node(int k, int v){
            Key = k;
            Value = v;
            prev = null;
            next = null;
        }
    }

    public LRUCache(int capacity){    //capacity should not be 0
        mCapacity = capacity;
        mHead = null;
        mTail = null;
        mHMap = new HashMap<Integer, node>();
    }

    public int get(int key){
        if(!mHMap.containsKey(key)){
            return -1;
        }
        node curr = mHMap.get(key);
        node cNext = curr.next;
        node cPrev = curr.prev;
        if(cNext != null){    //move referred node to tail
            if(cPrev == null){
                mHead = cNext;
            }else{
                cPrev.next = cNext;
            }
            cNext.prev = cPrev;
            curr.next = null;
            mTail.next = curr;
            curr.prev = mTail;
            mTail = curr;
        }
        return curr.Value;
    }

    public void set(int key, int value){
        if(mHMap.containsKey(key)){
            get(key);    //put it to mTail of DLL
            mHMap.get(key).Value = value;
            return;
        }
        if(mHMap.size() >= mCapacity){
            node oldNode = mHead;
            if(oldNode.next != null){    //remove the mHead which is least recently used 
                mHead = oldNode.next;
                mHead.prev = null;
            }else{
                mHead = mTail = null;
            }
            oldNode.next = null;
            mHMap.remove(oldNode.Key);
        }

        node cNode = new node(key, value);
        if(mTail == null){
            mHead = mTail = cNode;
        }else{
            mTail.next = cNode;
            cNode.prev = mTail;
            mTail = cNode;
        }
        mHMap.put(key, cNode);
        return;
    }

    public void test(){
    
    }

    public static void main(String[] args){
        int capa = 10;
        LRUCache lru = new LRUCache(capa);
        lru.test();
    }
}
