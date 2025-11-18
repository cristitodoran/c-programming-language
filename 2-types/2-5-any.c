#include <stdio.h>
#define MAX 10

int any(char s1[], char s2[]);

int main() {
  char s1[MAX], s2[MAX], c;
  int i;

  while ((c = getchar()) != '\n') {
    s1[i++] = c;
  }

  i = 0;

  while ((c = getchar()) != '\n') {
    s2[i++] = c;
  }

  printf("\ns1: %s\n", s1);
  printf("s2: %s\n", s2);

  printf("\nany: %d\n", any(s1, s2));
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}
