#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix_type != INCORRECT_MATRIX) {
        free(A->matrix);
        A->matrix = NULL;
        A->columns = 0;
        A->rows = 0;
        A->matrix_type = INCORRECT_MATRIX;
    }
}