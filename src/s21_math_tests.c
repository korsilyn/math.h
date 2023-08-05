#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"
#define S21_INF S21_INF_POS
//--------------------------s21_ceil---------------------------------

// long double s21_ceil(double x)
// возвращает ближайшее целое число, не меньше заданного значения
START_TEST(s21_ceil_test) {
  ck_assert_ldouble_eq_tol(ceil(1.0), s21_ceil(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(ceil(0.0), s21_ceil(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(ceil(1.9), s21_ceil(1.9), S21_EPS);
  ck_assert_ldouble_eq_tol(ceil(0.9), s21_ceil(0.9), S21_EPS);
  ck_assert_ldouble_eq_tol(ceil(-1.0), s21_ceil(-1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(ceil(-1.9), s21_ceil(-1.9), S21_EPS);
  ck_assert_ldouble_eq_tol(ceil(-0.9), s21_ceil(-0.9), S21_EPS);
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_NEG));
}
END_TEST

//--------------------------s21_fabs---------------------------------

// long double s21_fabs(double x)
// вычисляет абсолютное значение числа с плавающей токой
START_TEST(s21_fabs_test) {
  ck_assert_ldouble_eq_tol(fabs(-10000.9), s21_fabs(-10000.9), S21_EPS);
  ck_assert_ldouble_eq_tol(fabs(10000.9), s21_fabs(10000.9), S21_EPS);
  ck_assert_ldouble_eq_tol(fabs(0.0), s21_fabs(0.0), S21_EPS);
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_infinite(s21_fabs(S21_INF));
}
END_TEST

//--------------------------s21_fmod---------------------------------

// long double s21_fmod(double x, double y)
// остаток операции деления с плавающей точкой
START_TEST(s21_fmod_test) {
  ck_assert_ldouble_eq_tol(s21_fmod(2.34, 2.0), fmod(2.34, 2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(2.34, -2.0), fmod(2.34, -2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(3, 21.21), fmod(3, 21.21), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(3, -21.21), fmod(3, -21.21), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-9, -100500), fmod(-9, -100500), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-9, -9), fmod(-9, -9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1e+10, 9), fmod(1e+10, 9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1e+15, 9), fmod(1e+15, 9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1e+15, S21_INF), fmod(1e+15, S21_INF),
                           S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(2.45, 0));
  ck_assert_ldouble_nan(fmod(2.45, 0));
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(fmod(0, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 0));
  ck_assert_ldouble_nan(fmod(S21_INF, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, S21_INF_NEG));
}
END_TEST

//--------------------------s21_exp---------------------------------

// long double s21_exp(double x)
// возвращает значение e, возведенное в заданную степень
START_TEST(s21_exp_test) {
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(0.1), s21_exp(0.1), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(25), (double)s21_exp(25), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-1), s21_exp(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-800), s21_exp(-800), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(32), (double)s21_exp(32), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-'N'), s21_exp(-'N'), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-0.1), s21_exp(-0.1), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-37), s21_exp(-37), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-S21_INF), s21_exp(-S21_INF), S21_EPS);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
}
END_TEST

//--------------------------s21_log---------------------------------

// long double s21_log(double x)
// вычисляет натуральный логарифм
START_TEST(s21_log_test) {
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), S21_EPS);
  ck_assert_ldouble_eq_tol(log(0.1), s21_log(0.1), S21_EPS);
  ck_assert_ldouble_eq_tol(log(0.00001), s21_log(0.00001), S21_EPS);
  ck_assert_ldouble_eq_tol(log(S21_EPS), s21_log(S21_EPS), S21_EPS);
  ck_assert_ldouble_eq_tol(log(0.4), s21_log(0.4), S21_EPS);
  ck_assert_ldouble_eq_tol(log(100), s21_log(100), S21_EPS);
  ck_assert_ldouble_eq_tol(log(100000), s21_log(100000), S21_EPS);
  ck_assert_ldouble_eq_tol(log(1e100), s21_log(1e100), S21_EPS);
  ck_assert_ldouble_eq_tol(log(0.001), s21_log(0.001), S21_EPS);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_infinite(s21_log(S21_INF));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_nan(s21_log(-S21_INF));
  ck_assert_ldouble_nan(log(-S21_INF));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
}
END_TEST

