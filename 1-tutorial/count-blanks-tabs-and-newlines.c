#include <stdio.h>

int main()
{
  int c, blanks, tabs, nl;

  blanks = tabs = nl = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ')
      ++blanks;
    if (c == '\t')
      ++tabs;
    if (c == '\n')
      ++nl;
  }
  printf("blanks: %d\n", blanks);
  printf("tabs: %d\n", tabs);
  printf("new lines: %d\n", nl);
}
