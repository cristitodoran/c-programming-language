#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
  unsigned int x, y;
  int p, n;

  puts("Input parameters x, p, n, y:");
  scanf("%d %d %d %d", &x, &p, &n, &y);
  printf("x (%d): %b\n", x, x);
  printf("y (%d): %b\n", y, y);
  unsigned int result = setbits(x, p, n, y);
  printf("setbits (%d): %b\n", result, result);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y){
  int lastNBits = y & ~(~0 << n);
  int pBits = lastNBits << (p - n + 1);
  int cleared = ~((~(~0 << n)) << (p - n + 1));
  x = x & cleared;
  int result = x | pBits;

  return result;
}
