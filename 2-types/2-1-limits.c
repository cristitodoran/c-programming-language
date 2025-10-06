#include <limits.h>
#include <float.h>
#include <stdio.h>

long get_limit(long initial_value, long step, long limit);

int main() {
  printf("Char between %d and %d\n", CHAR_MIN, CHAR_MAX);
  printf("Unsigned Char between %d and %d\n", 0, UCHAR_MAX);
  printf("Short between %d and %d\n", SHRT_MIN, SHRT_MAX);
  printf("Unsigned Short between %d and %d\n", 0, USHRT_MAX);
  printf("Int between %d and %d\n", INT_MIN, INT_MAX);
  printf("Unsigned Int between %d and %ld\n", 0, UINT_MAX);
  printf("Long between %ld and %ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned Long between %ld and %lu\n", 0, ULONG_MAX);
  printf("----------------------------------------------------------\n");
  printf("Float between %.10e and %.10e\n", FLT_MIN, FLT_MAX);
  printf("Double between %.10e and %.10e\n", DBL_MIN, DBL_MAX);
  printf("Long Double between %.10e and %.10e\n", LDBL_MIN, LDBL_MAX);
  printf("----------------------------------------------------------\n");

  char c = 0;
  int min_char = 0;
  int max_char = 0;

  for (c = 0; c < 1000; c++) {
    if (c < 0) {
      max_char = --c;
      break;
    }
  }
  for (c = 0; c > -1000; c--) {
    if (c > 0) {
      min_char = ++c;
      break;
    }
  }

  unsigned char uc = 0;
  int max_uchar = 0;

  for (uc = 1; uc < 1000; uc++) {
    if (uc == 0) {
      max_uchar = --uc;
      break;
    }
  }
  printf("Char between %d and %d\n", min_char, max_char);
  printf("Unsigned Char between %d and %d\n", 0, max_uchar);
}
