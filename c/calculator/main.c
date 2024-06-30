/*
File: main.c
Author: Patrick Robbins
Date: 29/06/2024
Description: main file for a simple calculator program.
*/

#include "calculator.h"

//takes in command line arguments and passes them to the calculate function.
int main(int argc, char *argv[])
{
    return calculate(argc, argv);
}
