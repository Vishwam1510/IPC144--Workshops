/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//Displays the data
void displayFormattedPhone(const char* string);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//Checks if the input is a whole number or not
int inputInt(void);

//To check if input is a positive value!
int inputIntPositive(void);

//To check if the input is in a specific range!
int inputIntRange(int lowerLimit, int upperLimit);

//To check if the character entered is one of the allowed characters!
char inputCharOption(const char cstring[7]);

//To check if the length of the string is appropriate or not!
void inputCString(char* cstring, int minimum, int maximum);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H