#include<stdio.h>
#include"SuDoKu.h"

int main()
{
    FILE* inputFile;
	FILE* outputFile;
    char* inputFileName = "Input.txt";
    char* outputfileName = "Output.txt";
    printf("Reading input file \n");
    if((inputFile = fopen(inputFileName, "r"))== NULL)
    {
        printf("File could not be opened %s \n", inputFileName);
        perror("Error :");
        return 1;
    }
	
	AddInitialValues(inputFile);
	fclose(inputFile);

	printf("Su Do Ku Puzzle \n");
	PrintBoard(stdout);

	printf("Solving Puzzle ...\n");	
	Solve();

	printf("Solved Puzzle \n");	
    PrintBoard(stdout); 

	printf("Printing to output file \n");	
    if((outputFile = fopen(outputfileName, "w"))== NULL)
    {
        printf("File could not be opened %s \n", inputFileName);
        perror("Error :");
        return 1;
    }

    PrintBoard(outputFile);  
    fclose(outputFile);

	printf("Closing game \n");
    return 0;
}