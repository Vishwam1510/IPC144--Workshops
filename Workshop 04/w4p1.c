/*
*****************************************************************************
                          Workshop - #4 (P1)
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

int main(void)
{
    char looptypeInitial;
    int nIterate, iteration;


    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do
    {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &looptypeInitial, &nIterate);

        if ((looptypeInitial != 'D') && (looptypeInitial != 'W') && (looptypeInitial != 'F') && (looptypeInitial != 'Q'))
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        else if (looptypeInitial == 'Q' && nIterate != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
        }
        else if ((nIterate>0 && nIterate < 3) || nIterate > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }


        else
        {
            iteration = nIterate;
            if (looptypeInitial == 'D')
            {
                printf("DO-WHILE: ");
            }
            else if (looptypeInitial == 'W')
            {
                printf("WHILE   : ");
            }
            else if (looptypeInitial == 'F')
            {
                printf("FOR     : ");
            }
            while (iteration > 0)
            {

                printf("%c", looptypeInitial);
                iteration--;
            }
            printf("\n");
        }
        
    } while ((looptypeInitial != 'Q') || (nIterate != 0));

    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}


