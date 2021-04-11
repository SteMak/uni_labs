#include <stdio.h>
#include <math.h>

#define Lab2_1Options 4
#define Lab2_1Solutions 1

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();

int mainMenu(int, int);
int lab2_1Menu(int, int, int, int, int);
int lab2_1ScanA(int, int, int, int, int);
int lab2_1ScanB(int, int, int, int, int);
int lab2_1ScanX(int, int, int, int, int);

int lab2_1Menu(int cols, int rows, int a, int b, int x)
{
  char choicesFormat[Lab2_1Options][512] = {"Go back"};
  sprintf(choicesFormat[1], "Set A  (%d)\0", a);
  sprintf(choicesFormat[2], "Set B  (%d)\0", b);
  sprintf(choicesFormat[3], "Set X  (%d)\0", x);

  char *choices[Lab2_1Options];
  for (int i = 0; i < Lab2_1Options; i++)
    choices[i] = choicesFormat[i];

  char solutionsFormat[Lab2_1Solutions][512];
  if (a > b)
    sprintf(solutionsFormat[0], "Segment [A, B] is incorrect");
  else if (x >= a && x <= b)
    sprintf(solutionsFormat[0], "X belongs to the segment [A, B]");
  else
    sprintf(solutionsFormat[0], "X doesn't belong to the segment [A, B]");

  char *solutions[Lab2_1Solutions];
  for (int i = 0; i < Lab2_1Solutions; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, Lab2_1Options, cols);
  drowSolutions(solutions, Lab2_1Solutions, cols);
  drowWaitAnswer(cols, rows, Lab2_1Options + Lab2_1Solutions);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab2_1ScanA(cols, rows, a, b, x);
    break;
  case 2:
    lab2_1ScanB(cols, rows, a, b, x);
    break;
  case 3:
    lab2_1ScanX(cols, rows, a, b, x);
    break;
  default:
    lab2_1Menu(cols, rows, a, b, x);
  }

  return 0;
}

int lab2_1ScanA(int cols, int rows, int a, int b, int x)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab2_1Menu(cols, rows, choice, b, x);
}

int lab2_1ScanB(int cols, int rows, int a, int b, int x)
{
  char *solutions[1] = {"Please, enter new value of B"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab2_1Menu(cols, rows, a, choice, x);
}

int lab2_1ScanX(int cols, int rows, int a, int b, int x)
{
  char *solutions[1] = {"Please, enter new value of X"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab2_1Menu(cols, rows, a, b, choice);
}
