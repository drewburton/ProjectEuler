namespace Problem7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GetPrime(10001)); 
        }

        private static int GetPrime(int n)
        {
            HashSet<int> sieve = new();
            HashSet<int> primes = new();
            int i = 2;
            while (primes.Count < n)
            {
                if (!sieve.Contains(i))
                {
                    primes.Add(i);
                    for (int j = i * i; j < 1000000; j += i)
                        sieve.Add(j);
                }
                i++;
            }
            return primes.LastOrDefault();
        }
    }
}