#include "main.h"
void is_preprocessor(char* buff)
{
    if(strncmp(buff, "#i",2) == 0)
    {
        char* token = strtok(buff, " ");
        printf("PRE-PROCESSOR DIRECTIVE:  %s\n", token);
        while(token != NULL)
        {
            token = strtok(NULL, " ");
            if(strncmp(token,"<",1) == 0)
            {
                printf("STANDARD HEADER FILE:  %s", token);
                memset(buff,0, MAX_LINE_LEN*sizeof(buff[0]));
                return;
            }
            else
            {
                printf("CUSTOM DEFINED HEADER FILE:  %s", token);
                memset(buff,0, MAX_LINE_LEN*sizeof(buff[0]));
                return;
            }
        }
    }
    else if(strncmp(buff, "#d", 2) == 0)
    {
        char* token = strtok(buff, " ");
        printf("MACRO DEFINTION:  %s\n",token);
        while(token != NULL)
        {
            token = strtok(NULL," ");
            if(isalpha(token[0]) && isupper(token[0]))
            {
                printf("MACRO NAME:  %s\n", token);
            }
            else
            {
                printf("MACRO VALUE:  %s", token);
                memset(buff,0, MAX_LINE_LEN*sizeof(buff[0]));
                return;
            }
        }
    }
}
