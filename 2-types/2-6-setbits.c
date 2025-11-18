#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  unsigned x, y;
  scanf("%d %d", &x, &y);

  printf("\nx=%d - %b\n", x, x);
  printf("y=%d - %b\n", y, y);
  printf("setbits: %b\n", setbits(x, 2, 3, y));
}

// returns x with the n bits that begin at position p
// set to the rightmost n bits of y,
// leaving the other bits unchanged
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned xbits = x & ~(~(~0 << n) << (p + 1 - n));
  unsigned ybits = (y & ~(~0 << n)) << (p + 1 - n);

  return xbits | ybits;
}
