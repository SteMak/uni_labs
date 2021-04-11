int tWidth();
int tHeight();
int mainMenu(int, int);

int main()
{
  int cols = tWidth();
  int rows = tHeight();

  mainMenu(cols, rows);

  return 0;
}
