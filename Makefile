# make file 
CC=gcc
CFLAGS=-c -g

all: main

main: SuDoKu.o main.o 
	$(CC) -g main.o SuDoKu.o -o sudokuSolver

main.o: main.c
	$(CC) $(CFLAGS) main.c

SuDoKu.o: SuDoKu.c
	$(CC) $(CFLAGS) SuDoKu.c

clean: 
	rm -rf *o sudokuSolver
