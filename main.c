#include "tests/s21_matrix_test.h"

int main(void) {
    srand(time(0));
    run_tests();

    return 0;
}

void run_testcase(Suite *testcase) {
    static int counter_testcase = 1;

    if (counter_testcase > 1)
        putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;

    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
}
void run_tests(void) {
    Suite *list_cases[] = {                               //
                           suite_s21_create_matrix(),     // DONE
                           suite_s21_remove_matrix(),     // DONE
                           suite_s21_eq_matrix(),         // DONE
                           suite_s21_sum_matrix(),        // DONE
                           suite_s21_sub_matrix(),        // DONE
                           suite_s21_mult_number(),       // DONE
                           suite_s21_mult_matrix(),       // DONE
                           suite_s21_transpose(),         // DONE
                           suite_s21_calc_complements(),  // DONE
                           suite_s21_determinant(),       // DONE
                           suite_s21_inverse_matrix(),    //
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

void print_matrix(matrix_t *A) {
    print_line(A->columns);
    for (int i = 0; i < A->rows; i++) {
        printf("|");
        for (int j = 0; j < A->columns; j++) {
            printf("%8.2lf", A->matrix[i][j]);
            if (j != A->columns - 1)
                printf(" ");
        }

        printf("|\n");
    }
    print_line(A->columns);
}

void print_line(int n) {
    int k = n * 9 + 1;
    if (n != 0) {
        for (int i = 0; i < k; i++) {
            printf("-");
        }
        printf("\n");
    }
}
