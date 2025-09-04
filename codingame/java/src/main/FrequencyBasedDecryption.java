import java.util.HashMap;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class FrequencyBasedDecryption {
    private HashMap<Character, Float> engLetterFreq = new HashMap<>();

    public FrequencyBasedDecryption () {
        engLetterFreq.put('A', 8.08f);
        engLetterFreq.put('B', 1.67f);
        engLetterFreq.put('C', 3.18f);
        engLetterFreq.put('D', 3.99f);
        engLetterFreq.put('E', 12.56f);
        engLetterFreq.put('F', 2.17f);
        engLetterFreq.put('G', 1.80f);
        engLetterFreq.put('H', 5.27f);
        engLetterFreq.put('I', 7.24f);
        engLetterFreq.put('J', 0.14f);
        engLetterFreq.put('K', 0.63f);
        engLetterFreq.put('L', 4.04f);
        engLetterFreq.put('M', 2.60f);
        engLetterFreq.put('N', 7.38f);
        engLetterFreq.put('O', 7.47f);
        engLetterFreq.put('P', 1.91f);
        engLetterFreq.put('Q', 0.09f);
        engLetterFreq.put('R', 6.42f);
        engLetterFreq.put('S', 6.59f);
        engLetterFreq.put('T', 9.15f);
        engLetterFreq.put('U', 2.79f);
        engLetterFreq.put('V', 1.00f);
        engLetterFreq.put('W', 1.89f);
        engLetterFreq.put('X', 0.21f);
        engLetterFreq.put('Y', 1.65f);
        engLetterFreq.put('Z', 0.07f);
    }

    public float getLetterFreqWeight(char ch) {
        return Character.isLetter(ch) ? engLetterFreq.get(Character.toUpperCase(ch)) : 0.0f;
    }

    private char shiftChar(char ch, int n, boolean isLower) {
        if (!Character.isLetter(ch))    return ch;
        while (n < 0) {
            n += 26;
        }
        char res = (char)('A' + (Character.toUpperCase(ch) - 'A' + n) % 26);
        return isLower ? Character.toLowerCase(res) : res;
    }

    private int findBestShift(String srcStr) {
        double maxScore = 0.0f;
        int delta = -1;
        for (int d = 0; d < 26; d++) {
            final int n = -d; // local var referenced from a lambda expression must be effectively final
            double score = IntStream.range(0, srcStr.length())
                        .mapToObj(i -> getLetterFreqWeight(shiftChar(srcStr.charAt(i), n, false)))
                        .collect(Collectors.summingDouble(x -> x));
            if (score > maxScore) {
                maxScore = score;
                delta = d;
            }
        }
        return delta;
    }

    // entry method
    public String decrypStrByFreq(String srcStr) {
        final int delta = findBestShift(srcStr);
        return IntStream.range(0, srcStr.length())
                .mapToObj(i -> String.valueOf(shiftChar(srcStr.charAt(i), -delta, Character.isLowerCase(srcStr.charAt(i)))))
                .collect(Collectors.joining());
    }
}