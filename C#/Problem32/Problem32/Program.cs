namespace Problem32
{
    class Program
    {
        private const int PANDIGIAL_LENGTH = 9;

        static void Main(string[] args)
        {
            Console.WriteLine(GetPandigitalProducts().Sum());
        }

        private static HashSet<long> GetPandigitalProducts()
        {
            HashSet<long> products = new();
            for (long a = 1; a < 9999; a++)
            {
                for (long b = a + 1; b < 9999; b++)
                {
                    long product = a * b;
                    if (IsPandigital(a, b, product)) products.Add(product);
                }
            }
            return products;
        }

        private static bool IsPandigital(long multiplicand, long multiplier, long product)
        {
            string combined = $"{multiplicand}{multiplier}{product}";
            return combined.Length == PANDIGIAL_LENGTH && 
                combined.Distinct().AsEnumerable().Count() == PANDIGIAL_LENGTH &&
                !combined.Contains('0');
        }
    }
}