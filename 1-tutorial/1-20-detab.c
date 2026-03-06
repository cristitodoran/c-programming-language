// Write a program detab that replaces tabs in the input with the
// proper number of blanks to space to the next tab stop. Assume a fixed set of
// tab stops, say every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int limit);
void detab(char line[], char result[], int length, int tabLength);

int main() {
  char line[MAXLINE];
  char result[MAXLINE];
  int len;

  while ((len = getLine(line, MAXLINE)) > 0) {
    detab(line, result, len, 8);
    printf("%s", result);
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

void detab(char line[], char result[], int length, int tabLength) {
  int i, j, k;

  for (i = 0, j = 0; i < length; i++) {
    if (line[i] == '\t') {
      for (k = 0; k < tabLength - (j % tabLength); k++) {
        result[j + k] = ' ';
      }
      j += k;
    } else {
      result[j]= line[i];
      j++;
    }
  }
  line = result;
}
