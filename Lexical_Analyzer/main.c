#include "main.h"
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Error: Invalid arguments...\nUsage: ./a.out sample.c\n");
        return 1;
    }
    else if(argc == 2)
    {
        char* filename = argv[1];
        int len  = strlen(filename);
        if(len > 2 && filename[len-2] == '.' && filename[len-1] == 'c')
        {
            read_file_contents(filename);
        }
        else
        {
            printf("Error: Invalid file format...Only '.c' files are accepted...\nUsage: ./a.out sample.c\n");
            return 1;
        }
    }
    else
    {
        printf("Error: Morethan one '.c' files are not allowed...Only pass one '.c' file at a time...\nUsage: ./a.out sample.c\n");
        return 1;
    }
    return 0;
}

