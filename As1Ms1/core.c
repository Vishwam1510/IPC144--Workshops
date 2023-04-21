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

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "core.h"
#include <string.h>
    
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

int inputInt(void)
{
    char ch = 'x';
    int value;

    do
    {
        scanf("%d%c", &value, &ch);
        if (ch != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (ch != '\n');
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

int inputIntRange(int lowerLimit, int upperLimit)
{
    int value2 = lowerLimit - 1; //this point
    do
    {
        value2 = inputInt();
        if (value2<lowerLimit || value2>upperLimit)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerLimit, upperLimit);
        }
    } while (value2<lowerLimit || value2>upperLimit);
    return value2;
}

char inputCharOption(const char cstring[7])
{
    char userInput, ch;
    int i, flag;
    do
    {
        flag = 0;
        scanf("%c%c", &userInput, &ch);
        if (ch == '\n')
        {
            for (i = 0;i < 7;i++)
            {
                if (cstring[i] == userInput)
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
    return userInput;
}

void inputCString(char* cString, int minimum, int maximum)
{

    int flag, i, j, cnt;

    do
    {
        char str[100] = { '\0' };
        flag = 0;
        i = 0;
        j = 0;
        cnt = 0;

        scanf("%99[^\n]%*c", str);

        for (i = 0; i < 100; i++)
        {
            if (str[i] != '\0')
            {
                cnt++;
            }

        }

        if (cnt == minimum && minimum == maximum)
        {
            for (j = 0; j <= cnt;j++)
            {
                cString[j] = str[j];
            }
            cString[j] = '\0';
            flag = 1;
        }

        else
        {

            if (cnt >= minimum && cnt <= maximum)
            {
                for (j = 0;j <= cnt;j++)
                {
                    cString[j] = str[j];
                }
                cString[j] = '\0';
                flag = 1;
            }
        }


        if (flag == 0)
        {
            if (minimum == maximum)
            {
                printf("ERROR: String length must be exactly %d chars: ", minimum);
            }
            else if (cnt > maximum)
            {
                printf("ERROR: String length must be no more than %d chars: ", maximum);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", minimum, maximum);
            }
        }
    } while (flag == 0);
}


void displayFormattedPhone(const char* string)
{
    int flag = 0;
    int i = 0;

    if (string != NULL)
    {
        for (i = 0;string[i]; i++)
        {

            if (string[i] < 48 || string[i] > 57) 
            {
                flag = 1;
            }
        }
    }
    if (flag == 0 && i == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", string[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", string[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", string[i]);
    }
    else
    {
        printf("(___)___-____");
    }
}










