namespace cshsort;

public class VariantSorter
{
    // array implements IEnumerable, but not IEnumerable<T>
    public IEnumerable<int> MergeSort(int[] arr)
    {
        MergeSort(arr, 0, arr.Length); // in-place sort
        return from x in arr
               select x;
    }

    # region trial to use IEnumerable and query syntax for merge sort, fails
    private IEnumerable<int> MergeSortGeneric(IEnumerable<int> arr, int count)
    {
        if (count <= 1)
            return arr;
        var mid = count / 2;
        var left = from l in arr.Take(mid)
                    select l;
        var right = from r in arr.Skip(mid)
                    select r;
        return Merge(MergeSortGeneric(left, mid), MergeSortGeneric(right, count - mid));
    }

    private IEnumerable<int> Merge(IEnumerable<int> left, IEnumerable<int> right)
    {
        var lEnumerator = left.GetEnumerator();
        var rEnumerator = right.GetEnumerator();

        bool leftMove = lEnumerator.MoveNext();
        bool rightMove = rEnumerator.MoveNext();

        while (leftMove && rightMove)
        {
            if (lEnumerator.Current.CompareTo(rEnumerator.Current) < 0)
            {
                yield return lEnumerator.Current;
                leftMove = lEnumerator.MoveNext();
            }
            else
            {
                yield return rEnumerator.Current;
                rightMove = rEnumerator.MoveNext();
            }
        }

        while (lEnumerator.MoveNext())
        {
            yield return lEnumerator.Current;
        }

        while (rEnumerator.MoveNext())
        {
            yield return rEnumerator.Current;
        }
    }
    #endregion

    # region use array and index for merge sort
    private void MergeSort(int[] arr, int left, int right) // [left, right)
    {
        if (right - left <= 1) return; // termination condition depends on the range bounder incluiveness and exclusiveness
        var mid = left + (right - left) / 2;
        MergeSort(arr, left, mid); // [left, mid)
        MergeSort(arr, mid, right); // [mid, right)
        Merge(arr, left, mid, right);
    }

    private void Merge(int[] arr, int left, int mid, int right)
    {
        var n1 = mid - left; // [left, mid)
        var n2 = right - mid; // [mid, right)
        var leftArr = new int[n1]; // necessary temporary arrays to store two sorted half ranges
        var rightArr = new int[n2];
        for (var i = 0; i < n1; i++)
        {
            leftArr[i] = arr[left + i];
        }
        for (var i = 0; i < n2; i++)
        {
            rightArr[i] = arr[mid + i];
        }
        // copy two sorted halves into the original array
        int l = 0, r = 0, k = left;
        while (l < n1 && r < n2)
        {
            arr[k] = (leftArr[l] <= rightArr[r]) ? leftArr[l++] : rightArr[r++];
            k++;
        }
        while (l < n1)
        {
            arr[k++] = leftArr[l++];
        }
        while (r < n2)
        {
            arr[k++] = rightArr[r++];
        }
    }
    # endregion
}