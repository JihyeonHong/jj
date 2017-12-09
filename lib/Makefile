.PHONY: clean

libfuncs.a: game1.o game2.o game3.o game4.o makeeq.o verify.o init.o print.o quickSort.o
	ar rv libfuncs.a game1.o game2.o game3.o game4.o makeeq.o verify.o init.o print.o quickSort.o

game1.o: game1.c makeeq.o verify.o init.o print.o
	gcc -c -g -I../include game1.c -o game1.o

game2.o: game2.c makeeq.o verify.o init.o print.o
	gcc -c -g -I../include game2.c -o game2.o

game3.o: game3.c makeeq.o verify.o init.o print.o
	gcc -c -g -I../include game3.c -o game3.o

game4.o: game4.c makeeq.o verify.o init.o print.o quickSort.o
	gcc -c -g -I../include game4.c -o game4.o

makeeq.o: makeeq.c
	gcc -c -g -I../include makeeq.c -o makeeq.o

verify.o: verify.c
	gcc -c -g -I../include verify.c -o verify.o

print.o: print.c
	gcc -c -g -I../include print.c -o print.o

init.o: init.c
	gcc -c -g -I../include init.c -o init.o

quickSort.o: quickSort.c
	gcc -c -g -I../include quickSort.c -o quickSort.o

clean:
	rm *.o libfuncs.a

