#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int res = SUCCESS;
    if (is_correct(A) && is_correct(B) && is_eq_size(A, B)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) res = FAILURE;
            }
        }
    } else {
        res = FAILURE;
    }
    return res;
}