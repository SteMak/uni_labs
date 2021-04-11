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
  int max = 0;
  for (int i = 0; i < a; i++)
    if (max < arr[i])
      max = arr[i];
  return max;
}

int *randomizeArray(int *arr, int a)
{
  srand(time(NULL));
  for (int i = 0; i < a; i++)
    arr[i] = rand() % 100;
  return arr;
}

int *fibonaccinizeArray(int *arr, int a)
{
  if (a >= 2)
  {
    arr[0] = 1;
    arr[1] = 1;
  }
  for (int i = 2; i < a; i++)
    arr[i] = arr[i - 1] + arr[i - 2];
  return arr;
}

char *stringifyMatrix(int **mat, int a, char *matStr)
{
  for (int i = 0; i < a; i++)
  {
    char strEl[32] = "";
    stringifyArray(mat[i], a, strEl);
    strcat(matStr, "[ ");
    strcat(matStr, strEl);
    strcat(matStr, "] ");
  }
  return matStr;
}

int **matrixSum(int **matA, int **matB, int a, int **sum)
{
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      sum[i][j] = matA[i][j] + matB[i][j];

  return sum;
}

int **matrixMultiplication(int **matA, int **matB, int a, int **mult)
{
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < a; ++j)
      for (int k = 0; k < a; ++k)
        mult[i][j] += matA[i][k] * matB[k][j];

  return mult;
}

int **randomizeMatrix(int **mat, int a)
{
  srand(time(NULL));
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      mat[i][j] = rand() % 100;
  return mat;
}
