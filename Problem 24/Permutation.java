public class Permutation {
    private String current;
    private int permutationCount;
    
    public Permutation(String permutation) {
        current = permutation;
        permutationCount = 1;
    }

    public boolean nextPermutation() {
        int i;
        for (i = current.length() - 1; i > 0; i--) {
            int currentNum = Integer.parseInt(current.substring(i, i + 1));
            int previousNum = Integer.parseInt(current.substring(i - 1, i));
            if (currentNum > previousNum) {
                break;
            }
        }
        
        if (i == 0) {
            return false;
        }

        int j;
        for (j = current.length() - 1; j > i; j--) {
            int currentNum = Integer.parseInt(current.substring(j, j + 1));
            int pivot = Integer.parseInt(current.substring(i - 1, i));
            if (currentNum > pivot) {
                break;
            }
        }

        char[] string = current.toCharArray();
        char temp = string[i - 1];
        string[i - 1] = string[j];
        string[j] = temp;


        current = new String(string);
        current = current.substring(0, i) + (new StringBuilder(current.substring(i)).reverse()).toString();

        permutationCount++;
        return true;
    }

    public void printPermutation() {
        System.out.println(current);
    }

    public int getPermutationCount() {
        return permutationCount;
    }
}
