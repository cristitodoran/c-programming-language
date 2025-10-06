#include <stdio.h>

#define LOWER  0      /* lower limit of table */
#define UPPER  300    /* upper limit */
#define STEP   20     /* step size */

float ftoc(int f);

/* print Fahrenheit-Celsius table
*  for fahr = 0, 20, ..., 300 */
int main()
{
  int fahr;

  printf("  F      C\n");
  printf("----------\n");
  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    printf("%3d %6.1f\n", fahr, ftoc(fahr));
}

float ftoc(int f) {
  return (5.0 / 9.0) * (f - 32);
}
