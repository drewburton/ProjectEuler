namespace Problem23
{
    class Program
    {
        private static Dictionary<int, HashSet<int>> map;
        private static HashSet<int> abundantNumbers;

        static void Main(string[] args)
        {
            map = new Dictionary<int, HashSet<int>>();
            map.Add(1, new HashSet<int>());
            abundantNumbers = new HashSet<int>();

            Console.WriteLine("Calculating abundant numbers");
            CalculateAbundantNumbers();

            Console.WriteLine("Calculating sum of numbers that can't be written as the sum of two abundant");
            Console.WriteLine(SumNonSumOfAbundant());
        }

        private static int SumDivisors(int n)
        {
            return GetDivisors(n).Sum();
        }

        private static HashSet<int> GetDivisors(int n)
        {
            if (map.ContainsKey(n))
            {
                map.TryGetValue(n, out HashSet<int>? result);
                return result;
            }
            HashSet<int> divisors = new HashSet<int> { 1 };
            for (int d = 2; d <= n / 2; d++)
            {
                if (divisors.Contains(d)) continue;
                else if (map.ContainsKey(d) && n % d == 0)
                {
                    map.TryGetValue(d, out HashSet<int>? result);
                    divisors.UnionWith(result);
                    divisors.Add(d);
                    continue;
                }
                else if (n % d == 0)
                {
                    divisors.Add(n / d);
                    divisors.Add(d);
                }
            }
            map.Add(n, divisors);
            return divisors;
        }

        private static void CalculateAbundantNumbers()
        {
            for (int i = 12; i < 28123; i++)
            {
                int sum = SumDivisors(i);
                if (sum > i)
                    abundantNumbers.Add(i);
            }
        }

        private static int SumNonSumOfAbundant()
        {
            int sum = 0;
            for (int i = 1; i < 28123; i++)
            {
                if (!IsSumOfAbundant(i)) sum += i;
            }
            return sum;
        }

        private static bool IsSumOfAbundant(int n)
        {
            var filtered = abundantNumbers.Where(a => a < n).ToList();
            foreach (int element in filtered)
            {
                if (abundantNumbers.Contains(n - element))
                    return true;
            }
            return false;
        }
    }
}