#include <stdio.h>
#include "calc.h"

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return(bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int i = 0;
  while (s[i] != '\0') {
    ungetch(s[i++]);
  }
}
