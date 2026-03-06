#include <stdio.h>
#include <ctype.h>
#define MAX 1000

int getLine(char line[], int limit);
void expand(char s1[], char s2[]);

int main() {
  char line[MAX];
  char result[MAX];

  while (getLine(line, MAX) > 0) {
    expand(line, result);
    printf("\n%sExpands to:\n%s\n\n", line, result);
  }
}

void expand(char s1[], char s2[]) {
  int i, j, k;

  for (i = 0, j = 0; s1[i] != '\0'; i++, j++) {
    if ((islower(s1[i]) && s1[i + 1] == '-' && islower(s1[i + 2]) && s1[i] < s1[i + 2]) ||
        (isupper(s1[i]) && s1[i + 1] == '-' && isupper(s1[i + 2]) && s1[i] < s1[i + 2]) ||
        (isdigit(s1[i]) && s1[i + 1] == '-' && isdigit(s1[i + 2]) && s1[i] < s1[i + 2])) {
      s2[j] = s1[i];

      for (k = 0; k <= (s1[i + 2] - s1[i]); k++, j++) {
        s2[j] = s1[i] + k;
      }

      i += 2;
      j--;
    } else if (s1[i] != '\0') {
      s2[j] = s1[i];
    }
  }
  s2[j-1] = '\0';
}

int getLine(char line[], int limit) {
  int i;
  char c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < limit - 1) {
      line[i] = c;
    }
  }
  if (c == '\n') {
    line[i] = '\n';
    i++;
  }
  line[i] = '\0';

  return i;
}
