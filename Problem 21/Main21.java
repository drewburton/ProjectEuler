import java.util.HashMap;

public class Main21 {
    public static void main(String[] args) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int sum = 0;
        for (int i = 1; i < 10000; i++) {
            AmicableNums nums = new AmicableNums(i);
            if (nums.getNum2() != 0 && map.get(nums.getNum2()) == null) {
                map.put(nums.getNum1(), nums.getNum2());
            }
        }

        for (int k : map.keySet()) {
            sum += k + map.get(k);
        }
        System.out.println(sum);
    }   
}
