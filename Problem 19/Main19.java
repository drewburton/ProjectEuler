import java.time.DayOfWeek;
import java.time.LocalDate;

public class Main19 {
    /*
    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

    How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)
    */

    public static void main(String[] args) {
        LocalDate date = LocalDate.of(1901, 1, 1);
        int sundayCount = 0;
        while (date.isBefore(LocalDate.of(2001, 1, 1))) {
            date = date.plusMonths(1);
            if (date.getDayOfWeek() == DayOfWeek.SUNDAY) {
                sundayCount++;
            }
        }
        System.out.println(sundayCount);
    }
}
