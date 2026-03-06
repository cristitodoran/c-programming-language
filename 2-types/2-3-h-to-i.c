#include <stdio.h>
#include <ctype.h>
#define MAX 1000

long htoi(char s[]);

int main() {
  printf("123 = %d\n", htoi("123"));
  printf("aa = %d\n", htoi("aa"));
}

long htoi(char s[]) {
  int i;
  long n = 0;

  for (i = 0; s[i] != '\0'; i++) {
    if (isdigit(s[i])) {
      n = n * 16 + s[i] - '0';
    } else {
      n = n * 16 + 10 + s[i] - 'a';
    }
  }

  return n;
}
