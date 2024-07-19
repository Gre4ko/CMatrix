#ifndef MATRIX_H
#define MATRIX_H

/* Ua:
* Створення структури матриці.
* Складається з двовимірного масиву matrix та цілочисельних полів rows і columns
* Вся робота в цьому модулі виконується з цією структурою.
*  En:
* Create a matrix structure.
* Consists of a two-dimensional array matrix and integer fields rows and columns
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
struct Matrix add_matrices(const struct Matrix *, const struct Matrix *);
struct Matrix sub_matrices(const struct Matrix *, const struct Matrix *);
struct Matrix matrix_mul_double(const struct Matrix *, double);
struct Matrix mul_matrices(const struct Matrix *, const struct Matrix *);

void print_matrix(const struct Matrix *);
#endif // MYHEADER_H