using cshsort;
using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace cshTest;

public class Tests
{
    VariantSorter sorter;
    [SetUp]
    public void Setup()
    {
        sorter = new VariantSorter();
    }

    // Assert is from ns=Microsoft.VisualStudio.TestTools.UnitTesting
    private void AssertEnumerableEqual(IEnumerable<int> expected, IEnumerable<int> actual)
    {
        var expEnumerator = expected.GetEnumerator();
        var actEnumerator = actual.GetEnumerator();
        while (expEnumerator.MoveNext() && actEnumerator.MoveNext())
        {
            Assert.That(actEnumerator.Current, Is.EqualTo(expEnumerator.Current)); // recommended
        }
        Assert.IsFalse(expEnumerator.MoveNext() || actEnumerator.MoveNext());
    }

    [Test]
    public void Test1()
    {
        var srcArr = new int[] {3, 14, 8, 5, 103, 1, 9, 2, 7, 11, 6};
        var expected = srcArr.OrderBy(x => x);
        var actual = sorter.MergeSort(srcArr);
        AssertEnumerableEqual(expected, actual);
    }

    [Test]
    public void Test2()
    {
        var rand = new Random();
        var srcIEnum = from i in Enumerable.Range(0, 50)
                     select rand.Next(0, 100);
        var srcArr = srcIEnum.ToArray();
        var expected = srcArr.OrderBy(x => x);
        var actual = sorter.MergeSort(srcArr.ToArray());
        AssertEnumerableEqual(expected, actual);
    }
}