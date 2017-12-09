
.PHONY: clean

main: main.o
	gcc -o main main.c -L../lib -lfuncs -I../include

main.o: main.c ../lib/game1.o ../lib/game2.o ../lib/game3.o 
	gcc -g -c -I../include main.c -o main.o

clean:
	rm main.o main

