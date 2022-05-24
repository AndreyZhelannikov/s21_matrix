t #include "s21_matrix.h"

    matrix_t
    s21_create_matrix(int rows, int columns) {
    int fail = 0;
    matrix_t matrix;
    if (rows > 0 && columns > 0) {
        matrix.matrix = calloc(1, rows * columns * sizeof(double) + rows * sizeof(double *));
        if (matrix.matrix) {
            double *ptr = (double *)(matrix.matrix + rows);
            for (int i = 0; i < rows; i++) {
                matrix.matrix[i] = ptr + columns * i;
            }
        }
        matrix.matrix_type = ZERO_MATRIX;
    } else {
        fail = 1;
    }
    matrix.rows = rows;
    matrix.columns = columns;

    if (fail || !matrix.matrix) {
        matrix.matrix = NULL;
        matrix.rows = 0;
        matrix.columns = 0;
        matrix.matrix_type = INCORRECT_MATRIX;
    }

    return matrix;
}