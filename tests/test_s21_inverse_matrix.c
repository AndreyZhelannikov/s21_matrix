#include "s21_matrix_test.h"

Suite *suite_s21_inverse_matrix(void) {
    Suite *s = suite_create("s21_inverse_matrix");
    TCase *tc = tcase_create("suite_s21_inverse_matrix");

    // tcase_add_test(tc, );

    suite_add_tcase(s, tc);
    return s;
}