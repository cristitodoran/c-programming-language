#include <stdio.h>
#define MAXLINE 100

int main() {
  double sum, atofe(char []);
  char line[MAXLINE];
  int getLine(char line[], int max);

  sum = 0;
  while (getLine(line, MAXLINE) > 0)
    printf("\t%.12g\n", sum += atofe(line));
  return 0;
}
