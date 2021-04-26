#include <math.h>
#include <stdio.h>

#define Lab2_2Options 4
#define Lab2_2Solutions 1

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();

int lab2_2ScanA(int, int);
int lab2_2ScanB(int, int);
int lab2_2ScanC(int, int);

void lab2_2Menu(int cols, int rows, int a, int b, int c) {
  while (1) {
    char choicesFormat[Lab2_2Options][512] = {"Go back"};
    sprintf(choicesFormat[1], "Set A  (%d)\0", a);
    sprintf(choicesFormat[2], "Set B  (%d)\0", b);
    sprintf(choicesFormat[3], "Set C  (%d)\0", c);

    char *choices[Lab2_2Options];
    for (int i = 0; i < Lab2_2Options; i++)
      choices[i] = choicesFormat[i];

    char solutionsFormat[Lab2_2Solutions][512];
    if (a > b && a > c)
      sprintf(solutionsFormat[0], "A is the biggest");
    else
      (b > c) ? sprintf(solutionsFormat[0], "B is the biggest") : sprintf(solutionsFormat[0], "C is the biggest");

    char *solutions[Lab2_2Solutions];
    for (int i = 0; i < Lab2_2Solutions; i++)
      solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab2_2Options, cols);
    drowSolutions(solutions, Lab2_2Solutions, cols);
    drowWaitAnswer(cols, rows, Lab2_2Options + Lab2_2Solutions);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab2_2ScanA(cols, rows);
        break;
      case 2:
        b = lab2_2ScanB(cols, rows);
        break;
      case 3:
        c = lab2_2ScanC(cols, rows);
        break;
    }
  }
}

int lab2_2ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab2_2ScanB(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of B"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab2_2ScanC(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of C"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}
