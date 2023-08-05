#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if (x == S21_INF_POS)
    result = x;
  else if (x == 0)
    result = S21_INF_NEG;
  else if (x < 0)
    result = S21_NAN;
  else {
    long double cmp = 0;
    int repeat = 0;
    for (; x >= S21_E; repeat++) x /= S21_E;
    for (int i = 0; i < 10; i++) {
      cmp = result;
      result = cmp + 2 * (x - s21_exp(cmp)) / (x + s21_exp(cmp));
    }
    result += repeat;
  }
  return result;
}
