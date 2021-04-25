#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int println(char *data)
{
  printf(data);
  printf("\n");
  return 0;
}
int printlnCenter(int cols, char *data)
{
  char pad[512] = "";
  for (int i = 0; i < cols / 2 - strlen(data) / 2; i++)
    strcat(pad, " ");
  printf(pad);
  println(data);
  return 0;
}
int printlnLeft(int cols, char *data)
{
  char pad[512] = "";
  for (int i = 0; i < cols / 2 - strlen(data) / 2; i++)
    strcat(pad, " ");
  printf(pad);
  println(data);
  return 0;
}

int drowName(int cols, int rows)
{
  char name1[] = "    _      ___      _____   _____\0";
  char name2[] = "   / /    /   |    / _  /  / ___/\0";
  char name3[] = "  / /    / /| |   / /_/ /  \\__ \\ \0";
  char name4[] = " / /_   / ___ |  / /__/ / ___/ / \0";
  char name5[] = "/____/ /_/  |_| /______/ /____/  \0";
  println("");
  printlnCenter(cols, name1);
  printlnCenter(cols, name2);
  printlnCenter(cols, name3);
  printlnCenter(cols, name4);
  printlnCenter(cols, name5);
  println("");

  return 0;
}

int drowOptions(char **options, int options_num, int cols)
{
  int l = 0;
  for (int i = 0; i < options_num; i++)
    if (l < strlen(options[i]))
      l = strlen(options[i]);

  for (int i = 0; i < options_num; i++)
  {
    char pref[512];
    if (i < 10 && options_num > 9)
      sprintf(pref, "<%d>  %s", i, options[i]);
    else if (i < 100 && options_num > 99)
      sprintf(pref, "<%d>   %s", i, options[i]);
    else
      sprintf(pref, "<%d> %s", i, options[i]);
    for (int k = strlen(options[i]); k < l; k++)
      strcat(pref, " ");
    printlnCenter(cols, pref);
  }
  println("");

  return 0;
}

int drowSolutions(char **solutions, int solutions_num, int cols)
{
  int l = 0;
  for (int i = 0; i < solutions_num; i++)
    if (l < strlen(solutions[i]))
      l = strlen(solutions[i]);

  for (int i = 0; i < solutions_num; i++)
  {
    char pref[512];
    sprintf(pref, "%s", solutions[i]);
    for (int k = strlen(solutions[i]); k < l; k++)
      strcat(pref, " ");
    printlnCenter(cols, pref);
  }

  return 0;
}

int drowWaitAnswer(int cols, int rows, int chPadding)
{
  for (int i = 9 + chPadding; i < rows; i++)
    println("");

  char pref[512] = "";
  for (int i = 0; i < cols / 2 - 30; i++)
    strcat(pref, " ");
  printf(pref);
  printf("Enter your choice: ");
}
