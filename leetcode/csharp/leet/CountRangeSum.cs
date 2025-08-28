using System.Collections;
using System.Collections.Generic;

namespace leet;

/*
* Leetcode 327, hard level. 
* Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
* Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
*/

public delegate int CountRangeSum(int[] nums, int lower, int upper);

public class Solution01 {
    // DEPRECATED
    public int CountRangeSum_bulky(int[] nums, int lower, int upper) {
        var stepSums = getStepSums(nums);
        var allRangeSums = getSortedRangeSums(stepSums);
        int lowerIdx = binSearch(allRangeSums, lower, -1);
        int upperIdx = binSearch(allRangeSums, upper, 1);
        return upperIdx - lowerIdx;
    }

    public int CountRangeSum(int[] nums, int lower, int upper) {
        var stepSums = GetStepSumsGeneric(nums);
        var allRangeSums = GetSortedRangeSumsGeneric(stepSums);
        var sortedAllRangeSums = allRangeSums.OrderBy(x => x).ToList();
        int lowerIdx = binSearch(sortedAllRangeSums, lower, -1);
        int upperIdx = binSearch(sortedAllRangeSums, upper, 1);
        return upperIdx - lowerIdx;
    }

    // DEPRECATED
    // time complexity and memory complexity: both O(n^2)
    public List<long> getSortedRangeSums(List<long> stepSums) {
        var res = new List<long>();
        for(int i=0; i < stepSums.Count; i++) {
            insertRangeSum(res, stepSums[i]);
            for (int j=i+1; j < stepSums.Count; j++) {
                var rs = stepSums[j] - stepSums[i];
                insertRangeSum(res, rs);
            }
        }
        return res;
    }

    // NOTE: return IEumerable is unsorted !
    public IEnumerable<long> GetSortedRangeSumsGeneric(IEnumerable<long> stepSums)
    {
        var stepSumsList = stepSums.ToList();
        var idx = -1;
        var length = stepSumsList.Count;
        foreach(var step in stepSums)
        {
            idx++;
            yield return step;
            var newRangeSums = from s in stepSumsList.GetRange(idx+1, length - (idx+1))
                                select (s - step);
            foreach(var rs in newRangeSums)
            {
                yield return rs;
            }
        }
    }

    //public delegate void InsertElement(List<long> lst, long elem);
    public void insertRangeSum(List<long> res, long rs) {
        var idx = binSearch(res, rs, 0);
        if (idx >= res.Count || idx < 0) {
            res.Add(rs);
        } else {
            res.Insert(idx, rs);
        }
    }

    /*
    * DEPRECATED
    * return all step sums, count=n, res[i] equals to sum(src[0,,,i]))
    */
    public List<long> getStepSums(int[] src) {
        var res = new List<long>();
        long step = src[0];
        res.Add(step);
        for(int i=1; i < src.Length; i++) {
            step += src[i];
            res.Add(step);
        }
        return res;
    }

    public IEnumerable<long> GetStepSumsGeneric(int[] src)
    {
        long curr = 0; // this must be long!
        foreach(var elem in src)
        {
            curr += elem;
            yield return curr;
        }
    }

    /*
    * binary search, return the index where the @arg dust should be inserted
    * @arg brim: 0, no care of expand in case of equal values
    *            -1, brim to lower index
    *.           1, brim to higher index
    */
    public int binSearch(List<long> src, long dust, int brim) {
        int u = 0, v = src.Count; // u is inclusive, v is exclusive
        while (u < v) {
            int m = u + (v - u)/2;
            if (src[m] < dust) {
                u = m + 1; // enlarge m
            } else if (src[m] > dust){
                v = m; // reduce m
            } else {
                if (brim == -1) {
                    v = m; // reduce m
                } else if (brim == 1) {
                    u = m+1; // enlarge m
                } else {
                    return m;
                }
            }
        }
        return u;
    }
}

