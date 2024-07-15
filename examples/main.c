#include "..\Matrix\matrix.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  struct Matrix matrix;
  struct Matrix t_matrix;
  create_matrix(&matrix, 2, 2);
  matrix.matrix[0][1] = 1;
  t_matrix = transpose(&matrix);
  for (int i=0; i<t_matrix.rows; i++) {
    for (int j=0; j<t_matrix.columns; j++) printf("%.0f ", t_matrix.matrix[i][j]);
    printf("\n");
  }
  free_matrix(&matrix);
  free_matrix(&t_matrix);
  return 0;
}
