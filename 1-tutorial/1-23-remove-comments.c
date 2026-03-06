#include <stdio.h>
#define MAX 10000

int get_input(char input[], int limit);
void remove_comments(char input[], int length, char result[]);

int main() {
  char input[MAX];
  char result[MAX];
  int len;

  while ((len = get_input(input, MAX)) > 0) {
    remove_comments(input, len, result);
    printf("%s\n", result);
  }
}

int get_input(char input[], int limit) {
  int i;
  char c;

  for (i = 0; (c = getchar()) != EOF; i++) {
    if (i < limit - 1) {
      input[i] = c;
    }
  }
  input[i] = '\0';

  return i;
}

void remove_comments(char input[], int length, char result[]) {
  int i, j;
  int is_line_comment = 0;
  int is_multi_line_comment = 0;

  for (i = 0, j = 0; i < length; i++) {
    if (input[i] == '/' && input[i + 1] == '/' && !is_multi_line_comment) {
      is_line_comment = 1;
    }
    if (is_line_comment && input[i] == '\n') {
      is_line_comment = 0;
      continue;
    }

    if (input[i] == '/' && input[i + 1] == '*' && !is_line_comment) {
      is_multi_line_comment = 1;
    }
    if (is_multi_line_comment && input[i-1] == '*' && input[i] == '/'){
      is_multi_line_comment = 0;
      continue;
    }

    if (!is_line_comment && !is_multi_line_comment) {
      result[j] = input[i];
      j++;
    }
  }
}