//--------------------------s21_atan---------------------------------
START_TEST(test_s21_atan) {
  long double result_s21_atan = 0.;
  double result_atan = 0.;

  // testing values for s21_atan [-20 ; 20] with step 0.5
  for (double i = -10; i <= 10; i += 0.5) {
    result_s21_atan = s21_atan(i);
    result_atan = atan(i);
    ck_assert_ldouble_eq_tol(result_s21_atan, result_atan, S21_EPS);
  }
  // testing NAN for s21_atan
  ck_assert_ldouble_nan(s21_atan(S21_NAN));

  // testing INF for s21_atan
  result_s21_atan = s21_atan(S21_INF);
  result_atan = atan(S21_INF);
  ck_assert_ldouble_eq_tol(result_s21_atan, result_atan, S21_EPS);

  // testing DOUBLE_MAX and DOUBLE_MIN for s21_atan
  result_s21_atan = s21_atan(1.7 * pow(10, 308));
  result_atan = atan(1.7 * pow(10, 308));
  ck_assert_ldouble_eq_tol(result_s21_atan, result_atan, S21_EPS);
  result_s21_atan = s21_atan(-1.7 * pow(10, 308));
  result_atan = atan(-1.7 * pow(10, 308));
  ck_assert_ldouble_eq_tol(result_s21_atan, result_atan, S21_EPS);
}
END_TEST

//--------------------------s21_asin---------------------------------
START_TEST(test_s21_asin) {
  long double result_s21_asin = 0.;
  double result_asin = 0.;

  // testing values for s21_asin [-1.570796 ; 1.570796] with step 0.1
  for (double i = -1; i <= 1; i += 0.1) {
    result_s21_asin = s21_asin(i);
    result_asin = asin(i);
    ck_assert_ldouble_eq_tol(result_s21_asin, result_asin, S21_EPS);
  }
  ck_assert_ldouble_eq(s21_asin(1), asin(1));
  // testing NAN for s21_asin
  result_s21_asin = s21_asin(S21_PI);
  ck_assert_ldouble_nan(result_s21_asin);

  result_s21_asin = s21_asin(S21_NAN);
  ck_assert_ldouble_nan(result_s21_asin);
}
END_TEST

//--------------------------s21_acos---------------------------------
START_TEST(test_s21_acos) {
  long double result_s21_acos = 0.;
  double result_acos = 0.;
  // testing values for s21_asin [-1 ; 1] with step 0.1
  for (double i = -1; i <= 1; i += 0.1) {
    result_s21_acos = s21_acos(i);
    result_acos = acos(i);
    ck_assert_ldouble_eq_tol(result_s21_acos, result_acos, S21_EPS);
  }
  ck_assert_ldouble_eq(s21_acos(1), acos(1));

  // testing NAN for s21_acos
  result_s21_acos = s21_acos(S21_PI);
  ck_assert_ldouble_nan(result_s21_acos);

  result_s21_acos = s21_acos(S21_NAN);
  ck_assert_ldouble_nan(result_s21_acos);
}
END_TEST

//--------------------------s21_abs---------------------------------
START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-20), abs(-20));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483648), abs(-2147483648));
  ck_assert_int_eq(s21_abs(2486486484), abs(2486486484));
  ck_assert_int_eq(s21_abs('a'), abs('a'));
  ck_assert_int_eq(s21_abs(-2.5), abs(-2.5));
}
END_TEST

//--------------------------s21_sin---------------------------------
START_TEST(s21_sin_test) {
  long double result_s21_sin = 0.;
  double result_sin = 0.;

  // testing values for s21_sin [-20 ; 20] with step 0.5
  for (double i = -20; i <= 20; i += 0.5) {
    result_s21_sin = s21_sin(i);
    result_sin = sin(i);
    ck_assert_ldouble_eq_tol(result_s21_sin, result_sin, S21_EPS);
  }

  // testing NAN for s21_sin
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
}
END_TEST

