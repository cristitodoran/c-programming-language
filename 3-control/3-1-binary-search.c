#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int v[] = {1,2,5,4,6};
  printf("found (%d) at: %d\n", 5, binsearch(5, v, 5));
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while (low <= high && v[mid] != x) {
    printf("%d %d %d %d\n", low, high, mid, v[mid]);
    if (x <= v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low + high) / 2;
  }

  if (v[mid] == x)
    return mid;
  return -1;
}
