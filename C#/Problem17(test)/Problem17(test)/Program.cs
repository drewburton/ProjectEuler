namespace Problem17
{
    class Program
    {
        private static Dictionary<int, string> map = new Dictionary<int, string> {
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"},
            {6, "six"},
            {7, "seven"},
            {8, "eight"},
            {9, "nine"},
            {10, "ten"},
            {11, "eleven"},
            {12, "twelve"},
            {13, "thirteen"},
            {14, "fourteen"},
            {15, "fifteen"},
            {16, "sixteen"},
            {17, "seventeen"},
            {18, "eighteen"},
            {19, "nineteen"},
            {20, "twenty"},
            {30, "thirty"},
            {40, "forty"},
            {50, "fifty"},
            {60, "sixty"},
            {70, "seventy"},
            {80, "eighty"},
            {90, "ninety"},
            {100, "onehundred"},
            {200, "twohundred"},
            {300, "threehundred"},
            {400, "fourhundred"},
            {500, "fivehundred"},
            {600, "sixhundred"},
            {700, "sevenhundred"},
            {800, "eighthundred"},
            {900, "ninehundred"},
            {1000, "onethousand"}
        };
        static void Main(string[] args)
        {
            addLengths();
        }

        private static void addLengths()
        {
            long lengths = 0;
            for (int i = 101; i < 1000; i++)
            {
                lengths += getLength(i, out string? result, out string? result2);
                if (result2.Length > 0) Console.WriteLine(result + "and" + result2);
                else Console.WriteLine(result);
            }
            System.Console.WriteLine(lengths);
        }

        private static int getLength(int num, out string? result, out string? result2)
        {
            result2 = "";
            if (map.TryGetValue(num, out result)) return result.Length;
            if ((num + "").Length == 3 && map.TryGetValue((num / 100) * 100, out result) && map.TryGetValue(num - ((num / 100) * 100), out result2)) return (result + "and" + result2).Length;
            result2 = "";
            int power = 0;
            result = "";
            while (num > 0)
            {
                int next = (num % 10) * (int)Math.Pow(10, power);
                num /= 10;
                string? temp = "";
                if (next != 0) map.TryGetValue(next, out temp);
                result += temp;
                if (power == 2) result += "and";
                power++;
            }
            return result.Length;
        }

        
    }
}