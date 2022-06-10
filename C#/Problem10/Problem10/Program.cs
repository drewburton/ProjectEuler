using System.Numerics;

namespace Problem10
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(SumPrimes(2_000_000));
        }

        private static long SumPrimes(int n)
        {
            HashSet<int> sieve = new();
            long primeSum = 0;
            for (int i = 2; i <= n; i++)
            {
                if (!sieve.Contains(i))
                {
                    primeSum += i;
                    for (int j = i * 2; j <= n; j += i)
                        sieve.Add(j);
                }
            }
            return primeSum;
        }
    }
}