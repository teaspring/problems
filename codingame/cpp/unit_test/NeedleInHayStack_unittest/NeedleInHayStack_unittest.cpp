#include "NeedleInHayStack.cpp"
#include "gtest/gtest.h"
#include "ut_shared.cpp"
#include <vector>

using namespace std;

TEST(NeedleInHayStackTest, ShortHayStack)
{
    string msg("aaaaddaaabbbbbc");
    // act & assert
    Solution s;
    EXPECT_EQ("8 14", s.find_needle_in_haystack(msg, "a-c"));
    EXPECT_EQ("8 14", s.find_needle_in_haystack(msg, "c,a ,  b"));
    EXPECT_EQ("3 4", s.find_needle_in_haystack(msg, "d, a"));
    EXPECT_EQ("8 14", s.find_needle_in_haystack(msg, "a-c"));
}

TEST(NeedleInHayStackTest, LongHayStack)
{
    vector<string> stacks = {
        "andthecircleiscustomarilysubdividedinto360degreesalthoughpiradiansyieldshalfthecircleendsometimesreferredtoasarchimedessconstantbecausethegreekmathematiciancomputedlowerandupperboundsofpibydrawingregu",
        "larpolygonsinsideandoutsideacircleingermanyitwascalledtheludolphiannumberuntiltheearly20thcenturyafterthedutchmathematicianludolphvanceulen15401610whocalculatedupto35digitsofpiinthelate16thcenturymart",
        "inrennersep072016asofthebeginningof2019morethan22trilliondecimaldigitsofpiareknownseethewikipediaarticlechronologyofcomputationofpiharveypdalejan232019onmarch142019emmaharukaiwaoannouncedthecalculatio",
        "nof314trilliondigitsofpiusinggooglecloudsinfrastructuredavidradcliffeapr102019alsovolumeofthreequartersofasphereofradius1omarepolaug162019onaugust52021researchersfromtheuniversityofappliedsciencesofth",
        "egrisonsinswitzerlandannouncedtheyhadcalculated628trilliondigitsguinnessworldrecordshasnotverifiedthisyetalonsodelarteaug232021thehermitelindemann1882theoremstatesthatifzisanonzeroalgebraicnumberthene",
        "zisatranscendentnumberthetranscendenceofpithenresultsfromeulersrelationeipi1peterluschnyjul212023referencesmohammadkazarianasummaryofmathematicalworksofghiyathuddinjamshidkashanijournalofrecreationalm",
        "athematicsvol291pp32421998jarndtchaenelpiunleashedspringerny2001pbeckmannahistoryofpigolempressboulderco1977jpdelahayelefascinantnombrepipourlascienceparis1997peyardandjplafonthenumberpiamermathsoc200",
        "4srfinchmathematicalconstantsencyclopediaofmathematicsanditsapplicationsvol94cambridgeuniversitypresssection14lepetitarchimedespecialissueonpisupplementtono645may1980adcsamienscliffordapickoverapassio",
        "nformathematicswiley2005seep31njasloaneahandbookofintegersequencesacademicpress1973includesthissequencenjasloaneandsimonplouffetheencyclopediaofintegersequencesacademicpress1995includesthissequencelin",
        "ksharryjsmithtableofnanforn120000sanjarmabrarovrehansiddiquirajinderkjagpalandbrendanmquineunconditionalapplicabilityofthelehmersmeasuretothetwotermmachinlikeformulaforpiarxiv200411711mathgm2020davean"
    };
    stringstream ss;
    for (auto it = stacks.cbegin(); it < stacks.cend(); it++)
    {
        ss << *it;
    }
    string msg = ss.str();
    // act & assert
    Solution s;
    EXPECT_EQ("695 734", s.find_needle_in_haystack(msg, "1,6,2,t,h,o-u"));
    EXPECT_EQ("1260 1308", s.find_needle_in_haystack(msg, "a-n,o,p,y,9,2"));
    EXPECT_EQ("1916 1974", s.find_needle_in_haystack(msg, "c,i,l,y,t,u-x"));
}
