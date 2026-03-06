// Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the
// same tab stops as for detab. When either a tab or single blank would suffice
// to reach a tab stop, which should be given preference?

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int limit);
int detab(char line[], char result[], int length, int tabLength);
int entab(char line[], char result[], int length, int tabLength);

int main() {
  char line[MAXLINE];
  char result[MAXLINE];
  int len;

  while ((len = getLine(line, MAXLINE)) > 0) {
    entab(line, result, len, 8);
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

int entab(char line[], char result[], int length, int tabLength) {
  int i, j, k, spaces = 0;

  for (i = 0, j = 0; i < length; i++) {
    if (line[i] == ' ') {
      spaces++;
    } else if (spaces > 0) {
      for (k = 0; k < spaces % tabLength; k++) {
        result[j + k] = ' ';
      }
      j += k;
      for (k = 0; k < spaces / tabLength; k++) {
        result[j + k] = '\t';
      }
      j += k;
      result[j] = line[i];
      j++;
      spaces = 0;
    } else {
      result[j] = line[i];
      j++;
    }
  }

  result[j] = '\0';
  return j;
}
