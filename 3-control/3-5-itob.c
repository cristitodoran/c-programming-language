#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  int n = 0;
  char s[MAXLINE];
  int b = 10;

  puts("n: ");
  scanf("%d", &n);
  puts("b: ");
  scanf("%d", &b);
  itob(n, s, b);
  printf("\nn in base %d in char is: %s\n", b, s);
}

void itob(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;

  do {
    s[i++] = (n % b < 0 ? -(n % b) : n % b) + '0';
  } while ((n /= b) != 0);

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
