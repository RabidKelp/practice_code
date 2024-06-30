/*
File: calculator.h
Author: Patrick Robbins
Date: 30/06/2024
Description: Header file for calculator.c.
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

//Calculates the result, and returns the result as a float.
float calculate(float number_1, char operator, float number_2);

//Prints the usage instructions for the calculator.
void print_instructions(void);

//Clears the input buffer in the event of invalid input.
void clear_input_buffer(void);

#endif // CALCULATOR_H



/* End Of File */
