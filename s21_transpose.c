#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    int code = s21_create_matrix(A->columns, A->rows, result);
    if (code != MALLOC_FAILED) {
        for (int i = 0; i < A->columns; i++) {
            for (int j = 0; j < A->rows; j++) {
                result->matrix[i][j] = A->matrix[j][i];
            }
        }
    }
    return code;
}