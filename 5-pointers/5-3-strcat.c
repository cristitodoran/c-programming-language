#include <stdio.h>
#define MAX 1000

void my_strcat(char *s, char *t){
  while (*s)
    s++;
  while (*s++ = *t++)
    ;
}

int main() {
  char s[MAX], t[MAX];

  puts("s:");
  scanf("%s", &s);
  puts("t:");
  scanf("%s", &t);

  my_strcat(s, t);
  printf("s + t: %s\n", s);
}
