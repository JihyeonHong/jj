
.PHONY: clean

main: main.o
	gcc -o main main.c -L../lib -lfuncs -I../include

main.o: main.c
	gcc main.c -o main.o

clean:
	rm main.o main

