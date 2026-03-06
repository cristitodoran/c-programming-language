#include <stdio.h>
#define forever for (;;)
#define max(A, B) ((A) > (B) ? (A) : (B))
#define square(x) ((x) * (x))
#undef getchar
#define dprint(expr) printf(#expr " = %d\n", expr)
#define paste(front, back) front ## back

int main() {
  int x, p = 1, q = 2, r = 3, s = 4, x1 = 10;
  x = max(p+q, r+s);

  printf("x: %d\n", x);
  dprint(x + p);
  paste(x, 1) = 20;
  dprint(paste(x, 1));
  dprint(x1);
}
