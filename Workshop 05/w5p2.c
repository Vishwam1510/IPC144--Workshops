/*
*****************************************************************************
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month;
    int flag = 0, i;
    double morningRating, eveningRating;
    double tmorningRating = 0.0, teveningRating = 0.0;
    double avgmorningRating, avgeveningRating;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year<MIN_YEAR || year>MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        if (month<JAN || month>DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))
        {
            printf("\n*** Log date set! ***\n\n");
            flag = 1;
        }

    } while (flag == 0);

    for (i = 1;i <= LOG_DAYS;i++)
    {
        switch (month)
        {
        case 1:
        {
            printf("%d-JAN-0%d\n", year, i);
            break;
        }
        case 2:
        {
            printf("%d-FEB-0%d\n", year, i);
            break;
        }
        case 3:
        {
            printf("%d-MAR-0%d\n", year, i);
            break;
        }
        case 4:
        {
            printf("%d-APR-0%d\n", year, i);
            break;
        }
        case 5:
        {
            printf("%d-MAY-0%d\n", year, i);
            break;
        }
        case 6:
        {
            printf("%d-JUN-0%d\n", year, i);
            break;
        }
        case 7:
        {
            printf("%d-JUL-0%d\n", year, i);
            break;
        }
        case 8:
        {
            printf("%d-AUG-0%d\n", year, i);
            break;
        }
        case 9:
        {
            printf("%d-SEP-0%d\n", year, i);
            break;
        }
        case 10:
        {
            printf("%d-OCT-0%d\n", year, i);
            break;
        }
        case 11:
        {
            printf("%d-NOV-0%d\n", year, i);
            break;
        }
        case 12:
        {
            printf("%d-DEC-0%d\n", year, i);
            break;
        }
        }
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating < 0.0 || morningRating>5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (morningRating < 0.0 || morningRating>5.0);
        tmorningRating += morningRating;
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating < 0.0 || eveningRating>5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating>5.0);
        printf("\n");
        teveningRating += eveningRating;
    }
    avgmorningRating = tmorningRating / LOG_DAYS;
    avgeveningRating = teveningRating / LOG_DAYS;
    printf("Summary\n");
    printf("=======\n");

    printf("Morning total rating: %0.3lf\n", tmorningRating);
    printf("Evening total rating:  %0.3lf\n", teveningRating);

    printf("----------------------------\n");
    printf("Overall total rating: %0.3lf\n\n", (tmorningRating + teveningRating));

    printf("Average morning rating:  %0.1lf\n", avgmorningRating);
    printf("Average evening rating:  %0.1lf\n", avgeveningRating);

    printf("----------------------------\n");
    printf("Average overall rating:  %0.1lf\n", (avgmorningRating + avgeveningRating) / 2);

    return 0;
}

