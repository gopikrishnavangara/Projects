#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
static char* keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do","double", "else", "enum", "extern", "float", "for", "goto", "if","int", "long", "register", "return", "short", "signed","sizeof","static","struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
static char *operators[] = {
    // Arithmetic Operators
    "+", "-", "*", "/", "%",
    
    // Relational Operators
    "==", "!=", "<", ">", "<=", ">=",
    
    // Logical Operators
    "&&", "||", "!",
    
    // Bitwise Operators
    "&", "|", "^", "~", "<<", ">>",
    
    // Assignment Operators
    "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=",
    
    // Increment/Decrement Operators
    "++", "--",
    
    // Conditional (Ternary) Operator
    "?:",
    
    // Sizeof Operator
    "sizeof",
    
    // Pointer Operators
    "*", "&",
    
    // Typecast Operator
    "(type)"
};
    
void read_file_contents(char* f_name);
void check_each_line(char* buff);
void lexical_analyzer(char* buffer);
void is_preprocessor(char* buff);
