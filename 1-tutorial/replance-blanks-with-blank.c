#include <stdio.h>

int main()
{
  int count = 0;
  int c;

  while((c = getchar()) != EOF)
  {
    if (c != ' ')
    {
      count = 0;
      putchar(c);
    }
    else {
      ++count;
      if (count == 1)
        putchar(c);
    }
  }
}
