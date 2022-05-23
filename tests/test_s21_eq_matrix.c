#include "s21_matrix_test.h"

START_TEST(eq_correct) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            double number = RandomReal(-1e10, 1e10);
            A.matrix[i][j] = number;
            B.matrix[i][j] = number;
        }
    }

    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_incorrect_1) {
    int rows = RandomInteger(-100, 0);
    int columns = RandomInteger(-100, 0);
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_incorrect_2) {
    int rows1 = RandomInteger(-100, 0);
    int rows2 = RandomInteger(-100, 0);
    int columns1 = RandomInteger(-100, 0);
    int columns2 = RandomInteger(-100, 0);
    matrix_t A = s21_create_matrix(rows1, columns1);
    matrix_t B = s21_create_matrix(rows2, columns2);

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_diff_size) {
    int rows1 = RandomInteger(1, 50);
    int rows2 = RandomInteger(51, 100);
    int columns1 = RandomInteger(1, 50);
    int columns2 = RandomInteger(51, 100);
    matrix_t A = s21_create_matrix(rows1, columns1);
    matrix_t B = s21_create_matrix(rows2, columns2);

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_same_size) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            double number = RandomReal(-1e10, 1e10);
            A.matrix[i][j] = number;
            B.matrix[i][j] = number + 1;
        }
    }

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_zero) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);

    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_eq_matrix(void) {
    Suite *s = suite_create("s21_eq_matrix");
    TCase *tc = tcase_create("suite_s21_eq_matrix");

    tcase_add_loop_test(tc, eq_correct, 0, 100);
    tcase_add_loop_test(tc, eq_incorrect_1, 0, 100);
    tcase_add_loop_test(tc, eq_incorrect_2, 0, 100);
    tcase_add_loop_test(tc, eq_diff_size, 0, 100);
    tcase_add_loop_test(tc, eq_same_size, 0, 100);
    tcase_add_loop_test(tc, eq_zero, 0, 100);

    suite_add_tcase(s, tc);
    return s;
}
