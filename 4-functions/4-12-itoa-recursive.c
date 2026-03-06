#include <stdio.h>
#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  int n = 0;
  char s[MAXLINE];

  puts("n: ");
  scanf("%d", &n);
  itoa(n, s);
  printf("\nn in char is: %s\n", s);
}

void itoa(int n, char s[]) {
  static int i = 0;

  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }

  if (n / 10)
    itoa(n / 10, s);
  s[i++] = (n % 10 + '0');
  s[i] = '\0';
}

