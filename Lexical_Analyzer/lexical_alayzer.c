#include "main.h"
void lexical_analyzer(char* buffer)
{
    int i = 0, j = 0,ret;
    char word[100];
    while(buffer[i] != '\0')
    {
        char ch = buffer[i];
        // Handle character-by-character for string literals
        if (ch == '"') 
        {
            // Start of a string literal
            j = 0;
            word[j++] = ch;
            i++; // Move to the next character after the opening quote
            while (buffer[i] != '"' && buffer[i] != '\0') 
            { // Until we find the closing quote
                word[j++] = buffer[i++];
            }
            if (buffer[i] == '"') 
            { // If we found a closing quote
                word[j++] = buffer[i]; // Include the closing quote
                word[j] = '\0'; // Null-terminate the string

                // Call the is_string function to verify it's a string
                if (is_string(word)) 
                {
                    printf("STRING: %s\n", word);
                }
            }
            i++; // Skip the closing quote
            continue;
        }
        //Handle pre-processor and macros
        if(ch == '#')
        {
            is_preprocessor(buffer);
        }
        //Handle single and multiline comments
        if(ch == '/')
        {
            if (buffer[i + 1] == '/') 
            {  // Single-line comment
                i += 2; // Skip over "//"
                        // Store and print the comment content
                printf("SINGLE-LINE COMMENT: ");
                while (buffer[i] != '\n' && buffer[i] != '\0') 
                {
                    printf("%c", buffer[i]);
                    i++;  // Skip until end of line
                }
                printf("\n");  // End of the comment
                continue;  // Continue to the next token
            }
            if (buffer[i + 1] == '*') 
            {  // Multi-line comment
                i += 2; // Skip over "/*"
                printf("MULTI-LINE COMMENT: ");
                // Store and print the comment content
                while (!(buffer[i] == '*' && buffer[i + 1] == '/')) 
                {
                    if (buffer[i] == '\0') 
                    {
                        break; // Handle case where there's no closing */
                    }
                    printf("%c", buffer[i]);  // Print the comment character by character
                    i++;  // Skip over comment characters
                }
                printf("\n");  // End of the comment
                i += 2; // Skip over "*/"
                continue;  // Continue to the next token
            }
        }

        // Handle non-space, non-special character as part of a word
        if (ch != ' ' && ch != '{' && ch != '}' && ch != ';' && ch != '(' && ch != ')' && ch != '[' && ch != ']' && ch != ',') 
        {
            word[j++] = ch;
        }
        else 
        {
            if (j > 0) 
            {
                word[j] = '\0'; // Null-terminate the word
                if (is_keyword(word)) 
                {
                    printf("KEYWORD:  %s\n", word);
                } 
                else if (is_operator(word)) 
                {
                    printf("OPERATOR:  %s\n", word);
                } 
                else if (is_numeric_constant(word)) 
                {
                    printf("NUMERIC CONSTANT:  %s\n", word);
                } 
                else if (is_identifier(word)) 
                {
                    printf("IDENTIFIER:  %s\n", word);
                }
                j = 0; // Reset word for next token
            }
            //Handle comma
            if(ch == ',')
            {
                int len = strlen(buffer);
                int flag = 0, res = 0;
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
                            res = 1;
                        }
                        else
                        {
                            res = 0;
                        }
                    }
                }
                if(res == 1)
                {
                    printf("COMMA-OPERATOR:  %c\n", ch);
                }
                else
                {
                    printf("COMMA-DELIMITER:  %c\n", ch);
                }

            }

            // Check for braces, parentheses, square brackets, or strings
            ret = is_brace(buffer, ch);
            if (ret == 1) 
            {
                printf("O_BRACE:  %c\n", ch); // Opening brace
            } 
            else if (ret == 2) 
            {
                printf("C_BRACE:  %c\n", ch); // Closing brace
            } 
            else if (ret == 3) 
            {
                printf("DELIMITER:  %c\n", ch); // Semicolon
            }  
            else if (ret == 4) 
            {
                printf("O_PARENTHESIS:  %c\n", ch); // Opening parenthesis
            }  
            else if (ret == 5) 
            {
                printf("C_PARENTHESIS:  %c\n", ch); // Closing parenthesis
            } 
            else if (ret == 6) 
            {
                printf("O_BRACKET:  %c\n", ch); // Opening square bracket
            }
            else if (ret == 7) 
            {
                printf("C_BRACKET:  %c\n", ch); // Closing square bracket
            }
            else if( ret == 8)
            {
                printf("END OF LINE:  %c\n", ch);
            }
        }
        i++;
    }
    return;
}


