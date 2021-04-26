#include <math.h>
#include <stdio.h>

#define Lab3_1Options 2
#define Lab3_1Solutions 1

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();

int lab3_1ScanA(int, int);

void lab3_1Menu(int cols, int rows, int a) {
  while (1) {
    char choicesFormat[Lab3_1Options][512] = {"Go back"};
    sprintf(choicesFormat[1], "Set A  (%d)\0", a);

    char *choices[Lab3_1Options];
    for (int i = 0; i < Lab3_1Options; i++)
      choices[i] = choicesFormat[i];

    int acc = 0;
    int ctr = 2;
    while (ctr <= a) {
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

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab3_1ScanA(cols, rows);
        break;
    }
  }
}

int lab3_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new value of A"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}
