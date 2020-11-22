import java.io.File;

public class Main18 {
    public static void main(String[] args) {
        Triangle triangle = new Triangle(new File("C:\\development\\Learning\\ProjectEuler\\Problem 18\\Triangle.txt"));
        System.out.println(triangle.sumMaxPath());
    }    
}
