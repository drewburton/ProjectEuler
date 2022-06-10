namespace Problem18
{
    class Program
    {
        static  void Main(string[] args)
        {
            InitializeTriangle(out int[][] triangle);
            int maximalSum = CalculateMaximalSum(triangle);
            PrintArray(triangle);
            Console.WriteLine(maximalSum);
        }

        private static void InitializeTriangle(out int[][] triangle)
        {
            //string path = @"C:\Users\aburton2\OneDrive - LCE Corp\Documents\dev\ProjectEuler\Problem18\Problem18\input.txt";
            //string path = @"C:\Users\aburton2\OneDrive - LCE Corp\Documents\dev\ProjectEuler\Problem18\Problem18\test.txt";
            string path = @"C:\Users\aburton2\OneDrive - LCE Corp\Documents\dev\ProjectEuler\Problem18\Problem18\input67.txt";
            string[] lines = System.IO.File.ReadAllLines(path);

            triangle = new int[lines.Length][];
            int i = 0;
            foreach (string line in lines)
            {
                triangle[i] = line.Split(" ").Select(int.Parse).ToArray();
                i++;
            }
        }

        private static int CalculateMaximalSum(int[][] triangle)
        {
            //scan the triangle row by row
            //add the max from each comparison to the above value in the triangle
            //at the end the largest value in the first row will be the maximal sum
            for (int r = triangle.Length - 1; r > 0; r--)
            {
                for (int c = 0; c < triangle[r].Length - 1; c++)
                {
                    int max = Math.Max(triangle[r][c], triangle[r][c + 1]);
                    triangle[r - 1][c] += max;
                }
            }
            return triangle[0][0];
        }

        private static void PrintArray(int[][] triangle)
        {
            for (int r = 0; r < triangle.Length; r++)
            {
                for (int c = 0; c < triangle[r].Length; c++)
                {
                    Console.Write(triangle[r][c] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}