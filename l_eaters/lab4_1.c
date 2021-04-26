#include <math.h>
#include <stdio.h>

#define Lab4_1Options 5
#define Lab4_1Images 1
#define Lab4_1Solutions 2

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
void scanAswerArray(int, int *);

int sumArray(int *, int);
int maxArray(int *, int);
void stringifyArray(int *, int, char *);
void randomizeArray(int *, int);
void fibonaccinizeArray(int *, int);

int lab4_1ScanA(int, int);
void lab4_1ScanArray(int, int, int, int *);

void lab4_1Menu(int cols, int rows, int a, int *arr) {
  while (1) {
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

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab4_1ScanA(cols, rows);
        break;
      case 2:
        lab4_1ScanArray(cols, rows, a, arr);
        break;
      case 3:
        randomizeArray(arr, a);
        break;
      case 4:
        fibonaccinizeArray(arr, a);
        break;
    }
  }
}

int lab4_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new array length"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

void lab4_1ScanArray(int cols, int rows, int a, int *arr) {
  char request[512];
  sprintf(request, "Please, enter new array of length %d", a);
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerArray(a, arr);
}
