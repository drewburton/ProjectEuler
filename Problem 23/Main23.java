import java.util.HashSet;

import javax.xml.namespace.QName;

public class Main23 {
    public static void main(String[] args) {
        AbundantNums nums = new AbundantNums();
        HashSet<Integer> sums = new HashSet<>();
        System.out.println("creating set");
        for (int numsIndex = 0; numsIndex < nums.size(); numsIndex++) {
            for (int numsIndex2 = 0; numsIndex2 < nums.size(); numsIndex2++) {
                sums.add(nums.get(numsIndex) + nums.get(numsIndex2));
            }
        }
    
        System.out.println("adding set");
        int sum = 0;
        for (int i = 1; i < 28123; i++) {
            if (!sums.contains(i)) {
                sum += i;
            }
        }
        System.out.println(sum);
    }    
}
