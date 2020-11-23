public class Main24 {
    public static void main(String[] args) {
        Permutation p = new Permutation("0123456789");
        while (p.nextPermutation() && p.getPermutationCount() < 1000000) {
            continue;
        }
        p.printPermutation();
    }
}