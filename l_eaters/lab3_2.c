#include <math.h>
#include <stdio.h>

#define Lab3_2Options 2
#define Lab3_2Solutions 1

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();

int lab3_2ScanA(int, int);

long long int factorial(int);

void lab3_2Menu(int cols, int rows, int a) {
  while (1) {
    char choicesFormat[Lab3_2Options][512] = {"Go back"};
    sprintf(choicesFormat[1], "Set A  (%d)\0", a);

    char *choices[Lab3_2Options];
    for (int i = 0; i < Lab3_2Options; i++)
      choices[i] = choicesFormat[i];

    char solutionsFormat[Lab3_2Solutions][512];
    sprintf(solutionsFormat[0], "Factorial A equals %lld", factorial(a));

    char *solutions[Lab3_2Solutions];
    for (int i = 0; i < Lab3_2Solutions; i++)
      solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab3_2Options, cols);
    drowSolutions(solutions, Lab3_2Solutions, cols);
    drowWaitAnswer(cols, rows, Lab3_2Options + Lab3_2Solutions);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab3_2ScanA(cols, rows);
        break;
    }
  }
}

int lab3_2ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}