// merge sort, from https://leetcode.com/problems/count-of-range-sum/solutions/3792644/easy-to-understand-c-merge-solution/
public class Solution02 {
    int lower, upper;
    long[] preSum;
    long[] temp; // used to restore
    int count = 0;
    public int CountRangeSum(int[] nums, int lower, int upper) {
        this.lower = lower;
        this.upper = upper;
        preSum = new long[nums.Length + 1];
        temp = new long[nums.Length + 1];
        for(int i = 0; i < nums.Length; i++)
            preSum[i + 1] = preSum[i] + nums[i];
        Sort(preSum, 0, preSum.Length - 1);
        return count;
    }
    public void Sort(long[] nums, int left, int right){
        if(left >= right)
            return;
        int mid = left +(right - left) / 2;
        Sort(nums, left, mid);
        Sort(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }
    public void Merge(long[] nums, int left, int mid, int right){
        for(int i = left; i <= right; i++)
            temp[i] = nums[i];
        // collect the range num just before each merge sort via copy !!
        // continue to calculate any one of [mid+1, right] minus any one of [left, mid]
        int start = mid + 1;
        int end = mid + 1;
        // collect the range sum cross the two halves
        for(int i = left; i <= mid; i++){
            while(start <= right && nums[start] - nums[i] < lower) // (nums[start] - nums[i]) is one valid range sum
                start++;
            while(end <= right && nums[end] - nums[i] <= upper) // (nums[end] - nums[i]) is also one valid range sum
                end++;
            count += end - start; // [left, mid] and [mid+1, right] are sorted range sums respectively
        }
        // merge sort: copy elements from temp[left, mid] and temp[mid+1, right] to nums[left, right]
        int m = left;
        int n = mid + 1;
        for(int i = left; i <= right; i++){
            if(m == mid + 1) // temp[left, mid] is drained, copy from temp[mid+1, right]
                nums[i] = temp[n++];
            else if(n == right + 1) // temp[mid+1, right] is drained, copy from temp[left, mid]
                nums[i] = temp[m++];
            else if(temp[m] > temp[n]) // copy the smaller one
                nums[i] = temp[n++];
            else
                nums[i] = temp[m++];
        }
    }
}

// RB Tree, from https://leetcode.com/problems/count-of-range-sum/solutions/1613119/c-rb-tree/
public class Solution03 {
    public int CountRangeSum(int[] nums, int lower, int upper) {
        int count = 0; long sum = 0;
        var dic = new RBTreeSpecial(); dic.Add(0);
        for(var i = 0; i < nums.Length; i++) {
            sum+= nums[i];
            count += dic.GreaterThanCount(sum - upper - 1) - dic.GreaterThanCount(sum - lower);
            dic.Add(sum);
        }
        return count;
    }

