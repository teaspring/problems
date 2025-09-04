import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

class FrequencyBasedDecryptionTest {
    private FrequencyBasedDecryption game;

    @BeforeEach
    public void setUp(){
        game = new FrequencyBasedDecryption();
    }

    @Test
    @DisplayName("decrypt hello")
    void decryptStrByFreq_hello() {
        // arrange
        String msg = "Khoor Zruog ! Frqjudwxodwlrqv, brx kdyh vxffhvvixoob ghfubswhg ph ! Kdyh ixq zlwk wklv sxccoh";
        // act
        String res = game.decrypStrByFreq(msg);
        // assert
        String expected = "Hello World ! Congratulations, you have successfully decrypted me ! Have fun with this puzzle";
        Assertions.assertEquals(expected, res);
    }

    @Test
    @DisplayName("decrypt I rub")
    void decryptStrByFreq_rub() {
        // arrange
        String msg = "Q zcjjml apwctlmza eqbp xmwxtm epw axwsm wn nzqmvlapqx, jcb epw lql vwb pidm bpm aium ditcma ia um ib itt. Bpwam epw uism gwc ticop epmv mdmzgbpqvo qa owqvo emtt, jcb epw eqtt vmdmz jm bpmzm epmv uqanwzbcvm lzweva gwc. - Vmsnmc";
        // act
        String res = game.decrypStrByFreq(msg);
        // assert
        String expected = "I rubbed shoulders with people who spoke of friendship, but who did not have the same values as me at all. Those who make you laugh when everything is going well, but who will never be there when misfortune drowns you. - Nekfeu";
        Assertions.assertEquals(expected, res);
    }

    @Test
    @DisplayName("decrypt You can")
    void decryptStrByFreq_you_can() {
        // arrange
        String msg = "Iye mkx pyyv kvv yp dro zoyzvo cywo yp dro dswo, kxn cywo yp dro zoyzvo kvv yp dro dswo, led iye mkx'd pyyv kvv yp dro zoyzvo kvv yp dro dswo.";
        // act
        String res = game.decrypStrByFreq(msg);
        // assert
        String expected = "You can fool all of the people some of the time, and some of the people all of the time, but you can't fool all of the people all of the time.";
        Assertions.assertEquals(expected, res);
    }

    @Test
    @DisplayName("decrypt Any code")
    void decryptStrByFreq_any_code() {
        // arrange
        String msg = "Obm qcrs mci'js pssb kfwhwbu tcf 6 acbhvg cf acfs kwhvcih zccywbu oh wh awuvh og kszz vojs pssb kfwhhsb pm gcascbs szgs";
        // act
        String res = game.decrypStrByFreq(msg);
        // assert
        String expected = "Any code you've been writing for 6 months or more without looking at it might as well have been written by someone else";
        Assertions.assertEquals(expected, res);
    }

    @Test
    @DisplayName("decrypt Mr. Mrs.")
    void decryptStrByFreq_Mr_Mrs() {
        // arrange
        String msg = "Kp. ylb Kpq. Bspqjcw, md lskzcp dmsp, Npgtcr Bpgtc, ucpc npmsb rm qyw rfyr rfcw ucpc ncpdcarjw lmpkyj, rfyli wms tcpw ksaf. Rfcw ucpc rfc jyqr ncmnjc wms’b cvncar rm zc gltmjtcb gl ylwrfgle qrpylec mp kwqrcpgmsq, zcaysqc rfcw hsqr bgbl’r fmjb ugrf qsaf lmlqclqc. Kp. Bspqjcw uyq rfc bgpcarmp md y dgpk ayjjcb Epsllgleq, ufgaf kybc bpgjjq. Fc uyq y zge, zccdw kyl ugrf fypbjw ylw lcai, yjrfmsef fc bgb fytc y tcpw jypec ksqryafc. Kpq. Bspqjcw uyq rfgl ylb zjmlbc ylb fyb lcypjw rugac rfc sqsyj ykmslr md lcai, ufgaf aykc gl tcpw sqcdsj yq qfc qnclr qm ksaf md fcp rgkc apylgle mtcp eypbcl dclacq, qnwgle ml rfc lcgefzmpq. Rfc Bspqjcwq fyb y qkyjj qml ayjjcb Bsbjcw ylb gl rfcgp mnglgml rfcpc uyq lm dglcp zmw ylwufcpc. Rfc Bspqjcwq fyb ctcpwrfgle rfcw uylrcb, zsr rfcw yjqm fyb y qcapcr, ylb rfcgp epcyrcqr dcyp uyq rfyr qmkczmbw umsjb bgqamtcp gr. Rfcw bgbl’r rfgli rfcw amsjb zcyp gr gd ylwmlc dmslb msr yzmsr rfc Nmrrcpq.";
        // act
        String res = game.decrypStrByFreq(msg);
        // assert
        String expected = "Mr. and Mrs. Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal, thank you very much. They were the last people you’d expect to be involved in anything strange or mysterious, because they just didn’t hold with such nonsense. Mr. Dursley was the director of a firm called Grunnings, which made drills. He was a big, beefy man with hardly any neck, although he did have a very large mustache. Mrs. Dursley was thin and blonde and had nearly twice the usual amount of neck, which came in very useful as she spent so much of her time craning over garden fences, spying on the neighbors. The Dursleys had a small son called Dudley and in their opinion there was no finer boy anywhere. The Dursleys had everything they wanted, but they also had a secret, and their greatest fear was that somebody would discover it. They didn’t think they could bear it if anyone found out about the Potters.";
        Assertions.assertEquals(expected, res);
    }
}