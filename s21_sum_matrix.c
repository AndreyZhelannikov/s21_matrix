#include "s21_matrix.h"

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t sum;
    matrix_init_0(&sum);
    if (is_correct(A, B) && is_eq_size(A, B)) {
        sum = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                sum.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
    return sum;
}

void matrix_init_0(matrix_t *A) {
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
    A->matrix_type = INCORRECT_MATRIX;
}

int is_eq_size(matrix_t *A, matrix_t *B) { return A->rows == B->rows && A->columns == B->columns; }

int is_correct(matrix_t *A, matrix_t *B) {
    return A->matrix_type != INCORRECT_MATRIX && B->matrix_type != INCORRECT_MATRIX;
}