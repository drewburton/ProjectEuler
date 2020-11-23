import java.util.ArrayList;

public class AbundantNums {
    private ArrayList<Integer> nums;
    
    public AbundantNums() {
        nums = new ArrayList<>();

        System.out.println("getting abundant nums");
        for (int i = 12; i <= 28123; i++) {
           if (sumOfDivisors(i) > i) {
               nums.add(i);
           } 
        }
        System.out.println("finished getting abundant nums");
    }

    private int sumOfDivisors(int num) {
        int sum = 0;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return sum;
    }

    public int size() {
        return nums.size();
    }

    public int get(int index) {
        return nums.get(index);
    }
}
