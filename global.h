#ifndef global_h
#define global_h



//q weba andarle atinando a la medida d cada pc -.-
#define width 30
#define length 10

//nos ponemos globales para no complicar las cosas
int initx=0,inity=0,hit[2],dano[2],dt[2]={0};
char *escoje[]={
	"Ataka\n",
	"Corre\n",
	"Habla\n",
	"Duerme\n",
	};


//let it be random
int n=sizeof(escoje)/sizeof(char *);
#endif
