#include <ncurses.h>
#include <unistd.h>
void rectangle(int y1, int x1, int y2, int x2);
int drawElevator(int state);
int main(){
  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_YELLOW);
  drawElevator(2);
  //refresh();
  getch();
  endwin();
}
int drawElevator(int state){
  rectangle(4, 4, 20, 30);
  rectangle(2, 2, 20, 32);
  switch(state){
    case 0: //open
    attron(COLOR_PAIR(1));
    for(int i = 5; i<30;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    break;
    case 1: //close
    mvvline(5,17,0,15);
    break;
    case 2: // opening
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,17,0,15);
    refresh();
    sleep(1);
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,12,0,15);
    attron(COLOR_PAIR(1));
    for(int i = 13; i<22;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    mvvline(5,22,0,15);
    refresh();
    sleep(1);
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,7,0,15);
    mvvline(5,27,0,15);
    attron(COLOR_PAIR(1));
    for(int i = 8; i<27;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    refresh();
    sleep(1);
    clear();
    state = drawElevator(0);
    break;
    case 3:
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,7,0,15);
    mvvline(5,27,0,15);
    attron(COLOR_PAIR(1));
    for(int i = 8; i<27;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    refresh();
    sleep(1);
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,12,0,15);
    mvvline(5,22,0,15);
    attron(COLOR_PAIR(1));
    for(int i = 13; i<22;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    refresh();
    sleep(1);
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,17,0,15);
    refresh();
    sleep(1);
    clear();
    state = drawElevator(1);
    break;
  }
  return state;
}

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}
