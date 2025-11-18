#include <stdio.h>

int bitcount(unsigned x);

int main() {
  int x;

  scanf("%d", &x);
  printf("%b has %d 1 bits\n", x, bitcount(x));
}

int bitcount(unsigned x) {
  int b = 0;

  while (x > 0) {
    b++;
    x &= (x-1);
  }

  return b;
}
