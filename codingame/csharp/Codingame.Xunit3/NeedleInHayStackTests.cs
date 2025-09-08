using Xunit;

namespace Codingame.Xunit3;

public class NeedleInHayStackTests
{ 
    [Fact]
    public void FindNeedleInHayStack_Short()
    {
        // arrange
        string msg = "aaaaddaaabbbbbc";
        // act & assert
        var nhs = new Codingame.NeedleInHayStack();
        Assert.Equal("8 14", nhs.FindNeedle(msg, "a-c"));
        Assert.Equal("8 14", nhs.FindNeedle(msg, "c,a,b"));
        Assert.Equal("3 4", nhs.FindNeedle(msg, "d, a"));
        Assert.Equal("5 14", nhs.FindNeedle(msg, "d, b-c, a"));
    }

    [Fact]
    public void FindNeedleInHayStack_Long()
    {
        // arrange
        var stacks = new string[]{
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
        var msg = string.Concat(stacks);
        // act & assert
        var nhs = new Codingame.NeedleInHayStack();
        Assert.Equal("695 734", nhs.FindNeedle(msg, "1,6,2,t,h,o-u"));
        Assert.Equal("1260 1308", nhs.FindNeedle(msg, "a-n,o,p,y,9,2"));
        Assert.Equal("1916 1974", nhs.FindNeedle(msg, "c,i,l,y,t,u-x"));
    }
}