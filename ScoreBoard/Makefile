#Makefile Borrecurses 4 da win
#CC=/usr/bin/gcc
OUTPUT=ncurios
CFLAGS=-std=c99 
VFLAGS=-t -Wall -Wextra 
LDFLAGS= -lm -lncurses
DEPS=libncurses5-dev,cmake,build-essential,ld,binutils


all: ncurios.o 
	echo "Compilando Archivos" 
	cc ncurios.c $(LDFLAGS) -o $(OUTPUT)

verbose: ncurios.o
	cc $(CFLAGS) $(VFLAGS) ncurios.c $(LDFLAGS) -o $(OUTPUT)

clean:
	rm *.o *~ ncurios 

list_deps: 
	echo "Dependencias Necesarias:"
	echo $(DEPS)

 
#		Me gustan los Caballitos
#					Pobre Bebe Paquito
