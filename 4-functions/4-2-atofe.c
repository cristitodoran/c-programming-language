#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atofe(char s[]){
  double val, power, epower, result;
  int i, sign, esign;

  esign = 1;
  epower = 0.0;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    i++;

    esign = s[i] == '-' ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;

    for (epower = 0.0; isdigit(s[i]); i++) {
      epower = 10.0 * epower + (s[i] - '0');
    }
  }

  return (sign * val / power) * pow(10.0, esign * epower);
}
