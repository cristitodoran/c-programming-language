#include <stdio.h>
#define LOWER   0
#define UPPER   300
#define STEP    20

/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300 */

float ftoc(int fahr);

int main() {
  int fahr;

  printf("%3s %6s\n", "F", "C");
  printf("----------\n");

  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%3d %6.1f\n", fahr, ftoc(fahr));
  }
}

float ftoc(int fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}
