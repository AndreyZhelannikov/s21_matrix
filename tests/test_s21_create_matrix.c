#include "s21_matrix_test.h"

START_TEST(create_test) {
    int rows = rand() % 10;
    int columns = rand() % 10;
    if (rand() % 2) rows = -rows;
    if (rand() % 2) columns = -columns;

    matrix_t matrix;
    int code = s21_create_matrix(rows, columns, &matrix);
    if (matrix.matrix && rows > 0 && columns > 0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ck_assert_double_eq_tol(matrix.matrix[i][j], 0, 1e-6);
            }
        }
        ck_assert_int_eq(matrix.rows, rows);
        ck_assert_int_eq(matrix.columns, columns);
        ck_assert_int_eq(code, OK);
    } else {
        if (rows <= 0 || columns <= 0) {
            ck_assert_int_eq(code, INCORRECT_MATRIX);
        } else {
            ck_assert_int_eq(code, MALLOC_FAILED);
        }
    }
    if (code == OK) s21_remove_matrix(&matrix);
}
END_TEST

Suite *suite_s21_create_matrix(void) {
    Suite *s = suite_create("s21_create_matrix");
    TCase *tc = tcase_create("suite_s21_create_matrix");

    tcase_add_loop_test(tc, create_test, 0, 100);

    suite_add_tcase(s, tc);
    return s;
}
