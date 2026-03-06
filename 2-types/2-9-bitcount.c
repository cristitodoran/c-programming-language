#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned int x;

  puts("input x:");
  scanf("%u", &x);

  printf("x (%u): %b has 1 bits: %d\n", x, x, bitcount(x));
}

int bitcount(unsigned x) {
  int b = 0;

  while (x > 0) {
    x &= (x - 1);
    b++;
  }

  return b;
}
