#include "s21_matrix.h"
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    if (is_incorrect(A))
        return INCORRECT_MATRIX;
    if (A->rows != A->columns)
        return CALC_ERROR;

    matrix_t tmp;
    int code = OK;
    double det = 0;

    s21_determinant(A, &det);
    int n = A->rows;
    if (fabs(det) > 1e-6) {
        if (n == 1) {
            int codec = s21_create_matrix(n, n, result);
            if (!codec)
                result->matrix[0][0] = 1.0 / A->matrix[0][0];
        } else {
            s21_calc_complements(A, result);
            s21_transpose(result, &tmp);

            s21_remove_matrix(result);

            s21_mult_number(&tmp, 1.0 / det, result);

            s21_remove_matrix(&tmp);
        }
    } else {
        code = CALC_ERROR;
    }
    return code;
}