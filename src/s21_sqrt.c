#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0;
  if (x == S21_NAN || x < 0) {
    result = S21_NAN;
  } else if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (x == 0)
    result = 0;
  else {
    long double xhalf = 0.5 * x;
    union {
      float x;
      int i;
    } u;
    u.x = x;
    u.i = 0x5f375a86 - (u.i >> 1);
    result = u.x;
    for (int i = 0; i < 10; i++) {
      result = result * (1.5f - xhalf * result * result);
    }
    result = 1.0 / result;
  }
  return result;
}
