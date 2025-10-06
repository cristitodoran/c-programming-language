#include <stdio.h>
#define MAXLINE 80

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int last_len;
  int max;
  int overflow;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  len = 0;
  last_len = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > 0 && line[len-1] != '\n') {
      last_len += len;
      printf("%s", line);
    } else if (last_len > 0) {
      last_len += len;
      printf("%s - %d\n", line, last_len);
      last_len = 0;
    }
    if (len == 1) {
      continue;
    }
    if (len > max) {
      max = len;
      copy(longest, line);
    }
    if (len > 80) {
      printf("%s", line);
    }
  }
  if (max > 0)
    printf("longest - %s", longest);
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
