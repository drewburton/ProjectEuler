using System.Numerics;

namespace Problem25
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger previous = BigInteger.One;
            BigInteger current = previous + BigInteger.One;
            int index = 3;
            while (current.ToString().Length < 1000)
            {
                BigInteger temp = current;
                current = NextFibonacci(previous, current);
                previous = temp;
                index++;
            }
            Console.WriteLine(index);
        }
        
        private static BigInteger NextFibonacci(BigInteger minusOne, BigInteger minusTwo)
        {
            return minusOne + minusTwo;
        }
    }
}