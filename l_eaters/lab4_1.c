#include <stdio.h>
#include <math.h>

#define Lab4_1Options 5
#define Lab4_1Images 1
#define Lab4_1Solutions 2

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();
int *scanAswerArray(int, int *);

int sumArray(int *, int);
int maxArray(int *, int);
char *stringifyArray(int *, int, char *);
int *randomizeArray(int *, int);
int *fibonaccinizeArray(int *, int);

int mainMenu(int, int);
int lab4_1Menu(int, int, int, int *);
int lab4_1ScanA(int, int, int, int *);
int lab4_1ScanArray(int, int, int, int *);

int lab4_1Menu(int cols, int rows, int a, int *arr)
{
  char choicesFormat[Lab4_1Options][512] = {"Go back", "", "Enter array elements", "Randomize", "Fibonaccinize"};
  sprintf(choicesFormat[1], "Set array length  (%d)\0", a);

  char *choices[Lab4_1Options];
  for (int i = 0; i < Lab4_1Options; i++)
    choices[i] = choicesFormat[i];

  char arrayStr[512] = "";
  stringifyArray(arr, a, arrayStr);
  char imagesFormat[Lab4_1Solutions][512];
  sprintf(imagesFormat[0], "Array is [ %s]", arrayStr);

  char *images[Lab4_1Images];
  for (int i = 0; i < Lab4_1Images; i++)
    images[i] = imagesFormat[i];

  char solutionsFormat[Lab4_1Solutions][512];
  sprintf(solutionsFormat[0], "Sum of array elements is %d", sumArray(arr, a));
  sprintf(solutionsFormat[1], "Max of array elements is %d", maxArray(arr, a));

  char *solutions[Lab4_1Solutions];
  for (int i = 0; i < Lab4_1Solutions; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, Lab4_1Options, cols);
  drowSolutions(images, Lab4_1Images, cols);
  drowSolutions(solutions, Lab4_1Solutions, cols);
  drowWaitAnswer(cols, rows, Lab4_1Options + Lab4_1Solutions + Lab4_1Images);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab4_1ScanA(cols, rows, a, arr);
    break;
  case 2:
    lab4_1ScanArray(cols, rows, a, arr);
    break;
  case 3:
  {
    randomizeArray(arr, a);
    lab4_1Menu(cols, rows, a, arr);
    break;
  }
  case 4:
  {
    fibonaccinizeArray(arr, a);
    lab4_1Menu(cols, rows, a, arr);
    break;
  }
  default:
    lab4_1Menu(cols, rows, a, arr);
  }

  return 0;
}

int lab4_1ScanA(int cols, int rows, int a, int *arr)
{
  char *solutions[1] = {"Please, enter new array length"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab4_1Menu(cols, rows, choice, arr);
}

int lab4_1ScanArray(int cols, int rows, int a, int *arr)
{
  char request[512];
  sprintf(request, "Please, enter new array of length %d", a);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerArray(a, arr);
  lab4_1Menu(cols, rows, a, arr);
}
