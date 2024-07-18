#ifndef MATRIX_cpp
#define MATRIX_cpp
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

//ru: Создание матрицы rows*columns
//en: Creating rows*columns matrix
void create_matrix(struct Matrix *mat, int rows, int columns) {
  //ru: Создание двумерного массива data и динамическое выделение памяти для него
  //en: Creating a two-dimensional data array and dynamic memory allocation for it
  double** data = (double**)malloc(rows * sizeof(double*));
  for (int i=0; i<rows; i++) {
    data[i] = (double*)malloc(columns*sizeof(double));
    for (int j=0; j<columns; j++) data[i][j] = 0;
  }

  //ru: Заполняем Matrix значениями
  //en: Fill Matrix with values
  mat->matrix = data;
  mat->rows = rows;
  mat->columns = columns;

}

//ru: Освобождение памяти от matrix. Мы же не хотим утечек памяти, верно?
//en: Releasing the memory from the matrix. We don't want memory leaks, right?
void free_matrix(struct Matrix *mat) {
    for (int i = 0; i < mat->rows; ++i) free(mat->matrix[i]);
    free(mat->matrix);
}

//ru: Заполнение матрицы каким-то значением
//en: Filling matrix with some value
void fill_matrix(struct Matrix *mat, double value) {
  for (int i=0; i<mat->rows; i++)
    for (int j=0; j<mat->columns; j++)
      mat->matrix[i][j] = value;
}

//ru: Транспонирование матрицы, в общем это база.
//en: Matrix transpose, that's basically the base.
struct Matrix transpose(const struct Matrix *mat) {
    struct Matrix result;
    create_matrix(&result, mat->columns, mat->rows);

    for (int i = 0; i < mat->rows; ++i)
        for (int j = 0; j < mat->columns; ++j)
          result.matrix[j][i] = mat->matrix[i][j];

    return result;
}

//ru: Сложение матриц
//en: Matrix addition
struct Matrix add_matrices(const struct Matrix *a, const struct Matrix *b) {
  if (a->rows != b->rows || a->columns != b->columns) {
        fprintf(stderr, "Matrix dimensions must match for addition.\n");
        exit(EXIT_FAILURE);
  }

  struct Matrix result;
  create_matrix(&result, a->rows, a->columns);
  for (int i = 0; i<a->rows; i++)
    for (int j = 0; j<a->columns; j++)
      result.matrix[i][j] = a->matrix[i][j]+b->matrix[i][j];
  return result;
}

//ru: Вычитание матриц
//en: Subtraction of matrices
struct Matrix sub_matrices(const struct Matrix *a, const struct Matrix *b) {
  struct Matrix c = matrix_mul_double(b, -1);
  return add_matrices(a, &c);
}

//ru: Умножение матрицы на число
//en: Multiplying a matrix by a number
struct Matrix matrix_mul_double(const struct Matrix *a, double b) {
  struct Matrix result;
  create_matrix(&result, a->rows, a->columns);
  for (int i = 0; i<a->rows; i++)
    for (int j = 0; j<a->columns; j++)
      result.matrix[i][j] = a->matrix[i][j]*b;
  return result;
}

//ru: Умножение матриц
//en: Multiplication of matrices
struct Matrix mul_matrices(const struct Matrix *a, const struct Matrix *b) {
  if (a->columns != b->rows) {
        fprintf(stderr, "Number of columns of the first matrix must be equal to the number of rows of the second matrix.\n");
        exit(EXIT_FAILURE);
  }


  struct Matrix result;
  create_matrix(&result, a->rows, b->columns);

  for (int i = 0; i < a->rows; ++i) {
    for (int j = 0; j < b->columns; ++j) {
      for (int k = 0; k < a->columns; ++k) {
        result.matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
      }
    }
}

return result;
}

//ru: Печатание матрицы
//en: Printing the matrix
void print_matrix(const struct Matrix *mat) {
    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->columns; ++j) {
            printf("%lf ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}
#endif
