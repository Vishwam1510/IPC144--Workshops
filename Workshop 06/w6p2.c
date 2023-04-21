/*
*****************************************************************************
                          Workshop - #6 (P2)
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

#define MIN_ITEMS 1
#define MAX_ITEMS 10


int main(void)
{
    const double minIncome = 500.00, maxIncome = 400000.00, minCost = 100.00;
    double netIncome;
    int nwishItems, i;
    double cost[MAX_ITEMS] = { 0.0 };
    int priority[MAX_ITEMS] = { 0 };
    char finance[MAX_ITEMS] = { " " };
    double total = 0.0;
    int selection, flag = 0, mainflag = 0;
    int years, months;
    double extramonths;
    int prioritychoice;
    double totalprioritycost = 0.0;


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", minIncome);
        }
        else if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", maxIncome);
        }
        else
        {
            flag = 1;
        }
    } while (flag == 0);
    do
    {
        flag = 0;
            printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &nwishItems);

        if (nwishItems == 0 || nwishItems > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_ITEMS, MAX_ITEMS);
        }
        else
        {
            flag = 1;
        }
    } while (flag == 0);
    for (i = 0;i < nwishItems;i++)
    {

        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            flag = 0;
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
            else
            {
                flag = 1;
            }
        } while (flag == 0);

        do
        {
            flag = 0;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i]>3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                flag = 1;
            }
        } while (flag == 0);
        do
        {
            flag = 0;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (finance[i] != 'y' && finance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {
                flag = 1;
            }


        } while (flag == 0);
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0;i < nwishItems;i++)
    {
        total = total + cost[i];
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);



    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");

        printf("Selection: ");
        scanf("%d", &selection);

        if (selection < 0 || selection>2)
        {
            printf("\nERROR: Invalid menu selection.\n\n");

        }


        if (selection == 1)
        {
            flag = 0;
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", total);

            years = total / (netIncome * 12);
            months = (int)(total / netIncome) % 12;

            extramonths = (int)((total / (netIncome * 12)) * 100) % 100;
            extramonths = (extramonths * 12) / 100;

            if (extramonths - months > 0)
            {
                months = months + 1;
            }

            printf("Forecast: %d years, %d months\n", years, months);

            for (i = 0;i < nwishItems;i++)
            {
                if (finance[i] == 'y')
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }

        if (selection == 2)
        {
            flag = 0;
            totalprioritycost = 0;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &prioritychoice);
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", prioritychoice);

            for (i = 0;i < nwishItems;i++)
            {
                if (prioritychoice == priority[i])
                {
                    totalprioritycost += cost[i];
                    if (finance[i] == 'y')
                    {
                        flag = 1;
                    }
                }
            }
            printf("Amount:   $%0.2lf\n", totalprioritycost);

            years = totalprioritycost / (netIncome * 12);
            months = (int)(totalprioritycost / netIncome) % 12;

            extramonths = (int)((totalprioritycost / (netIncome * 12)) * 100) % 100;
            extramonths = (extramonths * 12) / 100;

            if (extramonths - months > 0)
            {
                months = months + 1;
            }

            printf("Forecast: %d years, %d months\n", years, months);

            if (flag == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");


        }
        if (selection == 0)
        {
            mainflag = 1;
            printf("\nBest of luck in all your future endeavours!\n");
        }

    } while (mainflag == 0);

    return 0;
}