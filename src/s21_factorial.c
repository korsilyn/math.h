#include "s21_math.h"

long double factorial(int n) {
  long double res = 1;
  if (n < 0) res = 0;
  if (n == 0) res = 1;
  if (n > 0) {
    for (int i = 1; i <= n; i++) {
      res = res * i;
    }
  }
  return res;
}