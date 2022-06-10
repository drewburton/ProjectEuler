using System.Numerics;

namespace Problem16
{
    class Program {

        private static List<int> result = new List<int>();
        static void Main(string[] args) {
            Console.WriteLine("Enter the power: ");
            int power = int.Parse(Console.ReadLine());
            BigInteger num = BigInteger.Pow(2, power);
            int sum = 0;
            while (num > 0) {
                int digit = (int)(num % 10);
                sum += digit;
                num /= 10;
            }
            Console.WriteLine(sum);
        }
    }
}