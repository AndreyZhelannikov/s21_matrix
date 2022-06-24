#include "s21_matrix_test.h"

START_TEST(det_test1) {
    int s = 0;
    int n = RandomInteger(1, 10);
    matrix_t m;
    int code = s21_create_matrix(n, n, &m);

    if (code == OK) {
        gsl_matrix *gsl_m = gsl_matrix_calloc(n, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double num = RandomReal(-10, 10);
                gsl_matrix_set(gsl_m, i, j, num);
                m.matrix[i][j] = num;
            }
        }

        double det;
        int code_d = s21_determinant(&m, &det);

        gsl_permutation *p = gsl_permutation_alloc(n);
        gsl_linalg_LU_decomp(gsl_m, p, &s);
        double det_gsl = gsl_linalg_LU_det(gsl_m, s);

        if (code_d == OK) {
            ck_assert_double_eq_tol(det, det_gsl, 1e-6);
        }

        gsl_matrix_free(gsl_m);
        s21_remove_matrix(&m);
        gsl_permutation_free(p);
    }
}
END_TEST

Suite *suite_s21_determinant(void) {
    Suite *s = suite_create("s21_determinant");
    TCase *tc = tcase_create("suite_s21_determinant");

    tcase_add_loop_test(tc, det_test1, 0, 100);

    suite_add_tcase(s, tc);
    return s;
}