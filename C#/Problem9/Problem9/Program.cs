namespace Problem9
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int a = 0; a < 1000; a++)
            {
                for (int b = a + 1; b < 1000; b++)
                {
                    double c = Math.Sqrt(a * a + b * b);
                    if (a + b + c == 1000) Console.WriteLine(a * b * c); 
                }
            }
        }

        private static bool IsTriplet(int a, int b, int c)
        {
            return a < b && 
                b < c && 
                (a * a + b * b) == c * c;
        }
    }
}