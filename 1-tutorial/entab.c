#include <stdio.h>
#define MAXCHARS 1000
#define TAB_LENGTH 8

void entab(char s[], int len);

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

  entab(input, i);
}

void entab(char s[], int len) {
  int i;
  char r[MAXCHARS];
  int j = 0;
  int k;
  int last_char = 0;

  for (i = 0; i < len; ++i) {
    if (s[i] != ' ') {
      if (i - last_char > 1) {
        for (k = 0; k < ((i - last_char) + last_char % TAB_LENGTH) / TAB_LENGTH; k++) {
          r[j++] = '\t';
        }
        for (k = 0; k < ((i - last_char) + last_char % TAB_LENGTH) % TAB_LENGTH; k++) {
          r[j++] = ' ';
        }
      }
      r[j++] = s[i];
      last_char = i;
    }
  }
  r[j] = '\0';
  printf("\n%s\n", r);
}
