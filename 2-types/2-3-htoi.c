#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 10

double htoi(char s[]);

int main(void) {
  int i = 0;
  char c;
  char s[MAX];

  while((c = getchar()) != EOF){
    s[i++] = c;
  }

  printf("\n%s = %f\n", s, htoi(s));
}

double htoi(char s[]) {
  double res = 0;
  int start = 0;
  size_t length = strlen(s);
  char reversed[MAX];

  if (length >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    start = 2;
  }

  int i = 0;
  int j = length - 1;
  while (j >= start) {
    reversed[i++] = s[j--];
  }

  for (i = 0; i < length; i++) {
    if (isdigit(reversed[i])) {
      res += (reversed[i] - '0') * pow(16, i);
    } else if (isxdigit(reversed[i])) {
      res += (toupper(reversed[i]) - 'A' + 10) * pow(16, i);
    }
  }

  return res;
}
