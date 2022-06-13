namespace Problem19
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime start = new(1901, 1, 1);
            DateTime end = new(2000, 12, 31);
            DateTime now = start;
            int sundays = 0;
            while (DateTime.Compare(now, end) < 0)
            {
                if (now.DayOfWeek == DayOfWeek.Sunday) sundays++;
                now = now.AddMonths(1);
            }
            Console.WriteLine(sundays);
        }
    }
}