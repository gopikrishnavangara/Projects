#include "main.h"
int is_operator(const char* word)
{
    int size = sizeof(operators) / sizeof(operators[0]);  // Number of operators
    for(int i = 0; i < size; i++)
    {
        if(strcmp(word, operators[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
