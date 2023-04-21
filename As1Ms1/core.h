/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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


#include <stdio.h>

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lowerLimit, int upperLimit);

char inputCharOption(const char cstring[7]);

void inputCString(char* cstring, int minimum, int maximum);

void displayFormattedPhone(const char* string);