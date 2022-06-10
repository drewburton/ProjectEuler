namespace Problem8
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = GetInput();
            Console.WriteLine(MaxProduct(input, 13));
        }

        private static string GetInput()
        {
            string path = @"C:\Users\aburton2\source\repos\Problem8\Problem8\input.txt";
            string[] unparsed = System.IO.File.ReadAllLines(path);
            string input = "";
            foreach (string s in unparsed)
            {
                input += s;
            }
            return input;
        }

        private static long SliceProduct(string input, int startInclusive, int endExclusive)
        {
            long prod = 1;
            for (int i = startInclusive; i < endExclusive; i++)
            {
                prod *= input[i] - '0';
            }
            return prod;
        }

        private static long MaxProduct(string input, int length)
        {
            long max = 0;
            for (int i = 0; i < input.Length - length; i++)
            {
                max = Math.Max(SliceProduct(input, i, i + length), max);
            }
            return max;
        }
    }
}