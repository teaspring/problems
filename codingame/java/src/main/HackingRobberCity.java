/**
 * At RobberCity, it is really hard to send a parcel safely. Postmen are thieves, and you can be sure that without a proper lock, your box will be opened and emptied prior to "delivery".
 * This is a famous riddle: how can Alice send a parcel to Bob, without having to send the lock key?
 *
 * The answer is:
 * * step 1: Alice locks the box using her own lock and send it to Bob.
 * * step 2: Bob receives the unopened parcel, but cannot open it without the key. He add his own lock on the parcel and send it back to Alice.
 * * step 3: Alice gets her parcel back with the 2 locks. She can now remove hers and send it Bob again.
 * * step 4: Bob receives the parcel with his lock, that he can open.
 *
 * Now, the electronic version!
 * This time, Alice wants to send secured data to Bob. They both read this wikipedia article:
 * https://en.wikipedia.org/wiki/XOR_cipher#Use_and_security about the XOR cipher
 * With a key that is truly random, the result is a one-time pad, which is unbreakable in theory.
 * Wow. Unbreakable.
 *
 * Alice and Bob decided to use the riddle solution applied to XOR.
 * * step 1: Alice encodes her message with her random key, as long as the message itself. She sends it to Bob.
 * * step 2: Bob encodes the ciphered message with his own random key, as long as the message itself. He sends it back to Alice.
 * * step 3: Alice decodes the message with her initial key, and sends it to Bob.
 * * step 4: Bob decodes the message with his initial key, and gets the clear text.
 *
 * And it works! XOR is both commutative and associative, and A XOR 0 = A and A XOR A = 0. Hence
 * Message XOR AliceKey XOR BobKey XOR AliceKey XOR BobKey
 *  = Message XOR (AliceKey XOR AliceKey) XOR (BobKey XOR BobKey)
 *  = Message XOR 0 XOR 0
 *  = Message
 *
 * You are a man-in-the-middle, intercepting any message between Alice and Bob.
 * (Btw, your existence proves that they both really had good reasons to put a data cipher process in place...)
 * So, you intercept the 3 messages message1, message2 and message3.
 *
 * Your goal is to be smarter than the smarties, and to break their code.
 *
 * Note: intercepted messages are made of bytes (values from 0 to 255), that will be displayed in hexadecimal form.
 * Thus, each message will be an hexadecimal string of size 2n, each digit pair corresponds to a byte (from 00=0 to FF=255).
 *
 * Once you get the clear message bytes, convert to clear text using ASCII encoding.
 * Input
 * Line 1: message1, the first message Alice sends to Bob (hexadecimal)
 * Line 2: message2, the second message Bob sends back (hexadecimal)
 * Line 3: message3, the last message Alice sends (hexadecimal)
 * Output
 * The clear text message
 * Constraints
 * Message length ≤ 250 chars (i.e. message1, message2 and message3 lengths are ≤ 500 hexadecimal digits)
 * */

import java.util.stream.Collectors;
import java.util.stream.IntStream;

class HackingRobberCity {

    public String process1(String msg1, String msg2, String msg3) {
        // process
        String tmp = xorTwoHexadecimalStr(msg1, msg2); // tmp = msg1 xor msg2 = B
        String resHexStr = xorTwoHexadecimalStr(tmp, msg3); // res = tmp xor msg3 = C
        // output
        return hexDecimal2CharStr(resHexStr);
    }

    private String xorTwoHexadecimalStr(String str1, String str2){
        byte[] byteArr1 = hexStr2ByteArray(str1);
        byte[] byteArr2 = hexStr2ByteArray(str2);
        // XOR between two byte[]
        return IntStream.range(0, byteArr1.length)
                .mapToObj(i -> String.format("%02x", (byte)(byteArr1[i] ^ byteArr2[i]))) // 0xFF -> "FF"
                .collect(Collectors.joining());
    }

    // hexadecimal with base-16: 00=0, FF=255 which uses 0-9 and A-F/a-f to represent value 0-15
    private byte[] hexStr2ByteArray(String hexStr) {
        int len = hexStr.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len-1; i += 2) {
            // e.g "FF" [as 0xFF] -> 15 * 2^4 + 15 = int(255) -> (byte)255 = 0xFF
            data[i/2] = (byte) (
                (Character.digit(hexStr.charAt(i), 16) << 4)
                    + Character.digit(hexStr.charAt(i + 1), 16));
        }
        return data;
    }

    // hexadecimal with base-16: 00=0, FF=255
    private String hexDecimal2CharStr(String hexStr) {
        int len = hexStr.length();
        char[] charArr = new char[len/2];
        for (int i=0; i < len - 1; i += 2) {
            // e.g "41" [as 0x41] -> 4 * 2^4 + 1 = int(65) -> (char)65 = 'A'
            charArr[i/2] = (char)(
                (Character.digit(hexStr.charAt(i), 16) << 4)
                    + Character.digit(hexStr.charAt(i + 1), 16));
        }
        return String.valueOf(charArr);
    }

    // another implementation
    public String process2(String msg1, String msg2, String msg3) {
        String tmp = xor(msg1, msg2);
        return decode(xor(tmp, msg3));
    }

    private String xor(String hexStr1, String hexStr2) {
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < hexStr1.length(); i += 2) {
            int nA = Integer.parseInt(hexStr1.substring(i, i+2), 16);
            int nB = Integer.parseInt(hexStr2.substring(i, i+2), 16);
            String hex = Integer.toHexString(nA ^ nB);
            // ensure 2 digits via padding
            hex = hex.length() == 1 ? "0" + hex : hex;
            builder.append(hex);
        }
        return builder.toString();
    }

    private String decode(String a) {
        StringBuilder out = new StringBuilder();
        for(int i = 0; i < a.length(); i+=2) {
            // "FF" -> 255
            int n = Integer.parseInt(a.substring(i, i+2), 16);
            // ASCII 65 -> "A"
            out.append((char)n);
        }
        return out.toString();
    }
}
// spend 2 hrs
