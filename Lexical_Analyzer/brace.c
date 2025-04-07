#include "main.h"
int is_brace(char* buffer, char ch)
{
    int len = strlen(buffer);
    int flag = 0;
    if (ch == '{') return 1;  // Opening brace
    if (ch == '}') return 2;  // Closing brace
    if (ch == '(') return 4;  // Opening parenthesis
    if (ch == ')') return 5;  // Closing parenthesis
    if (ch == '[') return 6;  // Opening square bracket
    if (ch == ']') return 7;  // Closing square bracket
    if (ch == ';')
    {
        int len = strlen(buffer);
        int flag = 0;
        for(int i = 0; i < len; i++)
        {
            if (buffer[i] == '(')
            {
                flag = 1;
            }
            else if(buffer[i] == ')')
            {
                flag = 0;
            }
            if(buffer[i] == ';')
            {
                if(flag)
                {
                    return 3;
                }
                else
                {
                    return 8;
                }
            }
        }
    }
    return 0;  // Not a brace or parenthesis
}
