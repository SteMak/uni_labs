int tWidth();
int tHeight();
void mainMenu(int, int);

int main() {
  int cols = tWidth();
  int rows = tHeight();

  mainMenu(cols, rows);

  return 0;
}
