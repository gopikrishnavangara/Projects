#include "main.h"
int is_string(char* word) 
{
    return (word[0] == '"' && word[strlen(word) - 1] == '"');
}
