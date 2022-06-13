namespace Problem28
{
    class Program
    {
        private const int _spiralWidth = 1001;

        static void Main(string[] args)
        {
            Console.WriteLine(CalculateSumDiags());
        }

        private static long CalculateSumDiags()
        {
            long sum = 0;
            for (int distanceFromCenter = 0; distanceFromCenter <= _spiralWidth / 2; distanceFromCenter++)
            {
                int boxSize = CalculateBoxSize(distanceFromCenter);
                sum += CalculateDiagsForBoxSize(boxSize);
            }
            return sum;
        }

        private static int _previousTopRight;
        private static long CalculateDiagsForBoxSize(int boxSize)
        {
            if (boxSize == 1)
            {
                _previousTopRight = 1;
                return 1;
            }
            int topRight = boxSize + _previousTopRight;
            // top left = topRight - (sqrt(topRight) - 1)
            // bottom left = topRight - 2(sqrt(topRight) - 1)
            // bottom right = topRight - 3(sqrt(topRight) - 1)
            _previousTopRight = topRight;
            return 4 * topRight - 6 * ((int)Math.Sqrt(topRight) - 1);
        }

        private static int CalculateBoxSize(int distanceFromCenter)
        {
            if (distanceFromCenter == 0) return 1;
            return 8 * distanceFromCenter;
        }
    }
}