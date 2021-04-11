#include <stdio.h>

#define Lab1_1Options 3
#define Lab1_1Solutions 5

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);
int scanAswer();

int mainMenu(int, int);

int lab1_1ScanA(int, int, int, int);
int lab1_1ScanB(int, int, int, int);

int lab1_1Menu(int cols, int rows, int a, int b)
{
  char choicesFormat[Lab1_1Options][512] = {"Go back"};
  sprintf(choicesFormat[1], "Set A  (%d)\0", a);
  sprintf(choicesFormat[2], "Set B  (%d)\0", b);

  char *choices[Lab1_1Options];
  for (int i = 0; i < Lab1_1Options; i++)
    choices[i] = choicesFormat[i];

  char solutionsFormat[Lab1_1Solutions][512];
  sprintf(solutionsFormat[0], "A + B = %d\0", a + b);
  sprintf(solutionsFormat[1], "A - B = %d\0", a - b);
  sprintf(solutionsFormat[2], "A * B = %d\0", a * b);
  sprintf(solutionsFormat[3], "A / B = %.3f\0", (a / (float)b));
  sprintf(solutionsFormat[4], "A % B = %d\0", a % b);

  char *solutions[Lab1_1Solutions];
  for (int i = 0; i < Lab1_1Solutions; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, Lab1_1Options, cols);
  drowSolutions(solutions, Lab1_1Solutions, cols);
  drowWaitAnswer(cols, rows, Lab1_1Options + Lab1_1Solutions);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab1_1ScanA(cols, rows, a, b);
    break;
  case 2:
    lab1_1ScanB(cols, rows, a, b);
    break;
  default:
    lab1_1Menu(cols, rows, a, b);
  }

  return 0;
}

int lab1_1ScanA(int cols, int rows, int a, int b)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab1_1Menu(cols, rows, choice, b);
}

int lab1_1ScanB(int cols, int rows, int a, int b)
{
  char *solutions[1] = {"Please, enter new value of B"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab1_1Menu(cols, rows, a, choice);
}
