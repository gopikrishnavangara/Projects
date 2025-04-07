#include "main.h"
void check_comma_usage(const char* buffer, char c) 
{
    int result = is_comma_operator_seperator(buffer);
    if (result == 1) 
    {
        printf("COMMA-OPERATOR:  %c\n", c);
        return;
    } 
    else if(result == 0) 
    {
        printf("COMMA-DELIMITER:  %c\n", c);
        return;
    }

}
int is_comma_operator_seperator(const char* buffer) 
{
    int len = strlen(buffer);
    int flag = 0;
    for(int i = 0; i < len; i++)
    {
        if(buffer[i] == '(')
        {
            flag = 1;
        }
        else if(buffer[i] == ')')
        {
            flag = 0;
        }
        if(buffer[i] == ',')
        {
            if(flag)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}
