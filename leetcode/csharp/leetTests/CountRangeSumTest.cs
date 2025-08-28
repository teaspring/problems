using leet;

namespace leetTests;

public class CountRangeSumTests
{
    CountRangeSum crs;

    [SetUp]
    public void Setup()
    {
        var sol = new Solution01();
        crs = sol.CountRangeSum;
    }

    [Test]
    public void Test1()
    {
        int[] nums = new int[] { -2, 5, -1 };
        int lower = -2, upper = 2;
        var res = crs(nums, lower, upper);
        Assert.AreEqual(3, res);
    }

    [Test]
    public void Test2()
    {
        int[] nums = new int[] { -2, 0, 0, 2};
        int lower = -3, upper = 1;
        var res = crs(nums, lower, upper);
        Assert.AreEqual(7, res);
    }

    [Test]
    public void Test3()
    {
        int[] nums = new int[] { -2, 0, 0, 2, 2, -2 };
        int lower = -3, upper = 1;
        var res = crs(nums, lower, upper);
        Assert.AreEqual(10, res);
    }

    [Test]
    public void Test4()
    {
        int[] nums = new int[] { -2147483647,0,-2147483647,2147483647};
        int lower = -564, upper = 3864;
        var res = crs(nums, lower, upper);
        Assert.AreEqual(3, res);
    }
}