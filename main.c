#include<stdio.h>

void CopyFile(FILE* fromFile, FILE* toFile)
{
    char reader;
    while (!feof(fromFile))
    {
        fscanf(fromFile, "%c", &reader);
        fprintf(toFile, "%c", reader);
    }
    
}

int main()
{
    FILE* inputFile;
    char* fileName = "Input.txt";
    if((inputFile = fopen(fileName, "r"))== NULL)
    {
        printf("File could not be opened %s \n", fileName);
        perror("Error :");
        return 1;
    }
    FILE* outputFile;
    char* outputfileName = "Output.txt";
    if((outputFile = fopen(outputfileName, "w"))== NULL)
    {
        printf("File could not be opened %s \n", fileName);
        perror("Error :");
        return 1;
    }
    CopyFile(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);

    int a;
    scanf("%d", &a);
    return 0;
}