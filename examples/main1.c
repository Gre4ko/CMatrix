#include "..\Matrix\matrix.h"
#include <stdio.h>

int main() {
  struct Matrix matrix;
  struct Matrix t_matrix;

  create_matrix(&matrix, 2, 2);
  matrix.matrix[0][1] = 1;
  t_matrix = transpose(&matrix);

  printf("Matrix: \n");
  print_matrix(&matrix);

  printf("\n Transpose matrix: \n");
  print_matrix(&t_matrix);

  free_matrix(&matrix);
  free_matrix(&t_matrix);
  return 0;
}
