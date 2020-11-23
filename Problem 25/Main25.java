public class Main25 {
    public static void main(String[] args) {
        Fibonacci f = new Fibonacci();
        while (f.getNum().length() < 1000) {
            f.next();
        }
        System.out.println(f.getIndex());
    }    
}
