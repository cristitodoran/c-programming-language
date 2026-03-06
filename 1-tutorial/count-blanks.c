#include <stdio.h>

int main() {
  int blanks = 0;
  int tabs = 0;
  int nl = 0;
  char c;

  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if (c == '\n')
      ++nl;

  printf("blanks: %d\n", blanks);
  printf("tabs: %d\n", tabs);
  printf("new lines: %d\n", nl);
}
