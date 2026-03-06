#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int wl = 0, i = 0;
  int state = OUT;
  char c;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      for (i = 0; i < wl; i++) {
        putchar('-');
      }
      putchar('\n');
      wl = 0;
    }
    else if (state == OUT) {
      state = IN;
      ++wl;
    } else if (state = IN) {
      ++wl;
    }
  }
}
