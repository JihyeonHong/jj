.PHONY: clean

libfuncs.a: game1.o game2.o game3.o game4.o
	ar rv libfuncs.a game1.o game2.o game3.o game4.o

game1.o: game1.c
	gcc -c -g -I../include game1.c -o game1.o

game2.o: game2.c
	gcc -c -g -I../include game2.c -o game2.o

game3.o: game3.c
	gcc -c -g -I../include game3.c -o game3.o

game4.o: game4.c
	gcc -c -g -I../include game4.c -o game4.o
