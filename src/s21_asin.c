#include "s21_math.h"

long double s21_asin(double x) {
  long double result;

  // Обработка специальных случаев: x = 1 or x = -1
  if (x == 1.0) {
    result = S21_PI / 2.0;
  } else if (x == -1.0) {
    result = -S21_PI / 2.0;

    // Проверьте, не находится ли x вне допустимого диапазона [-1, 1]
  } else if (x < -1.0 || x > 1.0) {
    result = S21_NAN;
  } else {
    // asin(x) = atan(x / sqrt(1 - x^2))
    long double squared_term = 1.0 - x * x;
    long double square_root = s21_sqrt(squared_term);
    //		long double square_root = sqrt(squared_term);
    long double atan_value = s21_atan(x / square_root);
    result = atan_value;
  }

  return result;
}
