#include<stdio.h>

typedef struct 
{
    int row;
    int column;
    int block;
    int value;
} CELL;

void InitializeEmptyBoard();

void AddInitialValues(FILE * );

void Solve();

void PrintBoard(FILE * );

void DeleteBoard();
