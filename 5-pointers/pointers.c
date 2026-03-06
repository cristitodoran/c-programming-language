#include <stdio.h>

void swap(int *px, int *py);

int main() {
  int x = 1, y = 2, z[10];
  int *ip;

  ip = &z[0];
  ip = &x;
  y = *ip;
  *ip = 0;

  *ip = *ip + 10;
  y = *ip + 1;
  *ip += 1;
  ++*ip;
  (*ip)++;

  int *iq = ip;

  swap(&x, &y);

  printf("x = %d, y = %d, *ip = %d, *iq = %d\n", x, y, *ip, *iq);
}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
