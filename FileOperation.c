#include<stdio.h>
#include"FileOperation.h"

void CopyFile(FILE* fromFile, FILE* toFile)
{
    char reader;
    while (!feof(fromFile))
    {
        fscanf(fromFile, "%c", &reader);
        fprintf(toFile, "%c", reader);
    }
    
}