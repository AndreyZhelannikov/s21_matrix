#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int code = OK;
    if (rows > 0 && columns > 0) {
        result->matrix = calloc(1, rows * columns * sizeof(double) + rows * sizeof(double *));
        if (result->matrix) {
            double *ptr = (double *)(result->matrix + rows);
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = ptr + columns * i;
            }
        } else {
            code = CALC_ERROR;
        }
    } else {
        code = INCORRECT_MATRIX;
    }
    result->rows = rows;
    result->columns = columns;

    return code;
}