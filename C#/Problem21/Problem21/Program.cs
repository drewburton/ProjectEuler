namespace Problem21
{
    class Program
    {
        private static Dictionary<int, HashSet<int>> map;

        static void Main(string[] args)
        {
            map = new Dictionary<int, HashSet<int>>();
            map.Add(1, new HashSet<int>());
            Console.WriteLine(SumAmicable());        
        }

        private static int SumAmicable()
        {
            int sum = 0;
            for (int a = 2; a < 9999; a++)
            {
                for (int b = a + 1; b < 10000; b++)
                {
                    if (IsAmicable(a, b)) 
                        sum += (a + b); 
                }
            }
            return sum;
        }

        private static bool IsAmicable(int a, int b)
        {
            return SumDivisors(a) == b && SumDivisors(b) == a;
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
    }
}