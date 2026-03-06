#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char s[]);

int main() {
  char s[MAXLINE];

  puts("s: ");
  scanf("%s", &s);
  reverse(s);
  printf("\nreversed: %s\n", s);
  puts("s: ");
  scanf("%s", &s);
  reverse(s);
  printf("\nreversed: %s\n", s);
}

void reverse(char s[]) {
  static int i = 0, j = 0;
  int c;

  if (s[j] != '\0') {
    j++;
    reverse(s);
  }
  if (i < j) {
    c = s[i], s[i] = s[j-1], s[j-1] = c;
    i++;
    j--;
  }
}
