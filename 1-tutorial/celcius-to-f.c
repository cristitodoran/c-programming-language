#include <stdio.h>
#define LOWER   0
#define UPPER   300
#define STEP    20

/* print Celsius-Fahrenheit table
     for fahr = 0, 20, ..., 300 */
int main() {
  int celsius;

  printf("%3s %6s\n", "C", "F");
  printf("----------\n");

  for (celsius = UPPER; celsius >= LOWER; celsius -= STEP) {
    printf("%3d %6.1f\n", celsius, celsius / (5.0/9.0) + 32.0);
  }
}
