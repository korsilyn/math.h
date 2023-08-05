#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 0;
  for (int i = 0; i < 500; i++) {
    long double tmp = 1 / x;
    // printf("%d_1) |%.15Lf|    |%.15Lf|\n", i, res, tmp);
    for (int n = 0; n < i; n++) tmp = tmp * x * x;
    res = res + (tmp * (2 * i + x)) / factorial(2 * i);
    // printf("%d_2) |%.15Lf|    |%.15Lf|\n", i, res, tmp);
  }
  if (x == 0) res = 1;
  if (x > 709.7827128) res = S21_INF_POS;
  if (x < -25) res = 0;
  if (res < 0) res = -res;
  return res;
}