#nformation on the shift cipher : https://en.wikipedia.org/wiki/Caesar_cipher
# Alice has been working in a secret intelligence bureau for several years. She's an expert in cryptography and
# often tasked with decoding intercepted messages.
# One day, Alice receives a strange message on her desk. It's a string of characters encoded with a shift cipher,
# but no key has been provided to decode it. Alice knows she needs to decode the message quickly to uncover the enemy's plans.
# Fortunately, Alice has a reliable method for decoding messages without a key. She uses frequency analysis of
# letters to determine the shift used in the encoding process.
# However, Alice knows that the shift is only applied to alphabetical characters. Non-alphabetical characters,
# such as numbers and symbols, are not affected by the shift.
# By comparing the frequency of letters in the encoded message with those in the English language, Alice eventually
# finds the shift used in the encoding process.
# In addition, Alice wants to preserve the characteristics of the original text, including capitalization.
# This means the program must maintain the case of the original text when generating the decoded message in plaintext.

# Now, your task is to help Alice by writing a program that takes the encoded string as input, uses letter
# frequency analysis to decode the message by applying the shift only to alphabetical characters, and generates
# the decoded message in plaintext while preserving the case of the original text.

# Use this frequency list:
# A: 8.08%	N: 7.38%
# B: 1.67%	O: 7.47%
# C: 3.18%	P: 1.91%
# D: 3.99%	Q: 0.09%
# E: 12.56%	R: 6.42%
# F: 2.17%	S: 6.59%
# G: 1.80%	T: 9.15%
# H: 5.27%	U: 2.79%
# I: 7.24%	V: 1.00%
# J: 0.14%	W: 1.89%
# K: 0.63%	X: 0.21%
# L: 4.04%	Y: 1.65%
# M: 2.60%	Z: 0.07%

from collections import Counter
import unittest

english_freq = {
    'E': 12.56, 'T': 9.15, 'A': 8.08, 'O': 7.47, 'I': 7.24, 'N': 7.38, 'S': 6.59, 'H': 5.27, 'R': 6.42,
    'D': 3.99, 'L': 4.04, 'C': 3.18, 'U': 2.79, 'M': 2.60, 'W': 1.89, 'F': 2.17, 'G': 1.80, 'Y': 1.65,
    'P': 1.91, 'B': 1.67, 'V': 1.00, 'K': 0.63, 'X': 0.21, 'Q': 0.09, 'J': 0.14, 'Z': 0.07
}

# Function to shift a char by n positions
def shift_char(c, n: int, is_lower: bool=False):
    if not c.isalpha():
        return c
    while n < 0:  # ensure n >= 0
        n += 26
    res = chr(ord('A') + (ord(c.upper()) - ord('A') + n) % 26)
    return res.lower() if is_lower else res

# Function to decode a message with a given shift and case preservation
def decode_caesar(cipher_text, sft, lower_tags: list[bool]) -> str:
    return ''.join(shift_char(cipher_text[i], -sft, lower_tags[i])
                   for i in range(len(cipher_text)))

# function to determine the best shift based on frequency analysis
def best_shift(ciphered_text: str) -> int:
    ### Counter of each letter occurrance in ciphered text
    # letter_count = Counter(c for c in ciphered_text if c.isalpha())
    #total_letters = sum(letter_count.values())
    #cipher_freq_mp = {ch: (cnt * 100 / total_letters) for ch, cnt in letter_count.items()}
    ### actually, this counter is not needed at all
    
    # based on the given English frequency
    max_score, best_sft = 0, 0
    for sft in range(26):
        score = sum(english_freq.get(shift_char(ch, -sft), 0) for ch in ciphered_text if ch.isalpha())
        if score > max_score:
            max_score, best_sft = score, sft
    return best_sft

# entry point
def decrypt_based_eng_freq(ciphered: str):
    # need to restore the initial case of each letter
    lowercase_tags = [c.islower() for c in ciphered]
    # frequency analyze
    shift = best_shift(ciphered)
    return decode_caesar(ciphered, shift, lowercase_tags)

