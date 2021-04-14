#include <stdio.h>
#include <stdlib.h>
#include "SuDoKu.h"

void InitializeBlock(int,int,int);
void DrawLine(FILE*);
void Solution1();
int Solution1Loop();

int Grid[9][9];

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
                Grid[i][j] = value;
            }
            else
            {
                Grid[i][j] = 0;
            }
        }
        
    }
}

void Solve()
{
    Solution1();
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
            int value = Grid[row][column];
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

void DrawLine(FILE* outputFile)
{
    for (int i = 0; i < 25; i++)
    {
       fprintf(outputFile,"=");  
    }
    fprintf(outputFile,"\n");
}

void Solution1()
{
    int unFoundValue = 1;
    while (unFoundValue > 0)
    {
         unFoundValue = Solution1Loop();
    }
    
}

int Solution1Loop()
{
    int unFoundValue = 0;
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if(Grid[row][column] != 0) 
            {
                continue;
            }
            int possibleVales[10] = {0};

            // Check row and column
            for (int index = 0; index < 9; index++)
            {
                possibleVales[(Grid[index][column])] = -1;
                possibleVales[(Grid[row][index])] = -1;
            }

            // Check block
            int rowStart = row - row%3;
            int columnStart = column - column%3;
            for (int row = rowStart; row < rowStart+3; row++)
            {
                for (int j = columnStart; j < columnStart+3; j++)
                {
                   possibleVales[(Grid[row][j])] = -1; 
                }
            }
            
            int possibleValueCount=0;
            int possibleValue;
            for (int i = 1; i < 10; i++)
            {
                if(possibleVales[i]==0)
                {
                    possibleValueCount++;
                    possibleValue = i;
                }
            }
            
            if(possibleValueCount == 1)
            {
                Grid[row][column] = possibleValue;
            }
            else
            {
                unFoundValue++;
            }
        }
    } 
    return unFoundValue;
}