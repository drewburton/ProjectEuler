namespace Problem5
{
    class Program
    {
       
        private static int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

        static void Main(string[] args)
        {
            int i = 2520;
            while (!DivisibleByAll(i)) i++;
            Console.WriteLine(i);
        }

        private static bool DivisibleByAll(int n)
        {
            foreach(int num in nums)
            {
                if (n % num != 0) return false;
            }
            return true;
        }
    }
}