#include "s21_matrix_test.h"

START_TEST(sub_test_1) {
    int rows = RandomInteger(-10, 100);
    int columns = RandomInteger(-10, 100);

    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);
    matrix_t sub1 = s21_create_matrix(rows, columns);

    if (rows > 0 && columns > 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                A.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                B.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                sub1.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
            }
        }
    }

    matrix_t sub2 = s21_sub_matrix(&A, &B);

    if (rows > 0 && columns > 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ck_assert_double_eq_tol(sub1.matrix[i][j], sub2.matrix[i][j], 1e-7);
            }
        }
    } else {
        ck_assert_int_eq(sub2.rows, 0);
        ck_assert_int_eq(sub2.columns, 0);
        ck_assert_int_eq(sub2.matrix_type, INCORRECT_MATRIX);
        ck_assert_ptr_null(sub2.matrix);
    }
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&sub1);
    s21_remove_matrix(&sub2);
}
END_TEST

Suite *suite_s21_sub_matrix(void) {
    Suite *s = suite_create("s21_sub_matrix");
    TCase *tc = tcase_create("suite_s21_sub_matrix");

    tcase_add_loop_test(tc, sub_test_1, 0, 1000);

    suite_add_tcase(s, tc);
    return s;
}