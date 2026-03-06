#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
  int i, leap;
  char *p;

  leap = year % 4 == 0 && year%100 != 0 || year % 400 == 0;
  p = *(daytab + leap);
  while (--month) {
    day += *++p;
  }
  return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  char *p;

  leap = year % 4 == 0 && year%100 != 0 || year % 400 == 0;
  p = *(daytab + leap);

  while (yearday > *++p)
    yearday -= *p;

  *pmonth = p - *(daytab + leap);
  *pday = yearday;
}

int main() {
  int month, day;

  printf("day of year for 12-07-2026 is %d\n", day_of_year(2026, 7, 12));
  month_day(2026, 67, &month, &day);
  printf("year: 2026, year day: 67, month: %d, day: %d\n", month, day);
}
