#include <ncurses.h>
#include <unistd.h>
#include <string>
void rectangle(int y1, int x1, int y2, int x2);
int drawElevator(int state);
void drawLegend(bool isFree, int floor_curr, int floor_dest);
void uiSetup();
extern bool isFree;
extern int floor_curr,floor_dest;
void uiSetup(){
  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_YELLOW);
  init_pair(2, COLOR_WHITE, COLOR_RED);
  init_pair(3, COLOR_WHITE, COLOR_GREEN);
}
void drawLegend(bool isFree, int floor_curr, int floor_dest){
  mvprintw(LINES/4,COLS/2+5,"Piano Corrente: ");
  mvprintw(LINES/4,COLS/2+21,std::to_string(floor_curr).c_str());
  mvprintw(LINES/4+2,COLS/2+5,"Destinazione: ");
  mvprintw(LINES/4+2,COLS/2+21,std::to_string(floor_dest).c_str());
  attron(COLOR_PAIR((isFree ? 3 : 2)));
  mvprintw(LINES/4+4,COLS/2+5,"  ");
  attroff(COLOR_PAIR((isFree ? 3 : 2)));
  mvprintw(LINES/4+4,COLS/2+8,(isFree ? "Libero  " : "Occupato"));
  refresh();
}

int drawElevator(int state){

  switch(state){
    case 0: //open
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    attron(COLOR_PAIR(1));
    for(int i = 5; i<30;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    drawLegend(isFree,floor_curr,floor_dest);
    refresh();
    break;
    case 1: //close
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,17,0,15);
    drawLegend(isFree,floor_curr,floor_dest);
    refresh();
    break;
    case 2: // opening
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,17,0,15);
    drawLegend(isFree,floor_curr,floor_dest);
    refresh();
    sleep(1);
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,12,0,15);
    drawLegend(isFree,floor_curr,floor_dest);
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
    drawLegend(isFree,floor_curr,floor_dest);
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
    drawLegend(isFree,floor_curr,floor_dest);
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
    drawLegend(isFree,floor_curr,floor_dest);
    attron(COLOR_PAIR(1));
    for(int i = 13; i<22;i++)mvvline(5,i,' ',15);
    attroff(COLOR_PAIR(1));
    refresh();
    sleep(1);
    clear();
    rectangle(4, 4, 20, 30);
    rectangle(2, 2, 20, 32);
    mvvline(5,17,0,15);
    drawLegend(isFree,floor_curr,floor_dest);
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
