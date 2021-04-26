#include <stdio.h>
#include <string.h>

void setEl(int *, int, int, int, int);

int scanAswer() {
  int scanned = 0;
  scanf("%d", &scanned);
  return scanned;
}

float scanAswerFloat() {
  float scanned = 0;
  scanf("%f", &scanned);
  return scanned;
}

void *scanAswerArray(int a, int *scanned) {
  for (int i = 0; i < a; i++)
    scanf("%d", &scanned[i]);
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void scanAswerMatrix(int a, int *scanned) {
  int scan;
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++) {
      scanf("%d", &scan);
      setEl(scanned, a, i, j, scan);
    }
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void scanAswerString(char *scanned) {
  scanf(" %99[^\n]", scanned);
}
