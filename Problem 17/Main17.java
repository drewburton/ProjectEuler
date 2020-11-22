
public class Main17 {
    public static void main(String[] args) {
        NumberWordConverter converter = new NumberWordConverter();
        long letterCount = 0;
        for (int i = 1; i <= 1000; i++) {
            letterCount += converter.getWord(i).length();
        }
        System.out.println(letterCount);
    }    
}
