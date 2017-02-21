#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void main(){

int maxy,maxx;
WINDOW *s;

initscr();
getmaxyx(stdscr,maxy,maxx);
box(stdscr,'*','*');
system("aplay *.wav &");
refresh();
mvprintw(2,2,"...");
getch();
mvprintw(2,2,"........");
getch();
mvprintw(2,2,"?");
usleep(100);
mvprintw(3,2,"Where am I?");
usleep(100);
mvprintw(4,2,"its...so cold");
getch();
clear();
system("./snow.sh &");
refresh();
getch();
system("killall snow.sh");
s=subwin(stdscr,7,25,maxy/2,(maxx/2)-7);
box(s,0,0);
mvwprintw(s,2,2,"EL BEBE PAQUITO EN:");
mvwprintw(s,4,1,"Un Invierno Propietario");
wrefresh(s);
getch();
endwin();
}             
