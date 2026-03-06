#include <stdio.h>
#define MAXLINE 100

int getLine(char line[], int limit);

int main() {
  char line[MAXLINE];
  int len;

  while ((len = getLine(line, MAXLINE)) >= 0) {
    if (len == 0) {
      puts("Empty line");
    } else {
      printf("-%s-", line);
    }
  }
}

int getLine(char line[], int limit) {
  char c;
  int i = 0;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == EOF) {
    return -1;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  if (line[i - 1] == '\n') {
    i = i - 2;
  } else {
    i = i - 1;
  }

  if (i == -1) {
    i = 0;
  }

  for (; i >= 0; i--) {
    if (line[i] != ' ' && line[i] != '\t') {
      line[i + 1] = '\n';
      line[i + 2] = '\0';
      break;
    }
  }

  return i;
}
