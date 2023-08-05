#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (!exp)
    result = 1;
  else if (base == S21_INF_NEG && exp == S21_INF_NEG)
    result = 0;
  else if (base == S21_INF_NEG && exp == S21_INF_POS)
    result = S21_INF_POS;
  else if (base < 0 && exp != (long long int)exp)
    result = S21_NAN;
  else if (S21_IS_NAN(exp))
    result = 1;
  else {
    int sign = 0;
    if (base < 0)
      sign = -1;
    else
      sign = 1;
    result = s21_exp(exp * s21_log(sign * base));
    if (s21_fmod(exp, 2)) result *= sign;
  }
  return result;
}
