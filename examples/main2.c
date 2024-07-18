#include "..\Matrix\matrix.h"
#include <stdio.h>

int main() {
    struct Matrix matrix1, matrix2, result;

    create_matrix(&matrix1, 2, 2);
    create_matrix(&matrix2, 2, 2);

    matrix1.matrix[0][0] = 1.0;
    matrix1.matrix[0][1] = 2.0;
    matrix1.matrix[1][0] = 3.0;
    matrix1.matrix[1][1] = 4.0;

    matrix2.matrix[0][0] = 5.0;
    matrix2.matrix[0][1] = 6.0;
    matrix2.matrix[1][0] = 7.0;
    matrix2.matrix[1][1] = 8.0;

    printf("Matrix 1:\n");
    print_matrix(&matrix1);

    printf("Matrix 2:\n");
    print_matrix(&matrix2);

    result = add_matrices(&matrix1, &matrix2);
    printf("Matrix 1 + Matrix 2:\n");
    print_matrix(&result);
    free_matrix(&result);

    result = sub_matrices(&matrix1, &matrix2);
    printf("Matrix 1 - Matrix 2:\n");
    print_matrix(&result);
    free_matrix(&result);

    result = mul_matrices(&matrix1, &matrix2);
    printf("Matrix 1 * Matrix 2:\n");
    print_matrix(&result);
    free_matrix(&result);

    free_matrix(&matrix1);
    free_matrix(&matrix2);

    return 0;
}
