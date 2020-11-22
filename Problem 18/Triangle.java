import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Triangle {
    ArrayList<ArrayList<Integer>> triangleList;

    public Triangle(File triangleFile) {
        Scanner scanner;
        try {
            scanner = new Scanner(triangleFile);
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
            return;
        }
        String triangle = "";

        while (scanner.hasNextLine()) {
            triangle += scanner.nextLine() + "\n";
        }

        triangleList = new ArrayList<>();
        String[] rows = triangle.split("\n");
        for (int rowIndex = 0; rowIndex < rows.length; rowIndex++) {
            triangleList.add(new ArrayList<>());
            String[] nums = rows[rowIndex].split(" ");
            for (int numIndex = 0; numIndex < nums.length; numIndex++) {
                triangleList.get(rowIndex).add(Integer.parseInt(nums[numIndex]));
            }
        }
    }

    public void printTriangle() {
        for (int rowIndex = 0; rowIndex < triangleList.size(); rowIndex++) {
            for (int numIndex = 0; numIndex < triangleList.get(rowIndex).size(); numIndex++) {
                System.out.print(triangleList.get(rowIndex).get(numIndex) + " ");
            }
            System.out.println();
        }
    }

    public int sumMaxPath() {
        for (int rowIndex = triangleList.size() - 2; rowIndex >= 0; rowIndex--) {
            ArrayList<Integer> row = triangleList.get(rowIndex);
            for (int numIndex = 0; numIndex < triangleList.get(rowIndex).size(); numIndex++) {
                int num = triangleList.get(rowIndex).get(numIndex);
                int leftChild = triangleList.get(rowIndex + 1).get(numIndex);
                int rightChild = triangleList.get(rowIndex + 1).get(numIndex + 1);
                row.set(numIndex, Math.max(num + leftChild, num + rightChild));
            }
            triangleList.set(rowIndex, (ArrayList<Integer>) row.clone());
        }
        return triangleList.get(0).get(0);
    }
}
