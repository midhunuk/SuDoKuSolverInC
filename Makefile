# make file 
CC=gcc
CFLAGS=-c -g

all: main

main: FileOperation.o SuDoKu.o main.o 
	$(CC) -g main.o FileOperation.o SuDoKu.o -o sudokuSolver

main.o: main.c
	$(CC) $(CFLAGS) main.c

FileOperation.o: FileOperation.c
	$(CC) $(CFLAGS) FileOperation.c

SuDoKu.o: SuDoKu.c
	$(CC) $(CFLAGS) SuDoKu.c

clean: 
	rm -rf *o sudokuSolver
