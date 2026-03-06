#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {
  int nlines;
  char linestor[ALLOCSIZE];

  if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000
int getLine(char *, int);

int readlines(char *lineptr[], char *linestor, int maxlines) {
  int len, nlines;
  char line[MAXLEN], *allocp = linestor;

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (linestor + ALLOCSIZE - allocp) < len)
      return -1;
    else {
      line[len - 1] = '\0';
      allocp += len;
      strcpy(allocp - len, line);
      lineptr[nlines++] = allocp - len;
    }

  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;

  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right) {
  int i, last;

  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int getLine(char *line, int limit) {
  int i = 0;
  char c;

  for (; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < limit - 1) {
      *line++ = c;
    }
  }
  if (c == '\n') {
    *line++ = '\n';
    i++;
  }
  *line = '\0';

  return i;
}

