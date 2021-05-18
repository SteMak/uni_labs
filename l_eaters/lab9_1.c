#include <math.h>
#include <stdio.h>

#define Lab9_1Options 5
#define Lab9_1Images 2
#define Lab9_1Solutions 2

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
int *scanAswerMatrix(int, int, int *);

int *newMatrix(int, int);
int *changeMatrix(int *, int, int, int, int);
int *matrixSum(int *, int *, int, int);
int *matrixMultiplication(int *, int *, int, int, int);
void stringifyMatrix(int *, int, int, char *);
void randomizeMatrix(int *, int, int);
void deleteMatrix(int *);
float matrixAverage(int *, int, int);
float matrixHarmonic(int *, int, int);

int lab9_1ScanA(int, int);
int lab9_1ScanB(int, int);
void lab9_1ScanArr(int, int, int, int, int *);

void lab9_1Menu(int cols, int rows, int a, int b, int *mat, int *arr) {
  while (1) {
    char choicesFormat[Lab9_1Options][512] = {"Go back", "", "", "Randomize matrix", "Enter array elements"};
    sprintf(choicesFormat[1], "Enter N  (%d)\0", a);
    sprintf(choicesFormat[2], "Enter M  (%d)\0", b);

    char *choices[Lab9_1Options];
    for (int i = 0; i < Lab9_1Options; i++)
      choices[i] = choicesFormat[i];

    char matStr[512] = "";
    char arrStr[512] = "";
    stringifyMatrix(mat, a, b, matStr);
    stringifyMatrix(arr, 1, a, arrStr);
    char imagesFormat[Lab9_1Solutions][512];
    sprintf(imagesFormat[0], "Random matrix is [ %s]", matStr);
    sprintf(imagesFormat[1], "Array is %s", arrStr);

    char *images[Lab9_1Images];
    for (int i = 0; i < Lab9_1Images; i++)
      images[i] = imagesFormat[i];

    char solutionsFormat[Lab9_1Solutions][512];
    sprintf(solutionsFormat[0], "Array average is %.2f", matrixAverage(arr, 1, a));
    sprintf(solutionsFormat[1], "Array harmonic is %.2f", matrixHarmonic(arr, 1, a));

    char *solutions[Lab9_1Solutions];
    for (int i = 0; i < Lab9_1Solutions; i++)
      solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab9_1Options, cols);
    drowSolutions(images, Lab9_1Images, cols);
    drowSolutions(solutions, Lab9_1Solutions, cols);
    drowWaitAnswer(cols, rows, Lab9_1Options + Lab9_1Solutions + Lab9_1Images);

    switch (scanAswer()) {
      case 0: {
        deleteMatrix(arr);
        deleteMatrix(mat);
        return;
      }
      case 1: {
        int tmp = lab9_1ScanA(cols, rows);
        arr = changeMatrix(arr, 1, a, 1, tmp);
        a = tmp;
        mat = changeMatrix(mat, a, b, a, b);
        randomizeMatrix(mat, a, b);
        break;
      }
      case 2: {
        b = lab9_1ScanB(cols, rows);
        mat = changeMatrix(mat, a, b, a, b);
        randomizeMatrix(mat, a, b);
        break;
      }
      case 3:
        randomizeMatrix(mat, a, b);
        break;
      case 4:
        lab9_1ScanArr(cols, rows, 1, a, arr);
        break;
    }
  }
}

int lab9_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of N"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab9_1ScanB(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of M"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

void lab9_1ScanArr(int cols, int rows, int a, int b, int *arr) {
  char request[512];
  sprintf(request, "Please, enter new array of length %d", b);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerMatrix(a, b, arr);
}
