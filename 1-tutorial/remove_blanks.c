#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxLine);

int main() {
  char line[MAXLINE];
  int len = 0;

  len = get_line(line, MAXLINE);

  printf("\n\n%s - %d\n", line, len);
}

int get_line(char s[], int lim) {
  int c, i, j;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  for (j = i; j > 0; --j) {
    if (s[j] == ' ' || s[j] == '\t') {
      s[j] = '\0';
      --i;
    } else if (s[j] != '\n' && s[j] != '\0')
      break;
  }

  return i;
}
