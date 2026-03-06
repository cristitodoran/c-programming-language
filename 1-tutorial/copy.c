#include <stdio.h>

int main() {
  int c;

  printf("EOF: %c\n", EOF);
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
