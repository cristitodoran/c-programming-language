#include <stdio.h>
#define MAX 1000

int any(char s1[], char s2[]);
int main() {
  char s1[MAX] = "acum ori niciodata";
  char s2[MAX] = "zzzx";

  printf("any s1: %s with s2: %s is: %d\n", s1, s2, any(s1, s2));
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
