using System.Numerics;

namespace Problem29
{
    class Program
    {
        static void Main(string[] args)
        {
            int limit = 100;
            Console.WriteLine(GenerateTerms(limit).Count);
        }

        private static HashSet<BigInteger> GenerateTerms(int limit)
        {
            HashSet<BigInteger> terms = new();
            for (int a = 2; a <= limit; a++)
            {
                for (int b = 2; b <= limit; b++)
                {
                    terms.Add(BigInteger.Pow(a, b));
                }
            }
            return terms;
        }
    }
}