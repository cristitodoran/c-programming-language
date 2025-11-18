#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
  unsigned x;

  scanf("%d", &x);
  printf("%b rotated to right by 3 is %b\n", x,rightrot(x, 3));
}

unsigned rightrot(unsigned x, int n) {
  unsigned endbits = x & ~(~0 << n);
  int bits = 0;
  int y = x;

  do {
    bits++;
  }
  while (y = y >> 1);

  return (endbits << (bits - n)) | (x >> n);
}
