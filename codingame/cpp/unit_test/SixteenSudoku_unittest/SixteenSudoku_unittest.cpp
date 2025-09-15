#include "SixteenSudoku.cpp"
#include "gtest/gtest.h"
#include "ut_shared.cpp"
#include <vector>

using namespace std;

TEST(SixteenSudokuTest, easy)
{
    vector<string> board = {
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
    };
    vector<string> solved_board = {
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
    };
    // act & assert
    Solution s;
    bool if_solved = s.solve_sudoku(board);
    EXPECT_TRUE(if_solved);
    EXPECT_EQ_VEC(solved_board, board);
}

TEST(SixteenSudokuTest, medium)
{
    vector<string> board = {
        "........B.HAL..N",
        "..N.....D...OEF.",
        "..K.A..J..NO.B.P",
        "...CL.D..G.E.M.J",
        "...JH..P.......E",
        ".N.K.....I..JGOD",
        ".OM..IECNB.GH...",
        "HB...D..P.J.NFCI",
        ".HA.ME......KN.C",
        "D..ENB.H.POL....",
        "NM.B..O.JK..D...",
        ".PL....D.....A.O",
        ".E.HDC.....FPK..",
        ".C..EAN.OL.P.I..",
        "IA.NG.PM..KD..E.",
        "..O.IH.....NAC.."
    };
    vector<string> solved_board = {
        "OIJPCKFEBMHALDGN",
        "MLNABPHGDCIJOEFK",
        "EDKGAMIJLFNOCBHP",
        "BFHCLODNKGPEIMAJ",
        "CGIJHNAPFODKBLME",
        "ANPKFLMBEICHJGOD",
        "FOMDJIECNBLGHPKA",
        "HBELODGKPAJMNFCI",
        "JHAOMELIGDFBKNPC",
        "DKFENBCHAPOLMJIG",
        "NMCBPGOAJKEIDHLF",
        "GPLIKFJDHNMCEABO",
        "LEGHDCBOIJAFPKNM",
        "KCDMEANFOLBPGIJH",
        "IABNGJPMCHKDFOEL",
        "PJOFIHKLMEGNACDB"
    };
    // act & assert
    Solution s;
    bool if_solved = s.solve_sudoku(board);
    EXPECT_TRUE(if_solved);
    EXPECT_EQ_VEC(solved_board, board);
}

TEST(SixteenSudokuTest, hard)
{
    vector<string> board = {
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
    };
    vector<string> solved_board = {
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
    };
    // act & assert
    Solution s;
    bool if_solved = s.solve_sudoku(board);
    EXPECT_TRUE(if_solved);
    EXPECT_EQ_VEC(solved_board, board);
}