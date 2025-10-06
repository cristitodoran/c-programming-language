#include <stdio.h>
#define MAXCHARS 1000

void remove_comments(char s[], int len);

int main() {
  char input[MAXCHARS];
  int i = 0;
  char c;

  while ((c = getchar()) != EOF) {
    input[i++] = c;
  }

  input[i] = '\0';
  remove_comments(input, i);
}

void remove_comments(char s[], int len) {
  int i;
  char r[MAXCHARS];
  int j = 0;
  int comment_start = 0;

  for (i = 0; i < len; i++) {
    if (comment_start == 0 && s[i] == '/' && s[i + 1] == '/') {
      comment_start = 1;
    }
    if (comment_start == 1 && s[i] == '\n') {
      comment_start = 0;
      continue;
    }
    if (!comment_start) {
      r[j++] = s[i];
    }
  }
  r[j] = '\0';

  printf("\n\n%s", r);
}
