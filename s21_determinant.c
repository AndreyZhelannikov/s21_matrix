#include "s21_matrix.h"

double det(matrix_t *tmp, int n);

int s21_determinant(matrix_t *A, double *result) {
    if (is_incorrect(A))
        return INCORRECT_MATRIX;
    if (A->rows != A->columns)
        return CALC_ERROR;
    if (A->rows == 1) {
        *result = A->matrix[0][0];
        return OK;
    }

    int n = A->rows;

    matrix_t tmp;
    int code = s21_create_matrix(n, n, &tmp);

    if (code == OK) {
        *result = det(A, n);
    }
    s21_remove_matrix(&tmp);
    return code;
}

double det(matrix_t *tmp, int n) {
    if (n == 1)
        return tmp->matrix[0][0];
    double determ = 0;

    matrix_t tmp2;
    int code = s21_create_matrix(n, n, &tmp2);

    if (code == OK) {
        int sign = 1;
        for (int i = 0; i < n; i++) {
            get_cofactor(tmp, &tmp2, 0, i, n);
            determ += sign * tmp->matrix[0][i] * det(&tmp2, n - 1);
            sign = -sign;
        }
        s21_remove_matrix(&tmp2);
    }
    return determ;
}

void get_cofactor(matrix_t *A, matrix_t *dest, int row, int col, int n) {
    dest->rows = n - 1;
    dest->columns = n - 1;
    for (int i = 0; i < n; i++) {
        int r = 0;
        int c = 0;
        if (i == row)
            r = 1;
        c = 0;
        for (int j = 0; j < n; j++) {
            if (j == col)
                c = 1;
            if (i != row && j != col)
                dest->matrix[i - r][j - c] = A->matrix[i][j];
        }
    }
}