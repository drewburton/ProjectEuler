namespace Problem24
{
    class Program
    {
        static void Main(string[] args)
        {
            string current = "0123456789";
            for (int i = 1; i < 1000000; i++)
            {
                current = NextPermutation(current);
            }
            Console.WriteLine(current);
        }

        private static string NextPermutation(string permutation)
        {
            int pivot = GetPivotCharIndex(permutation);
            int ceil = GetCeilCharIndex(permutation, pivot);
            string swapped = SwapChars(permutation, pivot, ceil);
            var endList = swapped[(pivot + 1)..].ToList();
            endList.Sort();
            return swapped[..(pivot + 1)] + new string(endList.ToArray());
        }

        private static int GetPivotCharIndex(string permutation)
        {
            for (int i = permutation.Length - 2; i >= 0; i--)
            {
                if (permutation[i] < permutation[i + 1]) return i;
            }
            return 0;
        }

        private static int GetCeilCharIndex(string permutation, int pivotIndex)
        {
            char minChar = permutation[pivotIndex + 1];
            int minIndex = pivotIndex + 1;
            for (int i = pivotIndex + 2; i < permutation.Length; i++)
            {
                if (permutation[i] < minChar && permutation[i] > permutation[pivotIndex])
                {
                    minChar = permutation[i];
                    minIndex = i;
                }
            }
            return minChar > permutation[pivotIndex] ? minIndex : 0;
        }

        private static string SwapChars(string permutation, int firstIndex, int secondIndex)
        {
            string beforeFirst = permutation[..firstIndex];
            string betweenSwapChars = permutation[(firstIndex + 1)..secondIndex];
            string afterSecond = permutation[(secondIndex + 1)..];

            return beforeFirst + permutation[secondIndex] + betweenSwapChars + permutation[firstIndex] + afterSecond;
        }
    }
}