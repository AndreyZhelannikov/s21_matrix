#include "s21_matrix_test.h"

START_TEST(mult_test1) {  //
    int n = RandomInteger(1, 5);
    int columns = RandomInteger(1, 5);
    int rows = RandomInteger(1, 5);

    matrix_t m1 = {0}, m2 = {0}, mul = {0};
    int code1 = s21_create_matrix(rows, n, &m1);
    int code2 = s21_create_matrix(n, columns, &m2);

    if (code1 == OK && code2 == OK) {
        gsl_matrix *gsl_m1 = gsl_matrix_alloc(rows, n);
        gsl_matrix *gsl_m2 = gsl_matrix_alloc(n, columns);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < n; j++) {
                double num = RandomReal(-DBL_MIN / 10000, DBL_MIN / 10000);
                m1.matrix[i][j] = num;
                gsl_matrix_set(gsl_m1, i, j, num);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < columns; j++) {
                double num = RandomReal(-DBL_MIN / 10000, DBL_MIN / 10000);
                m2.matrix[i][j] = num;
                gsl_matrix_set(gsl_m2, i, j, num);
            }
        }

        gsl_matrix *gsl_mul = gsl_matrix_alloc(rows, columns);
        gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, gsl_m1, gsl_m2, 0.0, gsl_mul);

        int mul_code = s21_mult_matrix(&m1, &m2, &mul);

        if (mul_code != CALC_ERROR) {
            ck_assert_int_eq(mul.rows, rows);
            ck_assert_int_eq(mul.columns, columns);

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    ck_assert_double_eq_tol(mul.matrix[i][j], gsl_matrix_get(gsl_mul, i, j), 1e-6);
                }
            }
        }

        gsl_matrix_free(gsl_m1);
        gsl_matrix_free(gsl_m2);
        gsl_matrix_free(gsl_mul);
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&mul);
    }
}
END_TEST

START_TEST(incorrect_matrix_1) {
    matrix_t m1 = {0};
    matrix_t m2 = {0};
    int code1 = s21_create_matrix(5, 5, &m1);
    int code2 = s21_create_matrix(6, 6, &m2);
    if (code1 == OK && code2 == OK) {
        matrix_t result;
        int mul_code = s21_mult_matrix(&m1, &m2, &result);
        ck_assert_int_eq(mul_code, CALC_ERROR);
    }
    s21_remove_matrix(&m1);
    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(incorrect_matrix_2) {
    matrix_t m1 = {0};
    matrix_t m2 = {0};
    int code1 = s21_create_matrix(5, 5, &m1);
    int code2 = s21_create_matrix(6, 6, &m2);
    m1.rows = -100;
    if (code1 == OK && code2 == OK) {
        matrix_t result;
        int mul_code = s21_mult_matrix(&m1, &m2, &result);
        ck_assert_int_eq(mul_code, INCORRECT_MATRIX);
    }
    s21_remove_matrix(&m1);
    s21_remove_matrix(&m2);
}
END_TEST

Suite *suite_s21_mult_matrix(void) {
    Suite *s = suite_create("s21_mult_matrix");
    TCase *tc = tcase_create("suite_s21_mult_matrix");

    tcase_add_loop_test(tc, mult_test1, 0, 10);
    tcase_add_test(tc, incorrect_matrix_1);
    tcase_add_test(tc, incorrect_matrix_2);

    suite_add_tcase(s, tc);
    return s;
}
