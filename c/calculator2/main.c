/*
File: main.c
Author: Patrick Robbins
Date: 30/06/2024
Description: main file for a simple calculator program.
*/

#include "calculator.h"

//takes in command line arguments and passes them to the calculate function.
int main(void)
{
    float number_1, number_2;
    char operator;

    //Print the usage instructions for the calculator.
    print_instructions();

    for (;;)
    {
        //prompt the user for the calculation to perform.
        printf("Enter your calculation to perform: ");

        //Get Input, and check for invalid input (not 3 arguments).
        if (scanf("%f %c %f", &number_1, &operator, &number_2) != 3)
        {
            printf("Error: invalid input\n");

            //Clears the input buffer to prevent an infinite loop.
            clear_input_buffer();
            continue;
        };

        //Calculate and print the result of the arithmetic operation.
        printf("Result: %.6g\n", calculate(number_1, operator, number_2));
    
    }
}



/* End Of File */
