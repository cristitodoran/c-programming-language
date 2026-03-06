#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

int getLine(char *line, int limit);
int atoi(char *s);
void itoa(int n, char s[]);
void reverse(char s[]);
int strindex(char *s, char *t);

int main() {
  char line[MAX];
  char nr[MAX];

  getLine(line, 100);
  printf("line: %s\n", line);
  reverse(line);
  printf("reversed: %s\n", line);

  puts("nr:");
  scanf("%s", nr);
  printf("%s atoi: %d\n", nr, atoi(nr));

  int n = -223;
  itoa(n, line);
  printf("%d itoa: %s\n", n, line);

  char s[MAX], t[MAX];
  puts("s:");
  scanf("%s", s);
  puts("t:");
  scanf("%s", t);
  printf("%s in %s: %d\n", t, s, strindex(s, t));
}

int getLine(char *line, int limit) {
  int i = 0;
  char c;

  for (; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < limit - 1) {
      *line++ = c;
    }
  }
  if (c == '\n') {
    *line++ = '\n';
    i++;
  }
  *line = '\0';

  return i;
}

int atoi(char *s) {
  int n, sign;

  while (isspace(*s))
    s++;
  sign = *s == '-' ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;
  for (n = 0; isdigit(*s); s++)
    n = 10 * n + (*s - '0');
  return sign * n;
}

void itoa(int n, char *s) {
  int i, sign;
  char *t = s;

  if ((sign = n) < 0)
    n = -n;

  do {
    *s++ = (n % 10 < 0 ? -(n % 10) : n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    *s++ = '-';

  *s = '\0';
  reverse(t);
}


void reverse(char s[]) {
  int c, i, j;
  char *t = &s[strlen(s) - 1];

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--, s++, t--) {
    c = *s, *s = *t, *t = c;
  }
}

int strindex(char *s, char *t) {
  int i = 0;
  char *v = t;

  while (*s) {
    v = t;
    while (*v && *s && *v++ == *s++)
      ;
    if (*v == '\0')
      return i;
    i++;
  }

  return -1;
}
