// See https://aka.ms/new-console-template for more information
using leet;
public class Program {
    public static void Main(string[] args) {
        var sol = new Solution01();
        int[] nums = new int[] { -2147483647,0,-2147483647,2147483647};
        int lower = -564, upper = 3864;
        var res = sol.CountRangeSum(nums, lower, upper);
        System.Console.WriteLine(res);
    }
}
