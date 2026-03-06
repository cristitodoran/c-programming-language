#include <stdio.h>
#define MAX 1000

void my_strncpy(size_t n, char *s, char *t);
void my_strncat(size_t n, char *s, char *t);
int my_strncmp(size_t n, char *s, char *t);

int main() {
  char s[MAX], t[MAX];
  int n;

  scanf("%s %s %d", s, t, &n);

  // my_strncpy(n, s, t);
  // printf("my_strncpy: %s\n", s);

  // my_strncat(n, s, t);
  // printf("my_strncat: %s\n", s);

  printf("my_strncmp: %d\n", my_strncmp(n, s, t));
}

void my_strncpy(size_t n, char *s, char *t) {
  for (; n > 0 && *s && *t; n--) {
    *s++ = *t++;
  }
}

void my_strncat(size_t n, char *s, char *t) {
  while (*s)
    *s++;
  for (; n > 0 && *t; n--)
    *s++ = *t++;
}

int my_strncmp(size_t n, char *s, char *t) {
  for (; n > 0 && *s == *t; n--, s++, t++)
    if (*s == '\0' || *t == '\0')
      return 0;
  return *s - *t;
}
