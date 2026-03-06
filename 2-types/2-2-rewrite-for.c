#include <stdio.h>
#define MAXLINE 1000

int main() {
  int i, lim = MAXLINE + 1;
  char c;
  char line[MAXLINE];

  for (i = 0; i < lim; i++) {
    if ((c = getchar()) != EOF) {
      if (c != '\n') {
        line[i] = c;
        continue;
      }
    }
    break;
  }
  line[i] = '\0';

  printf("%s\n", line);
}
