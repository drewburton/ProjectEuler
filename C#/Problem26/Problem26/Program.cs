namespace Problem26
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GetLongestReciprocalCycle());
        }

        private static int GetLongestReciprocalCycle()
        {
            int denominator = 0;
            int maxCycleLength = 0;
            for (int d = 2; d < 1000; d++)
            {
                int cycleLength = GetReciprocalCycleLength(d);
                if (cycleLength > maxCycleLength)
                {
                    maxCycleLength = cycleLength;
                    denominator = d;
                }
            }
            return denominator;
        }

        private static int GetReciprocalCycleLength(int denominator)
        {
            Dictionary<int, int> map = new Dictionary<int, int>();
            int remainder = 1; // because we are doing 1 / d, the starting division is always 1
            int index = 1; // keeps track of the current position of long division we are in
            while (!map.ContainsKey(remainder)) 
            {
                map.Add(remainder, index); // store where we found this remainder
                remainder = remainder * 10 % denominator; // find the next remainder in long division
                index++;
            }
            map.TryGetValue(remainder, out int initalIndex);
            return index - initalIndex; // where we are - where we first found the same value
        }
    }
}