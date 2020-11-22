import java.math.BigInteger;

public class Main16 {
    public static void main(String[] args) {
        BigInteger num = new BigInteger("2");
        num = num.pow(1000);
        
        BigInteger sum = new BigInteger("0");
        
        while (num.compareTo(new BigInteger("0")) == 1) {
            BigInteger digit = num.mod(new BigInteger("10"));
            num = num.divide(new BigInteger("10"));
            sum = sum.add(digit);
        }
        System.out.println(sum);
    }    
}
