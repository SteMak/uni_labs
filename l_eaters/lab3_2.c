#include <stdio.h>
#include <math.h>

#define Lab3_2Options 2
#define Lab3_2Solutions 1

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();

int mainMenu(int, int);
int lab3_2Menu(int, int, int);
int lab3_2ScanA(int, int, int);

long long int factorial(int);

int lab3_2Menu(int cols, int rows, int a)
{
  char choicesFormat[Lab3_2Options][512] = {"Go back"};
  sprintf(choicesFormat[1], "Set A  (%d)\0", a);

  char *choices[Lab3_2Options];
  for (int i = 0; i < Lab3_2Options; i++)
    choices[i] = choicesFormat[i];

  printf("haha %d", factorial(a));
  char solutionsFormat[Lab3_2Solutions][512];
  sprintf(solutionsFormat[0], "Factorial A equals %lld", factorial(a));

  char *solutions[Lab3_2Solutions];
  for (int i = 0; i < Lab3_2Solutions; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, Lab3_2Options, cols);
  drowSolutions(solutions, Lab3_2Solutions, cols);
  drowWaitAnswer(cols, rows, Lab3_2Options + Lab3_2Solutions);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab3_2ScanA(cols, rows, a);
    break;
  default:
    lab3_2Menu(cols, rows, a);
  }

  return 0;
}

int lab3_2ScanA(int cols, int rows, int a)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab3_2Menu(cols, rows, choice);
}
