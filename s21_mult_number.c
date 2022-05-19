#include "s21_matrix.h"

matrix_t s21_mult_number(matrix_t *A, double number) {
    matrix_t mul;
    matrix_init_0(&mul);
    if (is_correct(A)) {
        mul = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) { mul.matrix[i][j] = A->matrix[i][j] * number; }
        }
    }
    return mul;
}