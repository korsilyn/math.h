#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.141592653589793
#define S21_NAN 0.0 / 0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_LN2 0.693147180559945
#define S21_E 2.718281828459045
// #define CONST_COS (double[]){0.965925826289068, 0.866025403784439,
// 0.707106781186548, 0.500000000000000, 0.258819045102521, 0.000000000000000}
// #define CONST_SIN (double[]){0.258819045102521, 0.500000000000000,
// 0.707106781186548, 0.866025403784439, 0.965925826289068, 1.000000000000000}
#define S21_EPS 1e+17

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_POS || x == S21_INF_NEG)

int s21_abs(int x);
long double s21_sqrt(double x);
long double s21_log(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_exp(double x);
long double factorial(int n);
long double s21_pow(double base, double exp);
long double s21_fmod(double x, double y);
void calculate_cos_null(long double* res, int minus, double x,
                        int num_of_cycles);
void calculate_cos_straight(long double* res, int minus, double x,
                            int num_of_cycles, int sign);
void calculate_sin_null(long double* res, double x, int num_of_cycles);
void calculate_sin_straight(long double* res, double x, int num_of_cycles,
                            int sign);

#endif
