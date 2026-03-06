#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
  unsigned int x;
  int n;

  puts("input params x n:");
  scanf("%u %d", &x, &n);
  printf("x (%u): %b\n", x, x);
  printf("x rotated right by %d bits (%d): %b\n", n, rightrot(x, n), rightrot(x, n));
}

unsigned int rightrot(unsigned int x, int n) {
  int i = 0;
  unsigned int bit = 0;

  for (i = 0; i < n; i++) {
    bit = (x << (sizeof(unsigned int) - 1)) & (1 << (sizeof(unsigned int) - 1));
    printf("bit: %b\n", bit);
    x = (x >> 1) | bit;
  }
  return x;
}

