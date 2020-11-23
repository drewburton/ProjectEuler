import java.math.BigInteger;

public class Fibonacci {
    private BigInteger fn1 = BigInteger.ONE;
    private BigInteger fn2 = BigInteger.ONE;    
    private BigInteger current = BigInteger.TWO;
    private int n = 3;

    public Fibonacci() {

    }

    public void next() {
        fn1 = fn2;
        fn2 = current;
        current = fn1.add(fn2);
        n++;
    }

    public String getNum() {
        return current.toString();
    }

    public int getIndex() {
        return n;
    }
}
