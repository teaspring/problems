// See https://aka.ms/new-console-template for more information

using cshsort;
using static System.Console;
public class Program
{
    public static void Main(string[] args)
    {
        var sorter = new VariantSorter();

        var rand = new Random();
        var srcSeq = from i in Enumerable.Range(0, 20)
                     select rand.Next(0, 100);
        // lazy evaluation of query syntax: once it is executed, a new sequence is created

        var srcArr = srcSeq.ToArray(); // the IEnumerable<int> must be converted to int[] to make the sequence become stable
        var expected = srcArr.OrderBy(x => x).ToArray();
        WriteLine(String.Join(", ", expected));
        
        var actual = sorter.MergeSort(srcArr);
        WriteLine(String.Join(", ", actual));
    }
}
