#include <string.h>

#include "../structs.h"

#define MainOptions 12

void drowName(int, int);
void drowOptions(char **, int, int);
void drowWaitAnswer(int, int, int);
int scanAswer();

void lab1_1Menu(int, int, int, int);
void lab1_2Menu(int, int, float);
void lab2_1Menu(int, int, int, int, int);
void lab2_2Menu(int, int, int, int, int);
void lab3_1Menu(int, int, int);
void lab3_2Menu(int, int, int);
void lab3_3Menu(int, int, float);
void lab4_1Menu(int, int, int, int *);
void lab5_1Menu(int, int, int, int *, int *);
void lab6_1Menu(int, int, int, int, char *, char *);
void lab7_1Menu(int, int, struct Person *);

int *newMatrix(int);
void deleteMatrix(int *);

void mainMenu(int cols, int rows) {
  while (1) {
    char *choices[MainOptions];
    choices[0] = "Exit\0";
    choices[1] = "Lab 1_1 (+ - * / %)\0";
    choices[2] = "Lab 1_2 (test some functions)\0";
    choices[3] = "Lab 2_1 (belonging to segment)\0";
    choices[4] = "Lab 2_2 (biggest of 3)\0";
    choices[5] = "Lab 3_1 (count even numbers)\0";
    choices[6] = "Lab 3_2 (factorial)\0";
    choices[7] = "Lab 3_3 (degrees to rads)\0";
    choices[8] = "Lab 4_1 (arrays)\0";
    choices[9] = "Lab 5_1 (matrices)\0";
    choices[10] = "Lab 6_1 (strings)\0";
    choices[11] = "Lab 7_1 (people list)\0";

    drowName(cols, rows);
    drowOptions(choices, MainOptions, cols);
    drowWaitAnswer(cols, rows, MainOptions);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        lab1_1Menu(cols, rows, 1, 1);
        break;
      case 2:
        lab1_2Menu(cols, rows, 1.2);
        break;
      case 3:
        lab2_1Menu(cols, rows, 1, 3, 2);
        break;
      case 4:
        lab2_2Menu(cols, rows, 1, 3, 2);
        break;
      case 5:
        lab3_1Menu(cols, rows, 123);
        break;
      case 6:
        lab3_2Menu(cols, rows, 12);
        break;
      case 7:
        lab3_3Menu(cols, rows, 15.6);
        break;
      case 8: {
        int arr[512] = {3, 4, 2, 1};
        lab4_1Menu(cols, rows, 4, arr);
        break;
      }
      case 9: {
        int *matA = newMatrix(32);
        int *matB = newMatrix(32);
        lab5_1Menu(cols, rows, 3, matA, matB);
        deleteMatrix(matA);
        deleteMatrix(matB);
        break;
      }
      case 10: {
        char strA[512] = "Abc";
        char strB[512] = "CeDf";
        lab6_1Menu(cols, rows, 3, 5, strA, strB);
        break;
      }
      case 11: {
        struct Person people[32];
        for (int i = 0; i < 32; i++) {
          people[i].id = -1;
          strcpy(people[i].name, "");
          people[i].age = -1;
          people[i].salary = -1;
        }
        lab7_1Menu(cols, rows, people);
        break;
      }
    }
  }
}
