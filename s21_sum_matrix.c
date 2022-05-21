#include "s21_matrix.h"

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t sum;
    matrix_init_0(&sum);
    if (is_correct(A) && is_correct(B) && is_eq_size(A, B)) {
        sum = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) { sum.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j]; }
        }
    }
    return sum;
}
