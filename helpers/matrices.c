#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void deleteMatrix(int *mat) {
  free(mat);
}

int *newMatrix(int a, int b) {
  int *mat;
  mat = malloc(sizeof(int) * a * b);

  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++)
      *(mat + i * b + j) = i * a + j;
  return mat;
}

int *changeMatrix(int *mat, int old_a, int old_b, int a, int b) {
  mat = realloc(mat, sizeof(int) * a * b);

  for (int i = old_a - 1; i < a; i++)
    for (int j = old_b; j < b; j++)
      *(mat + i * b + j) = i * b + j;

  return mat;
}

int takeEl(int *mat, int b, int i, int j) {
  return *(mat + i * b + j);
}
void setEl(int *mat, int b, int i, int j, int el) {
  *(mat + i * b + j) = el;
}
void incrEl(int *mat, int b, int i, int j, int incr) {
  *(mat + i * b + j) += incr;
}

void stringifyMatrix(int *mat, int a, int b, char *matStr) {
  char strEl[32] = "";
  for (int i = 0; i < a; i++) {
    strcat(matStr, "[ ");
    for (int j = 0; j < b; j++) {
      sprintf(strEl, "%d ", takeEl(mat, i, b, j));
      strcat(matStr, strEl);
    }
    strcat(matStr, "] ");
  }
}

int *matrixSum(int *matA, int *matB, int a, int b) {
  int *sum = newMatrix(a, b);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++)
      setEl(sum, b, i, j, takeEl(matA, b, i, j) + takeEl(matB, b, i, j));
  return sum;
}

int *matrixMultiplication(int *matA, int *matB, int a, int b, int c) {
  int *mult = newMatrix(a, b);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++) {
      setEl(mult, b, i, j, 0);
      for (int k = 0; k < c; k++)
        incrEl(mult, b, i, j, takeEl(matA, b, i, k) * takeEl(matB, b, k, j));
    }
  return mult;
}

void randomizeMatrix(int *mat, int a, int b) {
  srand(time(NULL));
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++)
      setEl(mat, b, i, j, rand() % 100);
}
