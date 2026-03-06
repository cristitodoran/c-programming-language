#include <stdio.h>
#define MAXLINE 100

int getLine(char line[], int limit);
void reverse(int len, char line[], char reversed[]);

int main() {
  char line[MAXLINE];
  char reversed[MAXLINE];
  int len;

  while ((len = getLine(line, MAXLINE)) > 0) {
    puts(line);
    reverse(len, line, reversed);
    puts(reversed);
  }
}

int getLine(char line[], int limit) {
  char c;
  int i = 0;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void reverse(int len, char line[], char reversed[]) {
  int i, j;

  for (i = len - 1, j = 0; i >= 0; --i) {
    if (line[i] == '\0' || line[i] == '\n') {
      continue;
    } else {
      reversed[j] = line[i];
      j++;
    }
  }
  reversed[j] = '\n';
  reversed[j + 1] = '\0';
}
