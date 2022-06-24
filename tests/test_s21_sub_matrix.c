#include "s21_matrix_test.h"

START_TEST(sub_test_1) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);

    matrix_t A = {0}, B = {0}, sub1 = {0}, sub2 = {0};
    int code1 = s21_create_matrix(rows, columns, &A);
    int code2 = s21_create_matrix(rows, columns, &B);
    int code3 = s21_create_matrix(rows, columns, &sub1);
    if (code1 == OK && code2 == OK && code3 == OK) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                A.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                B.matrix[i][j] = RandomReal(-DBL_MIN / 2.0, DBL_MAX / 2.0);
                sub1.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
            }
        }

        int code4 = s21_sub_matrix(&A, &B, &sub2);
        if (code4 != CALC_ERROR) {
            ck_assert_int_eq(code4, OK);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    ck_assert_double_eq_tol(sub1.matrix[i][j], sub2.matrix[i][j], 1e-6);
                }
            }
            s21_remove_matrix(&sub2);
        }
        s21_remove_matrix(&A);
        s21_remove_matrix(&B);
        s21_remove_matrix(&sub1);
    }
}
END_TEST

START_TEST(sub_test_2) {
    int rows1 = RandomInteger(1, 50);
    int rows2 = RandomInteger(51, 100);
    int columns1 = RandomInteger(1, 50);
    int columns2 = RandomInteger(51, 100);

    matrix_t A = {0}, B = {0}, sub2 = {0};
    int code1 = s21_create_matrix(rows1, columns1, &A);
    int code2 = s21_create_matrix(rows2, columns2, &B);
    int code3 = s21_sub_matrix(&A, &B, &sub2);

    if (code1 == OK && code2 == OK)
        ck_assert_int_eq(code3, CALC_ERROR);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_sub_matrix(void) {
    Suite *s = suite_create("s21_sub_matrix");
    TCase *tc = tcase_create("suite_s21_sub_matrix");

    tcase_add_loop_test(tc, sub_test_1, 0, 10);
    tcase_add_loop_test(tc, sub_test_2, 0, 10);

    suite_add_tcase(s, tc);
    return s;
}