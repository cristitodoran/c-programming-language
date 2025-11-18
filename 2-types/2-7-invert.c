#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
  unsigned x;
  scanf("%d", &x);
  printf("%b inverted 2, 3 is %b\n", x, invert(x, 2, 3));
}

unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}
