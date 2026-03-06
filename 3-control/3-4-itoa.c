#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  int n = 0;
  char s[MAXLINE];
  printf("INT_MIN: %d\n", INT_MIN);

  puts("n: ");
  scanf("%d", &n);
  itoa(n, s);
  printf("\nn in char is: %s\n", s);
}

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;

  do {
    s[i++] = (n % 10 < 0 ? -(n % 10) : n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i], s[i] = s[j], s[j] = c;
  }
}
