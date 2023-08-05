#include "s21_math.h"

long double s21_sin(double x) {
  long double res = 1.0;
  // printf("|%.15f|\n", x);
  while (((x > 2 * S21_PI) || (x < -2 * S21_PI)) && (!S21_IS_INF(x)) &&
         (!S21_IS_NAN(x))) {
    if (x > 2 * S21_PI)
      x = x - ((long long int)(x / (2 * S21_PI)) * 2 * S21_PI);
    else
      x = x + ((long long int)(-x / (2 * S21_PI)) * 2 * S21_PI);
  }
  // printf("|%.15f|\n", x);
  if ((!S21_IS_INF(x)) && (!S21_IS_NAN(x))) {
    if (x > S21_PI) {
      x = x - (2 * S21_PI);
    } else if (x < -S21_PI)
      x = x + (2 * S21_PI);
    if ((x <= S21_PI) && (x > S21_PI / 2)) {
      x = S21_PI - x;
    }
    if ((x >= -S21_PI) && (x < -S21_PI / 2)) {
      x = -S21_PI - x;
    }
    // Диапазон покрытия в градусах [-45; 45]
    if ((x >= -(S21_PI / 4)) && (x <= (S21_PI / 4))) {
      calculate_sin_null(&res, x, 8);
    }
    // sin(x) = 1 - ((x - 90)^2 / 2!) + ((x - 90)^4 / 4!) - ((x - 90)^6 / 6!)
    // Диапазон покрытия в градусах (45; 90]
    if ((x > (S21_PI / 4)) && (x <= (S21_PI / 2))) {
      calculate_sin_straight(&res, x, 9, 1);
    }
    // Диапазон покрытия в градусах [-90; -45)
    if ((x >= -(S21_PI / 2)) && (x < -(S21_PI / 4))) {
      calculate_sin_straight(&res, x, 9, -1);
    }
  } else {
    res = S21_NAN;
  }
  return res;
}

void calculate_sin_null(long double* res, double x, int num_of_cycles) {
  *res = (long double)x;
  for (int i = 0; i < num_of_cycles; i++) {
    double tmp = x;
    for (int n = 0; n < i; n++) tmp = tmp * x * x;
    // printf("%d_1) |%.15Lf|    |%.15f|\n", i, *res, tmp);
    if (((i % 2) == 0) && (i != 0)) *res = *res + tmp / factorial(2 * i + 1);
    if ((i % 2) != 0) *res = *res - tmp / factorial(2 * i + 1);
    // printf("%d_2) |%.15Lf|    |%.15f|\n", i, *res, tmp);
  }
}

void calculate_sin_straight(long double* res, double x, int num_of_cycles,
                            int sign) {
  *res = sign;
  for (int i = 0; i < num_of_cycles; i++) {
    double tmp = 1;
    for (int n = 0; n < i; n++)
      tmp = tmp * (x - sign * S21_PI / 2) * (x - sign * S21_PI / 2);
    // printf("%d_1) |%.15Lf|    |%.15f|\n", i, *res, tmp);
    if ((i % 2 == 0) && (i != 0)) *res = *res + sign * tmp / factorial(2 * i);
    if (i % 2 != 0) *res = *res - sign * tmp / factorial(2 * i);
    // printf("%d_2) |%.15Lf|    |%.15f|\n", i, *res, tmp);
  }
}