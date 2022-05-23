#include "s21_matrix_test.h"

START_TEST(mult_number_test_1) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t mul2 = s21_create_matrix(rows, columns);
    double mult = RandomReal(-10, 10);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            double number = RandomReal(-1e5, 1e5);
            A.matrix[i][j] = number;
            mul2.matrix[i][j] = number * mult;
        }
    }

    matrix_t mul1 = s21_mult_number(&A, mult);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ck_assert_double_eq_tol(mul1.matrix[i][j], mul2.matrix[i][j], 1e-7);
        }
    }

    s21_remove_matrix(&A);
    s21_remove_matrix(&mul1);
    s21_remove_matrix(&mul2);
}
END_TEST

START_TEST(mult_number_test_2) {
    int rows = RandomInteger(-10, 0);
    int columns = RandomInteger(-10, 0);
    matrix_t A = s21_create_matrix(rows, columns);
    double mult = RandomReal(-10, 10);

    matrix_t mul = s21_mult_number(&A, mult);

    ck_assert_int_eq(mul.rows, 0);
    ck_assert_int_eq(mul.columns, 0);
    ck_assert_int_eq(mul.matrix_type, INCORRECT_MATRIX);
    ck_assert_ptr_null(mul.matrix);

    s21_remove_matrix(&A);
    s21_remove_matrix(&mul);
}
END_TEST

Suite *suite_s21_mult_number(void) {
    Suite *s = suite_create("s21_mult_number");
    TCase *tc = tcase_create("suite_s21_mult_number");

    tcase_add_loop_test(tc, mult_number_test_1, 0, 100);
    tcase_add_loop_test(tc, mult_number_test_2, 0, 100);

    suite_add_tcase(s, tc);
    return s;
}