#include "s21_matrix_test.h"

Suite *suite_s21_mult_number(void) {
    Suite *s = suite_create("s21_mult_number");
    TCase *tc = tcase_create("suite_s21_mult_number");

    // tcase_add_test(tc, );

    suite_add_tcase(s, tc);
    return s;
}