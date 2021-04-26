#include <math.h>
#include <stdio.h>

#define Lab2_1Options 4
#define Lab2_1Solutions 1

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();

int lab2_1ScanA(int, int);
int lab2_1ScanB(int, int);
int lab2_1ScanX(int, int);

void lab2_1Menu(int cols, int rows, int a, int b, int x) {
  while (1) {
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

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab2_1ScanA(cols, rows);
        break;
      case 2:
        b = lab2_1ScanB(cols, rows);
        break;
      case 3:
        x = lab2_1ScanX(cols, rows);
        break;
    }
  }
}

int lab2_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab2_1ScanB(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of B"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab2_1ScanX(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of X"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}
