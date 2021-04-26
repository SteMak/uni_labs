#include <math.h>
#include <stdio.h>

#define Lab5_1Options 6
#define Lab5_1Images 2
#define Lab5_1Solutions 2

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
int *scanAswerMatrix(int, int *);

int *matrixSum(int *, int *, int);
int *matrixMultiplication(int *, int *, int);
void stringifyMatrix(int *, int, char *);
void randomizeMatrix(int *, int);
void deleteMatrix(int *);

void lab5_1Menu(int, int, int, int *, int *, int);
int lab5_1ScanA(int, int);
void lab5_1ScanMatA(int, int, int, int *, int);
void lab5_1ScanMatB(int, int, int, int *, int);

void lab5_1Menu(int cols, int rows, int a, int *matA, int *matB, int size) {
  while (1) {
    char choicesFormat[Lab5_1Options][512] = {"Go back", "", "Enter A elements", "Enter B elements", "Randomize A", "Randomize B"};
    sprintf(choicesFormat[1], "Set matrix border length  (%d)\0", a);

    char *choices[Lab5_1Options];
    for (int i = 0; i < Lab5_1Options; i++)
      choices[i] = choicesFormat[i];

    char matAStr[512] = "";
    char matBStr[512] = "";
    stringifyMatrix(matA, a, matAStr);
    stringifyMatrix(matB, a, matBStr);
    char imagesFormat[Lab5_1Solutions][512];
    sprintf(imagesFormat[0], "A is [ %s]", matAStr);
    sprintf(imagesFormat[1], "B is [ %s]", matBStr);

    char *images[Lab5_1Images];
    for (int i = 0; i < Lab5_1Images; i++)
      images[i] = imagesFormat[i];

    int *matSum = matrixSum(matA, matB, a);
    int *matMult = matrixMultiplication(matA, matB, a);
    char matSumStr[512] = "";
    char matMultStr[512] = "";
    stringifyMatrix(matSum, a, matSumStr);
    stringifyMatrix(matMult, a, matMultStr);
    char solutionsFormat[Lab5_1Solutions][512];
    sprintf(solutionsFormat[0], "Sum of matrices is [ %s]", matSumStr);
    sprintf(solutionsFormat[1], "Multiplication of matrices is [ %s]", matMultStr);

    char *solutions[Lab5_1Solutions];
    for (int i = 0; i < Lab5_1Solutions; i++)
      solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab5_1Options, cols);
    drowSolutions(images, Lab5_1Images, cols);
    drowSolutions(solutions, Lab5_1Solutions, cols);
    drowWaitAnswer(cols, rows, Lab5_1Options + Lab5_1Solutions + Lab5_1Images);

    deleteMatrix(matSum);
    deleteMatrix(matMult);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab5_1ScanA(cols, rows);
        break;
      case 2:
        lab5_1ScanMatA(cols, rows, a, matA, size);
        break;
      case 3:
        lab5_1ScanMatB(cols, rows, a, matB, size);
        break;
      case 4: {
        randomizeMatrix(matA, a);
        break;
      }
      case 5: {
        randomizeMatrix(matB, a);
        break;
      }
    }
  }
}

int lab5_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new matrix border length"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

void lab5_1ScanMatA(int cols, int rows, int a, int *matA, int size) {
  char request[512];
  sprintf(request, "Please, enter new matrix A of length %dx%d", a, a);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerMatrix(a, matA);
}

void lab5_1ScanMatB(int cols, int rows, int a, int *matB, int size) {
  char request[512];
  sprintf(request, "Please, enter new matrix B of length %dx%d", a, a);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerMatrix(a, matB);
}
