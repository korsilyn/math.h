#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  if ((x > 0) && ((long long int)x < x) && (x < S21_EPS))
    res = (long long int)x + 1;
  else if ((x < 0) && (x > -S21_EPS))
    res = (long long int)x;
  else
    res = x;
  if (x == S21_INF_POS)
    res = S21_INF_POS;
  else if (x == S21_INF_NEG)
    res = S21_INF_NEG;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  return res;
}