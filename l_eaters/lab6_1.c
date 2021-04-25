#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define Lab6_1Options 5
#define Lab6_1Solutions 7

int drowName(int, int);
int drowOptions(char **, int, int);
int drowSolutions(char **, int, int);
int drowWaitAnswer(int, int, int);

int scanAswer();
void scanAswerString(char *);

int mainMenu(int, int);
int lab6_1Menu(int, int, int, int, char *, char *);
int lab6_1ScanA(int, int, int, int, char *, char *);
int lab6_1ScanB(int, int, int, int, char *, char *);
int lab6_1ScanStringA(int, int, int, int, char *, char *);
int lab6_1ScanStringB(int, int, int, int, char *, char *);

int lab6_1Menu(int cols, int rows, int a, int b, char *strA, char *strB)
{
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
    if (isdigit(strA[i]) && n == 0)
      n = 1;
  sprintf(solutionsFormat[2], "String A has%s digits", n ? "" : "n't");
  n = 0;
  for (int i = 0; i < strlen(strB); i++)
    if (isdigit(strB[i]) && n == 0)
      n = 1;
  sprintf(solutionsFormat[3], "String B has%s digits", n ? "" : "n't");
  strcat(strCopy, strB);
  sprintf(solutionsFormat[4], "A + B length is \"%s\"", strCopy);

  if (a < 1)
    sprintf(solutionsFormat[5], "Slice [1; %d] doesn't exist", a);
  else
  {
    char sliceK[512] = "";
    strncpy(sliceK, strA, a);
    sprintf(solutionsFormat[5], "Slice [1; %d] of A is \"%s\"", a, sliceK);
  }

  if (b < a)
    sprintf(solutionsFormat[6], "Slice [%d; %d] doesn't exist", a, b);
  else
  {
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

  int choice = scanAswer();

  switch (choice)
  {
  case 0:
    mainMenu(cols, rows);
    break;
  case 1:
    lab6_1ScanA(cols, rows, a, b, strA, strB);
    break;
  case 2:
    lab6_1ScanB(cols, rows, a, b, strA, strB);
    break;
  case 3:
    lab6_1ScanStringA(cols, rows, a, b, strA, strB);
    break;
  case 4:
    lab6_1ScanStringB(cols, rows, a, b, strA, strB);
    break;
  default:
    lab6_1Menu(cols, rows, a, b, strA, strB);
  }

  return 0;
}

int lab6_1ScanA(int cols, int rows, int a, int b, char *strA, char *strB)
{
  char *solutions[1] = {"Please, enter new k"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab6_1Menu(cols, rows, choice, b, strA, strB);
}

int lab6_1ScanB(int cols, int rows, int a, int b, char *strA, char *strB)
{
  char *solutions[1] = {"Please, enter new n"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  lab6_1Menu(cols, rows, a, choice, strA, strB);
}

int lab6_1ScanStringA(int cols, int rows, int a, int b, char *strA, char *strB)
{
  char request[512];
  sprintf(request, "Please, enter string A");
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerString(strA);
  lab6_1Menu(cols, rows, a, b, strA, strB);
}

int lab6_1ScanStringB(int cols, int rows, int a, int b, char *strA, char *strB)
{
  char request[512];
  sprintf(request, "Please, enter string A");
  char *solutions[1] = {};
  solutions[0] = request;

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerString(strB);
  lab6_1Menu(cols, rows, a, b, strA, strB);
}
