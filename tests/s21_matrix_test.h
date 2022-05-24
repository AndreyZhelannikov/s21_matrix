#ifndef TEST
#define TEST

#include <check.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_blas_types.h>
#include <gsl/gsl_cblas.h>
#include <gsl/gsl_matrix.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../s21_matrix.h"

Suite *suite_s21_create_matrix(void);
Suite *suite_s21_remove_matrix(void);
Suite *suite_s21_eq_matrix(void);
Suite *suite_s21_sum_matrix(void);
Suite *suite_s21_sub_matrix(void);
Suite *suite_s21_mult_number(void);
Suite *suite_s21_mult_matrix(void);
Suite *suite_s21_transpose(void);
Suite *suite_s21_calc_complements(void);
Suite *suite_s21_determinant(void);
Suite *suite_s21_inverse_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase);

double RandomReal(double low, double high);
int RandomInteger(int low, int high);

void print_matrix(matrix_t *A);
void print_line(int n);

#endif  //  TEST
