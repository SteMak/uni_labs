#include <stdio.h>
#include <string.h>

#include "../structs.h"

#define Lab7_1Options 4
#define Lab7_1Max_People 32

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
void scanAswerString(char *);
float scanAswerFloat();

void lab7_1ScanPerson(int, int, struct Person *);
void lab7_1DeletePerson(int, int, struct Person *);
void lab7_1PrintPeople(int, int, struct Person *);

void addPerson(struct Person *, char *, int, float);
void deletePerson(struct Person *, int);

void lab7_1Menu(int cols, int rows, struct Person *people) {
  while (1) {
    char choicesFormat[Lab7_1Options][512] = {"Go back", "Add person", "Delete person", "Print people"};

    char *choices[Lab7_1Options];
    for (int i = 0; i < Lab7_1Options; i++) choices[i] = choicesFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab7_1Options, cols);
    drowWaitAnswer(cols, rows, Lab7_1Options);

    switch (scanAswer()) {
      case 0:
        return;
      case 1:
        lab7_1ScanPerson(cols, rows, people);
        break;
      case 2:
        lab7_1DeletePerson(cols, rows, people);
        break;
      case 3:
        lab7_1PrintPeople(cols, rows, people);
        break;
    }
  }
}

void lab7_1ScanName(int cols, int rows, char *choice, int maxLen) {
  char *solutions[1] = {"Please, enter new person's name"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerString(choice);
  for (int i = strlen(choice); strlen(choice) < maxLen; i++)
    strcat(choice, " ");
}

int lab7_1ScanAge(int cols, int rows) {
  char *solutions[1] = {"Please, enter new person's age"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

float lab7_1ScanSalary(int cols, int rows) {
  char *solutions[1] = {"Please, enter new person's salary"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswerFloat();
}

void lab7_1ScanPerson(int cols, int rows, struct Person *people) {
  char name[64];
  lab7_1ScanName(cols, rows, name, 64);
  int age = lab7_1ScanAge(cols, rows);
  float salary = lab7_1ScanSalary(cols, rows);

  addPerson(people, name, age, salary);
}

void lab7_1DeletePerson(int cols, int rows, struct Person *people) {
  char *solutions[1] = {"Please, enter deleted person's id"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  deletePerson(people, choice);
}

void lab7_1PrintPeople(int cols, int rows, struct Person *people) {
  while (1) {
    char *choices[1] = {"Go back"};

    char solutionsFormat[Lab7_1Max_People][512];
    int i = 0;
    while (people[i].id != -1) {
      char sliceName[512] = "";
      strncpy(sliceName, people[i].name, 20);
      sprintf(solutionsFormat[i], "Id: %2d | Name: %20s | Age: %2d | Salary: %10.2f", people[i].id, sliceName, people[i].age, people[i].salary);
      i++;
    }
    char *solutions[Lab7_1Max_People];
    for (int i = 0; i < Lab7_1Max_People; i++) solutions[i] = solutionsFormat[i];

    drowName(cols, rows);
    drowOptions(choices, 1, cols);
    drowSolutions(solutions, i, cols);
    drowWaitAnswer(cols, rows, i + 1);

    int choice = scanAswer();

    switch (choice) {
      case 0:
        return;
    }
  }
}
