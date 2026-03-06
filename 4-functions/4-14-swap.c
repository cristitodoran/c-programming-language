#include <stdio.h>
#define printd(x, y) printf(#x " = %d, " #y " = %d\n", (x), (y))
#define swap(t, x, y) \
{ \
  t a = x; \
  x = y; \
  y = a; \
}
#define swap2(t, x, y) t a = x; x = y; y = a;

int main() {
  int x = 1, y = 2;
  printd(x, y);

  swap2(int, x, y);

  printd(x, y);
}
