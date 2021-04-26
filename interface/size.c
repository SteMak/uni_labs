#ifdef _WIN32
#include <windows.h>

int tWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int tHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
#endif

#ifdef linux
#include <sys/ioctl.h>

int tWidth(void) {
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  return w.ws_col;
}

int tHeight(void) {
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  return w.ws_row;
}
#endif
