#include <stdio.h>

/* print Celsius-Fahrenheit table
*  for celsius = 0, 20, ..., 300 */
int main()
{
  float celsius, fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("  C      F\n");
  printf("----------\n");
  while (celsius <= upper)
  {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
