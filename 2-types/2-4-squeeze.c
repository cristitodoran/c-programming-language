#include <stdio.h>
#define MAX 1000

void squeeze(char s1[], char s2[]);
int main() {
  char s1[MAX] = "acum ori niciodata";
  char s2[MAX] = "abcd";

  printf("squeeze s1: %s with s2: %s\n", s1, s2);
  squeeze(s1, s2);
  printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;
  int found = 0;

  for (i = k = 0; s1[i] != '\0'; i++) {
    found = 0;
    for (j = 0; s2[j] != '\0'; j++) {
      found = found || s1[i] == s2[j];
    }
    if (!found) {
      s1[k++] = s1[i];
    }
  }
  s1[k] = '\0';
}
