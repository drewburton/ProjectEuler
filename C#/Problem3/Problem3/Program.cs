namespace Problem3
{
    class Program
    {
        static void Main(string[] args)
        {
            long num = 600851475143;
            //long num = 13195;
            IEnumerable<long> primes = CalculatePrimes(num);
            Console.WriteLine(GetLargestPrimeFactor(num, primes));
        }

        private static IEnumerable<long> CalculatePrimes(long n)
        {
            HashSet<long> sieve = new();
            HashSet<long> primes = new();
            for (long i = 2; i <= Math.Sqrt(n); i++)
            {
                if (sieve.Contains(i)) continue;
                primes.Add(i);
                for (long j = i * i; j <= Math.Sqrt(n); j += i)
                    sieve.Add(j);
            }
            return primes;
        }

        private static long GetLargestPrimeFactor(long n, IEnumerable<long> primes)
        {
            long max = 0;
            foreach (long prime in primes)
            {
                if (n % prime == 0 && prime > max)
                    max = prime;
            }
            return max;
        }
    }
}