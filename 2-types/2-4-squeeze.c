#include <stdio.h>
#define MAX 10

void squeeze(char s1[], char s2[]);

int main() {
  char s1[MAX], s2[MAX], c;
  int i = 0;

  while ((c = getchar()) != '\n') {
    s1[i++] = c;
  }

  i = 0;

  while ((c = getchar()) != '\n') {
    s2[i++] = c;
  }

  printf("\ns1: %s\n", s1);
  printf("\ns2: %s\n", s2);

  squeeze(s1, s2);

  printf("\nsqueezed s1: %s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;
  bool exists = false;

  for (i = j = 0; s1[i] != '\0'; i++) {
    for (exists = false, k = 0; s2[k] != '\0'; k++) {
      if (s1[i] == s2[k]) {
        exists = true;
        break;
      }
    }
    if (!exists) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}
