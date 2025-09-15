namespace Codingame.Xunit3;

public class SixteenSudokuTests
{
    [Fact]
    public void SixteenSudoku_simple()
    { 
        // arrange
        string[] board = [
            ".LEK.G.....NO.C.",
            "..M.H.JOBDG.FENK",
            "J..C.BAN.EK....I",
            ".BG..K..C.J..DPM",
            ".HA.FL..K..M.P..",
            "...OA.....D.IK.G",
            "..KDJ.CBFAIG.MHL",
            ".M.....EPJNO.A..",
            "G...IA.DE.CJP...",
            "AK....GHNM..LIJ.",
            "..DJON..GL.BKH.F",
            ".N...J.K.F...GAB",
            "D..A..FJ..LIM.K.",
            "E.LFCDB.O.M.N.I.",
            ".JI....PD.....L.",
            ".....H.IJ....CBA"
        ];
        var ss = new SixteenSudoku();
        var res = ss.SolveSudoku(board);
        // assert
        Assert.True(res);
        string[] expected = [
            "HLEKDGMFAIPNOBCJ",
            "IAMPHCJOBDGLFENK",
            "JDOCPBANMEKFHLGI",
            "FBGNEKILCOJHADPM",
            "CHAIFLDGKBEMJPON",
            "BEJOAPNMLHDCIKFG",
            "NPKDJOCBFAIGEMHL",
            "LMFGKIHEPJNOBADC",
            "GFHBIALDEKCJPNMO",
            "AKCEBFGHNMOPLIJD",
            "MIDJONPCGLABKHEF",
            "ONPLMJEKIFHDCGAB",
            "DCBAGEFJHNLIMOKP",
            "EGLFCDBAOPMKNJIH",
            "KJIHNMOPDCBAGFLE",
            "PONMLHKIJGFEDCBA"
        ];
        for (var i = 0; i < expected.Length; i++)
        {
            Assert.Equal(expected[i], board[i]);
        }
    }

    [Fact]
    public void SixteenSudoku_hard()
    { 
        // arrange
        string[] board = [
            ".C......E.......",
            "..J..A.BFP...KLD",
            "..I.D.NJ.A..EB.G",
            "L..A....J..N...O",
            "DH.MBJCP..F..IKA",
            "...L.NM..OD....C",
            "..N.I........G..",
            "B..F..OGICP..LDM",
            ".G.E...D...IM.OK",
            ".A..G.P....FLHCN",
            ".F....HOM.B.G.E.",
            "MOP......G....A.",
            "..MI.B.F.HOEK.G.",
            ".B.DC.E.N.L..FM.",
            "G......NC..P.A.E",
            ".EFH...I..G...N."
        ];
        var ss = new SixteenSudoku();
        var res = ss.SolveSudoku(board);
        // assert
        Assert.True(res);
        string[] expected = [
            "KCBGOPLMEIHDANJF",
            "ENJOHAIBFPMGCKLD",
            "FMIPDKNJLACOEBHG",
            "LDHAFEGCJBKNPMIO",
            "DHEMBJCPGNFLOIKA",
            "PIGLKNMABODHJEFC",
            "OJNCIDFLKEAMBGPH",
            "BKAFEHOGICPJNLDM",
            "HGCEAFBDPLNIMJOK",
            "IADBGMPEOKJFLHCN",
            "JFLKNCHOMDBAGPEI",
            "MOPNLIJKHGECFDAB",
            "NPMIJBAFDHOEKCGL",
            "ABODCGEHNJLKIFMP",
            "GLKJMODNCFIPHABE",
            "CEFHPLKIAMGBDONJ"
        ];
        for (var i = 0; i < expected.Length; i++)
        {
            Assert.Equal(expected[i], board[i]);
        }
    }
}
