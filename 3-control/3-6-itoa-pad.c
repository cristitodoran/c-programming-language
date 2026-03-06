#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXLINE 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
  int n = 0;
  int w = 0;
  char s[MAXLINE];
  printf("INT_MIN: %d\n", INT_MIN);

  puts("n: ");
  scanf("%d", &n);
  puts("width: ");
  scanf("%d", &w);
  itoa(n, s, w);
  printf("\nn in char is: %s\n", s);
}

void itoa(int n, char s[], int w) {
  int i, sign, p, j;

  if ((sign = n) < 0)
    n = -n;

  i = 0;

  do {
    s[i++] = (n % 10 < 0 ? -(n % 10) : n % 10) + '0';
  } while ((n /= 10) != 0);

  if (i < w) {
    p = w - i;
    if (sign < 0) {
      p--;
    }
  }

  if (p > 0) {
    for (j = 0; j < p; j++) {
      s[i++] = '0';
    }
  }

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
