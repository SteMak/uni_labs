#include <math.h>
#include <stdio.h>

#define Lab1_2Options 2
#define Lab1_2Solutions 8

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
float scanAswerFloat();

float lab1_2ScanA(int, int);

void lab1_2Menu(int cols, int rows, float a) {
  while (1) {
    char choicesFormat[Lab1_2Options][512] = {"Go back"};
    sprintf(choicesFormat[1], "Set A  (%.3f)\0", a);

    char *choices[Lab1_2Options];
    for (int i = 0; i < Lab1_2Options; i++)
      choices[i] = choicesFormat[i];

    char solutionsFormat[Lab1_2Solutions][512];
    sprintf(solutionsFormat[0], "sin   A = %.3f\0", sin(a));
    sprintf(solutionsFormat[1], "cos   A = %.3f\0", cos(a));
    sprintf(solutionsFormat[2], "tg    A = %.3f\0", tan(a));
    sprintf(solutionsFormat[3], "ctg   A = %.3f\0", tan(M_PI / 2 - a));
    sprintf(solutionsFormat[4], "arctg A = %.3f\0", atan(a));
    sprintf(solutionsFormat[5], "abs   A = %.3f\0", fabs(a));
    sprintf(solutionsFormat[6], "sqrt  A = %.3f\0", sqrt(a));
    sprintf(solutionsFormat[7], "round A = %.3f\0", round(a));

    char *solutions[Lab1_2Solutions];
    for (int i = 0; i < Lab1_2Solutions; i++)
      solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab1_2Options, cols);
    drowSolutions(solutions, Lab1_2Solutions, cols);
    drowWaitAnswer(cols, rows, Lab1_2Options + Lab1_2Solutions);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab1_2ScanA(cols, rows);
        break;
    }
  }
}

float lab1_2ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswerFloat();
}
