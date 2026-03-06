#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]) {
  int i, c;

  static int pushed_back_char = -1;

  if (pushed_back_char != -1) {
    c = pushed_back_char;
    s[0] = c;
    pushed_back_char = -1;
  } else {
    c = getch();
    s[0] = c;
  }

  while (c == ' ' || c == '\t') {
    c = getch();
    s[0] = c;
  }
  s[1] = '\0';
  i = 0;
  if (islower(c)) {
    while (islower(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    int command = '\0';
    if (strcmp(s, "peek") == 0) {
      command = PEEK;
    } else if (strcmp(s, "duplicate") == 0) {
      command = DUPLICATE;
    } else if (strcmp(s, "swap") == 0) {
      command = SWAP;
    } else if (strcmp(s, "clear") == 0) {
      command = CLEAR;
    } else if (strcmp(s, "sin") == 0) {
      command = SIN;
    } else if (strcmp(s, "exp") == 0) {
      command = EXP;
    } else if (strcmp(s, "pow") == 0) {
      command = POW;
    } else if (strlen(s) == 2 && s[0] == 'v') {
      return STORE_VAR;
    } else if (strlen(s) == 1) {
      return GET_VAR;
    }
    return command;
  }
  if (!isdigit(c) && c != '.') {
    return c;
  }
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  return NUMBER;
}
