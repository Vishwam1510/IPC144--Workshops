/*
*****************************************************************************
                          Workshop - #6 (P1)
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
    } while (netIncome<minIncome || netIncome>maxIncome);
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &nwishItems);

        if (nwishItems == 0 || nwishItems > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (nwishItems<1 || nwishItems>MAX_ITEMS);
    
    for (i = 0;i < nwishItems;i++)
    {
        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
        } while (cost[i] < minCost);
        total = total + cost[i];
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i]>3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i]>3);
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (finance[i] != 'y' && finance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }


        } while (finance[i] != 'y' && finance[i] != 'n');
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0;i < nwishItems;i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}