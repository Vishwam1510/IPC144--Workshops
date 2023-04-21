/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

int inputInt(void)
{
    char newLine = 'x';
    int value;

    do
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (newLine != '\n');
    return value;
}

int inputIntPositive(void)
{
    int value1 = 0;
    do
    {
        value1 = inputInt();
        if (value1 < 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value1 < 0);
    return value1;
}

int inputIntRange(int lower, int upper)
{
    int value2 = lower - 1;
    do
    {
        value2 = inputInt();
        if (value2<lower || value2>upper)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (value2<lower || value2>upper);
    return value2;
}

char inputCharOption(char cstring[7])
{
    char input, newLine;
    int i, flag;
    do
    {
        flag = 0;
        scanf("%c%c", &input, &newLine);
        if (newLine == '\n')
        {
            for (i = 0;i < 7;i++)
            {
                if (input == cstring[i])
                {
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                printf("ERROR: Character must be one of [%s]: ", cstring);
            }
        }
    } while (flag == 0);
    return input;
}

void inputCString(char* cString, int min, int max)
{

    int flag, length;

    do
    {
        char str[100] = { '\0' };
        flag = 0;

        scanf("%99[^\n]%*c", str);

        length = strlen(str);

        if (length - 1 == min && length - 1 == max)
        {
            strcpy(cString, str);
            cString[length + 1] = '\0';
            flag = 1;
        }

        else
        {

            if (length - 1 >= min && length - 1 <= max)
            {
                strcpy(cString, str);
                cString[length + 1] = '\0';
                flag = 1;
            }
        }


        if (flag == 0)
        {
            if (min == max)
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else if (min == 0 || length - 1 > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
    } while (flag == 0);
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

void displayFormattedPhone(const char* string2)
{
    int flag = 0;
    int i = 0;

    if (string2 != NULL)
    {
        for (i = 0;string2[i]; i++)
        {

            if (string2[i] < 48 || string2[i] > 57)//ASCII CODE VALUES OF 0-9
            {
                flag = 1;
            }
        }
    }
    if (flag == 0 && i == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", string2[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", string2[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", string2[i]);
    }
    else
    {
        printf("(___)___-____");
    }
}
