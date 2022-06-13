namespace Problem30
{
    class Program
    {
        private const int _limit = 354294; // 6 * (9^5)
        private static readonly List<int> digitFifthPowers = new();

        static void Main(string[] args)
        {
            Console.WriteLine(SumDigitFifthPowers());
        }

        private static long SumDigitFifthPowers()
        {
            for (int i = 2; i < _limit; i++)
            {
                if (CanBeWrittenAsSumOfFifthPowersOfDigits(i))
                    digitFifthPowers.Add(i);
            }
            return digitFifthPowers.Sum();
        }

        private static bool CanBeWrittenAsSumOfFifthPowersOfDigits(int num)
        {
            int sum = 0;
            int n = num;
            while (n > 0)
            {
                sum += (int) Math.Pow(n % 10, 5);
                n /= 10;
            }
            return sum == num;
        }
    }
}