using System.Numerics;

namespace Problem20
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger val = BigInteger.Parse("100");
            for (BigInteger i = BigInteger.Parse("99"); i > BigInteger.Zero; i--)
            {
                val *= i;
            }
            int sum = 0;
            string numStr = val.ToString();
            foreach (char c in numStr)
            {
                sum += int.Parse(c + "");
            }
            Console.WriteLine(sum);
        }
    }
}