#include "main.h"
void read_file_contents(char* f_name)
{
    FILE* fp = fopen(f_name, "r");
    if(fp == NULL)
    {
        printf("Error: Unable to open the file %s\n", f_name);
        fclose(fp);
        return;
    }
    char buffer[MAX_LINE_LEN];
    printf("<--------------- LEXICAL ANALYZER --------------->\n\n");
    while(fgets(buffer,MAX_LINE_LEN,fp) != NULL)
    {
        lexical_analyzer(buffer);
    }
    printf("\n<------------------------------------------------>\n");
    fclose(fp);
}
