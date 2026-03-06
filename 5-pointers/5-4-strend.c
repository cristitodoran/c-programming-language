#include <stdio.h>
#define MAX 1000

int strend(char *s, char *t);

int main(){
  char s[MAX], t[MAX];
  puts("s:");
  scanf("%s", s);
  puts("t:");
  scanf("%s", t);

  printf("%s %s with %s\n", s, strend(s, t) ? "ends" : "doesn't end", t);
}

int strend(char *s, char *t) {
  int j = 0;
  while (*s) {
    if (*s == t[j])
      j++;
    else
      j = 0;
    s++;
  }
  return t[j] == '\0';
}
