#include "s21_matrix_test.h"

START_TEST(test1) {
    int rows = RandomInteger(1, 100);
    int columns = RandomInteger(1, 100);
    gsl_matrix *gsl_m = gsl_matrix_alloc(rows, columns);
    gsl_matrix *gsl_transpose = gsl_matrix_alloc(columns, rows);

    matrix_t m = {0}, transpose = {0};
    int code = s21_create_matrix(rows, columns, &m);
    if (code == OK) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                double num = RandomReal(-DBL_MIN, DBL_MAX);
                gsl_matrix_set(gsl_m, i, j, num);
                m.matrix[i][j] = num;
            }
        }

        gsl_matrix_transpose_memcpy(gsl_transpose, gsl_m);
        int t_code = s21_transpose(&m, &transpose);
        if (t_code == OK) {
            ck_assert_int_eq(transpose.rows, columns);
            ck_assert_int_eq(transpose.columns, rows);
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < rows; j++) {
                    ck_assert_double_eq_tol(transpose.matrix[i][j], gsl_matrix_get(gsl_transpose, i, j),
                                            1e-6);
                }
            }
            s21_remove_matrix(&transpose);
        }
        s21_remove_matrix(&m);
    }

    gsl_matrix_free(gsl_m);
    gsl_matrix_free(gsl_transpose);
}
END_TEST

Suite *suite_s21_transpose(void) {
    Suite *s = suite_create("s21_transpose");
    TCase *tc = tcase_create("suite_s21_transpose");

    tcase_add_loop_test(tc, test1, 0, 10);

    suite_add_tcase(s, tc);
    return s;
}