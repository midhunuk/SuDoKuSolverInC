# make file 
CC=gcc
CFLAGS=-c -g

all: main

main: FileOperation.o main.o
	$(CC) -g main.o FileOperation.o -o sudokuSolver

main.o: main.c
	$(CC) $(CFLAGS) main.c

FileOperation.o: FileOperation.c
	$(CC) $(CFLAGS) FileOperation.c

clean: 
	rm -rf *o main
