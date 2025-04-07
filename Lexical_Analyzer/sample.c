#include <stdio.h>

int main() {
    // Comma as a delimiter in function arguments and array elements
    int a = 5, b = 10, c = 20;
    int arr[] = {1, 2, 3, 4};  // Comma used to separate array elements
    
    printf("Initial values: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Comma as an operator: multiple expressions in a single statement
    int result = (a ++, b ++, c ++, a + b + c);  // This uses comma as an operator
    printf("After incrementing a, b, and c: result = %d\n", result);
    
    // Comma as a delimiter in a for loop
    for (int i = 0, j = 10; i < 5; i++, j--) {
        printf("i = %d, j = %d\n", i, j); // Comma used to separate loop control variables
    }

    return 0;
}

