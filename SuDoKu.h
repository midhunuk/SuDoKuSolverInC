#include<stdio.h>

struct Cell
{
    int row;
    int column;
    int block;
    int value;
};

void InitializeEmptyBoard();

void AddInitialValues(FILE * );

void Solve();

void PrintBoard(FILE * );

void DeleteBoard();
