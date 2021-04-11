#include <stdio.h>
#include <math.h>

#define Lab2_2Options 4
#define Lab2_2Solutions 1

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();

int mainMenu(int, int);
int lab2_2Menu(int, int, int, int, int);
int lab2_2ScanA(int, int, int, int, int);
int lab2_2ScanB(int, int, int, int, int);
int lab2_2ScanC(int, int, int, int, int);

int lab2_2Menu(int cols, int rows, int a, int b, int c)
{
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

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab2_2ScanA(cols, rows, a, b, c);
    break;
  case 2:
    lab2_2ScanB(cols, rows, a, b, c);
    break;
  case 3:
    lab2_2ScanC(cols, rows, a, b, c);
    break;
  default:
    lab2_2Menu(cols, rows, a, b, c);
  }

  return 0;
}

int lab2_2ScanA(int cols, int rows, int a, int b, int c)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab2_2Menu(cols, rows, choice, b, c);
}

int lab2_2ScanB(int cols, int rows, int a, int b, int c)
{
  char *solutions[1] = {"Please, enter new value of B"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab2_2Menu(cols, rows, a, choice, c);
}

int lab2_2ScanC(int cols, int rows, int a, int b, int c)
{
  char *solutions[1] = {"Please, enter new value of C"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab2_2Menu(cols, rows, a, b, choice);
}
