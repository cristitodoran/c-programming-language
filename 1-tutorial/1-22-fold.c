#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int limit);
void fold(char line[], int length, char result[], int limit);

int main() {
  char line[MAXLINE];
  char result[MAXLINE];
  int len;

  while ((len = getLine(line, MAXLINE)) > 0) {
    fold(line, len, result, 5);
    printf("%s\n", result);
  }
}

int getLine(char line[], int limit) {
  int i;
  char c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < limit - 1) {
      line[i] = c;
    }
  }
  if (c == '\n') {
    line[i] = '\n';
    i++;
  }
  line[i] = '\0';

  return i;
}

void fold(char line[], int length, char result[], int limit) {
  int i, lastSpace = 0;

  for (i = 0; i < length; i++) {
    result[i] = line[i];
    if (line[i] == ' ') {
      lastSpace = i;
    }
    if (i > limit) {
      result[lastSpace] = '\n';
      limit *= 2;
    }
  }
  result[i] = '\0';
}
