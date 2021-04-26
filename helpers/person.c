#include <string.h>

#include "../structs.h"

void addPerson(struct Person *people, char *name, int age, float salary) {
  int i = 0;
  while (people[i].id != -1)
    i++;
  strcat(name, "\0");
  strcpy(people[i].name, name);
  people[i].age = age;
  people[i].salary = salary;
  people[i].id = i;
  people[i + 1].id = -1;
}

void deletePerson(struct Person *people, int id) {
  for (int i = id; people[i].id != -1; i++) {
    strcpy(people[i].name, people[i + 1].name);
    people[i].age = people[i + 1].age;
    people[i].salary = people[i + 1].salary;
    people[i].id = people[i + 1].id == -1 ? -1 : i;
  }
}
