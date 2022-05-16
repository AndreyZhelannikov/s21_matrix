#include "s21_matrix_test.h"

Suite *suite_s21_calc_complements(void) {
    Suite *s = suite_create("s21_calc_complements");
    TCase *tc = tcase_create("suite_s21_calc_complements");

    // tcase_add_test(tc, );

    suite_add_tcase(s, tc);
    return s;
}