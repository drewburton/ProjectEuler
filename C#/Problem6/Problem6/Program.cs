using System.Numerics;

namespace Problem6
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 100;
            Console.WriteLine(SumSquares(n) - SquareSum(n));
        }

        private static BigInteger SumSquares(int n)
        {
            BigInteger sum = BigInteger.Zero;
            for (BigInteger i = BigInteger.One; i <= n; i++)
            {
                sum += BigInteger.Pow(i, 2);
            }
            return sum;
        }

        private static BigInteger SquareSum(int n)
        {
            int sum = ((n + 1) * n) / 2;
            return BigInteger.Pow(sum, 2);
        }
    }
}