	// RB Tree
    public class RBTreeBase<TKey,TNode>
        where TNode : RBTreeBase<TKey,TNode>.NodeBase
    {
        private readonly IComparer<TKey> _comparer;

        private TNode _root;

        private Func<TNode,TNode,TNode> _duplicate;

        public RBTreeBase()
            : this(Comparer<TKey>.Default)
        {

        }

        public RBTreeBase(IComparer<TKey> comparer)
            : this (comparer, (e,a) => throw new ArgumentOutOfRangeException($"Duplicate key: '{a.Key}'."))
        {
            
        }        

        public RBTreeBase(IComparer<TKey> comparer, Func<TNode,TNode,TNode> duplicate)
        {
            _comparer = comparer;
            _duplicate = duplicate;
        }        

        public int Count => _root?.Count ?? 0;

        public RBTreeBase<TKey,TNode> Add(TNode node)
        {
            var stack = new Stack<TNode>();

            var next = _root;
            while(next != null)
            {
                stack.Push(next);
                switch(Math.Sign(_comparer.Compare(node.Key, next.Key)))
                {
                    case -1:
                        next = next.LeftLink;
                        break;
                    case 0:
                        next = null;
                        break;
                    case 1:
                        next = next.RightLink;
                        break;
                }
            }

            if (!stack.TryPeek(out TNode peeked))
            {
                _root = node;
                _root.IsRed = false;
                _root.Count = _root.SelfCount();
                return this;
            }

            switch(Math.Sign(_comparer.Compare(node.Key, peeked.Key)))
            {
                case -1:
                    peeked.LeftLink = node;
                    break;
                case 0:
                    node = _duplicate.Invoke(peeked, node);
                    break;
                case 1:
                    peeked.RightLink = node;
                    break;
            }

            TNode last = node;

            while (stack.TryPop(out TNode prev))
            {
                if (prev.LeftLink?.IsRed == true && prev.RightLink?.IsRed == true)
                {
                    prev.LeftLink.IsRed = prev.RightLink.IsRed = false;
                    prev.IsRed = true;
                }

                if (last.IsRed && prev.RightLink == last)
                {
                    var temp = last.LeftLink;

                    if (stack.TryPeek(out peeked))
                        if (peeked.LeftLink == prev)
                            peeked.LeftLink = last;
                        else
                            peeked.RightLink = last;
                    else
                        _root = last;

                    last.LeftLink = prev;
                    last.IsRed = prev.IsRed;
                    prev.RightLink = temp;
                    prev.IsRed = true;

                    temp = last;
                    last = prev;
                    prev = temp;
                }

                if (last.IsRed && prev.LeftLink == last && last.LeftLink?.IsRed == true) 
                {
                    var temp = last.RightLink;

                    if (stack.TryPeek(out peeked))
                        if (peeked.LeftLink == prev)
                            peeked.LeftLink = last;
                        else
                            peeked.RightLink = last;
                    else
                        _root = last;

                    last.RightLink = prev;
                    last.IsRed = true;
                    prev.LeftLink = temp;
                    prev.IsRed = false;

                    last.LeftLink.IsRed = false;

                    temp = last;
                    last = prev;
                    prev = temp;
                }

                if (prev.LeftLink?.IsRed == true && prev.RightLink?.IsRed == true)
                {
                    prev.LeftLink.IsRed = prev.RightLink.IsRed = false;
                    prev.IsRed = true;
                }

                last.Count = last.SelfCount() + (last.LeftLink?.Count ?? 0) + (last.RightLink?.Count ?? 0);

                last = prev;
            }

            last.Count = last.SelfCount() + (last.LeftLink?.Count ?? 0) + (last.RightLink?.Count ?? 0);

            _root.IsRed = false;

            return this;
        }

        public TNode Search(TKey key)
        {
            var current = _root;
            while (current != null)
            {
                switch(Math.Sign(_comparer.Compare(key, current.Key)))
                {
                    case 0:
                        return current;
                    case -1:
                        current = current.LeftLink;
                        break;
                    case 1:
                        current = current.RightLink;
                        break;
                }
            }
            return null;
        }

        public IEnumerable<TNode> SearchPath(TKey key)
        {
            var current = _root;
            while (current != null)
            {
                yield return current;
                switch(Math.Sign(_comparer.Compare(key, current.Key)))
                {
                    case 0:
                        yield break;
                    case -1:
                        current = current.LeftLink;
                        break;
                    case 1:
                        current = current.RightLink;
                        break;
                }
            }
        }

        public IEnumerable<TNode> Enumerate()
        {
            return Enumerate(_root);
        }

        #region Private

        private IEnumerable<TNode> Enumerate(TNode node)
        {
            if (node == null)
                yield break;
            
            foreach(var kvp in Enumerate(node.LeftLink))
                yield return kvp;
            
            yield return node;

            foreach(var kvp in Enumerate(node.RightLink))
                yield return kvp;
        }
        #endregion

        public class NodeBase
        {
            public NodeBase(TKey key)
            {
                Key = key;
            }
            public TKey Key { get; }
            public int Count { get; set; } = 1;
            public bool IsRed { get; set; } = true;
            public TNode LeftLink { get; set; }
            public TNode RightLink { get; set; }
            public virtual int SelfCount() => 1;
        }
    }    
    public class RBTreeSpecial : IEnumerable<KeyValuePair<long,int>>
    {
        private readonly RBTreeBase<long,Node> _tree = 
            new RBTreeBase<long,Node>(Comparer<long>.Default, (e,a) => { e.KeysCount += 1;  return e; });

        public int Count => _tree.Count;

        public RBTreeSpecial Add(long key)
        {
            _tree.Add(new Node(key));
            return this;
        }

        public int GreaterThanCount(long value)
        {
            var count = 0;

            foreach(var node in _tree.SearchPath(value))
            {
                if (node.Key > value)
                    count += node.SelfCount();
                if (node.Key >= value)
                    count += node.RightLink?.Count ?? 0;
            }

            return count;
        }

        #region IEnumerable<KeyValuePair<long,TValue>>

        public IEnumerator<KeyValuePair<long, int>> GetEnumerator() =>
            Enumerate().GetEnumerator();

        // here IEnumerable.GetEnumerator() is to distinguish GetEnumerator() of generic IEnumerable<>
        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

        #endregion

        private IEnumerable<KeyValuePair<long,int>> Enumerate()
        {
            foreach(var node in _tree.Enumerate())
                yield return new KeyValuePair<long, int>(node.Key, node.KeysCount);
        }

        private class Node : RBTreeBase<long,Node>.NodeBase
        {
            public int KeysCount { get; set; } = 1;

            public Node(long key) : base(key)
            {
            }

            public override int SelfCount() => KeysCount;
        }        
    }
}