#include <ctype.h>
#include <stdio.h>
#include "getch.c"

double getfloat(double *pn);

int main() {
  double x = 0;
  getfloat(&x);
  printf("x = %g\n", x);
}

double getfloat(double *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (c == '0') {
      ungetch(c);
      ungetch(sign ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  if (c == '.') {
    c = getch();
    double exp;
    for (exp = 10; isdigit(c); c = getch(), exp *= 10)
      *pn = *pn + ((c - '0') / exp);
  }

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}
