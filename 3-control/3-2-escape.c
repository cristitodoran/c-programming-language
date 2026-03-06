#include <stdio.h>
#define MAX 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  char s[MAX] = "hai acasa\t\t\tmai\n baiete!";
  char t[MAX];

  printf("initial: %s\n", s);
  escape(s, t);
  printf("escaped: %s\n", t);
  unescape(t, s);
  printf("unescaped: %s\n", s);
}

void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;

  while(s[i] != '\0') {
    switch (s[i]) {
      case '\n':
        t[j] = '\\';
        j++;
        t[j] = 'n';
        break;
      case '\t':
        t[j] = '\\';
        j++;
        t[j] = 't';
        break;
      default:
        t[j] = s[i];
        break;
    }
    i++;
    j++;
  }
  t[j] = '\0';
}

void unescape(char s[], char t[]) {
  int i = 0;
  int j = 0;

  while(s[i] != '\0') {
    switch (s[i]) {
      case '\\':
        i++;
        switch(s[i]) {
          case 't':
            t[j] = '\t';
            break;
          case 'n':
            t[j] = '\n';
            break;
          default:
            t[j] = '\\';
            i--;
        }
        break;
      default:
        t[j] = s[i];
        break;
    }
    i++;
    j++;
  }
  t[j] = '\0';
}
