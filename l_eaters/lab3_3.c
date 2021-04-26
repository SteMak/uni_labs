#include <math.h>
#include <stdio.h>

#define Lab3_3Options 3
#define Lab3_3Solutions 1
#define Lab3_3TableSize 37

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
float scanAswerFloat();

float lab3_3ScanA(int, int);
void lab3_3SubMenu(int, int);

void lab3_3Menu(int cols, int rows, float a) {
  while (1) {
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

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        lab3_3SubMenu(cols, rows);
        break;
      case 2:
        a = lab3_3ScanA(cols, rows);
        break;
    }
  }
}

float lab3_3ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswerFloat();
}

void lab3_3SubMenu(int cols, int rows) {
  while (1) {
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

    switch (choice) {
      case 0:
        return;
    }
  }
}
