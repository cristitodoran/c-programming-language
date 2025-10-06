#include <stdio.h>

/* count digits, white space, others */
int main()
{
  int c, i, j, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c-'0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

  printf("%s", "\ndigits =");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);

  for (i = 0; i < 10; i++)
  {
    printf("digit %d: ", i);
    for (j = 0; j < ndigit[i]; j++)
    {
      printf("%s", "-");
    }
    printf("%s", "\n");
  }

  printf("white  : ", i);
  for (j = 0; j < nwhite; j++)
  {
    printf("%s", "-");
  }
  printf("%s", "\n");

  printf("other  : ", i);
  for (j = 0; j < nother; j++)
  {
    printf("%s", "-");
  }
  printf("%s", "\n");
  printf("%s", "\n");

  int max = nother;
  if (max < nwhite) {
    max = nwhite;
  }
  for (i = 0; i < 10; i++) {
    if (max < ndigit[i]) {
      max = ndigit[i];
    }
    printf("%d", i);
  }
  printf("%s", "w");
  printf("%s", "o\n");

  for (i = 0; i < max; i++) {
    for (j = 0; j < 10; j++) {
      if (ndigit[j] >= i)
        printf("%s", "|");
      else
        printf("%s", " ");
    }

    if (nwhite >= i)
      printf("%s", "|");
    else
      printf("%s", " ");

    if (nother >= i)
      printf("%s", "|");
    else
      printf("%s", " ");

    printf("%s", "\n");
  }
}
