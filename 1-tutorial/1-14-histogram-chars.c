#include <stdio.h>
#define LETTERS 26

int main() {
  int nletter[LETTERS] = {0};
  int i, j, c;

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      nletter[c - 'a']++;
    }
  }

  for (i = 0; i < LETTERS; i++) {
    printf("%c ", 'a' + i);
    for (j = 0; j < nletter[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }
}

