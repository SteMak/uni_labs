#include <stdio.h>
#include <math.h>

#define Lab3_1Options 2
#define Lab3_1Solutions 1

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();

int mainMenu(int, int);
int lab3_1Menu(int, int, int);
int lab3_1ScanA(int, int, int);

int lab3_1Menu(int cols, int rows, int a)
{
  char choicesFormat[Lab3_1Options][512] = {"Go back"};
  sprintf(choicesFormat[1], "Set A  (%d)\0", a);

  char *choices[Lab3_1Options];
  for (int i = 0; i < Lab3_1Options; i++)
    choices[i] = choicesFormat[i];

  int acc = 0;
  int ctr = 2;
  while (ctr <= a)
  {
    acc += ctr;
    ctr += 2;
  }

  char solutionsFormat[Lab3_1Solutions][512];
  sprintf(solutionsFormat[0], "Sum of even from 1 to A equals %d", acc);

  char *solutions[Lab3_1Solutions];
  for (int i = 0; i < Lab3_1Solutions; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, Lab3_1Options, cols);
  drowSolutions(solutions, Lab3_1Solutions, cols);
  drowWaitAnswer(cols, rows, Lab3_1Options + Lab3_1Solutions);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab3_1ScanA(cols, rows, a);
    break;
  default:
    lab3_1Menu(cols, rows, a);
  }

  return 0;
}

int lab3_1ScanA(int cols, int rows, int a)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab3_1Menu(cols, rows, choice);
}
