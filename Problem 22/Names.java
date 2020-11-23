import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Names {
    private ArrayList<String> nameStrings;

    public Names(File names) {
        Scanner scanner;
        nameStrings = new ArrayList<>();
        try {
            scanner = new Scanner(names);
            String line = scanner.nextLine();
            line = line.replaceAll("\"", "");
            String[] list = line.split(",");
            nameStrings.addAll(List.of(list));
            Collections.sort(nameStrings);
        } catch (FileNotFoundException e) {
            System.out.println(e);
            return;
        }
    }

    private int getAlphabeticalValue(String name) {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            sum += name.charAt(i) - 'A' + 1;
        }
        return sum;
    }

    private int getNameScore(int i) {
        return getAlphabeticalValue(nameStrings.get(i)) * (i + 1);
    }

    public BigInteger getTotalNameScore() {
        BigInteger sum = BigInteger.ZERO;
        for (int i = 0; i < nameStrings.size(); i++) {
            sum = sum.add(BigInteger.valueOf(getNameScore(i)));
        }
        return sum;
    }
}
