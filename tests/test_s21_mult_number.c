#include "s21_matrix_test.h"

START_TEST(mult_test_1) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);
    double number = RandomReal(-100, 100);

    matrix_t A = {0}, mult1 = {0}, mult2 = {0};
    int code1 = s21_create_matrix(rows, columns, &A);
    int code2 = s21_create_matrix(rows, columns, &mult1);
    if (code1 == OK && code2 == OK) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                A.matrix[i][j] = RandomReal(-DBL_MIN / 100.0, DBL_MAX / 100.0);
                mult1.matrix[i][j] = A.matrix[i][j] * number;
            }
        }

        int code3 = s21_mult_number(&A, number, &mult2);
        if (code3 != CALC_ERROR) {
            ck_assert_int_eq(code3, OK);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    ck_assert_double_eq_tol(mult1.matrix[i][j], mult2.matrix[i][j], 1e-6);
                }
            }
            s21_remove_matrix(&mult2);
        }
        s21_remove_matrix(&A);
        s21_remove_matrix(&mult1);
    }
}
END_TEST

Suite *suite_s21_mult_number(void) {
    Suite *s = suite_create("s21_mult_matrix");
    TCase *tc = tcase_create("suite_s21_mult_matrix");

    tcase_add_loop_test(tc, mult_test_1, 0, 10);

    suite_add_tcase(s, tc);
    return s;
}
