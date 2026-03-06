#include <stdio.h>

int lower(int c);

int main() {
  printf("Converting %c to lowercase gives %c\n", 'B', lower('B'));
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? 'a' + (c - 'A') : c;
}
