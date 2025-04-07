#include "main.h"
int is_numeric_constant(const char* word)
{
    int i = 0;

    // Handle '+' or '-' at the start
    if (word[i] == '+' || word[i] == '-')
    {
        i++;
    }

    // Check for integer or floating-point constants
    int has_digit = 0;
    int is_float = 0;
    int has_dot = 0;
    int has_exponent = 0;

    // Check for hexadecimal literals
    if (word[i] == '0' && (word[i+1] == 'x' || word[i+1] == 'X')) 
    {
        i += 2; // Skip "0x" or "0X"
        if (isxdigit(word[i])) 
        {
            while (isxdigit(word[i])) 
            {
                i++;
                has_digit = 1;
            }
        }
        return has_digit && word[i] == '\0'; // Valid hex constant
    }

    // Check for octal literals (starting with 0)
    if (word[i] == '0' && isdigit(word[i+1])) 
    {
        i++;
        while (word[i] >= '0' && word[i] <= '7') 
        {
            i++;
            has_digit = 1;
        }
        return has_digit && word[i] == '\0'; // Valid octal constant
    }

    // Check for digits (decimal number or floating-point)
    while (word[i] != '\0') 
    {
        if (isdigit(word[i])) 
        {
            has_digit = 1;
        }
        else if (word[i] == '.' && !has_dot) 
        {
            has_dot = 1; // Handle float numbers
            is_float = 1;
        }
        else if ((word[i] == 'e' || word[i] == 'E') && has_digit) 
        {
            has_exponent = 1; // Handle scientific notation
        }
        else if ((word[i] == 'f' || word[i] == 'F' || word[i] == 'l' || word[i] == 'L') && has_digit) {
            // Handle suffix for float or double
            break;
        }
        else 
        {
            return 0; // Invalid character
        }
        i++;
    }

    // Check if the number is a valid integer or float
    if (is_float && has_dot) 
    {
        // Valid floating-point number (with or without exponent)
        return has_digit && (word[i] == '\0' || word[i] == 'f' || word[i] == 'F' || word[i] == 'l' || word[i] == 'L');
    }

    // If no dot or exponent, it's likely an integer (decimal)
    return has_digit && word[i] == '\0';
}
