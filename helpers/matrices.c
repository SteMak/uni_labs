#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int *newMatrix(int a)
{
  int *mat;
  mat = malloc(sizeof(int) * a * a);

  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      *(mat + i * a + j) = i * a + j;
  return mat;
}

int takeEl(int *mat, int a, int i, int j)
{
  return *(mat + i * a + j);
}
void placeEl(int *mat, int a, int i, int j, int el)
{
  *(mat + i * a + j) = el;
}
void incrEl(int *mat, int a, int i, int j, int el)
{
  *(mat + i * a + j) += el;
}

void stringifyMatrix(int *mat, int a, char *matStr)
{
  char strEl[32] = "";
  for (int i = 0; i < a; i++)
  {
    strcat(matStr, "[ ");
    for (int j = 0; j < a; j++)
    {
      sprintf(strEl, "%d ", takeEl(mat, i, a, j));
      strcat(matStr, strEl);
    }
    strcat(matStr, "] ");
  }
}

int *matrixSum(int *matA, int *matB, int a)
{
  int *sum = newMatrix(a);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      placeEl(sum, a, i, j, takeEl(matA, a, i, j) + takeEl(matB, a, i, j));
  return sum;
}

int *matrixMultiplication(int *matA, int *matB, int a)
{
  int *mult = newMatrix(a);
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
    {
      placeEl(mult, a, i, j, 0);
      for (int k = 0; k < a; k++)
        incrEl(mult, a, i, j, takeEl(matA, a, i, k) * takeEl(matB, a, k, j));
    }
  return mult;
}

void randomizeMatrix(int *mat, int a)
{
  srand(time(NULL));
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      placeEl(mat, a, i, j, rand() % 100);
}
