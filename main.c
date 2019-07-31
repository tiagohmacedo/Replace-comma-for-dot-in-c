// This program replaces the comma character for dot in a given text file.
#include <stdio.h>
#include <stdlib.h>

static const char * const USAGE_ERROR = "Usage %s filename\n";
static const char * const FILE_OPEN_ERROR = "Error: file \"%s\" could not be open.\n";
static const char * const FILE_CLOSE_ERROR = "Error: file \"%s\" could not be closed.\n";

int main(int argc, char *argv[])
{
    const char OLD_CHAR = ',';
    const char NEW_CHAR = '.';

    int ch;

    const char *const FILE_NAME = argv[1];
    FILE *inputFile;

    if(argc != 2)
    {
        fprintf(stderr, USAGE_ERROR, argv[0]);
        exit(EXIT_FAILURE);
    }

    if((inputFile = fopen(FILE_NAME, "r+")) == NULL)
    {
        fprintf(stderr, FILE_OPEN_ERROR, argv[1]);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(inputFile)) != EOF)
    {
       if(ch == OLD_CHAR)
       {
            fseek(inputFile, -1, SEEK_CUR);
            fputc(NEW_CHAR, inputFile);
       }
    }

    if(fclose(inputFile) != 0)
    {
        fprintf(stderr, FILE_CLOSE_ERROR, argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
