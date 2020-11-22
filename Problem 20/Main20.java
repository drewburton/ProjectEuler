import java.math.BigInteger;

public class Main20 {
    public static void main(String[] args) {
        BigInteger num = factorial(BigInteger.valueOf(100));
        System.out.println(sumOfDigits(num));
    }    

    private static BigInteger factorial(BigInteger num) {
        BigInteger answer = num;
        for (BigInteger i = num.subtract(BigInteger.ONE); i.compareTo(BigInteger.ZERO) == 1; i = i.subtract(BigInteger.ONE)) {
            answer = answer.multiply(i);
        }        
        return answer;
    }

    private static BigInteger sumOfDigits(BigInteger num) {
        BigInteger sum = BigInteger.ZERO;
        for (BigInteger i = num; i.compareTo(BigInteger.ZERO) == 1; i = i.divide(BigInteger.TEN)) {
            sum = sum.add(i.mod(BigInteger.TEN));
        }
        return sum;
    }
}
