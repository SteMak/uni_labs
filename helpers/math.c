#include <math.h>

int takeEl(int *, int, int, int);

long long int factorial(int n) {
  if (n < 0)
    return -1;
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

float matrixAverage(int *mat, int a, int b) {
  int sum = 0;
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++)
      sum += takeEl(mat, b, i, j);
  return (float)sum / (a * b);
}

float matrixHarmonic(int *mat, int a, int b) {
  float sum = 0.0;
  for (int i = 0; i < a; i++)
    for (int j = 0; j < b; j++) {
      int el = takeEl(mat, b, i, j);
      if (el != 0)
        sum += 1.0 / el;
      else
        return 0;
    }
  return (a * b) / sum;
}
