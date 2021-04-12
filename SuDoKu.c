#include <stdio.h>
#include <stdlib.h>
#include "SuDoKu.h"

void InitializeBlock(int,int,int);

CELL Grid[9][9];

void InitializeEmptyBoard()
{
   InitializeBlock(0,0,0); 
   InitializeBlock(0,3,1);
   InitializeBlock(0,6,2);
   InitializeBlock(3,0,3);
   InitializeBlock(3,3,4);
   InitializeBlock(3,6,5);
   InitializeBlock(6,0,6);
   InitializeBlock(6,3,7);
   InitializeBlock(6,6,8);
}

void AddInitialValues(FILE * inputfile)
{

}

void Solve()
{

}

void PrintBoard(FILE * outputFile)
{

}

void DeleteBoard()
{

}

void InitializeBlock(int rowStart,int columnStart, int block)
{
    for (int i = rowStart; i < rowStart+3; i++)
    {
        for (int j = columnStart; j < columnStart+3; j++)
        {
            CELL* cell = &Grid[i][j];
            cell->row = i;
            cell->column = j;
            cell->block = block;
        }
    }
    
}