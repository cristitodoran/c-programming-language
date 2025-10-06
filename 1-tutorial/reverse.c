#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxLine);
void reverse(char line[], int maxLine);

int main() {
  char line[MAXLINE];
  int len = 0;

  len = get_line(line, MAXLINE);
  reverse(line, len);
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

  return i;
}

void reverse(char line[], int len) {
  int i;

  for (i = len ; i >= 0; --i) {
    printf("%c", line[i]);
  }
  printf("\n");
}
