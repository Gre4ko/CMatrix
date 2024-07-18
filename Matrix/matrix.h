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
<<<<<<< HEAD
struct Matrix add_matrices(const struct Matrix *, const struct Matrix *);
struct Matrix sub_matrices(const struct Matrix *, const struct Matrix *);
struct Matrix matrix_mul_double(const struct Matrix *, double);
struct Matrix mul_matrices(const struct Matrix *, const struct Matrix *);


void print_matrix(const struct Matrix *);
#endif // MYHEADER_H
=======
#endif
>>>>>>> 2bab85ce1d10f12b974d2ceb0450ef72ce32d915
