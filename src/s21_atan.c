#include "s21_math.h"

// atan(x) = x - x^3/3 + x^5/5 - x^7/7 + x^9/9 ... ((-1)^n * x^(2n+1)) / (2n +
// 1) works on [-1; 1]
long double s21_atan(double x) {
  // Используя ряд Маклорена
  long double result = 0.0;
  long double term = x;
  long double term_squared = x * x;
  long double sign = 1.0;

  // Проверка специального случая: x = 0.0
  if (x == 0.0) {
    result = 0.0;

    // Проверка специальных случаев: x = 1.0 и x = -1.0
  } else if (x == 1.0) {
    result = S21_PI / 4.0;
  } else if (x == -1.0) {
    result = -S21_PI / 4.0;

    // Проверка случая, когда |x| > 1
  } else if (s21_fabs(x) > 1.0) {
    if (x > 0) {
      // atan(x) = pi/2 - atan(1/x) for positive x
      result = (S21_PI / 2.0) - s21_atan(1.0 / x);
    } else {
      // atan(x) = -atan(-x) for negative x
      result = -s21_atan(-x);
    }
  } else {
    for (int i = 1; i <= 5000; i += 2) {
      result = result + (sign * term) / i;
      sign = -sign;
      term = term * term_squared;
    }
  }

  return result;
}