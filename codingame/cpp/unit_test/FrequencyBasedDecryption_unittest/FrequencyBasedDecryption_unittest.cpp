#include "FrequencyBasedDecryption.cpp"
#include "gtest/gtest.h"

using namespace std;

/*------ decrypt_by_freq() ------*/
TEST(DecryptByFrequecyTest, Hello)
{
    Solution s;
    const string msg = "Khoor Zruog ! Frqjudwxodwlrqv, brx kdyh vxffhvvixoob ghfubswhg ph ! Kdyh ixq zlwk wklv sxccoh";
    const string exp = "Hello World ! Congratulations, you have successfully decrypted me ! Have fun with this puzzle";
    string res;
    s.decrypt_by_freq(msg, res);
    EXPECT_EQ(exp, res);
}

TEST(DecryptByFrequecyTest, AnyCode)
{
    Solution s;
    const string msg = "Obm qcrs mci'js pssb kfwhwbu tcf 6 acbhvg cf acfs kwhvcih zccywbu oh wh awuvh og kszz vojs pssb kfwhhsb pm gcascbs szgs";
    const string exp = "Any code you've been writing for 6 months or more without looking at it might as well have been written by someone else";
    string res;
    s.decrypt_by_freq(msg, res);
    EXPECT_EQ(exp, res);
}

TEST(DecryptByFrequecyTest, E_is_not_most_common)
{
    Solution s;
    const string msg = "Frfsif fsi Fqfs fqbfdx fuuwjhnfyj frfensl fiajsyzwjx fsi fsnrfqx.";
    const string exp = "Amanda and Alan always appreciate amazing adventures and animals.";
    string res;
    s.decrypt_by_freq(msg, res);
    EXPECT_EQ(exp, res);
}

/*------ decrypt_by_req_2() ------*/
TEST(DecryptByFrequecy2Test, Hello)
{
    Solution s;
    string msg = "Khoor Zruog ! Frqjudwxodwlrqv, brx kdyh vxffhvvixoob ghfubswhg ph ! Kdyh ixq zlwk wklv sxccoh";
    string exp = "Hello World ! Congratulations, you have successfully decrypted me ! Have fun with this puzzle";
    string res;
    s.decrypt_by_freq_2(msg);
    EXPECT_EQ(exp, msg);
}

// this case will capture bug of decrypt_by_req_2()
TEST(DecryptByFrequecy2Test, E_is_not_most_common)
{
    Solution s;
    string msg = "Frfsif fsi Fqfs fqbfdx fuuwjhnfyj frfensl fiajsyzwjx fsi fsnrfqx.";
    string exp = "Amanda and Alan always appreciate amazing adventures and animals.";
    string res;
    s.decrypt_by_freq_2(msg);
    EXPECT_EQ(exp, msg);
}
