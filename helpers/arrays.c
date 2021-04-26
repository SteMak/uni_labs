#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *stringifyArray(int *arr, int a, char *arrayStr) {
  for (int i = 0; i < a; i++) {
    char strEl[32] = "";
    sprintf(strEl, "%d ", arr[i]);
    strcat(arrayStr, strEl);
  }
  return arrayStr;
}

int sumArray(int *arr, int a) {
  int sum = 0;
  for (int i = 0; i < a; i++)
    sum += arr[i];
  return sum;
}

int maxArray(int *arr, int a) {
  if (a <= 0)
    return -1;
  int max = arr[0];
  for (int i = 1; i < a; i++)
    if (max < arr[i])
      max = arr[i];
  return max;
}

void randomizeArray(int *arr, int a) {
  srand(time(NULL));
  for (int i = 0; i < a; i++)
    arr[i] = rand() % 100;
}

void fibonaccinizeArray(int *arr, int a) {
  if (a >= 2) {
    arr[0] = 1;
    arr[1] = 1;
  }
  for (int i = 2; i < a; i++)
    arr[i] = arr[i - 1] + arr[i - 2];
}
