#include <stdio.h>
#include <stdlib.h>
#include "SuDoKu.h"

void InitializeBlock(int,int,int);
void DrawLine(FILE*);

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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char reader;
            fscanf(inputfile,"%c", &reader);
            if(reader == '\n')
            {
               fscanf(inputfile,"%c", &reader); 
            }
            if(reader != '-')
            {
                int value = atoi(&reader);
                Grid[i][j].value = value;
            }
        }
        
    }
}

void Solve()
{

}

void PrintBoard(FILE * outputFile)
{
    DrawLine(outputFile);
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if(column == 0)
            {
               fprintf(outputFile,"| "); 
            }
            int value = Grid[row][column].value;
            if(value == 0)
            {
               fprintf(outputFile,"- "); 
            }
            else
            {
                fprintf(outputFile,"%d ", value);
            }

            if((column+1)%3 == 0)
            {
                fprintf(outputFile,"| ");
            }
            
        }
        fprintf(outputFile,"\n");
        if((row+1)%3 == 0)
        {
             DrawLine(outputFile);
        }
    }
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

void DrawLine(FILE* outputFile)
{
    for (int i = 0; i < 25; i++)
    {
       fprintf(outputFile,"=");  
    }
    fprintf(outputFile,"\n");
}