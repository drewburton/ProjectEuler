namespace Problem22
{
    class Program
    {
        static void Main(string[] args)
        {
            string inp = GetInput();
            List<string> names = ParseInput(inp);
            Console.WriteLine(SumNameScores(names));
        }

        private static string GetInput()
        {
            string path = @"C:\Users\aburton2\OneDrive - LCE Corp\Documents\dev\ProjectEuler\Program22\Program22\names.txt";
            return System.IO.File.ReadAllText(path);
        }

        private static List<string> ParseInput(string input)
        {
            List<string> names = input.Split(",").ToList();
            for (int i = 0; i < names.Count; i++)
                names[i] = names[i][1..^1];
            names.Sort();
            return names;
        }

        private static int SumNameScores(List<string> names)
        {
            int sum = 0;
            foreach (string name in names)
            {
                sum += GetNameScore(name) * (names.IndexOf(name) + 1);
            }
            return sum;
        }

        private static int GetNameScore(string name)
        {
            int sumCharScore = 0;
            foreach (char c in name)
            {
                sumCharScore += (int)(c - 'A') + 1;
            }
            return sumCharScore;
        }
    }
}