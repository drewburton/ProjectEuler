import java.io.File;

public class Main22 {
    public static void main(String[] args) {
        Names names = new Names(new File("C:\\development\\Learning\\ProjectEuler\\Problem 22\\names.txt"));
        System.out.println(names.getTotalNameScore());
    }    
}
