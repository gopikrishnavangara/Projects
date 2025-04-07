#include "main.h"
int is_identifier(char* word) 
{
    if (isalpha(word[0]) || word[0] == '_') 
    {
        for (int i = 1; word[i] != '\0'; i++) 
        {
            if (!isalnum(word[i]) && word[i] != '_') 
            {
                return 0; // not a valid identifier
            }
        }
        return 1; // valid identifier
    }
    return 0; // not an identifier
}
