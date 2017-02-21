//demo.c
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define delay 20000

int main(int argc, char *argv[]){

int initx=0,inity=1,xtops=0,ytops=0,xnext=0,flow=1;
time_t t;
struct tm *now;
char formatime[80];
WINDOW *hs;


initscr();
noecho();
curs_set(0);

/*  Averiguaremos el tamño estandar de una nueva ventana, si
 *  se usa dentro del cyclo, el contenido conservara sus 
 *  dimensiones aun al maximizar/minimizar la ventana.
 *
 *  Al usarlo fuera se ignora el maximizado/minimizado de la
 *  ventana y el contenido asume q la ventana sigue teniendo
 *  las dimensiones originales.
 *
 *  esta funcion crea una variable global tipo WINDOW * stdscr
 *
 *            getmaxyx(stdscr,ytops,xtops);
 */

while(1){
clear();
getmaxyx(stdscr,ytops,xtops);

//obtenemos la hora actual en Milis
t=time(0);

//Seguido de un formato para q sea legible
//y familiar para el usr
now=localtime(&t);
strftime(formatime,sizeof(formatime),"%a %Y-%m-%d %H:%M:%S %Z", now);

//Reloj ya con formato
mvprintw(1,xtops/2-5,"%s\n",formatime);

//lineas de separacion
box(stdscr,'*','*');
mvprintw(inity+1,initx,"°");
mvprintw(ytops-2,xtops-initx,"°");
move(3,1);
hline('*',xtops);
move(ytops-3,1);
hline('*',xtops);
refresh();

//Contenido de ssubventana
hs=newwin(ytops-10,xtops-6,6,3);
box(hs,0,0);
mvwprintw(hs,1,1,"HIGHSCORES");
wrefresh(hs);

//Demora $(delay) milisecs cada paso
usleep(delay);


//si llegaste a una pared, cambia de dirreccion
xnext=initx+flow;
if(xnext>=xtops||xnext<0){
  flow*= -1;
}else
  initx+=flow;
//si no a llegado, avanza otro lugar en la misma dirreccion
}

endwin();
return 0;
}
