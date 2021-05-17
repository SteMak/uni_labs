#include <stdio.h>
#include <string.h>

#include "../structs.h"

#define Lab8_1Options 5
#define Lab8_1Max_People 32

void drowName(int, int);
void drowOptions(char **, int, int);
void drowSolutions(char **, int, int);
void drowWaitAnswer(int, int, int);

int scanAswer();
void scanAswerString(char *);
float scanAswerFloat();

void lab8_1ScanPerson(int, int, struct Person *);
void lab8_1DeletePerson(int, int, struct Person *);
void lab8_1PrintPeople(int, int, struct Person *);
void lab8_1WriteToFile(struct Person *, FILE *, char *);

void addPerson(struct Person *, char *, int, float);
void deletePerson(struct Person *, int);
int peopleLength(struct Person *);

void lab8_1Menu(int cols, int rows) {
  const char *file_path = "records.dat";

  struct Person people[32];
  for (int i = 0; i < 32; i++) {
    people[i].id = -1;
    strcpy(people[i].name, "");
    people[i].age = -1;
    people[i].salary = -1;
  }

  FILE *records;
  records = fopen(file_path, "r");
  int len;
  fscanf(records, "%d", &len);
  for (int i = 0; i < len; i++) {
    fscanf(records, "%d %s %d %f", &people[i].id, people[i].name, &people[i].age, &people[i].salary);
    strcat(people[i].name, "                    ");
  }
  fclose(records);

  while (1) {
    char choicesFormat[Lab8_1Options][512] = {"Go back", "Add person", "Delete person", "Print people", "Save to file"};

    char *choices[Lab8_1Options];
    for (int i = 0; i < Lab8_1Options; i++) choices[i] = choicesFormat[i];

    drowName(cols, rows);
    drowOptions(choices, Lab8_1Options, cols);
    drowWaitAnswer(cols, rows, Lab8_1Options);

    int choice = scanAswer();

    switch (choice) {
      case 0:
        return;
      case 1:
        lab8_1ScanPerson(cols, rows, people);
        break;
      case 2:
        lab8_1DeletePerson(cols, rows, people);
        break;
      case 3:
        lab8_1PrintPeople(cols, rows, people);
        break;
      case 4:
        lab8_1WriteToFile(people, records, file_path);
        break;
    }
  }
}

void lab8_1WriteToFile(struct Person *people, FILE *records, char *file_path) {
  records = fopen(file_path, "w");
  fprintf(records, "%d\n", peopleLength(people));
  for (int i = 0; i == people[i].id; i++) {
    fprintf(records, "%d %s %d %f\n", people[i].id, people[i].name, people[i].age, people[i].salary);
  }
  fclose(records);
}

void lab8_1ScanName(int cols, int rows, char *choice, int maxLen) {
  char *solutions[1] = {"Please, enter new person's name"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  scanAswerString(choice);
  for (int i = strlen(choice); strlen(choice) < maxLen; i++)
    strcat(choice, " ");
}

int lab8_1ScanAge(int cols, int rows) {
  char *solutions[1] = {"Please, enter new person's age"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswer();
}

float lab8_1ScanSalary(int cols, int rows) {
  char *solutions[1] = {"Please, enter new person's salary"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  return scanAswerFloat();
}

void lab8_1ScanPerson(int cols, int rows, struct Person *people) {
  char name[64];
  lab8_1ScanName(cols, rows, name, 64);
  int age = lab8_1ScanAge(cols, rows);
  float salary = lab8_1ScanSalary(cols, rows);

  addPerson(people, name, age, salary);
}

void lab8_1DeletePerson(int cols, int rows, struct Person *people) {
  char *solutions[1] = {"Please, enter deleted person's id"};

  drowName(cols, rows);
  drowSolutions(solutions, 1, cols);
  drowWaitAnswer(cols, rows, 0);

  int choice = scanAswer();
  deletePerson(people, choice);
}

void lab8_1PrintPeople(int cols, int rows, struct Person *people) {
  while (1) {
    char *choices[1] = {"Go back"};

    char solutionsFormat[Lab8_1Max_People][512];
    int i = 0;
    while (people[i].id != -1) {
      char sliceName[512] = "";
      strncpy(sliceName, people[i].name, 20);
      sprintf(solutionsFormat[i], "Id: %2d | Name: %20s | Age: %2d | Salary: %10.2f", people[i].id, sliceName, people[i].age, people[i].salary);
      i++;
    }
    char *solutions[Lab8_1Max_People];
    for (int i = 0; i < Lab8_1Max_People; i++) solutions[i] = solutionsFormat[i];

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
