import java.util.HashMap;

public class NumberWordConverter {
    private HashMap<Integer, String> ones;
    private HashMap<Integer, String> tens;
    private HashMap<Integer, String> hundreds;

    public NumberWordConverter() {
        ones = new HashMap<>();
        ones.put(0, "");
        ones.put(1, "one");
        ones.put(2, "two");
        ones.put(3, "three");
        ones.put(4, "four");
        ones.put(5, "five");
        ones.put(6, "six");
        ones.put(7, "seven");
        ones.put(8, "eight");
        ones.put(9, "nine");

        tens = new HashMap<>();
        tens.put(0, "");
        tens.put(10, "ten");
        tens.put(11, "eleven");
        tens.put(12, "twelve");
        tens.put(13, "thirteen");
        tens.put(14, "fourteen");
        tens.put(15, "fifteen");
        tens.put(16, "sixteen");
        tens.put(17, "seventeen");
        tens.put(18, "eighteen");
        tens.put(19, "nineteen");
        tens.put(20, "twenty");
        tens.put(30, "thirty");
        tens.put(40, "forty");
        tens.put(50, "fifty");
        tens.put(60, "sixty");
        tens.put(70, "seventy");
        tens.put(80, "eighty");
        tens.put(90, "ninety");

        hundreds = new HashMap<>();
        hundreds.put(100, "onehundred");
        hundreds.put(200, "twohundred");
        hundreds.put(300, "threehundred");
        hundreds.put(400, "fourhundred");
        hundreds.put(500, "fivehundred");
        hundreds.put(600, "sixhundred");
        hundreds.put(700, "sevenhundred");
        hundreds.put(800, "eighthundred");
        hundreds.put(900, "ninehundred");
    }

    public String getWord(int num) {
        int[] digits = getDigits(num);
        if (ones.get(num) != null) {
            return ones.get(num);
        } else if (tens.get(num) != null) {
            return tens.get(num);
        } else if (hundreds.get(num) != null) {
            return hundreds.get(num);
        } else if (digits.length == 2) {
            return tens.get(digits[0] * 10) + ones.get(digits[1]);
        } else if (digits.length == 3) {
            return hundreds.get(digits[0] * 100) +
                    "and" +
                    getWord(digits[1] * 10 + digits[2]);
        }
        return "onethousand";
    }

    private int[] getDigits(int num) {
        int[] digits = new int[(num + "").length()];
        for (int i = (num + "").length() - 1; i >= 0; i--) {
            digits[i] = num % 10;
            num /= 10;
        }
        return digits;
    }
}