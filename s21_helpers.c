#include "s21_matrix.h"

int is_eq_size(matrix_t *A, matrix_t *B) { return A->rows == B->rows && A->columns == B->columns; }

int is_correct(matrix_t *A) { return A->matrix_type != INCORRECT_MATRIX && A->rows > 0 && A->columns > 0; }

void matrix_init_0(matrix_t *A) {
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
    A->matrix_type = INCORRECT_MATRIX;
}