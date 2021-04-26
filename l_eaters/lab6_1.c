#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define Lab6_1Options 5
#define Lab6_1Solutions 7

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
void scanAswerString(char *);

int lab6_1ScanA(int, int);
int lab6_1ScanB(int, int);
void lab6_1ScanStringA(int, int, char *);
void lab6_1ScanStringB(int, int, char *);

void lab6_1Menu(int cols, int rows, int a, int b, char *strA, char *strB) {
  while (1) {
    char strCopy[512] = "";
    strcat(strCopy, strA);

    char choicesFormat[Lab6_1Options][512] = {"Go back", "", "", ""};
    sprintf(choicesFormat[1], "Set k  (%d)\0", a);
    sprintf(choicesFormat[2], "Set n  (%d)\0", b);
    sprintf(choicesFormat[3], "Enter string A  (%s)\0", strCopy);
    sprintf(choicesFormat[4], "Enter string B  (%s)\0", strB);

    char *choices[Lab6_1Options];
    for (int i = 0; i < Lab6_1Options; i++)
      choices[i] = choicesFormat[i];

    char solutionsFormat[Lab6_1Solutions][512];

    sprintf(solutionsFormat[0], "String A length is %d", strlen(strA));
    sprintf(solutionsFormat[1], "String B length is %d", strlen(strB));
    int n = 0;
    for (int i = 0; i < strlen(strA); i++)
      if (isdigit(strA[i])) {
        n = 1;
        break;
      }
    sprintf(solutionsFormat[2], "String A has%s digits", n ? "" : "n't");
    n = 0;
    for (int i = 0; i < strlen(strB); i++)
      if (isdigit(strB[i])) {
        n = 1;
        break;
      }
    sprintf(solutionsFormat[3], "String B has%s digits", n ? "" : "n't");
    strcat(strCopy, strB);
    sprintf(solutionsFormat[4], "A + B length is \"%s\"", strCopy);

    if (a < 1)
      sprintf(solutionsFormat[5], "Slice [1; %d] doesn't exist", a);
    else {
      char sliceK[512] = "";
      strncpy(sliceK, strA, a);
      sprintf(solutionsFormat[5], "Slice [1; %d] of A is \"%s\"", a, sliceK);
    }

    if (b < a)
      sprintf(solutionsFormat[6], "Slice [%d; %d] doesn't exist", a, b);
    else {
      char sliceN[512] = "";
      strncpy(sliceN, a >= 1 ? strB + a - 1 : strB, a >= 1 ? b - a + 1 : b);
      sprintf(solutionsFormat[6], "Slice [%d; %d] of B is \"%s\"", a, b, sliceN);
    }
    char *solutions[Lab6_1Solutions];
    for (int i = 0; i < Lab6_1Solutions; i++)
      solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab6_1Options, cols);
    drowSolutions(solutions, Lab6_1Solutions, cols);
    drowWaitAnswer(cols, rows, Lab6_1Options + Lab6_1Solutions);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        a = lab6_1ScanA(cols, rows);
        break;
      case 2:
        b = lab6_1ScanB(cols, rows);
        break;
      case 3:
        lab6_1ScanStringA(cols, rows, strA);
        break;
      case 4:
        lab6_1ScanStringB(cols, rows, strB);
        break;
    }
  }
}

int lab6_1ScanA(int cols, int rows) {
  char *solutions[1] = {"Please, enter new k"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

int lab6_1ScanB(int cols, int rows) {
  char *solutions[1] = {"Please, enter new n"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

void lab6_1ScanStringA(int cols, int rows, char *strA) {
  char request[512];
  sprintf(request, "Please, enter string A");
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerString(strA);
}

void lab6_1ScanStringB(int cols, int rows, char *strB) {
  char request[512];
  sprintf(request, "Please, enter string A");
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerString(strB);
}
