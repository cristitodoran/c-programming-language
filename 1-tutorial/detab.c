#include <stdio.h>
#define MAXCHARS 1000

void detab(char s[], int len, int tab_length);

int main() {
  char input[MAXCHARS];
  int i = 0;
  int c;

  puts("12345678901234567890\n");

  while ((c = getchar())) {
    if (c != EOF) {
      input[i] = c;
      i++;
    } else {
      break;
    }
  }
  input[i] = '\0';

  detab(input, i, 8);
}

void detab(char s[], int len, int tab_length) {
  int i;
  int j = 0;
  int k;
  char r[MAXCHARS];

  for (i = 0; i < len; ++i) {
    if (s[i] != '\t') {
      r[j] = s[i];
      j++;
    } else {
      for (k = 0; k < (tab_length - j % tab_length); k++) {
        r[j + k] = ' ';
      }
      j += k;
    }
  }
  r[j] = '\0';
  printf("\n%s\n", r);
}
