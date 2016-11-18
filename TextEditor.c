#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>


struct point {
  unsigned int x;
  unsigned int y;
};

int main() {


  initscr();
  noecho();
  keypad(stdscr, TRUE);

  struct point location;
  location.x = 1;
  location.y = 1;

  char cont = 1; 

  while(cont) {

    switch(getch()) {
      case KEY_UP:
        location.y--;
        break;
      case KEY_DOWN:
        location.y++;
        break;
      case KEY_RIGHT:
        location.x++;
        break;
      case KEY_LEFT:
        location.x--;
        break;
    }

    for (int y = 0; y < location.y; y++) {
      for (int x = 0; x < location.x; x++) {
        printw(".");
      }
      printw("\n");
    }

    printw("#");
    refresh();
  }
  
  endwin();

  return 0;
}
