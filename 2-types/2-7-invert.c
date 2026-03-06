#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main() {
  unsigned int x;
  int p, n;

  puts("Input params x p n:");
  scanf("%u %d %d", &x, &p, &n);
  printf("x (%u): %b\n", x, x);
  unsigned int inverted = invert(x, p, n);
  printf("inverted (%u): %b\n", inverted, inverted);
}

unsigned int invert(unsigned int x, int p, int n) {
  unsigned int mask = (~(~0 << n)) << (p - n + 1);
  printf("mask: %b\n", mask);
  return x ^ mask;
}
