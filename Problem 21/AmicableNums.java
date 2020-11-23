public class AmicableNums {
    private int num1;
    private int num2;

    public AmicableNums(int num) {
        num1 = num;
        getAmicablePair();
    }

    private void getAmicablePair() {
        int num = sumOfDivisors(num1);
        if (num != num1 && sumOfDivisors(num) == num1) {
            num2 = num;
        } else {
            num2 = 0;
        }
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

    public int getNum1() {
        return num1;
    }

    public int getNum2() {
        return num2;
    }
}
