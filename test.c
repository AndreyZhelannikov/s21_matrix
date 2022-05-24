#include <gsl/gsl_matrix.h>
#include <stdio.h>

int main(void) {
<<<<<<< HEAD
    int i, j;
    gsl_matrix* m = gsl_matrix_alloc(10, 3);

    for (i = 0; i < 10; i++)
        for (j = 0; j < 3; j++) gsl_matrix_set(m, i, j, 0.23 + 100 * i + j);

    for (i = 0; i < 10; i++)
        for (j = 0; j < 3; j++) printf("m(%d,%d) = %g\n", i, j, gsl_matrix_get(m, i, j));

    gsl_matrix_free(m);

    return 0;
}
=======
    gsl_matrix *m = gsl_matrix_alloc(10, 3);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            gsl_matrix_set(m, i, j, 0.23 + 100 * i + j);
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("m(%d, %d) = %g\n", i, j, gsl_matrix_get(m, i, j));
        }
    }
    gsl_matrix_free(m);

    return 0;
}
>>>>>>> 912d433bbfff2b718fced1ecbdabbee315db6932
