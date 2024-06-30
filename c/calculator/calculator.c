/*
File: calculator.c
Author: Patrick Robbins
Date: 29/06/2024
Description: A simple program in c to perform basic arithmetic operations.
*/

#include "calculator.h"

//Prints the usage instructions for the calculator
void print_instructions(void)
{
    printf("Usage: ./calculator <num1> <operator> <num2>\n");
    printf("Example: ./calculator 5 '+' 3\n");
    printf("Operators:\n");
    printf("  + : Addition\n");
    printf("  - : Subtraction\n");
    printf("  * : Multiplication\n");
    printf("  / : Division\n");
    printf("NOTE:\n");
    printf("All input/output values will be integers.\n");
    printf("May need to escape/enclose the '*' operator for Unix systems\n");
}

//Calculates the result of the arithmetic operation gives by command line args.
int calculate(int argc, char *argv[])
{
    int number_1, number_2;
    char operator;

    //Print usage instructions if the number of arguments is incorrect.
    if (argc != 4)
    {
        printf("Error: Issue with the arguments being passed to calculate.\n");
        print_instructions();
        return 1;
    }

    number_1 = atoi(argv[1]);
    operator = argv[2][0];//Get the first character of the operator string.
    number_2 = atoi(argv[3]);

    //Perform the arithmetic operation based on the operator.
    int result;
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
            if (number_2 == 0)
            {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = number_1 / number_2;
            break;
        default://If the operator is not recognized, print usage instructions.
            printf("Error: unrecognized operator: %c\n", operator);
            print_instructions();
            return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}


/* End Of File */
