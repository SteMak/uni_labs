#include <stdio.h>
#include <math.h>

#define Lab5_1Options 6
#define Lab5_1Images 2
#define Lab5_1Solutions 2

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();
int *scanAswerMatrix(int, int **);

int **matrixSum(int **, int **, int, int **);
int **matrixMultiplication(int **, int **, int, int **);
char *stringifyMatrix(int **, int, char *);
int **randomizeMatrix(int **, int);

int mainMenu(int, int);
int lab5_1Menu(int, int, int, int **, int **);
int lab5_1ScanA(int, int, int, int **, int **);
int lab5_1ScanMatA(int, int, int, int **, int **);
int lab5_1ScanMatB(int, int, int, int **, int **);

int lab5_1Menu(int cols, int rows, int a, int **matA, int **matB)
{
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

  int matSum[32][32];
  int matMult[32][32];
  int *matSumAll[32];
  int *matMultAll[32];
  for (int i = 0; i < a; i++)
  {
    matSumAll[i] = matSum[i];
    matMultAll[i] = matMult[i];
    for (int j = 0; j < a; j++)
    {
      matSumAll[i][j] = matSum[i][j];
      matMultAll[i][j] = matMult[i][j];
    }
  }
  matrixSum(matA, matB, a, matSumAll);
  matrixMultiplication(matA, matB, a, matMultAll);
  char matSumStr[512] = "";
  char matMultStr[512] = "";
  stringifyMatrix(matSumAll, a, matSumStr);
  stringifyMatrix(matMultAll, a, matMultStr);
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

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab5_1ScanA(cols, rows, a, matA, matB);
    break;
  case 2:
    lab5_1ScanMatA(cols, rows, a, matA, matB);
    break;
  case 3:
    lab5_1ScanMatB(cols, rows, a, matA, matB);
    break;
  case 4:
  {
    matA = randomizeMatrix(matA, a);
    lab5_1Menu(cols, rows, a, matA, matB);
    break;
  }
  case 5:
  {
    matB = randomizeMatrix(matB, a);
    lab5_1Menu(cols, rows, a, matA, matB);
    break;
  }
  default:
    lab5_1Menu(cols, rows, a, matA, matB);
  }

  return 0;
}

int lab5_1ScanA(int cols, int rows, int a, int **matA, int **matB)
{
  char *solutions[1] = {"Please, enter new matrix border length"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab5_1Menu(cols, rows, choice, matA, matB);
}

int lab5_1ScanMatA(int cols, int rows, int a, int **matA, int **matB)
{
  char request[512];
  sprintf(request, "Please, enter new matrix A of length %d×%d", a, a);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerMatrix(a, matA);
  lab5_1Menu(cols, rows, a, matA, matB);
}

int lab5_1ScanMatB(int cols, int rows, int a, int **matA, int **matB)
{
  char request[512];
  sprintf(request, "Please, enter new matrix B of length %d×%d", a, a);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerMatrix(a, matB);
  lab5_1Menu(cols, rows, a, matA, matB);
}
