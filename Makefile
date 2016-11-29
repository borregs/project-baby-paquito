CC=gcc
OUTPUT=projectBbPacoStanley
CFLAGS=-std=c99
VFLAGS=-t -Wall -Wextra
LDFLAGS=-lm -lncurses
DEPS=choices.h cervatillo.h global.h ventanales.h


all : projectNULL.o
	echo "Building All, may take a sec..."
	$(CC) $(CFLAGS) -o $(OUTPUT) $^ $(DEPS) $(LDFLAGS) 

verbal : projectNULL.o
	echo "Building All, may take a sec..."
	$(CC) $(CFLAGS) $(VFLAGS) -o $(OUTPUT) $^ $(DEPS) $(LDFLAGS) 

projectNULL.o : projectNULL.c $(DEPS)
	cc -c -g $< -o $@ $(LDFLAGS)
choices.o : choices.h
	cc -c -g $< -o $@ $(LDFLAGS)
cervatillo.o : cervatillo.h
	cc -c -g $< -o $@ $(LDFLAGS)
global.o : global.h
	cc -c -g $< -o $@ $(LDFLAGS)
ventanales.o : ventanales.h
	cc -c -g $< -o $@ $(LDFLAGS)
like_a_tree :
	aplay maketree.wav
clean:
	rm *.o *~ projectBbPacoStanley
