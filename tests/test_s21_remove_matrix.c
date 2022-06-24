#include "s21_matrix_test.h"

START_TEST(remove_test) {
    int rows = rand() % 100;
    int columns = rand() % 100;
    matrix_t matrix = {0};
    int code = s21_create_matrix(rows, columns, &matrix);
    if (code == OK) {
        s21_remove_matrix(&matrix);
        ck_assert_ptr_null(matrix.matrix);
        ck_assert_int_eq(matrix.rows, 0);
        ck_assert_int_eq(matrix.columns, 0);
    }
}
END_TEST

Suite *suite_s21_remove_matrix(void) {
    Suite *s = suite_create("s21_remove_matrix");
    TCase *tc = tcase_create("suite_s21_remove_matrix");

    tcase_add_loop_test(tc, remove_test, 0, 10);

    suite_add_tcase(s, tc);
    return s;
}