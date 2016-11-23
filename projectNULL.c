#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ventanales.h"
#include "choices.h"
#include "global.h"
#include "cervatillo.h"




int main(){
//them good ol ints
int x,y=0,hl,c=0,maxx=0,maxy=0;
//sigue vivo?
bool vivo[2]={1,1},turn=1;
//para los jugadores y su token
char pk[50],* p;
p=&pk[0];
//para el menu (ahora en globales)
WINDOW *m,*dock,*main, *diag;
hl=1;
//arroja resultados aletorios diferentes cada segundo paro

time_t t;
srand((unsigned) time(&t));


initscr();
cbreak();

//Abilitamos todas las teclas para la ventana standar 
keypad(stdscr,1);

initx=(80-width)/2;
inity=(24-length)/2;

//Obtenemos las dimensiones de la ventana
getmaxyx(stdscr,maxy,maxx);


//inicializamos 2 ventanas dentro de stdscr
dock=mkwin(3,maxx,maxy-3,0,1);
diag=mkwin(maxy-3,maxx,0,0,1);
main=subwin(diag,maxy-5,maxx-2,1,1);

mvwprintw(dock,0,0,"Dock");
mvwprintw(diag,0,0,"Main");

wrefresh(dock);
wrefresh(diag);

sleep(5);

mvwprintw(main,1,1,"Un lindo dia cualquiera te encuentras caminando muy campante hacia el pueblo vecino. Cuando muy depronto...\n");
mvwprintw(main,2,1,"Volteas a ver a un chavo medio raro directo a los ojos. Este muchacho parece tener solo una cosa en mente, lentamente se acerca hacia ti con una mirada intensa q trata de penetrar hasta tu alma. Sin dejar pasar un segundo exclama:\n");
wrefresh(main);

sleep(2);

wclear(main);
mvwprintw(main,1,1,"I like shorts!\nthey're comfy and easy to wear");
wrefresh(main);
mvwprintw(dock,2,2,"Vs. Shorts Guy");
wrefresh(dock);


wclear(main);
mvwprintw(main,1,1,"En el panico del momento logras recordar que un profesor solitario alguna vez te regalo una pequeña creatura muy poderosa tratando de quedar bn con tu madre\n");
wrefresh(main);

sleep(1);

wclear(main);	
mvwprintw(main,1,1,"Pero cual era...?\n\n\n\t1) Charmander\n\t2) Bulbasor\n\t3) Squirtle\n\n>>");
wrefresh(main);
wscanw(main,"%d",&x);
switch(x){
	case 1:
		strcpy(pk,"Charmander");
	break;
	case 2:
		strcpy(pk,"Bulbasor");
	break;
	case 3:
		strcpy(pk,"Squirtle");
	break;
	default:
		strcpy(pk,"Psyduck");
	}
wrefresh(main);

sleep(1);

wclear(main);
mvwprintw(main,1,1,"Tan pronto recuerdas su nombre dejas escapar una sonrisa con aire de superioridad. Tan solo te toma un segundo alcanzar la pokebola de tu mochila, las palabras se escuren de de tu boca como si no fueran tuyas\n%s YO TE ELIJO!\n",pk);
wrefresh(main);

sleep(2);

wclear(main);
mvwprintw(main,1,30,"Novato, crees poder vencerme con ese pequeño %s",pk);
wrefresh(main);

sleep(2);


wclear(main);
mvwprintw(main,1,30,"Arbok, yo te elijoooooooo!");
wrefresh(main);

sleep(2);

do{

		hit[turn]=rand()%2;
		dano[turn]=(rand()%3)+1;
		
		wclear(main);
		mvwprintw(main,6,0,"Jugador %d, Es su turno",turn+1);
		wrefresh(main);
		getch();
		wclear(main);
	
		mvwprintw(main,1,60,"Arbok");
		for(x=4;x>=dt[0];x--)
			mvwprintw(main,2,60+x,"=");
		mvwprintw(main,2,57,"HP(");
		mvwprintw(main,2,65,")");
		wrefresh(main);
		getch();
		
		mvwprintw(main,20,5,"%s",pk);
		for(x=4;x>=dt[1];x--)
			mvwprintw(main,21,5+x,"=");
		mvwprintw(main,21,2,"HP(");
		mvwprintw(main,21,10,")");
		wrefresh(main);
		getch();


noecho();
cbreak();
initx=(80-width)/2;
inity=(24-length)/2;




m=subwin(main,length,width,inity,initx);
keypad(m,1);
mvprintw(6,0,"Utilize las flechas para resaltar su eleccion, presione enter para escoger");
refresh();
choices(m,hl);
while(1){
	c=0;
	y=wgetch(m);
	switch(y){
		case KEY_UP:
			if(hl==1)
				hl=n;
			else
				hl--;
		break;
		case KEY_DOWN:
			if(hl==n)
				hl=1;
			else
				hl++;
		break;
		case 10:
			c=hl;
		break;
		default:
			mvprintw(17,0,"El caracter que uds presiono [%3d] no es valido",c);
			refresh();
		break;
		}
	choices(m,hl);
	if(c!=0)
		break;
	}
mvwprintw(main,17,0,"Bn, uds opto por la opcion %d) %s",c,escoje[c-1]);
clrtoeol();
refresh();
vivo[turn]=cervatillo(c,turn);
turn=!turn;
clear();
}while(vivo[0]&&vivo[1]);

endwin();
return 0;
}
