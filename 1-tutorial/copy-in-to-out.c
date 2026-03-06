#include <stdio.h>

int main() {
  char c;
  int isBlank = 0;

  while((c = getchar()) != EOF) {
    if (!isBlank && c == ' ') {
      putchar(c);
      isBlank = 1;
    } else if (isBlank && c != ' ') {
      putchar(c);
      isBlank = 0;
    } else if (!isBlank) {
      putchar(c);
    }
  }
}
