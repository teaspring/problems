using System;

namespace Codingame;

public class HackingRobberCity
{
    // Entry point
    public string Process1(string msg1, string msg2, string msg3)
    {
        // Convert.FromHexString() return equivalent 8-bit unsigned integer array.
        var bytes1 = Convert.FromHexString(msg1); // its length is half of msg1
        var bytes2 = Convert.FromHexString(msg2);
        var bytes3 = Convert.FromHexString(msg3);

        var result = new byte[bytes1.Length];
        for (int i = 0; i < bytes1.Length; i++)
        {
            result[i] = (byte)(bytes1[i] ^ bytes2[i] ^ bytes3[i]);
        }
        return System.Text.Encoding.ASCII.GetString(result);
    }
}