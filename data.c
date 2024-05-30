#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int daysInMonth(int month, int year) {
    switch(month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void printCalendar(int year) {
    int month, day, totalDays, startingDay = 0;

    printf("Calendar for year %d:\n\n", year);

    for (month = 1; month <= 12; month++) {
        totalDays = daysInMonth(month, year);
        printf("   ------------%s-------------\n", month == 1 ? "January" : month == 2 ? "February" : month == 3 ? "March" : month == 4 ? "April" : month == 5 ? "May" : month == 6 ? "June" : month == 7 ? "July" : month == 8 ? "August" : month == 9 ? "September" : month == 10 ? "October" : month == 11 ? "November" : "December");
        printf("   Sun Mon Tue Wed Thu Fri Sat\n");

        for (day = 0; day < startingDay; day++)
            printf("    ");

        for (day = 1; day <= totalDays; day++) {
            printf("%4d", day);
            startingDay++;

            if (startingDay % 7 == 0 || day == totalDays)
                printf("\n");
        }

        startingDay = (startingDay + totalDays) % 7;
        printf("\n\n");
    }
}

int main() {
    int year;

    printf("Enter the year: ");
    scanf("%d", &year);

    printCalendar(year);

    return 0;
}

