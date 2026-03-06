#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define PEEK '1'
#define DUPLICATE '2'
#define SWAP '3'
#define CLEAR '4'
#define SIN '5'
#define EXP '6'
#define POW '7'
#define STORE_VAR '8'
#define GET_VAR '9'

int sp = 0;
double val[MAXOP];
double var[26];

int getop(char []);
void push(double);
double pop(void);

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero division\n");
        break;
      case '%': // 4-3 modulo
        op2 = pop();
        push(((int)pop()) % ((int)op2));
        break;
      case PEEK:
        printf("top element: %.8g\n", val[sp - 1]);
        break;
      case DUPLICATE:
        op2 = pop();
        push(op2);
        push(op2);
        break;
      case SWAP:
        double a = pop();
        double b = pop();
        push(a);
        push(b);
        break;
      case CLEAR:
        sp = 0;
        break;
      case SIN:
        push(sin(pop()));
        break;
      case EXP:
        push(exp(pop()));
        break;
      case POW:
        op2 = pop();
        push(pow(pop(), op2));
        break;
      case STORE_VAR:
        var[s[1] - 'a'] = pop();
        break;
      case GET_VAR:
        push(var[s[0] - 'a']);
        break;
      case '\n':
        printf("\t%g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, cant push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>
int getch(void);
void ungetch(int);
void ungets(char s[]);

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
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
    ungetch(c);
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
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return(bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int i = 0;
  while (s[i] != '\0') {
    ungetch(s[i++]);
  }
}
