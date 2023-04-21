/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    int nApples, nOranges, nPears, nTomatoes, nCabbages;
    int applesPicked, orangesPicked, pearsPicked, tomatoesPicked, cabbagesPicked;
    int decision;
    
    do
    {

        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {

            printf("How many APPLES do you need? : ");
            scanf("%d", &nApples);
            if (nApples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while(nApples < 0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &nOranges);
            if (nOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while(nOranges < 0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &nPears);
            if (nPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while(nPears < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &nTomatoes);
            if (nTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while(nTomatoes < 0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &nCabbages);
            if (nCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while(nCabbages < 0);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        while (nApples > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &applesPicked);

            if (applesPicked > nApples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", nApples);
            }
            else if (applesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (applesPicked > 0 && nApples > applesPicked)
            {
                printf("Looks like we still need some APPLES...\n");
                nApples -= applesPicked;
            }
            else
            {
                printf("Great, that's the apples done!\n\n");
                nApples -= applesPicked;
            }
        }

        while (nOranges > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangesPicked);

            if (orangesPicked > nOranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", nOranges);
            }
            else if (orangesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (orangesPicked > 0 && nOranges > orangesPicked)
            {
                printf("Looks like we still need some ORANGES...\n");
                nOranges -= orangesPicked;
            }
            else
            {
                printf("Great, that's the oranges done!\n\n");
                nOranges -= orangesPicked;
            }
        }

        while (nPears > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearsPicked);

            if (pearsPicked > nPears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", nPears);
            }
            else if (pearsPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pearsPicked > 0 && nPears > pearsPicked)
            {
                printf("Looks like we still need some PEARS...\n");
                nPears -= pearsPicked;
            }
            else
            {
                printf("Great, that's the pears done!\n\n");
                nPears -= pearsPicked;
            }
        }

        while (nTomatoes > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoesPicked);

            if (tomatoesPicked > nTomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", nTomatoes);
            }
            else if (tomatoesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (tomatoesPicked > 0 && nTomatoes > tomatoesPicked)
            {
                printf("Looks like we still need some TOMATOES...\n");
                nTomatoes -= tomatoesPicked;
            }
            else
            {
                printf("Great, that's the tomatoes done!\n\n");
                nTomatoes -= tomatoesPicked;
            }
        }

        while (nCabbages > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbagesPicked);

            if (cabbagesPicked > nCabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", nCabbages);
            }
            else if (cabbagesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (cabbagesPicked > 0 && nCabbages > cabbagesPicked)
            {
                printf("Looks like we still need some CABBAGES...\n");
                nCabbages -= cabbagesPicked;
            }
            else
            {
                printf("Great, that's the cabbages done!\n\n");
                nCabbages -= cabbagesPicked;
            }
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &decision);
        printf("\n");



    }while(decision > 0 || decision < 0);
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}


