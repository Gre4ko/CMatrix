#ifndef MATRIX_H
#define MATRIX_H

/* Ru:
* Создание структуры матрицы.
* Состоит из двумерного массива matrix и целочисленных полей raws и columns
* С этой струткурой производится вся работа в данном модуле.
*  En:
* Create a matrix structure.
* Consists of a two-dimensional array matrix and integer fields raws and columns
* All work in this module is done with this structure.
*/
struct Matrix {
  double** matrix;
  int rows, columns;
};

void create_matrix(struct Matrix *, int, int);
void free_matrix(struct Matrix *);
void fill_matrix(struct Matrix *, double);
struct Matrix transpose(const struct Matrix *);
#endif