//--------------------------s21_cos---------------------------------
START_TEST(s21_cos_test) {
  long double result_s21_cos = 0.;
  double result_cos = 0.;

  // testing values for s21_acos [-20 ; 20] with step 0.5
  for (double i = -20; i <= 20; i += 0.5) {
    result_s21_cos = s21_cos(i);
    result_cos = cos(i);
    ck_assert_ldouble_eq_tol(result_s21_cos, result_cos, S21_EPS);
  }

  //  testing PI values for cos
  for (int i = -30; i <= 30; i++) {
    result_s21_cos = s21_cos(i * S21_PI / 2);
    result_cos = cos(i * S21_PI / 2);
  }

  // testing NAN for s21_sin
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
}
END_TEST

//-------------------------s21_tan---------------------------------
START_TEST(s21_tan_test) {
  long double result_s21_tan = 0.;
  double result_tan = 0.;
  // testing values for s21_tan [-20 ; 20] with step 0.5
  for (double i = -20; i <= 20; i += 0.5) {
    result_s21_tan = s21_tan(i);
    result_tan = tan(i);
    ck_assert_ldouble_eq_tol(result_s21_tan, result_tan, S21_EPS);
  }

  // testing NAN for s21_tan
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
}
END_TEST
//--------------------------s21_pow---------------------------------

START_TEST(s21_pow_test) {
  long double result_s21_pow = 0.;
  double result_pow = 0.;
  double base = 1, exp = 1;

  for (int i = 0; i < 20; i++, base += 0.5, exp += 0.5) {
    result_s21_pow = s21_pow(base, exp);
    result_pow = pow(base, exp);
    ck_assert_ldouble_eq_tol(result_s21_pow, result_pow, S21_EPS);
  }

  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-10, 3), pow(-10, 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-10, 2), pow(-10, 2), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(-1, -2.123));
  ck_assert_ldouble_nan(s21_pow(-1, 2.123));
  ck_assert_ldouble_eq_tol(s21_pow(10, 1), pow(10, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(10, -1), pow(10, -1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(10, 0), pow(10, 0), S21_EPS);
  ck_assert_ldouble_eq(s21_pow(S21_INF_NEG, S21_INF_NEG),
                       pow(S21_INF_NEG, S21_INF_NEG));
  ck_assert_ldouble_eq(s21_pow(S21_INF_NEG, S21_INF_POS),
                       pow(S21_INF_NEG, S21_INF_POS));
}
END_TEST
//--------------------------s21_floor---------------------------------
START_TEST(s21_floor_test) {
  for (double i = -20.; i <= 20.; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), S21_EPS);
  }

  ck_assert_ldouble_eq_tol(s21_floor(-0.9999999999999999),
                           floor(-0.9999999999999999), S21_EPS);
  ck_assert_ldouble_infinite(s21_floor(S21_INF));
  ck_assert_ldouble_infinite(-(s21_floor(-S21_INF)));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

//--------------------------s21_sqrt---------------------------------
START_TEST(s21_sqrt_test) {
  for (double i = 0.; i <= 20.; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), S21_EPS);
  }

  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-10));
}
END_TEST

Suite *math_suite_create(void) {
  Suite *suite = suite_create("s21_math");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, s21_ceil_test);
  tcase_add_test(tcase_core, s21_fabs_test);
  tcase_add_test(tcase_core, s21_fmod_test);
  tcase_add_test(tcase_core, s21_exp_test);
  tcase_add_test(tcase_core, s21_log_test);
  tcase_add_test(tcase_core, test_s21_atan);
  tcase_add_test(tcase_core, test_s21_asin);
  tcase_add_test(tcase_core, test_s21_acos);
  tcase_add_test(tcase_core, s21_abs_test);
  tcase_add_test(tcase_core, s21_sin_test);
  tcase_add_test(tcase_core, s21_cos_test);
  tcase_add_test(tcase_core, s21_tan_test);
  tcase_add_test(tcase_core, s21_pow_test);
  tcase_add_test(tcase_core, s21_floor_test);
  tcase_add_test(tcase_core, s21_sqrt_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  int number_failed;
  Suite *suite = math_suite_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  // получаем количество проваленных тестов
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
