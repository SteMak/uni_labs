#include <stdio.h>
#include <math.h>

#define Lab3_3Options 3
#define Lab3_3Solutions 1
#define Lab3_3TableSize 37

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();
float scanAswerFloat();

int mainMenu(int, int);
int lab3_3Menu(int, int, float);
int lab3_3ScanA(int, int, float);
int lab3_3SubMenu(int, int, float);

int lab3_3Menu(int cols, int rows, float a)
{
  char choicesFormat[Lab3_3Options][512] = {"Go back", "Let me see the table!"};
  sprintf(choicesFormat[2], "Set A  (%.3f)\0", a);

  char *choices[Lab3_3Options];
  for (int i = 0; i < Lab3_3Options; i++)
    choices[i] = choicesFormat[i];

  char solutionsFormat[Lab3_3Solutions][512];
  sprintf(solutionsFormat[0], "A degrees are %.6f rad", a / 180 * M_PI);

  char *solutions[Lab3_3Solutions];
  for (int i = 0; i < Lab3_3Solutions; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, Lab3_3Options, cols);
  drowSolutions(solutions, Lab3_3Solutions, cols);
  drowWaitAnswer(cols, rows, Lab3_3Options + Lab3_3Solutions);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab3_3SubMenu(cols, rows, a);
    break;
  case 2:
    lab3_3ScanA(cols, rows, a);
    break;
  default:
    lab3_3Menu(cols, rows, a);
  }

  return 0;
}

int lab3_3ScanA(int cols, int rows, float a)
{
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  float choice = scanAswerFloat();
  lab3_3Menu(cols, rows, choice);
}

int lab3_3SubMenu(int cols, int rows, float a)
{
  char *choices[1] = {"Go back"};

  char solutionsFormat[Lab3_3TableSize][512];
  for (int i = 0; i <= 360; i += 10)
    sprintf(solutionsFormat[i / 10], "%d degrees are %.6f rad", i, (float)i / 180 * M_PI);

  char *solutions[Lab3_3TableSize];
  for (int i = 0; i < Lab3_3TableSize; i++)
    solutions[i] = solutionsFormat[i];

  drowName(cols, rows);
  drowOptions(choices, 1, cols);
  drowSolutions(solutions, Lab3_3TableSize, cols);
  drowWaitAnswer(cols, rows, Lab3_3TableSize + 2);

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    lab3_3Menu(cols, rows, a);
    break;
  default:
    lab3_3SubMenu(cols, rows, a);
  }

  return 0;
}
