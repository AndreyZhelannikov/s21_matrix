#include "tests/s21_matrix_test.h"

int main(void) {
    run_tests();

    return 0;
}

void run_testcase(Suite *testcase) {
    static int counter_testcase = 1;

    if (counter_testcase > 1) putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;

    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
}
void run_tests(void) {
    Suite *list_cases[] = {suite_s21_create_matrix(),  //
                           suite_s21_remove_matrix(),  //
                                                       //    suite_s21_eq_matrix(),         //
                                                       //    suite_s21_sum_matrix(),        //
                                                       //    suite_s21_sub_matrix(),        //
                                                       //    suite_s21_mult_number(),       //
                                                       //    suite_s21_mult_matrix(),       //
                                                       //    suite_s21_transpose(),         //
                                                       //    suite_s21_calc_complements(),  //
                                                       //    suite_s21_determinant(),       //
                                                       //    suite_s21_inverse_matrix(),    //
                           NULL};

    for (Suite **current_testcase = list_cases; *current_testcase != NULL; current_testcase++) {
        run_testcase(*current_testcase);
    }
}

double RandomReal(double low, double high) {
    double d;

    d = (double)rand() / ((double)RAND_MAX + 1);
    return (low + d * (high - low));
}

int RandomInteger(int low, int high) {
    int k;
    double d;

    d = (double)rand() / ((double)RAND_MAX + 1);
    k = (int)(d * (high - low + 1));
    return (low + k);
}

double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
