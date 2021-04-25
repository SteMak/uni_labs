#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

long long int factorial(int n)
{
  if (n < 0)
    return -1;
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

char *stringifyArray(int *arr, int a, char *arrayStr)
{
  for (int i = 0; i < a; i++)
  {
    char strEl[32] = "";
    sprintf(strEl, "%d ", arr[i]);
    strcat(arrayStr, strEl);
  }
  return arrayStr;
}

int sumArray(int *arr, int a)
{
  int sum = 0;
  for (int i = 0; i < a; i++)
    sum += arr[i];
  return sum;
}

int maxArray(int *arr, int a)
{
  if (a <= 0)
    return -1;
  int max = arr[0];
  for (int i = 1; i < a; i++)
    if (max < arr[i])
      max = arr[i];
  return max;
}

void randomizeArray(int *arr, int a)
{
  srand(time(NULL));
  for (int i = 0; i < a; i++)
    arr[i] = rand() % 100;
}

void fibonaccinizeArray(int *arr, int a)
{
  if (a >= 2)
  {
    arr[0] = 1;
    arr[1] = 1;
  }
  for (int i = 2; i < a; i++)
    arr[i] = arr[i - 1] + arr[i - 2];
}

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
