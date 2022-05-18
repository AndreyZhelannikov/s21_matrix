#include "s21_matrix.h"

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    matrix_t sub;
    matrix_init_0(&sub);
    if (is_correct(A, B) && is_eq_size(A, B)) {
        sub = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                sub.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return sub;
}
