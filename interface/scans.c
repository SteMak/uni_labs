#include <stdio.h>
#include <string.h>

int scanAswer()
{
  int scanned = 0;
  scanf("%d", &scanned);
  return scanned;
}

float scanAswerFloat()
{
  float scanned = 0;
  scanf("%f", &scanned);
  return scanned;
}

int *scanAswerArray(int a, int *scanned)
{
  for (int i = 0; i < a; i++)
    scanf("%d", &scanned[i]);
  char least[512] = "";
  scanf("%[^\n]", least);
  return scanned;
}

int **scanAswerMatrix(int a, int **scanned)
{
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      scanf("%d", &scanned[i][j]);
  char least[512] = "";
  scanf("%[^\n]", least);
  return scanned;
}
