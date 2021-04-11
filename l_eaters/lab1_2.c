#include <stdio.h>
#include <math.h>

#define Lab1_2Options 2
#define Lab1_2Solutions 8

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();
float scanAswerFloat();

int mainMenu(int, int);
int lab1_2Menu(int, int, float);
int lab1_2ScanA(int, int, float);

int lab1_2Menu(int cols, int rows, float a)
{
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

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab1_2ScanA(cols, rows, a);
    break;
  default:
    lab1_2Menu(cols, rows, a);
  }

  return 0;
}

int lab1_2ScanA(int cols, int rows, float a)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  float choice = scanAswerFloat();
  lab1_2Menu(cols, rows, choice);
}
