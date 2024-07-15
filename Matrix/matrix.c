#ifndef MATRIX_cpp
#define MATRIX_cpp
#include "matrix.h"
#include <stdlib.h>

//ru: Создание матрицы raws*columns
//en: Creating raws*columns matrix
void create_matrix(struct Matrix *mat, int raws, int columns) {
  //ru: Создание двумерного массива data и динамическое выделение памяти для него
  //en: Creating a two-dimensional data array and dynamic memory allocation for it
  double** data = (double**)malloc(raws * sizeof(double*));
  for (int i=0; i<raws; i++) {
    data[i] = (double*)malloc(columns*sizeof(double));
    for (int j=0; j<columns; j++) data[i][j] = 0;
  }

  //ru: Заполняем Matrix значениями
  //en: Fill Matrix with values
  mat->matrix = data;
  mat->raws = raws;
  mat->columns = columns;

}

//ru: Освобождение памяти от matrix. Мы же не хотим утечек памяти, верно?
//en: Releasing the memory from the matrix. We don't want memory leaks, right?
void free_matrix(struct Matrix *mat) {
    for (int i = 0; i < mat->raws; ++i) free(mat->matrix[i]);
    free(mat->matrix);
}

//ru: Заполнение матрицы каким-то значением
//en: Filling matrix with some value
void fill_matrix(struct Matrix *mat, double value) {
  for (int i=0; i<mat->raws; i++)
    for (int j=0; j<mat->columns; j++)
      mat->matrix[i][j] = value;
}

//ru: Транспонирование матрицы, в общем это база.
//en: Matrix transpose, that's basically the base.
struct Matrix transpose(const struct Matrix *mat) {
    struct Matrix result;
    create_matrix(&result, mat->columns, mat->raws);

    for (int i = 0; i < mat->raws; ++i)
        for (int j = 0; j < mat->columns; ++j)
          result.matrix[j][i] = mat->matrix[i][j];

    return result;
}

#endif
