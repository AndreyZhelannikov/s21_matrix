#include "s21_matrix_test.h"

START_TEST(sum_test_1) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);

    matrix_t A, B, sum1, sum2;
    int code1 = s21_create_matrix(rows, columns, &A);
    int code2 = s21_create_matrix(rows, columns, &B);
    int code3 = s21_create_matrix(rows, columns, &sum1);
    if (code1 == OK && code2 == OK && code3 == OK) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                A.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                B.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                sum1.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
            }
        }

        int code4 = s21_sum_matrix(&A, &B, &sum2);
        if (code4 != MALLOC_FAILED) {
            ck_assert_int_eq(code4, OK);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    ck_assert_double_eq_tol(sum1.matrix[i][j], sum2.matrix[i][j], 1e-6);
                }
            }
            s21_remove_matrix(&sum2);
        }
        s21_remove_matrix(&A);
        s21_remove_matrix(&B);
        s21_remove_matrix(&sum1);
    }
}
END_TEST

START_TEST(sum_test_2) {
    int rows1 = RandomInteger(1, 50);
    int rows2 = RandomInteger(51, 100);
    int columns1 = RandomInteger(1, 50);
    int columns2 = RandomInteger(51, 100);

    matrix_t A, B, sum2;
    int code1 = s21_create_matrix(rows1, columns1, &A);
    int code2 = s21_create_matrix(rows2, columns2, &B);
    int code3 = s21_sum_matrix(&A, &B, &sum2);

    if (code1 == OK && code2 == OK) ck_assert_int_eq(code3, CALC_ERROR);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_sum_matrix(void) {
    Suite *s = suite_create("s21_sum_matrix");
    TCase *tc = tcase_create("suite_s21_sum_matrix");

    tcase_add_loop_test(tc, sum_test_1, 0, 100);
<<<<<<< HEAD
=======
    tcase_add_loop_test(tc, sum_test_2, 0, 100);
>>>>>>> 912d433bbfff2b718fced1ecbdabbee315db6932

    suite_add_tcase(s, tc);
    return s;
}