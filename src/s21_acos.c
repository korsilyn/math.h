#include "s21_math.h"

long double s21_acos(double x) {
  long double result;

  // Обработка специальных случаев: x = 1 or x = -1
  if (x == 1.0) {
    result = 0.0;
  } else if (x == -1.0) {
    result = S21_PI;

    // Проверьте, не находится ли x вне допустимого диапазона [-1, 1]
  } else if (x < -1.0 || x > 1.0) {
    result = S21_NAN;

    // acos(x) = pi/2 - asin(x)
  } else {
    long double asin_value = s21_asin(x);
    result = (S21_PI / 2.0) - asin_value;
  }

  return result;
}