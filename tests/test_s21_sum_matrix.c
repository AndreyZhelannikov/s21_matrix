#include "s21_matrix_test.h"

START_TEST(sum_test_1) {
    int rows = RandomInteger(-10, 100);
    int columns = RandomInteger(-10, 100);

    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);
    matrix_t sum1 = s21_create_matrix(rows, columns);

    if (rows > 0 && columns > 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                A.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                B.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                sum1.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
            }
        }
    }

    matrix_t sum2 = s21_sum_matrix(&A, &B);

    if (rows > 0 && columns > 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ck_assert_double_eq_tol(sum1.matrix[i][j], sum2.matrix[i][j], 1e-7);
            }
        }
    } else {
        ck_assert_int_eq(sum2.rows, 0);
        ck_assert_int_eq(sum2.columns, 0);
        ck_assert_int_eq(sum2.matrix_type, INCORRECT_MATRIX);
        ck_assert_ptr_null(sum2.matrix);
    }
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&sum1);
    s21_remove_matrix(&sum2);
}
END_TEST

Suite *suite_s21_sum_matrix(void) {
    Suite *s = suite_create("s21_sum_matrix");
    TCase *tc = tcase_create("suite_s21_sum_matrix");

    tcase_add_loop_test(tc, sum_test_1, 0, 1000);

    suite_add_tcase(s, tc);
    return s;
}