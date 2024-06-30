/*
File: calculator.c
Author: Patrick Robbins
Date: 30/06/2024
Description: A simple program in c to perform basic arithmetic operations.
*/

#include "calculator.h"

//Calculates the result of the arithmetic operation, returns result as a float.
float calculate(float number_1, char operator, float number_2)
{
    float result;

    //Perform the arithmetic operation based on the operator.
    switch (operator)
    {
        case '+':
            result = number_1 + number_2;
            break;
        case '-':
            result = number_1 - number_2;
            break;
        case '*':
            result = number_1 * number_2;
            break;
        case '/':
            if ( 0.0f == number_2 )//Check for division by zero.
            {
                printf("Error: Division by zero\n");
                return 0.0f;
            }
            result = number_1 / number_2;
            break;
        default://If the operator is not recognized, print usage instructions.
            printf("Error: unrecognized operator: %c\n", operator);
            print_instructions();
            return 0.0f;
    }

    return result;
}


//Prints the usage instructions for the calculator
void print_instructions(void)
{
    printf("Usage: <num1> <operator> <num2>\n");
    printf("Example: 5.5 + 3\n");
    printf("Operators:\n");
    printf("  + : Addition\n");
    printf("  - : Subtraction\n");
    printf("  * : Multiplication\n");
    printf("  / : Division\n");
    printf("NOTE: Results are subject to inprecision inherent with");
    printf(" floating point operations.\n");//second line of note.
}

//Clears the input buffer in the event of invalid input.
void clear_input_buffer(void)
{
    int c;
    //get characters until newline or EOF is reached/found.
    while ((c = getchar()) != '\n' && c != EOF)
    {
        //do nothing.
    }
}



/* End Of File */
