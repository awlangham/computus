#include <stdio.h>

typedef struct monthDates {
    int month;
    int date;
} monthDate;

monthDate getMonthDate(int year)
{
    // Anonymous Gregorian algorithm
    int a = year % 19;
    int b = year/100;
    int c = year % 100;
    int d = b/4;
    int e = b % 4;
    int f = (b + 8)/25;
    int g = (b - f + 1)/3;
    int h = (19*a + b - d - g + 15) % 30;
    int i = c/4;
    int k = c % 4;
    int l = (32 + 2*e + 2*i - h - k) % 7;
    int m = (a + 11*h + 22*l)/451;

    int month = (h + l - 7*m + 114)/31;
    int date = ((h + l - 7*m + 114) % 31) + 1;

    monthDate easter = {month, date};
    return easter;
}

int main()
{
    int inYear = 1583;
    printf("Please enter a year: ");
    scanf("%d", &inYear);

    monthDate outEaster = getMonthDate(inYear);
    printf("Easter will be on %02d/%02d/%04d.\n", outEaster.month, outEaster.date, inYear);
    printf("----------------\n");
    printf("Next 5 years:\n");
    for (int i = 1; i <= 5; ++i) {
        outEaster = getMonthDate(inYear + i);
        printf("%02d/%02d/%04d\n", outEaster.month, outEaster.date, inYear + i);
    }

    return 0;
}
