#include "main.h"
int is_keyword(const char* word)
{
    int count = sizeof(keywords) / sizeof(keywords[0]);
    for(int i = 0; i < count; i++)
    {
        if(strcmp(word,keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

