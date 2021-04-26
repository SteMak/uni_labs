#include <stdio.h>

#define Lab1_1Options 3
#define Lab1_1Solutions 5

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);
int scanAswer();

int lab1_1ScanA(int, int);
int lab1_1ScanB(int, int);

void lab1_1Menu(int cols, int rows, int a, int b) {
  while (1) {
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

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab1_1ScanA(cols, rows);
        break;
      case 2:
        b = lab1_1ScanB(cols, rows);
        break;
    }
  }
}

int lab1_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab1_1ScanB(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of B"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}
