#include <stdio.h>
#define MAX 10000

int get_input(char input[], int limit);
void check_syntax(char input[], int length);

int main() {
  char input[MAX];
  char result[MAX];
  int len;

  while ((len = get_input(input, MAX)) > 0) {
    check_syntax(input, len);
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

void check_syntax(char input[], int length) {
  int lines[MAX];
  int columns[MAX];
  int errorsCount = 0;
  int column = 0;
  int line = 0;
  int i;

  for (i = 0; i < MAX; i++) {
    lines[i] = -1;
    columns[i] = -1;
  }

  for (i = 0; i < length; i++) {
    if (input[i] == '\n') {
      line++;
      column = 0;
      continue;
    }
    if (input[i] == '(') {
      lines[errorsCount] = line;
      columns[errorsCount] = column;
      errorsCount++;
    }
    if (input[i] == ')') {
      lines[errorsCount - 1] = -1;
      columns[errorsCount - 1] = -1;
    }
    column++;
  }

  i = 0;
  while (lines[i] >= 0) {
    printf("unclosed parantheses at %d, %d\n", lines[i], columns[i]);
    i++;
  }
}