class TestFrequencyBasedOnDecryption(unittest.TestCase):
    # each test case must start with 'test_'
    def test_decrypt_Hello(self):
        msg = "Khoor Zruog ! Frqjudwxodwlrqv, brx kdyh vxffhvvixoob ghfubswhg ph ! Kdyh ixq zlwk wklv sxccoh"
        expected = "Hello World ! Congratulations, you have successfully decrypted me ! Have fun with this puzzle"
        self.assertEqual(expected, decrypt_based_eng_freq(msg))

    def test_decrypt_I_rub(self):
        msg = "Q zcjjml apwctlmza eqbp xmwxtm epw axwsm wn nzqmvlapqx, jcb epw lql vwb pidm bpm aium ditcma ia um ib itt. Bpwam epw uism gwc ticop epmv mdmzgbpqvo qa owqvo emtt, jcb epw eqtt vmdmz jm bpmzm epmv uqanwzbcvm lzweva gwc. - Vmsnmc"
        expected = "I rubbed shoulders with people who spoke of friendship, but who did not have the same values as me at all. Those who make you laugh when everything is going well, but who will never be there when misfortune drowns you. - Nekfeu"
        self.assertEqual(expected, decrypt_based_eng_freq(msg))

    def test_decrypt_You_can(self):
        msg = "Iye mkx pyyv kvv yp dro zoyzvo cywo yp dro dswo, kxn cywo yp dro zoyzvo kvv yp dro dswo, led iye mkx'd pyyv kvv yp dro zoyzvo kvv yp dro dswo."
        expected = "You can fool all of the people some of the time, and some of the people all of the time, but you can't fool all of the people all of the time."
        self.assertEqual(expected, decrypt_based_eng_freq(msg))

    def test_decrypt_Any_Code(self):
        msg = "Obm qcrs mci'js pssb kfwhwbu tcf 6 acbhvg cf acfs kwhvcih zccywbu oh wh awuvh og kszz vojs pssb kfwhhsb pm gcascbs szgs"
        expected = "Any code you've been writing for 6 months or more without looking at it might as well have been written by someone else"
        self.assertEqual(expected, decrypt_based_eng_freq(msg))

    def test_decrypt_Mr_Mrs(self):
        msg = "Kp. ylb Kpq. Bspqjcw, md lskzcp dmsp, Npgtcr Bpgtc, ucpc npmsb rm qyw rfyr rfcw ucpc ncpdcarjw lmpkyj, rfyli wms tcpw ksaf. Rfcw ucpc rfc jyqr ncmnjc wms’b cvncar rm zc gltmjtcb gl ylwrfgle qrpylec mp kwqrcpgmsq, zcaysqc rfcw hsqr bgbl’r fmjb ugrf qsaf lmlqclqc. Kp. Bspqjcw uyq rfc bgpcarmp md y dgpk ayjjcb Epsllgleq, ufgaf kybc bpgjjq. Fc uyq y zge, zccdw kyl ugrf fypbjw ylw lcai, yjrfmsef fc bgb fytc y tcpw jypec ksqryafc. Kpq. Bspqjcw uyq rfgl ylb zjmlbc ylb fyb lcypjw rugac rfc sqsyj ykmslr md lcai, ufgaf aykc gl tcpw sqcdsj yq qfc qnclr qm ksaf md fcp rgkc apylgle mtcp eypbcl dclacq, qnwgle ml rfc lcgefzmpq. Rfc Bspqjcwq fyb y qkyjj qml ayjjcb Bsbjcw ylb gl rfcgp mnglgml rfcpc uyq lm dglcp zmw ylwufcpc. Rfc Bspqjcwq fyb ctcpwrfgle rfcw uylrcb, zsr rfcw yjqm fyb y qcapcr, ylb rfcgp epcyrcqr dcyp uyq rfyr qmkczmbw umsjb bgqamtcp gr. Rfcw bgbl’r rfgli rfcw amsjb zcyp gr gd ylwmlc dmslb msr yzmsr rfc Nmrrcpq."
        expected = "Mr. and Mrs. Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal, thank you very much. They were the last people you’d expect to be involved in anything strange or mysterious, because they just didn’t hold with such nonsense. Mr. Dursley was the director of a firm called Grunnings, which made drills. He was a big, beefy man with hardly any neck, although he did have a very large mustache. Mrs. Dursley was thin and blonde and had nearly twice the usual amount of neck, which came in very useful as she spent so much of her time craning over garden fences, spying on the neighbors. The Dursleys had a small son called Dudley and in their opinion there was no finer boy anywhere. The Dursleys had everything they wanted, but they also had a secret, and their greatest fear was that somebody would discover it. They didn’t think they could bear it if anyone found out about the Potters."
        self.assertEqual(expected, decrypt_based_eng_freq(msg))

if __name__ == '__main__':
    unittest.main()