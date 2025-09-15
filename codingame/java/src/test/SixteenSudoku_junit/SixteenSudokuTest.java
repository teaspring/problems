import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.Assertions;

class SixteenSudokuTest {
    private SixteenSudoku game;

    @BeforeEach
    public void setUp(){
        game = new SixteenSudoku();
    }

    @Test
    @DisplayName("solveSudoku() easy case")
    void solveSudoku_simple() {
        // arrange
        String[] board = {
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
        // act
        boolean valid = game.solveSudoku(board);
        Assertions.assertTrue(valid);
        // assert
        String[] expected = {
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
        Assertions.assertArrayEquals(expected, board);
    }

    @Test
    @DisplayName("solveSudoku() medium case")
    void solveSudoku_medium() {
        // arrange
        String[] board = {
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
        // act
        boolean valid = game.solveSudoku(board);
        Assertions.assertTrue(valid);
        // assert
        String[] expected = {
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
        Assertions.assertArrayEquals(expected, board);
    }

    @Test
    @DisplayName("solveSudoku() hard case")
    void solveSudoku_hard() {
        // arrange
        String[] board = {
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
        // act
        boolean valid = game.solveSudoku(board);
        Assertions.assertTrue(valid);
        // assert
        String[] expected = {
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
        Assertions.assertArrayEquals(expected, board);
    }
}