namespace Problem27
{
    class Program
    {
        private const int _PRIMES = 1_000_000;
        private static HashSet<int> primes = new();

        static void Main(string[] args)
        {
            GeneratePrimes(_PRIMES);
            (long, long) coefficients = GetLongestConsecutivePrimesCoefficients();
            Console.WriteLine(coefficients.Item1 * coefficients.Item2);
        }

        private static void GeneratePrimes(int n)
        {
            HashSet<int> nonPrimes = new();
            for (int i = 2; i < n; i++)
            {
                if (nonPrimes.Contains(i)) continue;
                primes.Add(i);
                for (int j = i * i; j <= n; j += i)
                {
                    nonPrimes.Add(j);
                }
            }
        }

        private static (int, int) GetLongestConsecutivePrimesCoefficients()
        {
            int maxA = 0;
            int maxB = 0;
            int maxConsecutive = 0;
            for (int a = -999; a < 1000; a++)
            {
                for (int b = -999; b < 1000; b++)
                {
                    if (a % 2 == 0) continue;
                    if (!primes.Contains(b)) continue;
                    int consecutive = ConsecutivePrimes(a, b);
                    if (consecutive > maxConsecutive)
                    {
                        maxConsecutive = consecutive;
                        maxA = a;
                        maxB = b;
                    }
                }
            }
            return (maxA, maxB);
        }

        private static int ConsecutivePrimes(int a, int b)
        {
            int consecutive = 0;
            for (int n = 0; n < b; n++)
            {
                if (!primes.Contains(GetQuadraticValue(n, a, b))) 
                    return consecutive;
                consecutive++;
            }
            return consecutive;
        }

        private static int GetQuadraticValue(int n, int a, int b)
        {
            return (n * n) + (a * n) + b;
        }
    }
}