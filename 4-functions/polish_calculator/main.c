#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

double var[26];

extern int sp;
extern double val[];

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
